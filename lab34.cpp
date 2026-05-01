// COMSC-210 | Lab 34 | Tianyi Cao
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Edge {
    int src, des, weight;
};

class Graph {
public:

    vector<<Pair>> adjList;


    Graph(vector<Edge> const &edges, int N) {
        adjList.resize(N);
        
 
        for (auto &edge == edges) {
            int src = edge.src;
            int weight = edge.weight;
            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight)); 
        }
    }

   
