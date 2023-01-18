#include <stdio.h>
#include <assert.h>
#include "obj.h"

struct matrix matrix_multiply(struct matrix a, struct matrix b) {
    struct matrix c;
    c.m[0][0] = a.m[0][0]*b.m[0][0] + a.m[0][1]*b.m[1][0];
    c.m[0][1] = a.m[0][0]*b.m[0][1] + a.m[0][1]*b.m[1][1];
    c.m[1][0] = a.m[1][0]*b.m[0][0] + a.m[1][1]*b.m[1][0];
    c.m[1][1] = a.m[1][0]*b.m[0][1] + a.m[1][1]*b.m[1][1];
    return c;
}

struct matrix matrix_power_n(struct matrix a, int n) {
  assert(n <= 90);
  if (n == 1) {
    return a;
  } else if (n % 2 == 0) {
    struct matrix b = matrix_power_n(a, n/2);
    return matrix_multiply(b, b);
  } else {
    struct matrix c = matrix_power_n(a, (n-1)/2);
    struct matrix d = matrix_multiply(c, c);
    return matrix_multiply(d, a);
  }
}

long fibo(int n) {
  if (n == 0 | n == 1) {
    return n;
  } else {
    struct matrix a;
    a.m[0][0] = 1;
    a.m[0][1] = 1;
    a.m[1][0] = 1;
    a.m[1][1] = 0;
    return fibo(1) * matrix_power_n(a, n).m[0][0] + fibo(0) * matrix_power_n(a, n).m[0][1];
  }
}