#include "..\include\Location.h"

Location::Location(int row, int column) : row(row), column(column)
{
}





Location Location::operator+(const Location& other) const
{
	return Location(row + other.row, column + other.column);
}

Location& Location::operator+=(const Location& other)
{
	row += other.row;
	column += other.column;
	return *this;
}

bool Location::operator==(const Location& other) const
{
	return (row == other.row && column == other.column);
}

bool Location::operator!=(const Location& other) const
{
	return !(*this == other);
}

ostream& operator<<(ostream& os, const Location& loc)
{
	os << "(" << loc.row << ", " << loc.column << ")";
	return os;
}

