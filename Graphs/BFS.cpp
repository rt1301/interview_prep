// BFS traversal for graph
// Time Complexity = O(V+E)
#include<bits/stdc++.h>
using namespace std;
// This class represents a directed graph using
// adjacency list representation
class Graph{
    int V; //no. of vertices
    // Pointer to an array containing adjacency
    // lists
    list<int>*adj;

    public:
    Graph(int V); // Constructor
    // function to add an edge between two vertices
    void addEdge(int v, int w);
    // function to find all the vertex from source s
    void BFS(int s);
};
Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::BFS(int s){
    // initially mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i] = false;
    // create a new queue for BFS
    list<int>queue;

    // mark the first vertex as visited
    // and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        // dequeue a vertex from queue and print it
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();
        // get all adjacent vertices of dequeued 
        // vertex s. If the adjacent vertex is not visited
        // then mark it visited and enqueue it
        for(auto i=adj[s].begin();i!=adj[s].end();i++){
            if(!visited[*i]){
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}
int main(){
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}