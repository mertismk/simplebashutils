#include "cat.h"

int main(int argc, char* argv[]) {
  int opt;
  int with_flags = 0;
  struct all_flags flags = {0, 0, 0, 0, 0};
  while ((opt = getopt_long(argc, argv, "benst", long_opt, NULL)) != -1) {
    switch (opt) {
      case 'b':
        flags.b = 1;
        break;
      case 'e':
        flags.e = 1;
        break;
      case 'n':
        flags.n = 1;
        break;
      case 's':
        flags.s = 1;
        break;
      case 't':
        flags.t = 1;
        break;
    }
  }
  controlCat(argc, argv, flags);
  return 0;
}

void controlCat(int argc, char* argv[], struct all_flags flags) {
  int check = 1;
  while (check < argc) {
    if (argv[check][0] != '-') {
      FILE* fp_r = fopen(argv[check], "r");
      if (fp_r != NULL) {
        char string[1000];
        int count = 0;
        int count_line_spaces = 1;
        while (fgets(string, 1000, fp_r)) {
          int flag_tab = 0;
          int flag_space = 0;
          if (flags.s == 1) catFlagS(string, &count_line_spaces, &flag_space);
          if (flags.b == 1) catFlagB(string, &count, &flag_tab);
          if (flags.e == 1) catFlagE(string);
          if (flags.n == 1 && flags.b == 0) {
            catFlagN(string, &count, &flag_tab);
            if (flag_space == 1) count--;
          }
          if (flags.t == 1) catFlagT(string);
          if (flag_tab == 0 && flag_space == 0)
            printf("%s", string);
          else if (flag_space == 0)
            printf("%6.d\t%s", count, string);
        }
      } else {
        printf("cat: %s: No such file or directory\n", argv[check]);
      }
      fclose(fp_r);
    }
    check++;
  }
}

void catFlagB(char* string, int* count, int* flag_tab) {
  if (strcmp(string, "\n") != 0) {
    *flag_tab = 1;
    *count = *count + 1;
  }
}

char* catFlagE(char* string) {
  int x;
  for (x = 0; string[x] != '\0'; x++)
    ;
  if (string[x - 1] == '\n') {
    string[x - 1] = '$';
    string[x] = '\n';
    string[x + 1] = '\0';
  }
  return string;
}

void catFlagN(char* string, int* count, int* flag_tab) {
  *flag_tab = 1;
  *count = *count + 1;
}

void catFlagS(char* string, int* count_line_spaces, int* flag_space) {
  if (strcmp(string, "\n") == 0 && *count_line_spaces == 1) {
    *count_line_spaces = *count_line_spaces + 1;
  } else if (strcmp(string, "\n") != 0) {
    *count_line_spaces = 1;
  } else {
    *flag_space = 1;
  }
}

char* catFlagT(char* string) {
  int len;
  for (len = 0; string[len] != '\0'; len++)
    ;
  for (int x = 0; string[x] != '\0'; x++) {
    if (string[x] == '\t') {
      for (int shift = len; shift > x; shift--)
        string[shift + 1] = string[shift];
      string[x] = '^';
      string[x + 1] = 'I';
    }
  }
  return string;
}
