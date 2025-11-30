#include <iostream>
using namespace std;

const int INF = 1000000000;

struct Edge {
    int from;
    int to;
    int weight;
};

void sortEdges(Edge edges[], int edgeCount) {
    for (int i = 0; i < edgeCount - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < edgeCount; j++) {
            if (edges[j].weight < edges[minIndex].weight)
                minIndex = j;
        }
        if (minIndex != i) {
            Edge temp = edges[i];
            edges[i] = edges[minIndex];
            edges[minIndex] = temp;
        }
    }
}

int findParent(int parent[], int x) {
    if (parent[x] == x)
        return x;
    parent[x] = findParent(parent, parent[x]);
    return parent[x];
}

void unionSets(int parent[], int rank[], int a, int b) {
    int rootA = findParent(parent, a);
    int rootB = findParent(parent, b);

    if (rootA == rootB) return;

    if (rank[rootA] < rank[rootB]) {
        parent[rootA] = rootB;
    } else if (rank[rootA] > rank[rootB]) {
        parent[rootB] = rootA;
    } else {
        parent[rootB] = rootA;
        rank[rootA]++;
    }
}

void kruskalMST(int vertexCount, Edge edges[], int edgeCount) {
    sortEdges(edges, edgeCount);

    int* parent = new int[vertexCount];
    int* rank = new int[vertexCount];

    for (int i = 0; i < vertexCount; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int totalWeight = 0;
    cout << "Kruskal MST edges:\n";

    int chosenEdges = 0;
    for (int i = 0; i < edgeCount && chosenEdges < vertexCount - 1; i++) {
        int u = edges[i].from;
        int v = edges[i].to;

        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        if (rootU != rootV) {
            cout << u << " - " << v << " (w=" << edges[i].weight << ")\n";
            totalWeight += edges[i].weight;
            unionSets(parent, rank, rootU, rootV);
            chosenEdges++;
        }
    }

    cout << "Total weight (Kruskal): " << totalWeight << "\n";

    delete[] parent;
    delete[] rank;
}

int minKey(int key[], bool inMST[], int vertexCount) {
    int minValue = INF;
    int minIndex = -1;

    for (int i = 0; i < vertexCount; i++) {
        if (!inMST[i] && key[i] < minValue) {
            minValue = key[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void primMST(int vertexCount, int** graph, int start) {
    int* parent = new int[vertexCount];
    int* key = new int[vertexCount];
    bool* inMST = new bool[vertexCount];

    for (int i = 0; i < vertexCount; i++) {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }

    key[start] = 0;

    for (int count = 0; count < vertexCount - 1; count++) {
        int u = minKey(key, inMST, vertexCount);
        if (u == -1) break;

        inMST[u] = true;

        for (int v = 0; v < vertexCount; v++) {
            if (graph[u][v] != INF && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalWeight = 0;
    cout << "Prim MST edges:\n";
    for (int v = 0; v < vertexCount; v++) {
        if (v != start && parent[v] != -1) {
            cout << parent[v] << " - " << v << " (w=" << graph[parent[v]][v] << ")\n";
            totalWeight += graph[parent[v]][v];
        }
    }
    cout << "Total weight (Prim): " << totalWeight << "\n";

    delete[] parent;
    delete[] key;
    delete[] inMST;
}

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;

    Edge* edges = new Edge[e];

    int** weightMatrix = new int*[v];
    for (int i = 0; i < v; i++) {
        weightMatrix[i] = new int[v];
        for (int j = 0; j < v; j++)
            weightMatrix[i][j] = INF;
    }

    cout << "Enter edges (u v w) for undirected weighted graph (0-based):\n";
    for (int i = 0; i < e; i++) {
        int u, w, wt;
        cin >> u >> w >> wt;
        edges[i].from = u;
        edges[i].to = w;
        edges[i].weight = wt;

        weightMatrix[u][w] = wt;
        weightMatrix[w][u] = wt;
    }

    kruskalMST(v, edges, e);

    int start;
    cout << "Enter start vertex for Prim MST: ";
    cin >> start;
    primMST(v, weightMatrix, start);

    for (int i = 0; i < v; i++)
        delete[] weightMatrix[i];
    delete[] weightMatrix;
    delete[] edges;

    return 0;
}
