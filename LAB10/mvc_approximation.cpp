#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, list<int>> adj;
unordered_map<int, bool> visited;

// cteate a adj list
void addEdge(int u, int v, bool direction) {

  // creation a edge from u to v
  adj[u].push_back(v);

  if (direction == 0) {
    adj[v].push_back(u);
  }
}

void printadjacencylist(unordered_map<int, list<int>> &adj, int n) {
  for (int i = 0; i < n; i++) {
    cout << i << "->";
    for (int &x : adj[i]) {
      cout << x << " ";
    }
    cout << endl;
  }
}

void printVertexCover(int n, unordered_map<bool> &visited,
                      unordered_map<int, list<int>> &adj) {
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }

  list<int>::iterator i;
  for (int u = 0; u < n; u++) {
    // An edge is only picked when both visited[u] and visited[v]
    // are false
    if (visited[u] == false) {
      // Go through all adjacents of u and pick the first not
      // yet visited vertex (We are basically picking an edge
      // (u, v) from remaining edges.
      for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i;
        if (visited[v] == false) {
          // Add the vertices (u, v) to the result set.
          // We make the vertex u and v visited so that
          // all edges from/to them would be ignored
          visited[v] = true;
          visited[u] = true;
          break;
        }
      }
    }
  }

  // Print the vertex cover
  for (int i = 0; i < V; i++)
    if (visited[i])
      cout << i << " ";
}

int main() {
  int n;
  cout << "Enter a number of Nodes :" << endl;
  cin >> n;

  int m;
  cout << "Enter a number of Edges :" << endl;
  cin >> m;

  // graph g;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    // prepare the adj list
    addEdge(u, v, 0);
  }

  // g.printVertexCover();

  // printadjacencylist(adj, n);

  printVertexCover(n, visited, adj);

  return 0;
}
