#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Animal.h"
#include <cstdlib>
using namespace std;
class Goose : public Animal
{
public:
	Goose(const string& name, const Location& loc) :Animal(name, loc) { move(); };
	void printDetails() const override;
	char getInitial() const override;
	string LorR ;
	string UorD ;
	void step() override;
	void move() override;
	void turnVertically() override;
	void turnHorizontally() override;
};