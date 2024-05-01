
#include <iostream>

unsigned int getJacobstahlNr(unsigned int n) {
    return (n % 2 == 0) ? ((1<<n)-1)/3 : ((1<<n)+1)/3;
}

int main() {
    for (int i=0; i<10; i++)
    std::cout << getJacobstahlNr(i) << std::endl;
}
