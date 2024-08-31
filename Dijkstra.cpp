#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number 
vector<int> adj[N]; // Lista de adjacências
int dist[N]; // Vetor de distâncias

void dijkstra(int s) {
    // Fila de prioridade: (distância negativa, vértice)
    priority_queue<pair<int, int>> pq;

    // Inicializa todas as distâncias com um valor grande (próximo de infinito)
    memset(dist, 63, sizeof(dist));
    dist[s] = 0; // A distância do vértice inicial para ele mesmo é 0
    pq.push({0, s}); // Adiciona o vértice inicial à fila de prioridade

    // Enquanto houver vértices na fila de prioridade
    while (!pq.empty()) {
        int ud = -pq.top().first; // Distância do vértice atual (negativa para fila de prioridade)
        int u = pq.top().second; // Vértice atual
        pq.pop(); // Remove o vértice da fila

        // Se a distância atual no vetor dist é menor, continue
        if (dist[u] < ud) continue;

        // Percorre todos os vizinhos do vértice atual
        for (auto x : adj[u]) {
            int v = x.first; // Vértice destino
            int w = x.second; // Peso da aresta

            // Se encontrar um caminho mais curto para o vértice v
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w; // Atualiza a distância
                pq.push({-dist[v], v}); // Adiciona v à fila de prioridade com distância negativa
            }
        }
    }
}


//Funcao para recuperar o caminho
int par[N];
vector<int> recover(int u) {
    vector<int> path;
    stack<int> reversePath; // Usamos uma pilha para inverter o caminho

    // Reconstrói o caminho a partir do vértice u até o vértice de origem
    while (u != par[u]) {
        reversePath.push(u);
        u = par[u];
    }
    reversePath.push(u); // Adiciona o vértice de origem à pilha

    // Transferindo a pilha invertida para o vetor de caminho
    while (!reversePath.empty()) {
        path.push_back(reversePath.top());
        reversePath.pop();
    }

    return path;
}
