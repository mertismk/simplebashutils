#ifndef SRC_CAT_CAT_H_
#define SRC_CAT_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static struct option long_opt[] = {
    {"number-nonblank", optional_argument, NULL, 'b'},
    {"E", optional_argument, NULL, 'e'},
    {"number", optional_argument, NULL, 'n'},
    {"squeeze-blank", optional_argument, NULL, 's'},
    {"T", optional_argument, NULL, 't'},
    {NULL, 0, NULL, 0}};

struct all_flags {
  int b, e, n, s, t;
};

void catFlagB(char* string, int* count, int* flag_tab);
char* catFlagE(char* string);
void catFlagN(char* string, int* count, int* flag_tab);
void catFlagS(char* string, int* count_line_spaces, int* flag_space);
char* catFlagT(char* string);
void controlCat(int argc, char* argv[], struct all_flags flags);

#endif  // SRC_CAT_CAT_H_