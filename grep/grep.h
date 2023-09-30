#ifndef SRC_GREP_GREP_H_
#define SRC_GREP_GREP_H_

#include <regex.h>
#include <stdio.h>

void grepWithFlags(int argc, char* argv[], char flag);
void grepWithoutFlags(int argc, char* argv[]);
void grepFlagE(char* str_find, char* filename, int is_file_one);
void grepFlagV(char* str_find, char* filename, int is_file_one);
void grepFlagI(char* str_find, char* filename, int is_file_one);
void grepFlagC(char* str_find, char* filename, int is_file_one);
void grepFlagL(char* str_find, char* filename);
void grepFlagN(char* str_find, char* filename, int is_file_one);
void grepFlagH(char* str_find, char* filename);
void grepFlagS(char* str_find, char* filename, int is_file_one);
void grepFlagF(char* filename_mask, char* filename_in, int is_file_one);
void grepFlagO(char* str_find, char* filename, int is_file_one);
int checkLineBreak(char string[1000]);

#endif  // SRC_GREP_GREP_H_