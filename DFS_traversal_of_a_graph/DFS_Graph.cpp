// Project CSC 323 Abrar Fahad
// Depth First Search (DFS) traversal of a graph
#include <iostream>
using namespace std;

// Size of the adjacency matrix
#define sz 10

// Global adjacency matrix since multidimensional arrays cannot be directly passed to functions
int adjMat[sz][sz];

// Depth First Search (DFS) algorithm
void deapthFirstSearch(int currentVertex, string &dfs, int &dfSize, bool *visit, const string &vertex) {
    dfs[dfSize] = vertex[currentVertex];
    dfSize++;
    visit[currentVertex] = true;

    for(int i = 0; i < vertex.size(); i++ ) {
        if(!visit[i] && adjMat[currentVertex][i] == 1) {
            deapthFirstSearch(i, dfs, dfSize, visit, vertex);
        }
    }
}

// Use user input function to populate the adjacency matrix.
void input(const string &s, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "Enter 1 if there is an edge from - " << s[i] << " - to - " << s[j] << " or 0 if not: ";
            cin >> adjMat[i][j];
        }
    }
}

int main() {
    string vertex;
    int dfSize = 0;

    // Input vertices of the graph
    cout << "Enter all the vertices without space: ";
    cin >> vertex;

    // Validate size of input vertices
    if(vertex.size() > sz) {
        cout << "The number of vertices exceeds the limit!";
        return 1;
    }

    // Take input for adjacency matrix
    input(vertex, vertex.size());

    // Initialize visited array
    bool visit[sz] = {false};

    // Record DFS traversal starting from vertex 0 (Assuming Vertex A as root)
    string dfs(vertex.size(), ' ');
    deapthFirstSearch(0, dfs, dfSize, visit, vertex);

    cout << endl;
    for (int i = 0; i < dfSize; i++) {
        cout << dfs[i];
    }
}
