#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number of nodes

int n, m;
vector<int> adj[N];
int vis[N];

void dfs(int u) {
   vis[u] = 1;
   for (int v : adj[u]){
       if (!vis[v]) {
           dfs(v);
       }
   }
}

int main() {
 cin >> n >> m;
 for(int i = 0; i < m; i++) {
     int a, b;
     cin >> a >> b;
     adj[a].push_back(b);
     adj[b].push_back(a);
 }
}


