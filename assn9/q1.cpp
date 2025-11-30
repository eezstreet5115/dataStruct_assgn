#include <iostream>
using namespace std;

struct Graph {
    int vertexCount;
    int** adjacency;

    Graph(int v) {
        vertexCount = v;
        adjacency = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++) {
            adjacency[i] = new int[vertexCount];
            for (int j = 0; j < vertexCount; j++)
                adjacency[i][j] = 0;
        }
    }

    ~Graph() {
        for (int i = 0; i < vertexCount; i++)
            delete[] adjacency[i];
        delete[] adjacency;
    }

    void addEdge(int from, int to, bool undirected) {
        adjacency[from][to] = 1;
        if (undirected)
            adjacency[to][from] = 1;
    }

    void bfs(int start) {
        if (start < 0 || start >= vertexCount) {
            cout << "Invalid start vertex\n";
            return;
        }

        int* visited = new int[vertexCount];
        for (int i = 0; i < vertexCount; i++)
            visited[i] = 0;

        int* queue = new int[vertexCount];
        int front = 0, rear = 0;

        visited[start] = 1;
        queue[rear++] = start;

        cout << "BFS order: ";

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            for (int v = 0; v < vertexCount; v++) {
                if (adjacency[current][v] && !visited[v]) {
                    visited[v] = 1;
                    queue[rear++] = v;
                }
            }
        }

        cout << "\n";

        delete[] visited;
        delete[] queue;
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    Graph graph(v);

    cout << "Enter edges (u v) for undirected graph (0-based):\n";
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        graph.addEdge(u, w, true);
    }

    int start;
    cout << "Enter start vertex for BFS: ";
    cin >> start;

    graph.bfs(start);

    return 0;
}
