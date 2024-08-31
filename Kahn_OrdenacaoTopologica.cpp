#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7; // Maximum number

vector<int> adj[N];
int inc[N];
queue<int> q;
vector<int> tsort;
int n, e, a, b;

void topologicalSort(int n, int e) {

    // Inicializa a lista de adjacência e o contador de grau de entrada
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); // Adiciona aresta de 'a' para 'b'
        inc[b]++; // Incrementa o grau de entrada de 'b'
    }

    // Inicializa a fila com os nós que têm grau de entrada zero
    for (int i = 1; i <= n; ++i) {
        if (inc[i] == 0) {
            q.push(i);
        }
    }

    // Processa os nós na fila
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tsort.push_back(u); // Adiciona o nó 'u' à ordenação topológica
        for (int v : adj[u]) {
            // Reduz o grau de entrada de 'v' e adiciona 'v' à fila se seu grau de entrada se tornar zero
            if (--inc[v] == 0) {
                q.push(v);
            }
        }
    }

    // Verifica se foi possível realizar a ordenação topológica
    if (tsort.size() != n) {
        cout << "O grafo contém ciclos!" << endl;
        return;
    }

    // Imprime a ordenação topológica
    cout << "Ordenação Topológica:";
    for (int node : tsort) {
        cout << " " << node;
    }
    cout << endl;
}