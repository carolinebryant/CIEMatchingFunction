#include <iostream>
#include <vector>
#include "vector.h"

void Vector::set (double x, double y, double z) {
		this -> x = x;
		this -> y = y;
		this -> z = z;
}

Vector Vector::add (Vector v2) {

	Vector v3;

	v3.x = x + v2.x;
	v3.y = y + v2.y;
	v3.z = z + v2.z;

	return v3;
}

Vector Vector::operator+ (Vector v2) {

	return (this-> add(v2));
}

Vector Vector::subtract(Vector v2) {

	Vector v3;
	
	v3.x = x - v2.x;
	v3.y = y - v2.y;
	v3.z = z - v2.z;

	return v3;
}

Vector Vector::operator- (Vector v2) {

	return (this-> subtract(v2));
}

Vector Vector::multiply (Vector v2) {

	Vector v3;

	v3.x = x * v2.x;
	v3.y = y * v2.y;
	v3.z = z * v2.z;

	return v3;
}

Vector Vector::operator* (Vector v2) {

	return (this-> multiply(v2));
}

double Vector::dotProduct(Vector v2) {
  double result;
  result = ((x*v2.x) + (y*v2.y) + (z*v2.z));
  return result;
}

Vector Vector::crossProduct(Vector vector2) {
  Vector result;
  result.x = (y*vector2.z - z*vector2.y);
  result.y = -(x*vector2.z - z*vector2.x);
  result.z = (x*vector2.y - y*vector2.x);
  return result;
}

Vector Vector::divide(double Det) {
  Vector result;
  result.x = x/Det;
  result.y = y/Det;
  result.z = z/Det;
  return result; 
}

void Vector::divide2(Vector &v, double Det) {
  v.x = v.x/Det;
  v.y = v.y/Det;
  v.z = v.z/Det;
}

void Vector::print() {

  std::cout << "  [" << x << "  " << y << "  " << z << "]" << std::endl;
}
