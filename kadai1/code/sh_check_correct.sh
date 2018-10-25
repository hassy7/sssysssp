#! /bin/bash

gcc check_correct.c
for f in ../list/*.c; do
  echo
  basename ${f%.c}
  gcc -std=c99 $f -o b.out
  ./b.out > tmp.txt
  ./a.out answer.txt tmp.txt
  rm b.out tmp.txt
done
rm a.out

#if [ "${f}" == "check_correct.c" -o "${f}" == "check_copyPaste.c" ]; then
#  continue
#fi
#gcc $f -o ${f%.c}
#./${f%.c} > tmp.txt
#rm ${f%.c} tmp.txt
