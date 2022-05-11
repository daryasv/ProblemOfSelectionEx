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


