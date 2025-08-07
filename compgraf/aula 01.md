
### datas

23/10 - prova
após isso, 3 dias de seminários seguidos

média = (P + S +T)/3

---
### linha do tempo

1886 - início do CRT (Cathode Ray Tube)

1929 - fotograma (24 FPS)

1927 - ENIAC dos cria

1938 - CRT colorido

1947 - invenção do transistor

1950 - Laposky cria obras de arte digitais

1955 - Sage (monitoramento aéreo)

 1959 - surge o termo Computer Graphics

1960 - primeiro computador comercial

 1961 - primeiro jogo com comp graf

1963 - sistema de desenho (Sutherland)

1963 - primeiro filme feito por computador (Zajac)

1964 - Boeing cria modelo computacional de um corpo humano

1966 - Odissey (primeiro video game)

1966 - MAGI (primeira empresa de produção computacional de animações e efeitos especiais)

1970 - algorimos para CG

1971 - tomografia computadorizada

1972 - Atari 

1975 - reconhecimento da CG como área (SIGGRAPH)

1977 - nova categoria no Oscar de efeitos especiais

1992 - padronização de pacotes gráficos (OpenGL)

---
### computação gráfica (hoje)

é a interseção de três áreas:
- sintese de imagens
- processamento de imagens
- análise de imagens

### OpenGL - Graphics LIbrary

a interface entre o software e o hardware gráfico é feita através de procedimentos e funções 

### sistemas e dispositivos gráficos

- vetoriais
	- x, y e z
	- noção de profundidade
	- ex.: blender, impressora 3D
	
- matriciais
	- somente x e y
	- ex.: paint

### tecnologia CRT

técnica da esquerda para direita e de cima para baixo
- assim, poderia se reduzir pela metade o FPS e o olho humano não perceberia a diferença

o pixel: medidada admensional (sem tamanho físico definido, é definido pela resolução do dispositivo) -> isto afeta a qualidade da imagem

**qualidade da imagem**
influenciada pelo dot pitch, o qual, para manter a qualidade, deve ser no máximo de 0.28mm

### LCD (Liquid Crystal Display)

### Plasma

### LED

---
### Bibliografia

Computação Gráfica: Teoria e Prática

---

### Modelos de Cores

**colorimetria**
quantificação das cores e padronização de como enxergamos

**sistema CIE**

**cor**
modelo XYZ, desenvolvido pela CIE
resposta espectral

**diagrama de cromaticidade**
gama de cores "Gamut"

*resumindo*

distinção entre cores, considera:
- matiz: cor pura (comprimento de onda dominante)
- saturação: quantidade em que a cor pura é diluida na luz branca (pureza)
- cromaticidade: matiz e saturação tomadas juntas

percepção de cores

tipos
- aditivos (luz)
	- misturada pela projeção da luz
	- exemplo: RGB, XYZ
	- aplicação: monitore, projetores e TVs
	
- subtrativo (luz)
	- misturada pela absorção da luz
	- exemplo: CMY e CMYK
	- aplicação: impressão e tinta


### Processamento de Imagens Coloridas

**transformaçõa de intensidades para cor**
técninca atinge uma escala mais ampla de realce

---

### OpenGL

#### morfologia das funções

### definições dos comandos

*glClear()*
- inicializa as combinações de matrizes para escrita com cores
- os componentes RGB são geralmente referenciados como color buffer ou pixel buffer

*glutSwapBuffers()*
- faz com que qualquer comando não executado seja executado

*glClearColor()*
- inicializa a cor de fundo
- parametro aplha define coisas como transparencia e tals (deixa "frufru")

*glutMainLoop()*
