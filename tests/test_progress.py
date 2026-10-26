"""The progress map must not count assembly placeholders as completed C."""
import importlib.util
import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

spec = importlib.util.spec_from_file_location('progress', Path(__file__).resolve().parents[1] / 'tools/progress.py')
progress = importlib.util.module_from_spec(spec)
spec.loader.exec_module(progress)


class ProgressTest(unittest.TestCase):
    def test_units_and_placeholders(self):
        functions = [{'name': name, 'seg': 'engine', 'asm': f'asm/nonmatchings/engine/{name}.s'}
                     for name in ('written', 'remaining')]
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            with patch.multiple(progress.build, ROOT=root, B={'functions': functions, 'asm_preamble': '.text\n'}), \
                    patch.object(progress.build, 'c_source', side_effect=['src/engine/written.c', None]), \
                    patch.object(progress.build, 'build_objects') as assemble:
                progress.configure()
            units = json.loads((root / 'objdiff.json').read_text())['units']
            self.assertEqual([u['name'] for u in units], ['engine/written', 'engine/remaining'])
            self.assertTrue(units[0]['metadata']['complete'])
            self.assertEqual(units[0]['metadata']['source_path'], 'src/engine/written.c')
            self.assertFalse(units[1]['metadata']['complete'])
            self.assertNotEqual(units[1]['base_path'], units[1]['target_path'])
            self.assertEqual(units[1]['base_path'], 'build/progress/empty.o')
            self.assertEqual(len(assemble.call_args.args[0]), 3)

    def test_source_alias_header_is_not_included(self):
        from unittest.mock import MagicMock
        from tools import source_names
        symbol = MagicMock()
        symbol.name = 'ReadableName'
        symbol.__getitem__.side_effect = {'st_info': {'type': 'STT_FUNC'}, 'st_shndx': 1}.__getitem__
        elf = MagicMock()
        elf.get_section_by_name.return_value.iter_symbols.return_value = [symbol]
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / 'include').mkdir()
            (root / 'build/src').mkdir(parents=True)
            (root / 'build/src/original.o').touch()
            with patch.object(source_names, 'ELFFile', return_value=elf):
                source_names.generate(root, [{'name': 'func_80001000', 'c': 'src/original.c'}])
            text = (root / 'include/bytematch_names.h').read_text()
            self.assertIn('#define func_80001000 ReadableName', text)
            self.assertNotIn('#include', text)


if __name__ == '__main__':
    unittest.main()
