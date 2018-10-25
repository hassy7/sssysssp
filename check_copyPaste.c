#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256

int main(int argc, char *argv[])
{
  FILE *fp;
  FILE *fp2;
  char fname[N];
  char fname2[N];
  char readline1[N] = {'\0'};
  char readline2[N] = {'\0'};
  int i = 0;

  char *pt1, *pt2;
  char match = 0;
  int match_sum = 0;

  if (argc != 3) {
    printf("!!!!!!!!!!!!!!! exit !!!!!!!!!!!!!!!\n");
    exit(1);
  }

  fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("%s file not open!\n", fname);
    return -1;
  }
  while (fgets(readline1, N, fp) != NULL) {
    if (*readline1 == '\n' || *readline1 == '\r' || *readline1 == '\0' || *readline1 == '}')
      continue;
    if (*readline1 == '{' && (*(readline1 + 1) == '0' || *(readline1 + 1) == '\n' || *(readline1 + 1) == '\r'))
      continue;
    fp2 = fopen(argv[2], "r");
    if (fp2 == NULL) {
      printf("%s file not open!\n", fname2);
      return -1;
    }
    while (fgets(readline2, N, fp2) != NULL) {
      pt1 = readline1;
      pt2 = readline2;
      if (*pt2 == '\n' || *pt2 == '\0' || *pt2 == '\r' || *pt2 == '}')
        continue;
      for (;;) {
        if (*pt1 == ' ' || *pt1 == '\t') {
          pt1 = pt1 + 1;
          continue;
        }
        if (*pt2== ' ' || *pt2 == '\t') {
          pt2 = pt2 + 1;
          continue;
        }
        if (*pt1 == '}' && (*(pt1 - 1) == ' ' || *(pt1 - 1) == '\t')) {
          break;
        }
        if (*pt1 != *pt2 && ((*pt1 != '\0' && *pt2 != '\n') && (*pt1 != '\n' && *pt2 != '\0') && (*pt1 != '\r' && *pt2 != '\r'))) {
          break;
        } else if (*pt1 != *pt2 && ((*pt1 == '\0' && (*pt2 != '\n' && *pt2 != '\r')) || (*pt1 == '\n' && (*pt2 != '\0' && *pt2 != '\r')) || (*pt1 == '\r' && (*pt2 != '\n' && *pt2 != '\0')))) {
          break;
        } else {
          if (*pt1 == '\0' || *pt1 == '\n' || *pt1 == '\r') {
            //printf("!!!!!!!! match !!!!!!!!\n");
            //printf("1: %s\n2: %s\n", readline1, readline2);
            match = match + 1;
            match_sum = match_sum + 1;
            break;
          }
          pt1 = pt1 + 1;
          pt2 = pt2 + 1;
        }
      }
      if (match != 0) {
        match = 0;
        break;
      }
    }
    fclose(fp2);
  }
  fclose(fp);

  printf("match_sum: %d\n", match_sum);
  return 0;
}
