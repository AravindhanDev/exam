#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#define N 40

typedef struct Queue {
    int items[N];
    int front;
    int rear;
} Queue;

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

int queue[N];
int front = -1, rear = -1;

void bfs(Graph*, int);
void printQueue();
void addEdge(Graph*, int, int);
Node* createNode(int);
Graph* createGraph(int);
Queue* createQueue();
void enqueue(int);
int dequeue();

int main() {
    Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    bfs(graph, 0);

    return 0;
}

void enqueue(int value) {
    if (rear == N - 1) {
        printf("Queue is full");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = value;
}

int dequeue() {
    if (rear == -1) {
        printf("Queue is empty");
        return -1;
    }
    int item = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return item;
}

void bfs(Graph* graph, int startVertex) {
    graph->visited[startVertex] = 1;
    enqueue(startVertex);
    while (rear != -1) {
        int currentVertex = dequeue();
        printf("%d", currentVertex);
        printf("Visited %d\n", currentVertex);
        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
            temp = temp->next;
        }   
    }
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] == newNode;   
}

void printQueue() {
    if (rear == -1) {
        printf("Queue is empty");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node));
    graph->visited = malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = value;
    newNode->next = NULL;
    return newNode;
}