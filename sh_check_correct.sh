#! /bin/bash

gcc check_correct.c
for f in *.c; do
  if [ "${f}" == "check_correct.c" -o "${f}" == "check_copyPaste.c" ]; then
    continue
  fi
  echo
  echo ${f%.c}
  gcc -std=c99 $f -o ${f%.c}
  #gcc $f -o ${f%.c}
  ./${f%.c} > tmp.txt
  ./a.out answer.txt tmp.txt
  rm ${f%.c} tmp.txt
done
rm a.out
