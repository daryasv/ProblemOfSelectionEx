#pragma once

#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <string.h>  
#include "Person.h"
using namespace std;

void error();
Person* getInfo(int& moked, int& size);

#endif