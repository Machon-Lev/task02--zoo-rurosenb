#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Animal.h"
#include "Lion.h"
#include "Monkey.h"
#include "Goose.h"
using namespace std;
class Zoo {
public:
    Zoo();
    void run();
private:
    vector<unique_ptr<Animal>> animals;
    void stopAnimal(int index);
    void printHelp();
    void createAnimal(char _type, string _name);
    void deleteAnimal(int index);
    void moveAnimal(int index);
    void deleteAllAnimalsOfType(char c);
    void stepAnimal();
    void printAllAnimals();

};