#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# test case 1:
fileName="file1"
findStr="hello"
replaceStr="goodbye"
original="hello1\nhello2\nhello3\n";
expected="goodbye1\ngoodbye2\ngoodbye3\n";

echo $original > $fileName;
echo $expected > "${fileName}.expected";
./findreplace file1 $findStr $replaceStr;
res=$(diff "${fileName}.expected" "${fileName}.replace" | wc -l);
if [ "$res" -eq "0" ]; then
  printf "case1: ${GREEN}[OK]${NC}\n"
else
  printf "case1: ${RED}[NOK]${NC}\n"
fi
rm $fileName
rm "${fileName}.expected"
rm "${fileName}.replace"

