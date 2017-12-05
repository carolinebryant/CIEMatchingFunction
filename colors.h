#ifndef COLORS__H
#define COLORS__H

#include <iostream>
#include <vector>

class Colors {
  public:
    double xr, yr, zr, xg, yg, zg, xb, yb, zb, xw, yw, zw, Xw, Yw, Zw;
    void init();
    void recoverWhite();
};

#endif
