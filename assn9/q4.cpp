#include <iostream>
using namespace std;

const int INF = 1000000000;

int minDistance(int distance[], bool visited[], int vertexCount) {
    int minValue = INF;
    int minIndex = -1;

    for (int i = 0; i < vertexCount; i++) {
        if (!visited[i] && distance[i] < minValue) {
            minValue = distance[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    int** weight = new int*[v];
    for (int i = 0; i < v; i++) {
        weight[i] = new int[v];
        for (int j = 0; j < v; j++) {
            if (i == j) weight[i][j] = 0;
            else weight[i][j] = INF;
        }
    }

    cout << "Enter edges (u v w) for directed weighted graph (0-based):\n";
    for (int i = 0; i < e; i++) {
        int u, w, wt;
        cin >> u >> w >> wt;
        weight[u][w] = wt;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    int* distance = new int[v];
    bool* visited = new bool[v];

    for (int i = 0; i < v; i++) {
        distance[i] = INF;
        visited[i] = false;
    }

    distance[source] = 0;

    for (int count = 0; count < v - 1; count++) {
        int u = minDistance(distance, visited, v);
        if (u == -1) break;

        visited[u] = true;

        for (int w = 0; w < v; w++) {
            if (!visited[w] && weight[u][w] != INF && distance[u] != INF &&
                distance[u] + weight[u][w] < distance[w]) {
                distance[w] = distance[u] + weight[u][w];
            }
        }
    }

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < v; i++) {
        if (distance[i] == INF)
            cout << "Vertex " << i << ": INF\n";
        else
            cout << "Vertex " << i << ": " << distance[i] << "\n";
    }

    for (int i = 0; i < v; i++)
        delete[] weight[i];
    delete[] weight;
    delete[] distance;
    delete[] visited;

    return 0;
}
