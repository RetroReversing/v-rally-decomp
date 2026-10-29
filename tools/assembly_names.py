"""Keep regenerated function assembly paths aligned with the checked-in build manifest."""
import re
from pathlib import Path


def canonicalize(root, functions):
    by_address = {fn['vram']: fn for fn in functions}
    for path in list((root / 'asm/nonmatchings').rglob('*.s')):
        if not path.exists():
            continue
        text = path.read_text()
        first = re.search(r'/\*\s*[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+[0-9A-Fa-f]{8}\s*\*/', text)
        fn = by_address.get(int(first[1], 16)) if first else None
        if not fn or path == root / fn['asm']:
            continue
        # SDK names may have been added after this manifest was exported. Its symbol table retains those
        # readable aliases; the assembly unit itself must use the name/path expected by its C counterpart.
        text = re.sub(r'\b'+re.escape(path.stem)+r'\b', fn['name'], text)
        destination = root / Path(fn['asm'])
        destination.parent.mkdir(parents=True, exist_ok=True)
        destination.write_text(text)
        path.unlink()
