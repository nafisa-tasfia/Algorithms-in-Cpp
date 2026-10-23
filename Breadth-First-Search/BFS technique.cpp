#include <iostream>
using namespace std;

#define SIZE 6

void BFS(int graph[SIZE][SIZE], int start_node) {
    int visited[SIZE] = {0};
    int queue[SIZE];

    int front = 0, rear = 0;

    visited[start_node] = 1;
    queue[rear] = start_node;
    rear++;

    cout << "BFS Traversal: ";

    while (front < rear) {
        int current = queue[front];
        front++;

        cout << current << " ";

        for (int neighbor = 0; neighbor < SIZE; neighbor++) {
            if (graph[current][neighbor] == 1 && visited[neighbor] == 0) {
                visited[neighbor] = 1;
                queue[rear] = neighbor;
                rear++;
            }
        }
    }

    cout << endl;
}

int main() {
    int graph[SIZE][SIZE] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    BFS(graph, 0);

    return 0;
}
