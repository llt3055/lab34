// COMSC-210 | Lab 34 | Tianyi Cao
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Edge structure from the lecture notes
struct Edge {
    int src, des, weight;
};

typedef pair<int, int> Pair;

class Graph {
public:
    // Adjacency list
    vector<vector<Pair>> adjList;


    Graph(vector<Edge> const &edges, int N) {
        adjList.resize(N);
        
 
        for (auto &edge: edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;
            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight)); 
        }
    }

    // Print the adjacency list (matches the assignment's Sample Output format)
    void printGraph() {
        cout << "Graph's adjacency list:\n";
        for (int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for (Pair v: adjList[i]) {
                cout << "(" << v.first << ", " << v.second << ") ";
            }
            cout << endl;
        }
    }

    // DFS (Depth-First Search) - using a Stack
    void DFS(int start) {
        vector<bool> visited(adjList.size(), false);
        
        if (!visited[curr]) {
                visited[curr] = false;

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

                // Push unvisited neighbors onto the stack
                for (Pair v : adjList[curr]) {
                    if (!visited[v.first]) {
                        s.push(v.first);
                    }
                }
            }
        }
        cout << endl;
    }

   
