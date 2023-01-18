#include <stdio.h>
#include <assert.h>
#include "obj.h"

int main() {
  for (int n = 0; n < 21; n++) {
    long x = fibo(n);
    printf("%ld\n", x);
  }
  return 0;
}