#include <stdio.h>
#include <string.h>

int main(void){
    float f[4];
    
    // 以下に適切な値を設定する
    f[0] = 1143139122437582505939828736.000000;
    f[1] = 66592994030331831990133719040.000000;
    f[2] = 0.00000000000000000000000000000001099819697936194958;
    f[3] = 0.00000000000000000000000000000000000000587747175411;
    
    
    // "Hello,World\n" と出力してほしい
    printf("%s",(char*)f);

    // char c[4] = "Hell";
    // printf("%f\n", c);

    char str[16] = "Hello,World\n";

    // for (int i0 = 0; i0 < 16; i0++) {
    //     char c = str[i0];
    //     for (int i = 7; i >= 0; i--) {
    //         printf("%d", (c >> i) & 1);
    //     }
    //     printf("\n");
    // }

    unsigned int data[4][32];
    for (int f_i = 0; f_i < 4; f_i++) {
        for (int bite = 3; bite >= 0; bite--) {
            char c = str[f_i * 4 + bite];
            for (int j = 7; j >= 0; j--) {
                data[f_i][31 - bite*8 - j] = ((c >> j) & 1);
            }
        }
    }

    return 0;
}
