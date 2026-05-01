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

// Pair definition from the lecture notes
typedef pair<int, int> Pair;

class Graph {
public:
    // Adjacency list
    vector<vector<Pair>> adjList;

    vector<string> nodeNames;

    // Constructor
    Graph(vector<Edge> const &edges, int N, vector<string> names) {
        adjList.resize(N);
        nodeNames = names;
        
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
    // Real-world application: Cloud Data Center Network
    int N = 12; // 12 nodes representing different server centers
    vector<string> centerNames = {
        "HQ Data Center", "West Region", "East Region", "North Region",
        "South Region", "Backup Center 1", "Backup Center 2", "Edge Node A",
        "Edge Node B", "Edge Node C", "Edge Node D", "Global Hub"
    };
    // Network connections with latency (ms) as weights
    vector<Edge> edges = {
        {0, 1, 15}, {0, 2, 20}, {0, 11, 5},
        {1, 3, 12}, {1, 7, 8},  {2, 4, 18},
        {2, 8, 10}, {3, 5, 25}, {4, 6, 22},
        {5, 9, 14}, {6, 10, 16}, {7, 11, 30},
        {8, 11, 28}, {9, 10, 5}, {11, 5, 40}
    };

    // Instantiate the graph with names
    Graph graph(edges, N, centerNames);

    // Execute the application functions
    graph.printGraph();
    graph.DFS(0);
    graph.BFS(0);

    return 0;
}
   
