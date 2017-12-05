#ifndef VECTOR__H
#define VECTOR__H

#include <iostream>
#include <vector>

class Vector {
  public:
    double x, y, z;
  void set(double x, double y, double z);
  
  Vector add (Vector v2);
	Vector operator+ (Vector v2);

	Vector subtract (Vector v2);
	Vector operator- (Vector v2);

	Vector multiply (Vector v2);
	Vector operator* (Vector v2);
  
  double dotProduct(Vector vector2);
  Vector crossProduct(Vector vector2);
  Vector divide(double Det);
  void divide2(Vector &v, double Det);
  void print();
};

#endif
