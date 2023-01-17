#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char buffer[100];

    fp1 = fopen("sample.txt", "r");
    if (fp1 == NULL) {
        printf("入力ファイルを開くことができません\n");
        return 1;
    }

    fp2 = fopen("sample.dat", "wb");
    if (fp2 == NULL) {
        printf("出力ファイルを開くことができません\n");
        return 1;
    }

    size_t number = 0;
    fscanf(fp1, "%zd", &number);
    double value[number];
    double weight[number];
    for (int i = 0; i < number; i++) {
      fscanf(fp1, "%lf", &value[i]);
    }
    for (int i = 0; i < number; i++) {
      fscanf(fp1, "%lf", &weight[i]);
    }

    printf("number = %zu\n", number);
    for (int i = 0; i < number; i++) {
      printf("value = %lf\n", value[i]);
      printf("weight = %lf\n", weight[i]);
    }

    fwrite(&number, sizeof(size_t), 1 ,fp2);
    fwrite(value, sizeof(double), number ,fp2);
    fwrite(weight, sizeof(double), number ,fp2);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
