#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number 
vector<int> adj[N]; // Lista de adjacências
int dist[N]; // Vetor de distâncias

void bfs (int s) {
   queue <int> q;
   memset(dist, 63, sizeof(dist));
   dist[s] = 0;
   q.push(s);

   while (!q.empty()) {
       int u = q.front(); q.pop();
       for (auto v : adj[u]){
           if(dist[v] > dist[u] + 1){
               dist[v] = dist[u] + 1;
               q.push(v);
           }
       }
   }
}

int main() {
    // Exemplo de como definir um grafo:
    int n = 6; // Número de vértices no grafo
    adj[1].push_back(2); // Adiciona uma aresta do vértice 1 ao vértice 2
    adj[1].push_back(3); // Adiciona uma aresta do vértice 1 ao vértice 3
    adj[2].push_back(4); // Adiciona uma aresta do vértice 2 ao vértice 4
    adj[3].push_back(5); // Adiciona uma aresta do vértice 3 ao vértice 5
    adj[4].push_back(5); // Adiciona uma aresta do vértice 4 ao vértice 5
    adj[5].push_back(6); // Adiciona uma aresta do vértice 5 ao vértice 6
    
    int start_node = 1; // Vértice inicial para iniciar a BFS

    // Chama a função BFS a partir do vértice inicial
    bfs(start_node);

    // Agora o vetor dist[] contém as distâncias mínimas a partir de start_node
    // Exemplo de impressão das distâncias mínimas:
    for (int i = 1; i <= n; ++i) {
        cout << "Distância mínima de " << start_node << " até " << i << " é " << dist[i] << "\n";
    }

    return 0;
}