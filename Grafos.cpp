#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number 
int n, m;
vector<int> adj[N];
vector<pair<int, int>> adjw[N];

int main() {
 cin >> n >> m;
 for(int i = 0; i < m; i++) {
     int a, b, c;
     cin >> a >> b >> c;
     adj[a].push_back(b);
     adj[b].push_back(a);
     adjw[a].push_back({b, c});
     adjw[b].push_back({a, c});
 }
}
