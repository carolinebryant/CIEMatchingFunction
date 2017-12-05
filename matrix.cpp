#include <iostream>
#include <vector>
#include "matrix.h"
#include "vector.h"

void Matrix::init(double xr, double yr, double zr, double xg, double yg, double zg, double xb, double yb, double zb) {

  row[0].set(xr, xg, xb);
  row[1].set(yr, yg, yb);
  row[2].set(zr, zg, zb);

  row[0].print();
  row[1].print();
  row[2].print();

}

void Matrix::invert(double Xw, double Yw, double Zw) {

  // calculate determinant
  Det = row[0].dotProduct((row[1].crossProduct(row[2])));

  std::cout << " Det is: " << Det << std::endl;

  invRow[0] =   row[1].crossProduct(row[2]);
  invRow[1] =   row[0].crossProduct(row[2]);
  // make this row negative
  invRow[1].x = -invRow[1].x;
  invRow[1].y = -invRow[1].y;
  invRow[1].z = -invRow[1].z;
  invRow[2] =   row[0].crossProduct(row[1]);
  
  // divide each element by determinant
  invRow[0] = invRow[0].divide(Det);
  invRow[1] = invRow[1].divide(Det);
  invRow[2] = invRow[2].divide(Det);
  
  std::cout << " cofactor matrix: " << std::endl;
  invRow[0].print();
  invRow[1].print();
  invRow[2].print();
  
  // transpose
  inv[0].set(invRow[0].x, invRow[1].x, invRow[2].x);
  inv[1].set(invRow[0].y, invRow[1].y, invRow[2].y);
  inv[2].set(invRow[0].z, invRow[1].z, invRow[2].z);

  std::cout << " inverted matrix: " << std::endl;
  inv[0].print();
  inv[1].print();
  inv[2].print();
  
  Cr = ( (inv[0].x*Xw) + (inv[0].y*Yw) + (inv[0].z*Zw) );
  Cg = ( (inv[1].x*Xw) + (inv[1].y*Yw) + (inv[1].z*Zw) );
  Cb = ( (inv[2].x*Xw) + (inv[2].y*Yw) + (inv[2].z*Zw) );
  
  std::cout << " Cr: " << Cr << std::endl;
  std::cout << " Cg: " << Cg << std::endl;
  std::cout << " Cb: " << Cb << std::endl;
} // end of invert function

void Matrix::getRGB(double X, double Y, double Z) {

  // calculate determinant
  Det = row[0].dotProduct((row[1].crossProduct(row[2])));

  std::cout << " Det is: " << Det << std::endl;
  
//   row[0] is [xr, xg, xb]
//   row[1] is [yr, yg, yb]
//   row[2] is [zr, zg, zb]

  // check 
  std::cout << " check orginial matrix " << std::endl;
  row[0].print();
  row[1].print();
  row[2].print();


  // scale each element by Cr, Cg, and Cb respectively
  row[0].x = row[0].x * Cr;
  row[0].y = row[0].y * Cg;
  row[0].z = row[0].z * Cb;
  
  row[1].x = row[1].x * Cr;
  row[1].y = row[1].y * Cg;
  row[1].z = row[1].z * Cb;
  
  row[2].x = row[2].x * Cr;
  row[2].y = row[2].y * Cg;
  row[2].z = row[2].z * Cb;

  std::cout << " check scaled matrix " << std::endl;
  row[0].print();
  row[1].print();
  row[2].print();
  
  // invert scaled matrix
  
  // calculate determinant
  Det = row[0].dotProduct((row[1].crossProduct(row[2])));

  std::cout << " Det is: " << Det << std::endl;
  
  invRow[0] =   row[1].crossProduct(row[2]);
  invRow[1] =   row[0].crossProduct(row[2]);
  // make this row negative
  invRow[1].x = -invRow[1].x;
  invRow[1].y = -invRow[1].y;
  invRow[1].z = -invRow[1].z;
  invRow[2] =   row[0].crossProduct(row[1]);
  
  // divide each element by determinant
  invRow[0] = invRow[0].divide(Det);
  invRow[1] = invRow[1].divide(Det);
  invRow[2] = invRow[2].divide(Det);
  
  std::cout << " cofactor matrix: " << std::endl;
  invRow[0].print();
  invRow[1].print();
  invRow[2].print();
  
  // transpose
  inv[0].set(invRow[0].x, invRow[1].x, invRow[2].x);
  inv[1].set(invRow[0].y, invRow[1].y, invRow[2].y);
  inv[2].set(invRow[0].z, invRow[1].z, invRow[2].z);

  std::cout << " inverted matrix: " << std::endl;
  inv[0].print();
  inv[1].print();
  inv[2].print();
  
  R = ( (inv[0].x*X) + (inv[0].y*Y) + (inv[0].z*Z) );
  G = ( (inv[1].x*X) + (inv[1].y*Y) + (inv[1].z*Z) );
  B = ( (inv[2].x*X) + (inv[2].y*Y) + (inv[2].z*Z) );
     
  std::cout << " R: " << R << std::endl;
  std::cout << " G: " << G << std::endl;
  std::cout << " B: " << B << std::endl;
}
