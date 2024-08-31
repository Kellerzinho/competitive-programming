#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number 

vector<pair<int, int>> adj[N]; // Lista de adjacências: adj[u] é uma lista de pares (vértice destino, peso da aresta)
int vis[N]; // Vetor de visitados

void primMST(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start}); // Inicia com o vértice inicial com peso zero

    int mst_cost = 0; // Variável para armazenar o custo total da MST

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (vis[u]) continue; // Se já visitou, continua
        vis[u] = 1; // Marca o vértice como visitado
        mst_cost += w; // Adiciona o peso da aresta à MST

        // Percorre todos os vizinhos não visitados
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;
            if (!vis[v]) {
                pq.push({weight, v});
            }
        }
    }

    cout << "Custo total da MST: " << mst_cost << "\n";
}