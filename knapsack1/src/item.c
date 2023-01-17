#include <stdio.h>
#include <stdlib.h>
#include "item.h"

// 構造体をポインタで確保するお作法を確認してみよう
Itemset *init_itemset(size_t number, int seed)
{
  Itemset *list = (Itemset*)malloc(sizeof(Itemset));

  Item *item = (Item*)malloc(sizeof(Item)*number);

  srand(seed);
  for (int i = 0 ; i < number ; i++){
    item[i].value = 0.1 * (rand() % 200);
    item[i].weight = 0.1 * (rand() % 200 + 1);
  }
  *list = (Itemset){.number = number, .item = item};
  return list;
}

//
//
Itemset *load_itemset(char *filename)
{
  FILE *fp;

  if ((fp = fopen(filename, "rb")) == NULL){ ////
    perror(filename); ////
    exit(1);
  }

  size_t number = 0;
  fread(&number, sizeof(size_t), 1, fp);

  Itemset *list = (Itemset*)malloc(sizeof(Itemset));
  Item *item = (Item*)malloc(sizeof(Item)*number);

  double *value = (double*)malloc(sizeof(double)*number);
  double *weight = (double*)malloc(sizeof(double)*number);
  fread(value, sizeof(double), number, fp);
  fread(weight, sizeof(double), number, fp);

  fclose(fp);

  for (int i = 0 ; i < number ; i++){
    item[i].value = value[i];
    item[i].weight = weight[i];
  }

  // printf("number = %zu\n", number);
  // for (int i = 0 ; i < number ; i++){
  //   printf("value = %f\n", value[i]);
  //   printf("weight = %f\n", weight[i]);
  // }

  free(value);
  free(weight);

  *list = (Itemset){.number = number, .item = item};
  return list;
}
//
//

// itemset の free関数
void free_itemset(Itemset *list)
{
  free(list->item);
  free(list);
}

// 表示関数
void print_itemset(const Itemset *list)
{
  size_t n = list->number;
  const char *format = "v[%d] = %4.1f, w[%d] = %4.1f\n";
  for(int i = 0 ; i < n ; i++){
      Item item = get_item(list, i);
      printf(format, i, get_itemvalue(item), i, get_itemweight(item));
  }
  printf("----\n");
}

Item get_item(const Itemset *list, size_t index)
{
    return list->item[index];
}

double get_itemweight(Item item)
{
    return item.weight;
}

double get_itemvalue(Item item){
    return item.value;
}

