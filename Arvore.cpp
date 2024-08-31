#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number 
int n, vis[N], sz[N];
vector<int> adj[N], cent;

void dfs (int u) {
   bool ok = true;
   sz[u] = 1;

   for (auto v : adj[u]) if (!vis[v]) {
       vis[v] = 1;
       dfs(v);
       sz[u] += sz[v];
       if (2*sz[v] > n) ok = false;
   }

   if (ok and 2*(n-sz[u]) <= n) cent.push_back(u);
}
