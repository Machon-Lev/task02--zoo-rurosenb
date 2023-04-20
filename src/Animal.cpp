#include "..\include\Animal.h"

Animal::Animal(const string& name, const Location& loc)
{
	_name = name;
	_location = loc;
	
}

Location Animal:: getLocation() const
{
	return _location;
}

void Animal::stop()
{
	_stopped = true;
}
