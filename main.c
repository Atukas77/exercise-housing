/*
 The problem requires calculating an area of a polygonal house. A good way to
 achieve this is by using the shoelace formula, which is equal to
 (1/2) * |(x1*y2 + x2*y3 + ... + x(n-1)*yn +xn*y1) - (x2*y1 + x3*y2 + ... +
 xn*ny(n-1) + x1*yn)|
 I found it on https://www.101computing.net/the-shoelace-algorithm/

 The main function scans the input coordinates and stores their x and y values
 in separate arrays, which makes the most sense for the function calculating the
 area. Said function involves a simple loop for "shoelacing" the x and y
 coordinates and connecting the last parts after the loop, finally dividing by
 two and taking the absolute value of the result.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double shoelace(int n, int X[], int Y[]) {
  double area = 0;
  for (int i = 0; i < n - 1; i++)
    area += (X[i] * Y[i + 1]) - (X[i + 1] * Y[i]);
  // connect last x to first y and first x with last y:
  area += (X[n - 1] * Y[0]) - (X[0] * Y[n - 1]);
  return fabs(area / 2);
}

int main() {
  int n;
  scanf("%d", &n);
  int X[n], Y[n];
  for (int i = 0; i < n; i++)
    scanf("%d %d", &X[i], &Y[i]);
  printf("%lf", shoelace(n, X, Y));
}
