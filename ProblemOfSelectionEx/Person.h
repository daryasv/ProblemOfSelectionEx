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
	int compareTo(Person person,int &counter);//return -1 if smaller, 0 if equals 1 if bigger 
	int compareTo(int id, int& counter);//return -1 if smaller, 0 if equals 1 if bigger 
};

#endif