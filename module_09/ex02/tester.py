#!/usr/bin/python3

import random
import subprocess

def test(nrValues: int) -> str:
    # create random numbers
    random.seed(42)
    maxValue = (2**31)-1
    randomIntList = random.sample(range(1,maxValue), nrValues)
    randomIntStrList: list[str] = [str(n) for n in randomIntList]

    # sort with PmergeMe (c++)
    arglist: list[str] = ["./PmergeMe"] + randomIntStrList
    cpp_resultList = subprocess.run(arglist, capture_output=True).stdout.decode('utf-8').split('\n')

    # sort with Python
    randomIntList.sort()
    py_result = "After:   " + " ".join(map(str,randomIntList))

    # compare
    if (cpp_resultList[1] == py_result):
        return("ok")
    else:
        return("nok")


if __name__ == '__main__':
    print(test(1))
    print(test(10))
    print(test(100))
    print(test(1000))
    print(test(3000))

    for j in range(1, 50):
        if (test(j) != "ok"):
            print("error")

    print("done")
