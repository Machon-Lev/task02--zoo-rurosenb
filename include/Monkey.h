#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Animal.h"
#include <cstdlib>
#include <ctime>
using namespace std;
class Monkey : public Animal
{
public:
	Monkey(const string& name, const Location& loc) :Animal(name, loc) { move(); };
	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void move() override;
	void turnVertically();
	void turnHorizontally() override;
	string direction ;//left or right or up or down
	int randomNum ;
	int _steps = 0;

};