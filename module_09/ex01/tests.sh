#!/bin/bash
C_RED='\x1b[31m'
C_GREEN='\x1b[32m'
C_RESET='\x1b[0m'

echo -e "${C_GREEN}base cases..${C_RESET}"

echo -n " - expecting 5  : "
./RPN "2 3 +"

echo -n " - expecting 42 : "
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo -n " - expecting 42 : "
./RPN "7 7 * 7 -"

echo -n " - expecting 0  : "
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo -n " - expecting 7  : "
./RPN "7"

echo -n " - expecting -7 : "
./RPN "0 9 - 2 +"


echo -e "${C_RED}\nerror cases..${C_RESET}"
./RPN
./RPN "2" "2" "+"
./RPN "42 42 +"
./RPN ""
./RPN "7 7 7 +"
./RPN "7 +"
./RPN "7 0 /"
./RPN "7 7 a"
./RPN "9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
