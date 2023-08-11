/*
Project Description:
This program represents a graph and finds the strong components related to a specified vertex.
The program uses both Breadth First Search (BFS) and Depth First Search (DFS) algorithms to identify the strong components.

*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define sz 10

using namespace std;

int adjMat[sz][sz];

// Function to identify an unvisited vertex connected to a given vertex
int verUnvisited(int index, int size, bool *visit) {
    for (int i = 0; i < size; i++) {
        if (adjMat[index][i] == 1 && (visit[i] == false)) {
            return i;
        }
    }
    return -1;
}

// Function for Depth First Search
void depthFirstSearch(int currentVertex, string &dfs, bool *visit, string vertex, int size) {
    dfs += vertex[currentVertex];
    visit[currentVertex] = true;

    for (int i = 0; i < size; i++) {
        if (visit[i] == false && adjMat[currentVertex][i] == 1) {
            depthFirstSearch(i, dfs, visit, vertex, size);
        }
    }
}

// Function for Breadth First Search
string breadthFirstSearch(string s, int size, char node) {
    bool vertexVisited[size] = {false};
    queue<int> Queue;
    int root = s.find(node);
    vertexVisited[root] = true;
    Queue.push(root);
    string bfs;

    while (!Queue.empty()) {
        int index = Queue.front();
        Queue.pop();
        bfs += s[index];
        int nxtVer;
        while ((nxtVer = verUnvisited(index, size, vertexVisited)) != -1) {
            vertexVisited[nxtVer] = true;
            Queue.push(nxtVer);
        }
    }
    return bfs;
}

// Function to take input for the graph
void input(string s, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter 1 if there is an edge from - " << s[i] << " - to - " << s[j] << " or 0 if not: ";
            cin >> adjMat[i][j];
        }
    }
}


int main() {
    string s;
    cout << "Enter all the vertices without a space: ";
    cin >> s;
    int size = s.length();
    input(s, size);
    char ver;
    cout << "Enter the vertex for which you want to find the strong component: ";
    cin >> ver;

    string bfs = breadthFirstSearch(s, size, ver);
    vector<string> dfsResults;
    for (int i = 0; i < size; i++) {
        bool visit[sz] = {false};
        string dfs;
        depthFirstSearch(i, dfs, visit, s, size);
        dfsResults.push_back(dfs);
    }

    string strong;
    for (char c : bfs) {
        for (string dfsStr : dfsResults) {
            if (dfsStr.find(c) != string::npos) {
                strong += c;
                break;
            }
        }
    }

    cout << "\nThe possible paths for every vertex starting at the first: ";
    for (string str : dfsResults) {
        cout << endl << str;
    }

    cout << "\nThe Strong components of the vertex " << ver << " are: " << strong << endl;

    return 0;
}
