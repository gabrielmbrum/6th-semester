
### intro

a sincronização que examinamos até então, é baseada em leitura e escrita em variáveis compartilhadas

consequentemente, para programas concorrentes, os programas eram executados com processadores compartilhanado memória

implica em mecanismo em cima de comunicação disponível pela rede, ao invés de compartilhar memória em si

para isso ser possível, os processos vão ser comunicar por mensagens

implica em IPC (Interprocess Comunication)
- troca de mensagens 
- RPC (Remote Procedure Call)
- Roudevous

----

### troca de mensagens

necessita da criação de um canal dedicado

a conversação no canal pode ser feita de forma síncrona/assíncrona

**sintaxe**
- declaraçaõ de canal
$$\text{chan nomecanal (lista de conteúdo)}$$
- lista de conteúdo tem um desses formatos
$$
\begin{array}{c}
(tipo_1 & id_1, & tipo_2 & id_2, & \dots, & tipo_n & id_n) \\
(tipo_1, & tipo_2  ,& \dots, & tipo_n)
\end{array}
$$


**exemplo**
```c
chan input(char);
chan result[n](int);
chan disk_access(int cylinder, int blockm, int count, char *buffer)
```

**sintaxe do uso do canal**
- empty(ch);
	- retorna true se não existe msg nmo canal ch
- receive ch(lista variáveis);
- send ch(list parâmetros); -> assíncrona
- sync_send ch(lista parâmetros); -> síncrona

**merge sort**

versão inicial:
```
chan in1(int), in2(int), out(int);

process Merge() 
{
	int v1, v2;
	receive in1(v1);
	receive in2(v2);
	
	while (!emtpy(v1) && !empty(v2))
	{
		if (v1 < v2)
		{
			send out(v1);
			receive in1(v1);
		} else {
			send out(v2);
			receive in2(v2);
		}
	}
	
	if (empty(in1))
	{
		while (!empty(in2))
		{
			send out(v2);
			receive in2(v2);
		}
	}
	
	if (empty(in2))
	{
		while (!empty(in1))
		{
			send out(v1);
			receive in1(v1);
		}
	}
}	
```
a verificação de canal vazio é inválida, pois o canal pode estar vazio por um momento (esperando chegar a mensagem) e o processo o consideraia finalizado, sem realmente ter sido finalizado

segunda versão:
```
chan in1(int), in2(int), out(int);

process Merge() 
{
	int v1, v2;
	receive in1(v1);
	receive in2(v2);
	
	while (v1 != EOS && v2 != EOS)
	{
		if (v1 < v2)
		{
			send out(v1);
			receive in1(v1);
		} else {
			send out(v2);
			receive in2(v2);
		}
	}
	
	if (v1 != EOS)
	{
		while (v2 != EOS)
		{
			send out(v2);
			receive in2(v2);
		}
	}
	
	if (v1 != EOS)
	{
		while (v2 != EOS)
		{
			send out(v1);
			receive in1(v1);
		}
	}
}	
```