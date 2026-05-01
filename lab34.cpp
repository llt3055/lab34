// COMSC-210 | Lab 34 | Tianyi Cao
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <limits>

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
    // Node names for the real-world application
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
        cout << "Data Center Network Topology:\n";
        cout << "=================================\n";
        for (int i = 0; i < adjList.size(); i++) {
            cout << "Node " << i << " (" << nodeNames[i] << ") connects to:\n";
            for (Pair v: adjList[i]) {
                cout << "  -> Node " << v.first << " (" << nodeNames[v.first] 
                     << ") with latency " << v.second << " ms\n";
            }
        }
    }

    // DFS (Depth-First Search) - using a Stack
    void DFS(int start) {
        vector<bool> visited(adjList.size(), false);
        stack<int> s;
        
        s.push(start);
        cout << "\nDFS (Deep Node Audit) starting from " << nodeNames[start] << ":\n";
        cout << "Purpose: Security audit traversing as deep into the network as possible.\n";
        cout << "-----------------------------------------------------------------------\n";

        while (!s.empty()) {
            int curr = s.top();
            s.pop();

            if (!visited[curr]) {
                cout << "Auditing: Node " << curr << " (" << nodeNames[curr] << ")\n";
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

        cout << "\nBFS (Network Flood Trace) starting from " << nodeNames[start] << ":\n";
        cout << "Purpose: Tracing localized data spread layer by layer.\n";
        cout << "-----------------------------------------------------------------------\n";
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            cout << "Tracing: Node " << curr << " (" << nodeNames[curr] << ")\n";

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

    // Step 4: Shortest Path (Dijkstra's Algorithm)
    void calculateShortestPaths(int start) {
        // Priority queue to store pairs of {distance, vertex}
        // Using greater<Pair> to make it a min-heap based on distance
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        
        // Initialize distances to all nodes as infinite
        vector<int> dist(adjList.size(), numeric_limits<int>::max());

        // Insert source itself in priority queue and initialize its distance as 0
        pq.push(make_pair(0, start));
        dist[start] = 0;

        cout << "\nShortest path (Lowest Latency Routing) from node " << start << " (" << nodeNames[start] << "):\n";
        
        while (!pq.empty()) {
            // Extract the minimum distance vertex from the priority queue
            int u = pq.top().second;
            pq.pop();

        // Print the calculated shortest distances formatted to match the assignment sample
        for (int i = 0; i < adjList.size(); ++i) {
            cout << start << " -> " << i << " : " << dist[i] << "\n";
        }
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
   
