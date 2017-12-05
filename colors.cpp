#include <iostream>
#include <vector>
#include "colors.h"

void Colors::init() {
  // red
  xr = 0.690;
  yr = 0.300;
  zr = (1-xr-yr);
  // green
  xg = 0.205;
  yg = 0.715;
  zg = (1-xg-yg);
  // blue
  xb = 0.150;
  yb = 0.045;
  zb = (1-xb-yb);
}

void Colors::recoverWhite() {
  
  xw = 0.31271;
  yw = 0.32902;
  zw = (1-xw-yw);
  
  Xw = xw/yw;
  Yw = 1.0;
  Zw = zw/yw;

  std::cout << " Xw is: " << Xw << std::endl;
  std::cout << " Zw is: " << Zw << std::endl;
}
