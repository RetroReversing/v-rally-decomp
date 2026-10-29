"""A readable SDK alias must not break the manifest's regenerated assembly unit."""
import tempfile
import unittest
from pathlib import Path

from tools.assembly_names import canonicalize


class AssemblyNamesTest(unittest.TestCase):
    def test_names_follow_manifest_without_changing_instruction_words(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            old = root / 'asm/nonmatchings/engine/ReadableHelper.s'
            old.parent.mkdir(parents=True)
            old.write_text('glabel ReadableHelper\n/* 000010 80001000 03E00008 */ jr $ra\n'
                           '/* 000014 80001004 00000000 */ nop\n')
            units = [{'name':'func_80001000','vram':0x80001000,
                      'asm':'asm/nonmatchings/engine/func_80001000.s'}]
            canonicalize(root, units)
            result = root / units[0]['asm']
            self.assertFalse(old.exists())
            self.assertIn('glabel func_80001000', result.read_text())
            self.assertIn('80001000 03E00008', result.read_text())
            self.assertIn('80001004 00000000', result.read_text())
            stamp = result.stat().st_mtime_ns
            canonicalize(root, units)
            self.assertEqual(result.stat().st_mtime_ns, stamp)

    def test_unknown_address_is_left_untouched(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / 'asm/nonmatchings/engine/other.s'
            path.parent.mkdir(parents=True)
            text = 'glabel other\n/* 000010 80001000 00000000 */ nop\n'
            path.write_text(text)
            canonicalize(root, [])
            self.assertEqual(path.read_text(), text)


if __name__ == '__main__':
    unittest.main()
