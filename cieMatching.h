#ifndef CIEMATCHING__H
#define CIEMATCHING__H

#include <iostream>
#include <vector>

class cieMatching { 
  public:
  
    struct point {
      double x,y;
    };
      
    void getData();
    void integrate();
    double calcSteps(double a, double b, double c, double d, double lambda);   
    struct point Slambda[40];
    struct point Rlambda[40];
    struct point fx[40];
    struct point fy[40];
    struct point fz[40];
    double N, X, Y, Z, T; 
    double a, b, c, d, x, y, z, lambda; 
};
#endif

