#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;

	const Animal	*zoo[10];
	for (int i = 0; i < 10; i++) {
		if (i % 2)
			zoo[i] = new Cat;
		else
			zoo[i] = new Dog;
		std::cout << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		delete zoo[i];
	}

	std::cout << std::endl;

	Cat	*cat = new Cat;

	std::cout << std::endl;

	std::string	catIdea = "🐱 The Sound of cat thinking 🐱";
	cat->getBrain().addIdea(catIdea);

	std::cout << std::endl;

	Cat catCopy = *cat;
	catIdea = "🐱 The Sound of snoozing 🐱";
	cat->getBrain().addIdea("🐱 The Sound of snoozing 🐱");

	std::cout << std::endl;

	for (int i = 0; i < 100; i++) {
		std::string	tmp = catCopy.getBrain().getIdea(i);
		if (!tmp.size())
			break ;
		std::cout << tmp << std::endl;
	}

	std::cout << std::endl;

	delete cat;

	std::cout << std::endl;

	Dog	*dog = new Dog;

	std::cout << std::endl;

	std::string	dogIdea = "🐶 The Sound of dog thinking 🐶";
	dog->getBrain().addIdea(dogIdea);

	std::cout << std::endl;

	Dog dogCopy;
	dogCopy = *dog;
	dogIdea = "🐶 The Sound of snoozing 🐶";
	dog->getBrain().addIdea("🐶 The Sound of snoozing 🐶");

	std::cout << std::endl;

	for (int i = 0; i < 100; i++) {
		std::string	tmp = dogCopy.getBrain().getIdea(i);
		if (!tmp.size())
			break ;
		std::cout << tmp << std::endl;
	}

	std::cout << std::endl;

	delete dog;

	std::cout << std::endl;

	return 0;
}