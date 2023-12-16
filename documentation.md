# SetsC

## Estratégia utilizada

Este código foi desenvolvido com o propósito de oferecer um conjunto de funções práticas para lidar com operações matemáticas em conjuntos. Em essência, o foco principal deste trabalho é executar operações entre conjuntos, cada uma representada por uma função específica no código.

Cada operação realizada no código envolve a relação entre dois conjuntos, A e B, cujo resultado é armazenado no conjunto C. A representação dos conjuntos é feita por meio de arrays com alocação dinâmica de tamanho, uma abordagem que oferece mais flexibilidade em comparação com a alocação fixa. Isso não apenas otimiza o uso de memória, mas também permite lidar com conjuntos de tamanho variável, dentro das limitações de memória do sistema.

O conjunto C é representado por um ponteiro que aponta para uma área de memória alocada dinamicamente, de acordo com a operação realizada. As funções são construídas com base nas fórmulas matemáticas de conjuntos, mantendo uma lógica sólida e consistente.

Cada função retorna um array contendo o conjunto resultante. Essa abordagem permite não apenas a visualização dos resultados, mas também a manipulação efetiva dos conjuntos.

Uma escolha feita no código foi não utilizar a função exit() e, em vez disso, retornar códigos de erro. Isso foi pensado para evitar possíveis interrupções inesperadas que poderiam afetar a execução do programa. Ao lidar com retornos de códigos de erro, é possível gerenciar exceções de forma mais controlada, garantindo a integridade do programa mesmo em situações adversas. Além disso, a liberação de qualquer memória alocada durante os cálculos é feita imediatamente, mesmo em caso de falha, minimizando possíveis vazamentos de memória durante o uso das funções desta biblioteca.

## Descrição do algoritmo e das estruturas utilizadas

Agora vamos explicar cada parte do código individualmente. 

### Bibliotecas utilizadas

Foram utilizadas somente as bibliotecas padrão do C. A biblioteca stdio.h contém as funções de entrada e saída de dados para o usuário. A biblioteca stdlib.h contém as funções de gerenciamento de memória que são utilizadas para a alocação dinâmica do tamanho dos arrays que representam conjuntos. 

### Funções

Explicando as funções e algoritmos desenvolvidos. 

#### verificaRepeticao:

A função `verificaRepeticao` realiza a verificação de duplicatas em um array de inteiros até um ponto específico. Essa funcionalidade é crucial para garantir a integridade dos dados, evitando a inclusão de valores duplicados. Ao receber um array, um índice máximo e um valor a ser verificado, ela percorre os elementos até a posição indicada, retornando -1 se uma repetição for identificada e 0 caso contrário.

Por meio de um loop `for`, a função percorre os elementos do array até a posição `i`, comparando cada item com o valor de elemento. Caso haja correspondência, a função retorna -1, indicando a presença de repetição. No entanto, se nenhum valor duplicado for identificado, a função retorna 0, sinalizando a ausência de repetições até a posição especificada

#### intersecao:

A função `intersecao` realiza a identificação dos elementos comuns entre dois conjuntos de inteiros representados pelos arrays `a` e `b`. Ao receber esses arrays juntamente com os tamanhos dos conjuntos `cardA` e `cardB`, um ponteiro para um ponteiro de array `c` e um inteiro `cardC`, a função executa sua operação.

Inicialmente, o processo inicia definindo `*cardC` como 0 para acompanhar a quantidade de elementos compartilhados. Dois loops for aninhados são usados para percorrer os elementos dos conjuntos `a` e `b`, buscando por elementos idênticos. Cada vez que um par de elementos iguais é encontrado, `*cardC` é incrementado, indicando a existência de um elemento comum.

Se `*cardC` for maior que zero, sinaliza-se a presença de ao menos um elemento compartilhado. Neste caso, a função aloca dinamicamente memória para o conjunto de interseção `c` utilizando `malloc`. Falhas na alocação de memória resultam em uma mensagem de erro e retorno de -1.

Após uma alocação bem-sucedida, um novo conjunto é construído novamente por meio de loops aninhados. Os elementos presentes tanto em `a` quanto em `b` são copiados para o conjunto `c`, controlados pelo contador `contC`. Posteriormente, o conjunto resultante é ordenado utilizando a função `bubbleSort`, garantindo a ordenação crescente dos elementos.

#### diferenca:

A função `diferenca` calcula a diferença entre dois conjuntos de inteiros, `A - B`. Ao receber os arrays `a` e `b`, juntamente com os tamanhos dos conjuntos `cardA` e `cardB`, um ponteiro para um ponteiro de array `c` e um inteiro `cardC` para armazenar o resultado, a função executa o seguinte processo:

Começando com a inicialização de `*cardC` como 0, a função percorre os elementos do conjunto a usando loops `for`. Para cada elemento em `a`, verifica-se se o elemento está presente no conjunto `b`. Se o elemento de `a` não estiver em `b`, é incluído no conjunto diferença. A contagem de elementos no conjunto diferença é mantida por meio do incremento de `*cardC`.

Quando `*cardC` é maior que 0, a função aloca dinamicamente memória para o conjunto diferença `c` usando `malloc`. Caso ocorra falha na alocação, a função exibe uma mensagem de erro e retorna -1.

Após a alocação bem-sucedida, a função cria um novo conjunto diferença, copiando os elementos de `a` que não estão presentes em `b` por meio de loops aninhados. Em seguida, o conjunto resultante é ordenado usando a função `bubbleSort` para garantir que os elementos estejam em ordem crescente.

#### soma:

A função `soma` gera um conjunto que representa a união de dois conjuntos de inteiros, ou seja, a soma dos conjuntos `a` e `b`, formando um novo conjunto que inclui todos os elementos de ambos os conjuntos. Recebendo os arrays `a` e `b`, os tamanhos dos conjuntos `cardA` e `cardB`, um ponteiro para um ponteiro de array `c`, e um inteiro `cardC` para armazenar o resultado, a função executa o seguinte processo:

Iniciando com a inicialização de `contC` para 0, a função calcula `*cardC` como a soma dos tamanhos de `cardA` e `cardB`, representando o tamanho total do conjunto resultante da união. Em seguida, a função aloca dinamicamente memória para o conjunto de união `c` usando `malloc`. Em caso de falha na alocação, a função exibe uma mensagem de erro e retorna -1.

Após uma alocação de memória bem-sucedida, a função inicia a construção do conjunto de união. Ela percorre o conjunto `a` utilizando um loop `for`, copiando cada elemento para o conjunto de união `c` e incrementando `contC`. Em seguida, percorre o conjunto `b` de maneira similar, copiando cada elemento para o conjunto `c` e novamente incrementando `contC`.

O conjunto resultante, agora contendo todos os elementos de `a` e `b`, é ordenado utilizando a função `bubbleSort` para assegurar que os elementos estejam em ordem crescente. Essa ordenação é realizada para organizar adequadamente os elementos no conjunto resultante.

#### uniao:

A função `uniao` cria um conjunto que representa a união entre dois conjuntos de inteiros `a` e `b`, seguindo a fórmula `A + (B - (A ∩ B))`. Para executar essa operação, a função faz uso de outras funções auxiliares, como `intersecao`, `diferenca` e `soma`. Recebe os arrays `a` e `b`, juntamente com seus tamanhos `cardA` e `cardB`, um ponteiro para um ponteiro de array `c` e um inteiro `cardC` que armazenarão o resultado da união.

Inicialmente, a função cria ponteiros temporários `iAB` e `dBIAB` para armazenar, respectivamente, os resultados da interseção e diferença entre os conjuntos `a` e `b`, de acordo com a fórmula. Calcula os tamanhos `cardIAB` e `cardDBIAB` utilizando as funções auxiliares `intersecao` e `diferenca`. Se alguma dessas operações falhar (retorna -1), a função libera a memória alocada até esse ponto, se necessário, e retorna -1 para indicar erro.

Quando as operações de interseção e diferença são bem-sucedidas, a função continua realizando a soma entre o conjunto a e o resultado da diferença `B - (A ∩ B)`, utilizando a função auxiliar `soma`. Se a operação de soma falhar (retorna -1), a função novamente libera a memória alocada até esse ponto e retorna -1.

Após a operação de soma bem-sucedida, a função libera a memória alocada para os conjuntos intermediários `iAB` e `dBIAB`, uma vez que esses resultados não são mais necessários. Em seguida, o conjunto resultante da união é ordenado utilizando a função `bubbleSort` para garantir que os elementos estejam em ordem crescente.

#### diferencaSimetrica:

A função `diferencaSimetrica` calcula a diferença simétrica entre dois conjuntos de inteiros `a` e `b`, seguindo a fórmula `(A - B) ∪ (B - A)`. Para executar essa operação, a função faz uso de outras funções auxiliares: `diferenca` e `uniao`. Recebe os arrays `a` e `b`, juntamente com seus tamanhos `cardA` e `cardB`, um ponteiro para um ponteiro de array `c` e um inteiro `cardC` que armazenará o resultado da diferença simétrica.

Iniciando o processo, a função cria ponteiros temporários `dAB` e `dBA` para armazenar os resultados das diferenças `A - B` e `B - A`, conforme a fórmula. Calcula os tamanhos `cardDAB` e `cardDBA` usando a função auxiliar diferenca. Se alguma dessas operações falhar (retorna -1), a função libera a memória alocada até esse ponto, se necessário, e retorna -1 indicando erro.

Quando as operações de diferença são bem-sucedidas, a função avança para realizar a união entre os resultados das diferenças `A - B` e `B - A`, utilizando a função auxiliar `uniao`. Se a operação de união falhar (retorna -1), a função novamente libera a memória alocada até esse ponto e retorna -1.

Após a operação de união bem-sucedida, a função libera a memória alocada para os conjuntos intermediários `dAB` e `dBA`, uma vez que esses resultados não são mais necessários. Em seguida, o conjunto resultante da diferença simétrica é ordenado utilizando a função `bubbleSort` para garantir que os elementos estejam em ordem crescente.

#### produtoCartesiano:

A função `produtoCartesiano` calcula o produto cartesiano entre dois conjuntos de inteiros `a` e `b`. O produto cartesiano consiste em um conjunto que contém todos os pares ordenados possíveis, onde o primeiro elemento pertence a um conjunto e o segundo elemento pertence ao outro conjunto.

Ao receber os arrays `a` e `b`, juntamente com seus tamanhos `cardA` e `cardB`, um ponteiro para um ponteiro de array `c` e um inteiro `cardC` que armazenará o resultado do produto cartesiano, a função inicia seu processo. Inicialmente, calcula o tamanho necessário para o conjunto resultante do produto cartesiano, que é `(cardA * cardB) * 2`, pois cada par ordenado ocupa duas posições no array resultante.

Em seguida, a função aloca dinamicamente memória para o conjunto de produto cartesiano utilizando `malloc`. Se a alocação falhar, é exibida uma mensagem de erro e a função retorna -1.

Após uma alocação bem-sucedida, a função utiliza dois loops aninhados para percorrer todas as combinações possíveis de elementos entre os conjuntos `a` e `b`. Para cada par de elementos, a função copia os elementos correspondentes para o conjunto de produto cartesiano `c`, incrementando `cont` em duas unidades a cada iteração para acomodar os pares ordenados.

Uma vez preenchido o conjunto resultante, é realizado um processo de ordenação utilizando a função `bubbleSort` para garantir que os elementos estejam em ordem crescente, organizando corretamente os pares ordenados no conjunto resultante.
