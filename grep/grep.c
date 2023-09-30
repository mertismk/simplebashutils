#include "grep.h"

int main(int argc, char* argv[]) {
  int with_flags = 0;
  char flag;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      with_flags = 1;
      flag = argv[i][1];
    }
  }
  if (!with_flags)
    grepWithoutFlags(argc, argv);
  else
    grepWithFlags(argc, argv, flag);
  return 0;
}

void grepWithFlags(int argc, char* argv[], char flag) {
  int check = 1;
  int is_file_one = argc <= 4 ? 1 : 0;
  int ind_str_find = -1;
  while (check < argc) {
    if (argv[check][0] != '-' && ind_str_find == -1)
      ind_str_find = check;
    else if (argv[check][0] != '-') {
      switch (flag) {
        case 'e':
          grepFlagE(argv[ind_str_find], argv[check], is_file_one);
          break;
        case 'v':
          grepFlagV(argv[ind_str_find], argv[check], is_file_one);
          break;
        case 'i':
          grepFlagI(argv[ind_str_find], argv[check], is_file_one);
          break;
        case 'c':
          grepFlagC(argv[ind_str_find], argv[check], is_file_one);
          break;
        case 'l':
          grepFlagL(argv[ind_str_find], argv[check]);
          break;
        case 'n':
          grepFlagN(argv[ind_str_find], argv[check], is_file_one);
          break;
        case 'h':
          grepFlagH(argv[ind_str_find], argv[check]);
          break;
        case 's':
          grepFlagS(argv[ind_str_find], argv[check], is_file_one);
          break;
        case 'f':
          grepFlagF(argv[ind_str_find], argv[check], is_file_one);
          break;
        case 'o':
          grepFlagO(argv[ind_str_find], argv[check], is_file_one);
          break;
      }
    }
    check++;
  }
}

void grepWithoutFlags(int argc, char* argv[]) {
  int check = 1;
  int is_file_one = argc <= 3 ? 1 : 0;
  int ind_str_find = -1;
  while (check < argc) {
    if (ind_str_find == -1)
      ind_str_find = check;
    else {
      grepFlagE(argv[ind_str_find], argv[check], is_file_one);
    }
    check++;
  }
}

void grepFlagE(char* str_find, char* filename, int is_file_one) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (!mask) {
        if (is_file_one == 1)
          checkLineBreak(string) == 1 ? printf("%s", string)
                                      : printf("%s\n", string);
        else
          checkLineBreak(string) == 1 ? printf("%s:%s", filename, string)
                                      : printf("%s:%s\n", filename, string);
      }
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagV(char* str_find, char* filename, int is_file_one) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (mask) {
        if (is_file_one == 1)
          checkLineBreak(string) == 1 ? printf("%s", string)
                                      : printf("%s\n", string);
        else
          checkLineBreak(string) == 1 ? printf("%s:%s", filename, string)
                                      : printf("%s:%s\n", filename, string);
      }
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagI(char* str_find, char* filename, int is_file_one) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, REG_ICASE);
  if (fp_r != NULL) {
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (!mask) {
        if (is_file_one == 1)
          checkLineBreak(string) == 1 ? printf("%s", string)
                                      : printf("%s\n", string);
        else
          checkLineBreak(string) == 1 ? printf("%s:%s", filename, string)
                                      : printf("%s:%s\n", filename, string);
      }
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagC(char* str_find, char* filename, int is_file_one) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    int counter = 0;
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (!mask) {
        counter++;
      }
    }
    if (is_file_one == 1)
      printf("%d", counter);
    else
      printf("%s:%d\n", filename, counter);
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagL(char* str_find, char* filename) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (!mask) {
        printf("%s\n", filename);
        break;
      }
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagN(char* str_find, char* filename, int is_file_one) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    int count_line = 1;
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (!mask) {
        if (is_file_one == 1)
          checkLineBreak(string) == 1 ? printf("%d:%s", count_line, string)
                                      : printf("%d:%s\n", count_line, string);
        else
          checkLineBreak(string) == 1
              ? printf("%s:%d:%s", filename, count_line, string)
              : printf("%s:%d:%s\n", filename, count_line, string);
      }
      count_line++;
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagH(char* str_find, char* filename) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (!mask) {
        printf("%s", string);
      }
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagS(char* str_find, char* filename, int is_file_one) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    while (fgets(string, 1000, fp_r)) {
      mask = regexec(&regex, string, 0, NULL, 0);
      if (!mask) {
        if (is_file_one == 1)
          checkLineBreak(string) == 1 ? printf("%s", string)
                                      : printf("%s\n", string);
        else
          checkLineBreak(string) == 1 ? printf("%s:%s", filename, string)
                                      : printf("%s:%s\n", filename, string);
      }
    }
  }
  regfree(&regex);
  fclose(fp_r);
}

void grepFlagF(char* filename_mask, char* filename_in, int is_file_one) {
  FILE* fp_in = fopen(filename_in, "r");
  FILE* fp_mask = fopen(filename_mask, "r");
  char string_in[1000];
  char string_mask[1000];
  regex_t regex;
  int mask;
  if (fp_in != NULL && fp_mask != NULL) {
    while (fgets(string_in, 1000, fp_in)) {
      while (fgets(string_mask, 1000, fp_mask)) {
        mask = regcomp(&regex, string_mask, 0);
        mask = regexec(&regex, string_in, 0, NULL, 0);
        if (!mask) {
          if (is_file_one == 1)
            checkLineBreak(string_in) == 1 ? printf("%s", string_in)
                                           : printf("%s\n", string_in);
          else
            checkLineBreak(string_in) == 1
                ? printf("%s:%s", filename_in, string_in)
                : printf("%s:%s\n", filename_in, string_in);
          regfree(&regex);
          break;
        }
        regfree(&regex);
      }
      rewind(fp_mask);
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename_mask);
  }
  fclose(fp_in);
  fclose(fp_mask);
}

void grepFlagO(char* str_find, char* filename, int is_file_one) {
  FILE* fp_r = fopen(filename, "r");
  char string[1000];
  regex_t regex;
  regmatch_t match[100];
  int mask = regcomp(&regex, str_find, 0);
  if (fp_r != NULL) {
    while (fgets(string, 1000, fp_r)) {
      char* p = string;
      mask = regexec(&regex, p, 100, match, 0);
      int already_printed = 0;
      while (mask == 0) {
        if (is_file_one == 1) {
          printf("%s\n", str_find);
          already_printed = 1;
        } else if (already_printed == 0) {
          printf("%s:%s\n", filename, str_find);
          already_printed = 1;
        } else {
          printf("%s\n", str_find);
        }
        p += match[0].rm_eo;
        mask = regexec(&regex, p, 100, match, 0);
      }
    }
  } else {
    printf("grep: %s: No such file or directory\n", filename);
  }
  regfree(&regex);
  fclose(fp_r);
}

int checkLineBreak(char string[1000]) {
  int x;
  int status;
  for (x = 0; string[x] != '\0'; x++)
    ;
  if (string[x - 1] == '\n')
    status = 1;
  else
    status = 0;
  return status;
}
