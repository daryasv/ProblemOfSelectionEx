#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
	int id;
	string name;

public:
	Person();
	Person(int newId, string newName);
	int getId() { return id; }
	string getName() { return name; }
};

#endif