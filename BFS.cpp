#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number of nodes

int n, m;
vector<int> adj[N];
int vis[N];
queue<int> q;

void bfs (int s) {
   memset(vis, false, sizeof(vis));
   vis[s] = 1;
   q.push(s);

   while (!q.empty()) {
       int u = q.front(); q.pop();
       for (auto v : adj[u]) if (!vis[v]) {
           vis[v] = 1;
           q.push(v);
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



