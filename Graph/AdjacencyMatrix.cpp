#include <iostream>
#include <vector>
using namespace std;

// Adjacency matrix representation of a graph
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;
public:
    Graph(int vertices) : V(vertices) { 
        adjMatrix.resize(V, vector<int>(V, -1));
        for (int i = 0; i < V; i++) {
            adjMatrix[i][i] = 0; 
        }
    }
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }
    void printGraph() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
                if (j == V - 1) cout << endl;
            }
        }
    }
};

int main() {
    // Create a graph with 5 vertice
    Graph g(5);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);
    g.addEdge(2, 4, 80);
    cout << "Adjacency Matrix:" << endl;
    g.printGraph();
    return 0;   
}