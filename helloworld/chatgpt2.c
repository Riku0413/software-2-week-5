#include <stdio.h>
#include <string.h>

int main() {
    char bits[] = {0x3f, 0x80, 0x00, 0x00}; // bit representation of 1.0
    float num;
    memcpy(&num, bits, sizeof(float));
    printf("%f", num);


    char c = 'd';
    PrintBitC(c);
    return 0;
}
