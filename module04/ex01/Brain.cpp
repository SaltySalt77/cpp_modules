#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Generating one Brain. 🧠" << std::endl;
	count = 0;
	isFull = false;
}

Brain::Brain(const Brain	&brain) {
	std::cout << "Creating Brain by copying another. 🧠" << std::endl;
	this->count = 0;
	for (int i = 0; i < brain.count; i++)
		this->addIdea(brain.getIdea(i));
	this->count = brain.count;
	this->isFull = brain.isFull;
}

Brain	&Brain::operator= (const Brain	&brain) {
	std::cout << "Copying information of another Brain. 🧠" << std::endl;
	if (this == &brain)
		return *this;
	this->removeIdea();
	for (int i = 0; (i < brain.count) || (brain.isFull && i < 100); i++)
		this->addIdea(brain.getIdea(i));
	this->count = brain.count;
	this->isFull = brain.isFull;
	return *this;
}

Brain::~Brain() {
	std::cout << "Removing Brain. 🧠" << std::endl;
}

std::string	Brain::getIdea(int index) const {
	std::string	error;

	if (index < 0 || index >= 100)
		return error;
	return ideas[index];
}

void	Brain::addIdea(const std::string	idea) {
	ideas[count] = idea;
	count = (count + 1) % 100;
	if (count == 0)
		isFull = true;
}

void	Brain::removeIdea() {
	for (int i = 0; (i < count) || (isFull && i < 100); i++)
		ideas[i].clear();
}
