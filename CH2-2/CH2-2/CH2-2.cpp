#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
	virtual void makeSound(){}
};

class Dog : public Animal {
private:
	string sound;

public:
	Dog(string sound) : sound(sound) {}
	void makeSound() {
		cout << "Dog : " << sound << endl;
	}
};

class Cat : public Animal {
private:
	string sound;

public:
	Cat(string sound) : sound(sound) {}
	void makeSound() {
		cout << "Cat : " << sound << endl;
	}
};

class Cow : public Animal {
private:
	string sound;

public:
	Cow(string sound) : sound(sound) {}
	void makeSound() {
		cout << "Cow : " << sound << endl;
	}
};


Animal* createRandomAnimal() {
	int ranNum = rand() % 3;

	if (ranNum == 0) {
		return new Dog("¿Ð¿Ð");
	}
	else if (ranNum == 1) {
		return new Cat("¾ß¿Ë");
	}
	else {
		return new Cow("À½¸Ó");
	}
}


class Zoo {
private:
	Animal* animals[10];
	int count = 0;

public:
	void addAnimal(Animal* animal) {
			animals[count] = animal;
			count++;
	}

	void performActions() {
		for (int i = 0; i < 10; i++) {
			animals[i]->makeSound();
		}
	}
	
	~Zoo() {
		for (int i = 0; i < 10; i++) {
			delete animals[i];
		}
	}
};



int main() {
	Dog d("¿Ð¿Ð");
	Cat c("¾ß¿Ë");
	Cow co("À½¸Ó");

	Animal* animals[3] = { &d, &c, &co };

	for (int i = 0; i < 3; i++) {
		animals[i]->makeSound();
	}

	Zoo z;

	for (int i = 0; i < 10; i++){
		z.addAnimal(createRandomAnimal());
	}
	z.performActions();
	
}