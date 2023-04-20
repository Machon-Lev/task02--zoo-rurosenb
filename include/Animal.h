#pragma once
#include "Location.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;
#include <cstdlib> // for rand()
#include <ctime>   // for time()using namespace std;
class Animal
{
protected:
	string _name;
	Location _location;
	bool _stopped = true;

public:
	Animal(const string&, const Location&);
	virtual void printDetails() const = 0;
	virtual char getInitial() const = 0;
	Location getLocation() const;
	virtual void step() =0;
	void stop();
	virtual void move() = 0;
	virtual void turnVertically() = 0; //up or down
	virtual void turnHorizontally() = 0; // left or right
};