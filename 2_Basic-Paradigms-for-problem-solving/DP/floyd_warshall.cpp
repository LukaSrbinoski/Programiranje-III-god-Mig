#include <iostream>
#include <climits>

using namespace std;

void floydWarshall(int graph[][4], int v) {
    int dist[4][4];

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < v; k++)
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cout << "Shortest distances:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INT_MAX) cout << "INF ";
            else cout << dist[i][j] << "   ";
        }
        cout << "\n";
    }
}

int main() {
    int graph[4][4] = {
        {0,         3,         INT_MAX,   7},
        {8,         0,         2,         INT_MAX},
        {5,         INT_MAX,   0,         1},
        {2,         INT_MAX,   INT_MAX,   0}
    };

    floydWarshall(graph, 4);
    return 0;
}