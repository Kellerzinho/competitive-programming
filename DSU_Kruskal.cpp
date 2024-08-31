#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number 
int parent[N], sz[N];

void initDSU(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        sz[u] += sz[v];
        parent[v] = u;
    }
}

int kruskal(vector<pair<int, pair<int, int>>>& edges, int n) {
    sort(edges.begin(), edges.end()); // Ordena as arestas por peso

    initDSU(n);

    int mst_cost = 0;
    for (auto& e : edges) {
        int u = e.second.first;
        int v = e.second.second;
        int weight = e.first;
        
        if (find(u) != find(v)) { // Se estão em componentes diferentes
            unite(u, v); // Une os componentes
            mst_cost += weight; // Adiciona o peso da aresta à MST
        }
    }

    return mst_cost;
}

int main() {
    int n = 4; // Número de vértices
    vector<pair<int, pair<int, int>>> edges; // Lista de arestas (peso, (u, v))

    // Exemplo de arestas (u, v, peso)
    edges.push_back({1, {1, 2}});
    edges.push_back({2, {1, 3}});
    edges.push_back({3, {1, 4}});
    edges.push_back({4, {2, 3}});
    edges.push_back({5, {2, 4}});
    edges.push_back({6, {3, 4}});

    int mst_cost = kruskal(edges, n);
    cout << "Custo da Minimum Spanning Tree (MST): " << mst_cost << endl;

    return 0;
}