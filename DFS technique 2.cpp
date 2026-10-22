#include <iostream>
using namespace std;

#define SIZE 6

void DFS(int graph[SIZE][SIZE], int start_node) {
    int visited[SIZE] = {0};
    int stack[SIZE];
    int top = -1;

    // push start node
    stack[++top] = start_node;

    while (top >= 0) {
        int current = stack[top--];

        if (!visited[current]) {
            visited[current] = 1;
            cout << current << " ";

            // push neighbors in reverse order
            for (int neighbor = SIZE - 1; neighbor >= 0; neighbor--) {
                if (graph[current][neighbor] == 1 && !visited[neighbor]) {
                    stack[++top] = neighbor;
                }
            }
        }
    }
}

int main() {
    int graph[SIZE][SIZE] = {
        {0,1,1,0,0,0},
        {1,0,0,1,1,0},
        {1,0,0,0,1,0},
        {0,1,0,0,0,1},
        {0,1,1,0,0,1},
        {0,0,0,1,1,0}
    };

    cout << "DFS Traversal: ";
    DFS(graph, 0);

    return 0;
}
