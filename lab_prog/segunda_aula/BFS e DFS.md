# Busca em Largura (BFS)
- Algoritmo mais simples de busca em grafos
- Base para diversos outros algoritmos
- Dado um grafo $G = (V,E)$ e um vértice fonte $s$, a BFS explora sistematicamente o grafo e alcança todos os vértices alcançáveis a partir de $s$.
- O algoritmo expande a fronteira de vértices descobertos e não descobertos uniformemente ao longo da fronteira.
	- Descobre todos os vértices à uma distância $k$ de $s$ antes de descobrir qualquer vértice à distância $k+1$.
- A busca em largura distingue os vértices da seguinte forma:
	- vértices brancos: não descobertos
	- vértices cinza: descobertos e adjacentes à vértices brancos
	- vértices pretos: descobertos e adjacentes à vértices descobertos (cinza ou preto)
- A busca em largura constrói uma árvore em largura, que contém inicialmente apenas sua raiz, que é o vértice fonte $s$.
- Sempre que a busca descobre um vértice branco $v$ na varredura da lista de adjacências de um vértice $u$ já descoberto, $u$ e $v$ é descoberto, o vértice $v$ e a aresta $u,v$ é adicionada à árvore.
	- $u$ é o pai ou predecessor de $v$ na árvore em largura
	- Cada vértice da árvore tem no máximo um pai, já que cada vértice é descoberto uma única vez.

## Algoritmo em pseudocódigo
- Assume a representação em lista de adjacências
BFS(G)
	for cada vértice $u \in V[G]$
		u.cor = branco // estado
		u.d = $\infty$ // distancia
		u.$\pi$ = NIL  //predecessor
	for cada vértice $u \in V[G]$
		if u.cor == branco
			BFS-Visit(G, u)
BFS-Visit(G, u)
	s.cor = cinzento
	s.d = 0
	s.$\pi$ = NIL
	Q = $\varnothing$
	Enqueue(Q,s)
	While $Q \ne \varnothing$
		t = Dequeue(Q)
		for cada $v \in G.adj\[u]$
			if v.cor == branco
				v.cor == cinzento
				v.d = v.d+1
				v.$\pi$ = u
				Enqueue(Q, v)
		t.cor = preto

## Algoritmo em C++
```cpp
vector<int> bfs_visit(vector<vector<int>>& adj, int s, vector<bool> &visited) {
    vector<int> res;
    queue<int> q;  
    visited[s] = true;
    q.push(s);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        
        for (int x : adj[curr]) {
            if (!visited[x]) {
                visited[x] = true;
                q.push(x);
            }
        }
    }

    return res;
}

vector<vector<int>> bfs(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<vector<int>> res;

    for (int u = 0; u < V; u++) {
        if (!visited[u]) {
            res.push_back(bfs_visit(adj, u, visited));
        }
    }

    return res;
}

```
			
		
# Busca em Profundidade (DFS)
- Busca mais fundo no grafo, sempre que possível.
	- Explora arestas partindo do vértice $v$ mais recentemente descoberto que ainda possuem arestas inexploradas.
	- Quando todas as arestas de $v$ forem exploradas, ele regressa pelo caminho realizado para explorar todas as arestas do vértice a partir do qual $v$ foi descoberto.
	- Esse processo continua até termos todos os vértices que podem ser visitados a partir do vértice fonte inicial.
- A busca em profundidade distingue os seus vértices de forma igual à busca em profundidade.
	- Brancos: não descobertos
	- Cinzas: descobertos
	- Pretos: terminados (lista de adjacências totalmente examinada)

# Algoritmo em pseudocódigo
- Assume a representação em lista de adjacências
DFS(G)
	for cada vértice $u \in V[G]$
		u.cor = branco
		u.$\pi$ = NIL
	for cada vértice $u \in v[G]$
		if u.cor == branco
			DFS-Visit(G, u)

DFS-Visit(G, u)
	u.cor = cinzento
	for cada $v \in G.Adj[u]$
		if v.cor == branco 
			v.$\pi$ = u
			DFS-Visit(G,v)
	u.cor = preto

## Algoritmo em C++
```cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive function for DFS traversal
void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
{

    visited[s] = true;

    res.push_back(s);

    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i : adj[s])
        if (visited[i] == false)
            dfsRec(adj, visited, i, res);
}

// Main DFS function that initializes the visited array
// and call DFSRec
vector<int> DFS(vector<vector<int>> &adj)
{
    vector<bool> visited(adj.size(), false);
    vector<int> res;
    dfsRec(adj, visited, 0, res);
    return res;
}

// To add an edge in an undirected graph
void addEdge(vector<vector<int>> &adj, int s, int t)
{
    adj[s].push_back(t);
    adj[t].push_back(s);
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(V);

    // Add edges
    vector<vector<int>> edges = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    // Starting vertex for DFS
    vector<int> res = DFS(adj); // Perform DFS starting from the source verte 0;

    for (int i = 0; i < V; i++)
        cout << res[i] << " ";
}
```