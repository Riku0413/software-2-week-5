#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hell";
    int len = sizeof(str) / sizeof(str[0]); //文字数
    char bits[len * 8 + 1];  // char型配列strのビット列を格納する配列
    memset(bits, 0, sizeof(bits)); // 配列を0で初期化
    int k = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 7; j >= 0; j--) {
            bits[k++] = (str[i] >> j) & 1 + '0';
        }
    }
    bits[k] = '\0'; //末尾にNULL文字
    printf("%s\n", bits);

    // unsigned int i;
    // memcpy(&i, bits, sizeof(unsigned int)); // bitsからiにコピー
    float f;
    memcpy(&f, bits, sizeof(float)); // iからfにコピー
    printf("%f\n", f);
    return 0;
}
