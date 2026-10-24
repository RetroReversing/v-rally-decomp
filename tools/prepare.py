#!/usr/bin/env python3
# SPDX-License-Identifier: AGPL-3.0-only
"""Normalize the user's own V-Rally Europe ROM; never download game data."""
from pathlib import Path
import argparse
import hashlib
import json

root = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('rom', type=Path)
args = parser.parse_args()
config = json.loads((root / 'build.json').read_text())
dest = root / config['image']
if dest.is_symlink() or dest.resolve() == args.rom.resolve() or (dest.exists() and dest.samefile(args.rom)):
    parser.error('Keep your original ROM separate from the generated baserom file.')
data = args.rom.read_bytes()
magic = data[:4]
if magic == bytes.fromhex('37804012') and len(data) % 2 == 0:
    normalized = bytearray(data)
    normalized[0::2], normalized[1::2] = data[1::2], data[0::2]
    data = bytes(normalized)
elif magic == bytes.fromhex('40123780') and len(data) % 4 == 0:
    normalized = bytearray(len(data))
    for offset in range(4):
        normalized[offset::4] = data[3-offset::4]
    data = bytes(normalized)
elif magic != bytes.fromhex('80371240'):
    parser.error('Unrecognized N64 byte order or invalid byte alignment.')
if hashlib.sha1(data).hexdigest() != config['sha1']:
    parser.error('This project requires V-Rally Edition 99 Europe revision 0; normalized SHA-1 differs.')
dest.write_bytes(data)
print('Prepared baserom.z64; fixed original-ROM hash verified.')
