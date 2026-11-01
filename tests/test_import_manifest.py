"""Public import metadata must describe the same cartridge as the portable save."""
import json
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


class ImportManifestTest(unittest.TestCase):
    def test_cartridge_and_setup_match_the_export(self):
        manifest = json.loads((ROOT / '.decomp.wtf.json').read_text())
        build = json.loads((ROOT / 'build.json').read_text())
        progress = json.loads((ROOT / 'progress/decompdecomp.json').read_text())
        self.assertEqual(manifest['game']['sha1'], build['sha1'])
        self.assertEqual(manifest['game']['sha1'], progress['game']['sha1'])
        self.assertEqual(manifest['game']['path'], build['image'])
        self.assertEqual(manifest['platform'], progress['platform'])
        self.assertEqual(manifest['setup'], [['python3', 'build.py', 'targets'], ['python3', 'build.py']])
        self.assertTrue((ROOT / 'build.py').is_file())
