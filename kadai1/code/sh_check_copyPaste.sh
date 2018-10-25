#! /bin/bash

i=0
gcc check_copyPaste.c
for f in ../list/*.c; do
  echo && echo && basename ${f%.c} && echo
  nkf -w ${f} > tmp.txt
  j=0
  for f2 in ../list/*.c; do
    if [ "${f2}" == "${f}" ]; then
      continue
    fi
    if [ $j -lt $i ] ; then
      #echo "スキップします"
      j=$(($j + 1))
      continue
    fi
    basename ${f2%.c}
    nkf -w ${f2} > tmp2.txt
    ./a.out tmp.txt tmp2.txt
    rm tmp2.txt
    j=$(($j + 1))
  done
  rm tmp.txt
  i=$(($i + 1))
done
rm a.out

#if [ "${f}" == "check_copyPaste.c" -o "${f}" == "check_correct.c" ]; then
#  continue
#fi
