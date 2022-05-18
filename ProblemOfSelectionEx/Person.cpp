#include "Person.h"
#include <iostream>
using namespace std;

Person::Person()
{
	id = 0;
	name = "";
}
Person::Person(int newId, string newName)
{
	id = newId;
	name = newName;
}

int Person::compareTo(Person person, int& counter) {
	counter++;
	if (this->id > person.getId()) {
		return 1;
	}
	else if (this->id < person.getId()) {
		return -1;
	}
	else {
		return 0;
	}
}

int Person::compareTo(int id, int& counter)
{
	counter++;
	if (this->id > id) {
		return 1;
	}
	else if (this->id < id) {
		return -1;
	}
	else {
		return 0;
	}
}
