#ifndef MATRIX__H
#define MATRIX__H

#include <iostream>
#include <vector>
#include "vector.h"

class Matrix {
  public:
    Vector row[3];
    Vector invRow[3];
    Vector inv[3];
    void init(double xr, double yr, double zr, double xg, double yg, double zg, double xb, double yb, double zb);
    void invert(double Xw, double Yw, double Zw);
    void getRGB(double X, double Y, double Z);  
    double Cr, Cg, Cb, Det, R, G, B;  
};

#endif
