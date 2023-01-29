#include "stdio.h"
#define MAX 30 

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct EdgeList {
    Edge data[MAX];
    int n;
} EdgeList;

EdgeList elist;
EdgeList spanList;
int Graph[MAX][MAX], n;

void kruskalAlgo();
void sort();
void print();
int find(int*, int);
void applyUnion(int*, int, int);

int main() {
  int i, j, total_cost;

  n = 6;

  Graph[0][0] = 0;
  Graph[0][1] = 4;
  Graph[0][2] = 4;
  Graph[0][3] = 0;
  Graph[0][4] = 0;
  Graph[0][5] = 0;
  Graph[0][6] = 0;

  Graph[1][0] = 4;
  Graph[1][1] = 0;
  Graph[1][2] = 2;
  Graph[1][3] = 0;
  Graph[1][4] = 0;
  Graph[1][5] = 0;
  Graph[1][6] = 0;

  Graph[2][0] = 4;
  Graph[2][1] = 2;
  Graph[2][2] = 0;
  Graph[2][3] = 3;
  Graph[2][4] = 4;
  Graph[2][5] = 0;
  Graph[2][6] = 0;

  Graph[3][0] = 0;
  Graph[3][1] = 0;
  Graph[3][2] = 3;
  Graph[3][3] = 0;
  Graph[3][4] = 3;
  Graph[3][5] = 0;
  Graph[3][6] = 0;

  Graph[4][0] = 0;
  Graph[4][1] = 0;
  Graph[4][2] = 4;
  Graph[4][3] = 3;
  Graph[4][4] = 0;
  Graph[4][5] = 0;
  Graph[4][6] = 0;

  Graph[5][0] = 0;
  Graph[5][1] = 0;
  Graph[5][2] = 2;
  Graph[5][3] = 0;
  Graph[5][4] = 3;
  Graph[5][5] = 0;
  Graph[5][6] = 0;

  kruskalAlgo();
  print();
}

void kruskalAlgo() {
    int belongs[MAX], cno1, cno2;
    elist.n = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (Graph[i][j] != 0) {
                elist.data[elist.n].src = i;
                elist.data[elist.n].dest = j;
                elist.data[elist.n].weight = Graph[i][j];
                elist.n++;
            }
        }
    }

    sort();

    for (int i = 0; i < elist.n; i++) {
        printf("%d %d %d\n", elist.data[i].src, elist.data[i].dest, elist.data[i].weight);
    }

    for (int i = 0; i < n; i++) {
        belongs[i] = i;
    }

    spanList.n = 0;

    for (int i = 0; i < elist.n; i++) {
        int cno1 = find(belongs, elist.data[i].src);
        int cno2 = find(belongs, elist.data[i].dest);
        if (cno1 != cno2) {
            spanList.data[spanList.n] = elist.data[i];
            spanList.n++;
            applyUnion(belongs, cno1, cno2);
        }
        printf("%d %d = ", cno1, cno2);
        for (int j = 0; j < n; j++) {
            printf("%d ", belongs[j]);
        }
        printf("\n");
    }
}

void print() {
    int cost = 0;
    for (int i = 0; i < spanList.n; i++) {
        printf("%d - %d = %d\n", spanList.data[i].src, spanList.data[i].dest, spanList.data[i].weight);
        cost += spanList.data[i].weight;
    }
    printf("\n Spanning tree cost: %d", cost);
}

void sort() {
    Edge temp;
    for (int i = 0; i < elist.n; i++) {
        for (int j = 0; j < elist.n; j++) {
            if (elist.data[j].weight > elist.data[j + 1].weight) {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
        }
    }
}

void applyUnion(int* belongs, int c1, int c2) {
    for (int i = 0; i < n; i++) {
        if (belongs[i] == c2) {
            belongs[i] = c1;
        }
    }
}

int find(int* belongs, int vertexNo) {
    return belongs[vertexNo];
}