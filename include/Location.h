#pragma once
#include <iostream>
using namespace std;
struct Location {
  int row;
  int column;

  // Constructor
  Location(int row, int column);
  Location() {};


  // Connection operator
  Location operator+(const Location& other) const;

  // += operator
  Location& operator+=(const Location& other);

  // Equality operator
  bool operator==(const Location& other) const;

  // Inequality operator
  bool operator!=(const Location& other) const;
};
// Print Location
ostream& operator<<(ostream& os, const Location& loc);
