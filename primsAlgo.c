#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#define INF 999999
#define N 5

int G[N][N] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
};

int main() {
    int no_edge = 0;
    int selected[N];
    memset(selected, false, sizeof(selected));   

    selected[0] = true;
    int x, y;

    while (no_edge < N - 1) {
        int min = INF;
        x = 0;
        y = 0;
        for (int i = 0; i < N; i++) {
            if (selected[i]) {
                for (int j = 0; j < N; j++) {
                    if (!selected[j] && G[i][j]) {
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }       
        printf("%d - %d: %d\n", x, y, G[x][y]);
        selected[y] = true;
        no_edge++;
    }
    return 0;
}