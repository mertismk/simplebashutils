import os
import unittest

def calc(pattern, flag):
    os.system(f"grep {pattern} {flag} file.txt file2.txt file3.txt > first")
    os.system(f"./s21_grep {pattern} {flag} file.txt file2.txt file3.txt > second")
    os.system(f"diff first second > result")


def calc_f(flag):
    os.system(f"grep {flag} file3.txt file.txt > first")
    os.system(f"./s21_grep {flag} file3.txt file.txt > second")
    os.system(f"diff first second > result")


class TestGrep(unittest.TestCase):

    def test_no_flag(self):
        calc("aboba", "")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_i(self):
        calc("boba", "-i")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_v(self):
        calc("boba", "-v")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_c(self):
        calc("boba", "-c")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_l(self):
        calc("boba", "-l")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_n(self):
        calc("boba", "-n")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_o(self):
        calc("boba", "-o")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_h(self):
        calc("boba", "-h")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_s(self):
        calc("boba", "-s")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

    def test_flag_f(self):
        calc_f("-f")
        self.assertEqual(os.path.getsize("result"), 0, "Diff size should be 0")

if __name__ == '__main__':
    unittest.main()