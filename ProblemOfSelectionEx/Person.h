#pragma once
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
	Person(int id, string name);
	int getId() { return id; }
	string getNam() { return name; }
};

#endif