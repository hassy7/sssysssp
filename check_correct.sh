#! /bin/bash

for f in *.c; do
  if [ "${f}" == "text.c" ]; then
    continue
  fi
  echo
  echo ${f%.c}
  #gcc -std=c99 $f -o ${f%.c}
  gcc $f -o ${f%.c}
  ./${f%.c} > tmp.txt
  gcc text.c
  ./a.out
  rm ${f%.c} a.out tmp.txt
done
