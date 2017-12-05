#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include "cieMatching.h"

void cieMatching::getData() {

  // get S(lambda) distribution
  std::fstream file;
  file.open("spectralDist.txt");
//  file.open("testColor.txt");
  
  double item;
  int cell = 0;
  
  while(file >> item) {
  
    Slambda[cell].x = item; // x
    
    file >> item;
    Slambda[cell].y = item; // y
    
    if(cell < 39) cell++;
  }

  file.close(); //because no one likes memory leaks
    
  // get matching functions  
  file.open("cieMatching.txt");
  
  
  item = 0; // clear out item
  cell = 0;
  int counter = 0;
  
  while(file >> item) {
  
    if(counter < 40) {
       
      fx[cell].x = item; // x
      
      file >> item;
      fx[cell].y = item; // y
    }
    
    else if(counter == 40 || counter < 80) {
      
      fy[cell-40].x = item; // x
      
      file >> item;
      fy[cell-40].y = item; // y   
    }
    
    else if(counter == 80 || counter < 120) {
    
      fz[cell-80].x = item; // x
      
      file >> item;
      fz[cell-80].y = item; // y
    }
    
    cell++;
    counter++;
  } 
  file.close(); //because no one likes memory leaks
} // end of getdata function

double cieMatching::calcSteps(double a, double b, double c, double d, double lambda) {

  return ( ((a*c)*pow(lambda, 3) / 3.0 ) + ((a*d + b*c)*pow(lambda, 2) / 2.0 ) + ((b*d)*lambda) );
}

void cieMatching::integrate() {

  // calculate R(lambda) distrubution
  for(int i = 0; i < 40; i++) {
  
    Rlambda[i].x = (Slambda[i].x * 1.0);
    Rlambda[i].y = (Slambda[i].y * 1.0); 
  }
  
  // calculate N
  N = 0;
  for(int i = 0; i < 39; i++) {
  
    a = ((fy[i+1].y - fy[i].y) / (fy[i+1].x - fy[i].x));
    b = fy[i].y - (a*fy[i].x);
    c = 0;  // slope is zero
    d = 1.0; // constant illumination of 1.0
    
    N += calcSteps(a, b, c, d, fy[i+1].x) - calcSteps(a, b, c, d, fy[i].x);
  }
  std::cout << " N is: " << N << std::endl;
  
  // calculate X
  X = 0;
  for(int i = 0; i < 39; i++) {
    
    a = ((fx[i+1].y - fx[i].y) / (fx[i+1].x - fx[i].x));
    b = fx[i].y - (a*fx[i].x);
    c = ((Rlambda[i+1].y - Rlambda[i].y) / (Rlambda[i+1].x - Rlambda[i].x));
    d = Rlambda[i].y - (c*Rlambda[i].x);
      
    X += calcSteps(a, b, c, d, fx[i+1].x) - calcSteps(a, b, c, d, fx[i].x); 
  }
  X = X/N;
  std::cout << " X is: " << X << std::endl;
  
  // calculate Y
  Y = 0;
  for(int i = 0; i < 39; i++) {
  
    a = ((fy[i+1].y - fy[i].y) / (fy[i+1].x - fy[i].x));
    b = fy[i].y - (a*fy[i].x);
    c = ((Rlambda[i+1].y - Rlambda[i].y) / (Rlambda[i+1].x - Rlambda[i].x));
    d = Rlambda[i].y - (c*Rlambda[i].x);
  
    Y += calcSteps(a, b, c, d, fy[i+1].x) - calcSteps(a, b, c, d, fy[i].x); 
  }
  Y = Y/N;
  std::cout << " Y is: " << Y << std::endl;

  // calculate Z
  Z = 0;
  for(int i = 0; i < 39; i++) {
  
    a = ((fz[i+1].y - fz[i].y) / (fz[i+1].x - fz[i].x));
    b = fz[i].y - (a*fz[i].x);
    c = ((Rlambda[i+1].y - Rlambda[i].y) / (Rlambda[i+1].x - Rlambda[i].x));
    d = Rlambda[i].y - (c*Rlambda[i].x);
  
    Z += calcSteps(a, b, c, d, fz[i+1].x) - calcSteps(a, b, c, d, fz[i].x); 
  }
  Z = Z/N;
 std::cout << " Z is: " << Z << std::endl;
}
