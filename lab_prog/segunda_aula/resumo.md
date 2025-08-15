## caminho em grafos/árvores

- DFS: primeiro em profundidade
- BFS: primeiro em largura

### quando usar?

solução próxima da raiz => BFS

solução da estrutura completa => DFS

## estudos 

estudar sobre BFS, DFS, bitset e .cpp

---
### DFS (Depth-first Search)

a partir de um vértice inicial, irá visitar todos seus vizinhos, até que não exista mais vizinhos visitados, quando chegar a isso, irá se fazer um back-track, voltando ao vértice anterior e continuar o algoritmo

![[grafo_exemplar.png]]

a ordem de visita é => 0, 1, 3, 4, 6, 2, 5, 7

tendo em vista que o 1 foi adicionado antes que o 2

```cpp
void dfs(int u) {
	visited[u] = true;
	cout << adj[u] << ' '
	for (auto v : adj[u]) {
		if(!visited[v]){
			dfs(v);
		}
	}
}
```

##### em pilha

fazendo uma implementação em pilha, a ordem de visita é diferente

```cpp
void dfsStack(int u) {
	stack<int> s;
	s.push(u);
	while(!s.empty()) {
		int v = s.top();
		
	}
}
```

https://www.youtube.com/watch?v=jYwonGls6RQ