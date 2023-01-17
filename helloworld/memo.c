#include <stdio.h>

#define NUM_BIT 32

void print_bit_char(char c) {
    for (int i = 0; i < 8; ++i) {
        if (c & 1 << (7 - i)) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void list_bit_char(char c[4], unsigned int data[32]) {
  for (int k = 0; k < 4; k++) {
    for (int i = 0; i < 8; ++i) {
        if (c[3 - k] & 1 << (7 - i)) {
            data[k*8 + i] = 1;
        } else {
            data[k*8 + i] = 0;
        }
    }
  }
}

int main(void) {

    char str[16] = "Hello,World";
    str[11] = 'g';
    str[12] = '\0';
    str[13] = '\0';
    str[14] = '\0';
    str[15] = '\0';
    print_bit_char('\n');

    int data1[3][32];
    for (int f_i = 0; f_i < 3; f_i++) {
        for (int bite = 3; bite >= 0; bite--) {
            char c = str[f_i * 4 + bite];
            for (int j = 7; j >= 0; j--) {
              if (c & 1 << j) {
                data1[f_i][31 - bite*8 - j] = 1;
              } else {
                data1[f_i][31 - bite*8 - j] = 0;
              }
            }
        }
    }

    unsigned int data[32] =
    {
      0,0,0,0,1,0,1,0,
      0,1,1,0,0,1,0,0,
      0,1,1,0,1,1,0,0,
      0,1,1,1,0,0,1,0,
    };

    // for (int i = 0; i < 32; i++) {
    //   data[i] = data1[2][i];
    // }

    // list_bit_char("dlr\n", data);

    float mantissa; /* 仮数 */
    int exponent; /* 指数 */
    int sign; /* 符号 */
    float plus_value; /* 符号なしの数値 */
    float value; /* 数値 */
    int i;
    int shift_num;

    /* 仮数を計算 */
    mantissa = 1; /* 整数部は 1 */
    for (i = 9; i < 32; i++) {
        if (data[i] == 1) {
            /* ビットが1の箇所に対応する2の冪乗の値を加算 */
            shift_num = i - 8;
            mantissa += (double)1 / (double)(1 << shift_num);
        }
    }

    /* 指数を計算 */
    exponent = 0;
    for (i = 1; i < 9; i++) {
        if (data[i] == 1) {
            /* ビットが1の箇所に対応する2の冪乗の値を加算 */
            shift_num = 8 - i;
            exponent += (1 << shift_num);
        }
    }
    /* 最後に 127 を引く */
    exponent = exponent - 127.0;

    /* 符号を計算 */
    if (data[0] == 0) {
        sign = 1;
    } else {
        sign = -1;
    }

    /* 符号と指数と仮数から数値を計算 */

    /* 仮数*2^指数を計算 */
    plus_value = mantissa;

    if (exponent >= 0) {
        for (i = 0; i < exponent; i++) {
            plus_value = plus_value * 2;
        }
    } else {
        for (i = 0; i > exponent; i--) {
            plus_value = plus_value / 2;
        }
    }

    /* 最後に符号を掛ける */
    value = sign * plus_value;

    /* 内部データの表示 */
    printf("data = ");
    for (i = 0; i < NUM_BIT; i++) {
        printf("%u", data[i]);
    }
    printf("\n");

    /* 数値の表示 */
    printf("value = %f\n", value);

    return 0;
}