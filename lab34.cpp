// COMSC-210 | Lab 34 | Tianyi Cao
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// Edge structure from the lecture notes
struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph {
public:
    // Adjacency list
    vector<vector<Pair>> adjList;

    // Constructor
    Graph(vector<Edge> const &edges, int N) {
        adjList.resize(N);
        
    // Build an undirected graph (add edges in both directions)
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
        stack<int> s;
        
        s.push(start);
        cout << "DFS starting from vertex " << start << ":\n";

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                cout << curr << " ";
                visited[curr] = true;

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

    // BFS (Breadth-First Search) - using a Queue
    void BFS(int start) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS starting from vertex " << start << ":\n";
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            // Enqueue unvisited neighbors
            for (Pair v : adjList[curr]) {
                if (!visited[v.first]) {
                    visited[v.first] = true;
                    q.push(v.first);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Initial graph data provided in the lecture notes
    vector<Edge> edges = {
        {0,1,12}, {0,2,8}, {0,3,21}, {2,3,6}, 
        {2,6,2}, {5,6,6}, {4,5,9}, {2,4,4}, {2,5,5}
    }

    graph.printGraph();
    graph.DFS(0);
    graph.BFS(0);

    return 0;
}
   
