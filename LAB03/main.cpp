#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

using namespace std;

bool bfs(int n, vector<vector<int>> &rGraph, int s, int t,
         vector<int> &parent) {
  vector<bool> visited(n, 0);

  queue<int> q;
  q.push(s);
  visited[s] = 1;
  parent[s] = -1;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v = 0; v < n; v++) {
      if (visited[v] == 0 && rGraph[u][v] > 0) {
        if (v == t) {
          parent[v] = u;
          return true;
        }
        q.push(v);
        visited[v] = 1;
        parent[v] = u;
      }
    }
  }
  return false;
}

int fordfulkerson(int n, vector<vector<int>> &Graph, int s, int t) {

  // create a residual graph
  vector<vector<int>> rGraph = Graph;

  vector<int> parent(n, -1);
  int max_flow = 0;
  while (bfs(n, rGraph, s, t, parent)) {
    int path_flow = INT_MAX;
    for (int v = t; v != s; v = parent[v]) {
      int u = parent[v];
      path_flow = min(path_flow, rGraph[u][v]);
    }

    for (int v = t; v != s; v = parent[v]) {
      int u = parent[v];
      rGraph[u][v] -= path_flow;
      rGraph[v][u] += path_flow;
    }

    max_flow += path_flow;
  }
  return max_flow;
}

int main() {
  int n = 6;

  vector<vector<int>> Graph = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0},
                               {0, 4, 0, 0, 14, 0},  {0, 0, 9, 0, 0, 20},
                               {0, 0, 0, 7, 0, 4},   {0, 0, 0, 0, 0, 0}};

  int s = 0, t = 5;
  int ans = fordfulkerson(n, Graph, s, t);
  // cout << s << " " << t << endl;

  cout << "max flow is :" << ans << endl;

  return 0;
}
