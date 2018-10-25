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

  if (argc != 3) {
    printf("!!!!!!!!!!!!!!can't excute!!!!!!!!!!!!!!\n");
    exit(1);
  }

  fp = fopen(argv[1], "r");

  if (fp == NULL) {
    printf("%s file not open!\n", fname);
    return -1;
  } else {
    //printf("%s file opened!\n", fname);
  }

  fp2 = fopen(argv[2], "r");

  if (fp2 == NULL) {
    printf("%s file not open!\n", fname2);
    return -1;
  } else {
    //printf("%s file opened!\n", fname2);
  }

  while (fgets(readline1, N, fp) != NULL && fgets(readline2, N, fp2) != NULL) {
    //printf("%s%s", readline1, readline2);
    if ((i + 2) % 2 == 0) {
      i = i + 1;
      continue;
    }
    pt1 = readline1;
    pt2 = readline2;
    for (;;) {
      if (*pt1 == ' ' || *pt1 == '\t') {
        pt1 = pt1 + 1;
        continue;
      }
      if (*pt2== ' ' || *pt2 == '\t') {
        pt2 = pt2 + 1;
        continue;
      }
      if (*pt1 != *pt2) {
        printf("pt1: %c, pt2: %c\n", *pt1, *pt2);
        printf("!!!!!!!!!!!!!!!!! incorrect, exit !!!!!!!!!!!!!!!!!\n");
        exit(1);
      } else {
        if (*pt1 == '\0' || *pt1 == '\n')
          break;
        pt1 = pt1 + 1;
        pt2 = pt2 + 1;
      }
    }
    i = i + 1;
  }
  if (i == 12)
    printf("correct !\n");

  fclose(fp);
  fclose(fp2);
  return 0;
}
