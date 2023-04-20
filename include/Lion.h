#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Animal.h"
#include <cstdlib>
using namespace std;
class Lion : public Animal
{
public:
	Lion(const string& name, const Location& loc) :Animal(name, loc) { move(); };
	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void move() override;
	void turnHorizontally() override;
	void turnVertically() override {};
	string LorR;
};