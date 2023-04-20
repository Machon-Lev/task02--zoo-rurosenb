#include <iostream>
#include "zoo.h"
using namespace std;

int main()
{
	cout << "Welcome To The Zoo Game" << endl;
	// Seed the random number generator with the current time
	srand(time(NULL));
	Zoo zoo1;
	zoo1.run();
	return 0;
}