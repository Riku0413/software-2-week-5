#include <stdio.h>
#include <math.h>

float char32_to_float(const char bit[32]) {
  float f = 1.0;
  if (bit[0] == '1') {
    f = -1.0;
  }

  float kasu = 1.0;
  for (int i = 9; i < 31; i++) {
    if (bit[i] == '1') {
      kasu += pow(2, 8.0-i);
    }
  }
  f *= kasu;

  float sisu = 0.0;
  for (int i = 1; i <= 8; i++) {
    if (bit[i] == '1') {
      sisu += pow(2, 8.0-i);
    }
  }
  sisu -= 127.0;
  sisu = pow(2, sisu);

  f *= sisu;

  return f;
}

// double char32_to_double(const char bit[32]) {
//   double f = 1.0;
//   if (bit[0] == '1') {
//     f = -1.0;
//   }

//   double kasu = 1.0;
//   for (int i = 9; i < 31; i++) {
//     if (bit[i] == '1') {
//       kasu += pow(2, 8.0-i);
//     }
//   }
//   f *= kasu;

//   printf("%lf\n", f);

//   double sisu = 0.0;
//   for (int i = 1; i <= 8; i++) {
//     if (bit[i] == '1') {
//       sisu += pow(2, 8.0-i);
//     }
//   }
//   sisu -= 127.0;
//   sisu = pow(2, sisu);
//   printf("%lf\n", sisu);

//   f *= sisu;

//   return f;
// }

int main() {

  char str[16] = "Hello,World\n";
  char bit[4][32];

  for (int i = 0; i < 16; i++) {
      char c = str[i];
      for (int j = 7; j >= 0; j--) {
          // printf("%d", (c >> j) & 1);
          if (((c >> j) & 1) == 1) {
            bit[i / 4][31 - (i % 4) * 8 - j] = '1'; 
          } else {
            bit[i / 4][31 - (i % 4) * 8 - j] = '0'; 
          }
      }
      // printf("\n");
  }

  // char bit[32] = "01101100011011000110010101001000";
  // char bit2[32] = "00001010011001000110110001110010";
  // char bit3[32] = "00000000000000000000000000000000";
  float f = char32_to_float(bit[0]);
  float f1 = char32_to_float(bit[1]);
  float f2 = char32_to_float(bit[2]);
  float f3 = char32_to_float(bit[3]);
  printf("%f\n", f);
  printf("%f\n", f1);
  printf("%.50f\n", f2);
  printf("%.50f\n", f3);
  return 0;
}