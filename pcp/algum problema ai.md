
ele tem 5 versões

### comando *await*

utilizado para abstrair condições de exclusão mútuae sincronismo, ele não existe de fato em alguma linguagem de programação, é apenas uma abstração.
em sua forma mais simples temos:

`<S;>` => indica que S é executado de modo exclusivo

temos também a forma que indica sincronismo simples:

`<await(B);>`=> indica que o próximo comando será executado quando B for verdade 

temos finalmente, a combinação, dada por:

`<await(B) S;>`-

### *múltiplos leitores e escritores*

```pseudo
int nr = 0;
sem rw = 1;

process Writer[j=1 to N] {
	while (true) {
		...
		
		P(rw);
		escreve;
		V(rw);
	}
}

process Reader [i=1 to M] {
	while (true) {
		...
		
		<	nr = nr + 1;
			if (nr == 1) P(rw); >
		leitura;
		<   nr = nr - 1;
		    if (nr == 0) V(rw); >	
	}
}
```

como await é uma abstração, precisamos implementá-lo de alguma forma, neste caso usaremos semáforos

```c
int nr = 0;
sem rw = 1;
sem mutex = 1;

process Writer[j=1 to N] {
	while (true) {
		...
		
		P(rw);
		escreve;
		V(rw);
	}
}

process Reader [i=1 to M] {
	while (true) {
		...
		
		P(mutex);
		nr = nr + 1;
		if (nr == 1) P(rw);
		V(mutex);
		
		leitura;
		
		P(mutex)
		nr = nr - 1;
		if (nr == 0) V(rw);
		V(mutex);
	}
}
```

esta solução possui o problema de **starvation** (writer fica de xereca kk)

