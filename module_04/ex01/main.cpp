#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Brain.h"

#include <iostream>

int main()
{
    // create and delete array with a mix of cats and dogs
    std::cout << "create array with cats and dogs: " << std::endl;
    Animal *arr[10];
    for (int i=0; i<5; i++) {
        arr[i] = new Cat;
    }
    for (int i=5; i<10; i++) {
        arr[i] = new Dog;
    }
    for (int i=0; i<10; i++) {
        delete arr[i];
    }

    // test deep copies
    std::cout << std::endl << "testing deep copies of cat: " << std::endl;
    Cat cat1;
    cat1.updateBrain(0, "I want to be copied");

    std::cout << "copying..." << std::endl;
    Cat cat2 = cat1;
    Cat cat3(cat1);
    cat1.brainDump();
    cat2.brainDump();
    cat3.brainDump();

    std::cout << "updating..." << std::endl;
    cat1.updateBrain(1, "new idea on index 1");
    cat2.updateBrain(2, "new idea on index 2");
    cat3.updateBrain(3, "new idea on index 3");
    cat1.brainDump();
    cat2.brainDump();
    cat3.brainDump();

    // tests from exersize
    std::cout << std::endl << "testing from exercize: " << std::endl;
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j;
    delete i;
    std::cout << std::endl << "end of main" << std::endl;
    return 0;
}
