#include "Monkey.h"
#define ROWS 20
#define COLS 40
void Monkey::printDetails() const {
	cout << _name << " - " << "Monkey " << _location << "\n";
}

char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::step()
{
    if (!_stopped) {
        _steps++;
        if (_steps == 6 ) {
            _steps = 0;
            move();
        }
        if (direction == "left")
        {
            _location = Location(_location.row, _location.column- randomNum);
        }
        if (direction == "right")
        {
            _location = Location(_location.row, _location.column + randomNum);
        }
        if (direction == "up")
        {
            _location = Location(_location.row + randomNum, _location.column);
        }
        if (direction == "down")
        {
            _location = Location(_location.row - randomNum, _location.column);
        }
        if (_location.column < 0 || _location.column >= COLS) {
            if (direction == "right")
                direction = "left";
            else
                direction == "right";
            step();
            step();
        }
        else if (_location.row < 0 || _location.row >= ROWS) {
            if (direction == "up")
                direction = "down";
            else
                direction == "up";
            step();
            step();
        }       
    }
}

void Monkey::move()
{
    if (_stopped) {
        _stopped = false;
        int randomNumber = rand() % 4;
        randomNum = rand() % 2 + 1;
        switch (randomNumber) {
        case 0:
            direction = "left";
            break;
        case 1:
            direction = "right";
            break;
        case 2:
            direction = "up";
            break;
        case 3:
            direction = "down";
            break;
        }
    }
}

void Monkey::turnVertically()
{
    if (direction == "up")
        direction = "down";
    else
        direction = "up";
}

void Monkey::turnHorizontally()
{
    if (direction == "left")
        direction = "right";
    else
        direction = "left";
}
