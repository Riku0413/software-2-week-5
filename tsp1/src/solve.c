#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "city.h"
#include "map.h"
#include "solve.h"

double solve(const City *city, int n, int *route, int *visited, int loop)
{
    // 局所最適解リスト
    int min_route_list[loop][n];
    double min_sum_list[loop];
    // 最終的な解
    double sum_d = 0;

    srand((unsigned int)time(NULL));

    for (int q = 0; q < loop; q++) {

        //
        // 1. ランダムな初期化
        int i, j, tmp;
        for (i = 0; i < n; i++) {
            route[i] = i;
            visited[i] = 1; // 訪問済みかチェック
        }
        for (i = 0; i < n; i++) {
            j = rand() % n;
            tmp = route[i];
            route[i] = route[j];
            route[j] = tmp;
        }
        //

        double sum_d_2 = 0;
        for (int i = 0 ; i < n ; i++) {
            const int c0 = route[i];
            const int c1 = route[(i+1)%n]; // nは0に戻る
            sum_d_2 += distance(city[c0],city[c1]);
        }

        // これをこねくり回す
        int route_2[n];
        // int *route_2 = (int*)malloc(sizeof(int)*n);

        for (int i = 0 ; i < n ; i++){
            route_2[i] = route[i];
        }
        // memcpy(route_2, route, sizeof(int)*n);

        // これは暫定最短ルート
        for (int i = 0 ; i < n ; i++){
            min_route_list[q][i] = route[i];
        }
        // 暫定最短距離
        min_sum_list[q] = sum_d_2;

        // 全入れ替えを試す
        int flag = 1;
        // int count = 0;
        while (flag == 1) {
            // この回の基準の距離とルート
            double sum_d_zero = min_sum_list[q];
            for (int i = 0 ; i < n ; i++){
                route_2[i] = min_route_list[q][i];
            }

            for (int k1 = 0; k1 < n - 1; k1++) {
                for (int k2 = k1 + 1; k2 < n; k2++) {
                    tmp = route_2[k1];
                    route_2[k1] = route_2[k2];
                    route_2[k2] = tmp;
                    sum_d_2 = 0; // リセット
                    // ある入れ替えパターンの距離を計算
                    for (int i = 0 ; i < n ; i++) {
                        const int c0 = route_2[i];
                        const int c1 = route_2[(i+1)%n]; // nは0に戻る
                        sum_d_2 += distance(city[c0],city[c1]);
                    }
                    // もし,最短が更新されるなら値を更新
                    if (sum_d_2 < min_sum_list[q]) {
                        min_sum_list[q] = sum_d_2;
                        for (int i = 0 ; i < n ; i++){
                            min_route_list[q][i] = route_2[i];
                        }
                    }
                    // リセット
                    tmp = route_2[k1];
                    route_2[k1] = route_2[k2];
                    route_2[k2] = tmp;
                    if (k1 == (n - 2) && k2 == (n - 1)) {
                        if (sum_d_zero == min_sum_list[q]) {
                            flag = 0;
                        }
                    }
                }
            }
            // count++;
        }
        // printf("count = %d\n", count);

    }

    sum_d = min_sum_list[0];
    int p_index = 0;
    for (int p = 1; p < loop; p++) {
        if (min_sum_list[p] < sum_d) {
            sum_d = min_sum_list[p];
            p_index = p;
        }
    }
    for (int i = 0; i < n; i++) {
        route[i] = min_route_list[p_index][i];
    }

    return sum_d;
}
