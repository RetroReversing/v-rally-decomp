#!/usr/bin/env python3
"""Record compiled symbol aliases for ByteMatch; this header is never included."""
from pathlib import Path

from elftools.elf.elffile import ELFFile


def generate(root, functions):
    aliases = []
    for fn in functions:
        if not fn.get('c'):
            continue
        with (root / 'build' / Path(fn['c']).with_suffix('.o')).open('rb') as stream:
            elf = ELFFile(stream)
            names = [symbol.name for symbol in elf.get_section_by_name('.symtab').iter_symbols()
                     if symbol['st_info']['type'] == 'STT_FUNC' and symbol['st_shndx'] != 'SHN_UNDEF']
        if len(names) == 1 and names[0] != fn['name']:
            aliases.append(f"#define {fn['name']} {names[0]}\n")
    (root / 'include/bytematch_names.h').write_text(
        '/* Report symbol aliases for ByteMatch source lookup. Not included by the build. */\n' + ''.join(aliases))
