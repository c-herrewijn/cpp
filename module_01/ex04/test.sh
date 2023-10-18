#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

execute_test()
{
  fileName="file${test_case_nr}"
  echo -e "$original" > $fileName
  echo -e "$expected" > "${fileName}.expected"
  ./findreplace "$fileName" "$findStr" "$replaceStr"
  res=$(diff "${fileName}.expected" "${fileName}.replace" | wc -l)
  if [ "$res" -eq "0" ]; then
    printf "case${test_case_nr}: ${GREEN}[OK]${NC}\n"
  else
    printf "case${test_case_nr}: ${RED}[NOK]${NC}\n"
  fi
  rm $fileName
  rm "${fileName}.expected"
  rm "${fileName}.replace"
}

test_case_nr=1
findStr="hello"
replaceStr="goodbye"
original="hello1\nhello2\nhello3\n"
expected="goodbye1\ngoodbye2\ngoodbye3\n"
execute_test

test_case_nr=2
findStr=" "
replaceStr="."
original="hello there\nhow are you\n  extra spaces  \n  "
expected="hello.there\nhow.are.you\n..extra.spaces..\n.."
execute_test

test_case_nr=3
findStr="hello"
replaceStr="goodbye"
original="11hello\n11hellohello"
expected="11goodbye\n11goodbyegoodbye"
execute_test

test_case_nr=4
findStr="aa"
replaceStr="b"
original="aaaaa"
expected="bba"
execute_test

test_case_nr=5
findStr="hello"
replaceStr="goodbye"
original="hello"
expected="goodbye"
execute_test

test_case_nr=6
findStr="hello"
replaceStr=""
original="hellohello"
expected=""
execute_test
