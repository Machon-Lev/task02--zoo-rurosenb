#include "Lion.h"
#define ROWS 20
#define COLS 40
void Lion::printDetails() const {
	cout << _name << " - " << "Lion " << _location << "\n";
}

char Lion::getInitial() const {
	return 'L';
}

void Lion::step()
{
	if (!_stopped)
	{
		if (LorR == "right")
			_location.column += 2;

		if (LorR == "left")
			_location.column -= 2;

		if (_location.column < 0 || _location.column >= COLS) {
			if (LorR == "right")
				LorR = "left";
			else
				LorR == "right";

			step();
			step();
		}
	}
}

void Lion::move()
{
	if (_stopped) {
		_stopped = false;
		int randomNumber = rand() % 2;
		switch (randomNumber) {
		case 0:
			LorR = "left";
			break;
		case 1:
			LorR = "right";
			break;
		}

	}
}

void Lion::turnHorizontally()
{
	if(LorR == "left")
		LorR = "right";
	else
		LorR = "left";
}
