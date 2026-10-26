#!/usr/bin/env python3
"""Verify the cartridge, then prepare objdiff inputs for ByteMatch (NVLP)."""
import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import build
from tools.source_names import generate


def configure():
    """Describe every function; absent C compares against an empty object, never itself."""
    units = []
    targets = []
    empty = build.ROOT / 'build/progress/empty.s'
    empty.parent.mkdir(parents=True, exist_ok=True)
    empty.write_text('.text\n')
    targets.append(('asm', 'build/progress/empty.s', 'build/progress/empty.o'))
    for fn in build.B['functions']:
        source = build.c_source(fn)
        wrapper = f"build/progress/{fn['seg']}/{fn['name']}.s"
        path = build.ROOT / wrapper
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(build.B['asm_preamble'] + f'.include "{fn["asm"]}"\n')
        target = f"build/{Path(fn['asm']).with_suffix('.o').as_posix()}"
        targets.append(('asm', wrapper, target))
        units.append({
            'name': f"{fn['seg']}/{fn['name']}",
            'target_path': target,
            'metadata': {'complete': bool(source), 'source_path': source or fn['asm']},
            'base_path': f"build/{Path(source).with_suffix('.o').as_posix()}" if source else 'build/progress/empty.o',
        })
    build.build_objects(targets)
    (build.ROOT / 'objdiff.json').write_text(json.dumps({
        'build_base': False, 'build_target': False, 'units': units,
    }, indent=2) + '\n')


if __name__ == '__main__':
    if not build.build():
        sys.exit(1)
    configure()
    generate(build.ROOT, build.B['functions'])
