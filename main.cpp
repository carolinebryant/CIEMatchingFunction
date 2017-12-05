#include <iostream>
#include <vector>
#include "cieMatching.h"
#include "colors.h"
#include "vector.h"
#include "matrix.h"

int main(int, char*[]) {
   try {
    Colors colors;
    colors.init();
    colors.recoverWhite();
    
    Matrix matrix;
    matrix.init(colors.xr, colors.yr, colors.zr, colors.xg, colors.yg, colors.zg, colors.xb, colors.yb, colors.zb);
    matrix.invert(colors.Xw, colors.Yw, colors.Zw);
   
    cieMatching cieMatching;
    cieMatching.getData();
    cieMatching.integrate();
    
    matrix.getRGB(cieMatching.X, cieMatching.Y, cieMatching.Z);
   } 
   catch (const std::string& msg) { std::cout << msg << std::endl; }
   catch (...) {
      std::cout << "Oops, you done fucked up!" << std::endl;
   }
   return 0;
}   
