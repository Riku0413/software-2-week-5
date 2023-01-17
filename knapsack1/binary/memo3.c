#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 2 ){
      fprintf(stderr, "usage: %s filename\n", argv[0]);
      exit(1);
    }

    FILE *fp;

    if ((fp = fopen(argv[1],"rb")) == NULL){
      perror(argv[1]);
      exit(1);
    }

    size_t number = 0;
    fread(&number, sizeof(size_t), 1, fp);

    double *value = (double*)malloc(sizeof(double)*number);
    double *weight = (double*)malloc(sizeof(double)*number);
    fread(value, sizeof(double), number, fp);
    fread(weight, sizeof(double), number, fp);

    fclose(fp);

    printf("number = %zu\n", number);
    for (int i = 0 ; i < number ; i++){
      printf("value = %f\n", value[i]);
      printf("weight = %f\n", weight[i]);
    }

    free(value);
    free(weight);

    return EXIT_SUCCESS;
}