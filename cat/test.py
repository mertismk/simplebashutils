import os
import unittest

def calc(flag):
    os.system(f"cat {flag} file.txt file2.txt file3.txt > first")
    os.system(f"./s21_cat {flag} file.txt file2.txt file3.txt > second")
    os.system(f"diff first second > result")


class TestCat(unittest.TestCase):

    def test_no_flag(self):
        calc("")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_b(self):
        calc("-b")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_e(self):
        calc("-e")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_n(self):
        calc("-n")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_s(self):
        calc("-s")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_t(self):
        calc("-t")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_bn(self):
        calc("-bn")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_bs(self):
        calc("-bs")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_bt(self):
        calc("-bt")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_ne(self):
        calc("-ne")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_es(self):
        calc("-es")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_et(self):
        calc("-et")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_ns(self):
        calc("-ns")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")
    
    def test_flag_nt(self):
        calc("-nt")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_st(self):
        calc("-st")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

if __name__ == '__main__':
    unittest.main()