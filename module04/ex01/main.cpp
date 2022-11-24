#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	const Animal	*zoo[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			zoo[i] = new Cat;
		else
			zoo[i] = new Dog;
	}

	for (int i = 0; i < 10; i++) {
		delete zoo[i];
	}

	Cat	*cat = new Cat;

	cat->getBrain().addIdea("🐱 The Sound of cat thinking 🐱");
	Cat catCopy = *cat;
	cat->getBrain().addIdea("🐱 The Sound of snoozing 🐱");

	std::cout << catCopy.getBrain().getIdea(1) << std::endl;
	return 0;
}