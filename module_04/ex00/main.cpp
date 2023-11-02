#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

#include <iostream>

int main()
{
    // test dog
    std::cout << "testing dog: " << std::endl;
    const Animal *goodDog = new Dog();
    std::cout << "good dog has type: " << goodDog->getType() << std::endl;
    goodDog->makeSound();
    delete goodDog;

    // test cat
    std::cout << std::endl << "testing cat: " << std::endl;
    const Animal *goodCat = new Cat();
    std::cout << "good cat has type: " << goodCat->getType() << std::endl;
    goodCat->makeSound();
    delete goodCat;

    // test base animal
    std::cout << std::endl << "testing base animal: " << std::endl;
    const Animal *baseAnimal = new Animal();
    std::cout << "base animal has type: " << baseAnimal->getType() << std::endl;
    baseAnimal->makeSound();
    delete baseAnimal;

    // test wrong cat
    std::cout << std::endl << "testing wrong cat: " << std::endl;
    const WrongAnimal *myWrongCat = new WrongCat();
    std::cout << "wrong cat has type: " << myWrongCat->getType() << std::endl;
    myWrongCat->makeSound();
    delete myWrongCat;

    return 0;
}
