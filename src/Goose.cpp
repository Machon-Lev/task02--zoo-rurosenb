#include "Goose.h"
#define ROWS 20
#define COLS 40
void Goose::printDetails() const {
	cout << _name << " - " << "Goose " << _location << "\n";
}

char Goose::getInitial() const
{
	return 'G';
}

void Goose::step()
{
	if (!_stopped)
	{
		if (LorR == "right") {
			if (UorD == "up") {
				_location.row -= 1;
				UorD = "down";
			}
			else {
				_location.row += 1;
				UorD = "up";
			}
			_location.column += 1;
		}
		else {
			if (UorD == "up") {
				_location.row -= 1;
				UorD = "down";
			}
			else {
				_location.row += 1;
				UorD = "up";
			}
			_location.column -= 1;
		}
		if (_location.column < 0 || _location.column >= COLS) {
			if (LorR == "right")
				LorR = "left";
			else
				LorR = "right";
			step();
			step();
		}
		else if (_location.row < 0 || _location.row >= ROWS) {
			if (UorD == "up")
				UorD = "down";
			else
				UorD = "up";
			step();
			step();
		}
	}
}

void Goose::move()
{
	if (_stopped) {
		_stopped = false;
		int randomNumber1 = rand() % 2;
		int randomNumber2 = rand() % 2;
		switch (randomNumber1) {
		case 0:
			LorR = "left";
			break;
		case 1:
			LorR = "right";
			break;
		}
		switch (randomNumber2) {
		case 0:
			UorD = "up";
			break;
		case 1:
			UorD = "down";
			break;
		}

	}
}

void Goose::turnVertically()
{
	if(UorD == "up")
		UorD = "down";
	else
		UorD = "up";	
}

void Goose::turnHorizontally()
{
	if (LorR == "left")
		LorR = "right";
	else
		LorR = "left";
}
