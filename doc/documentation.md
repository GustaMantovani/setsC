# SetsC

Esta documentação explica como a calculadora de conjuntos funciona. Trata-se de uma calculadora capaz de realizar operações com conjuntos numéricos.

## Estratégia utilizada

O objetivo deste código é servir como uma biblioteca de funções úteis, funcionais e aplicáveis para trabalhar e realizar operações matemáticas de conjuntos. De forma geral, este trabalho é orientado a estas operações, onde cada uma é expressa, no código, por uma função. 

Assim, cada operação trabalha com uma relação entre o conjunto A e o conjunto B, com o resultado sendo sempre armazenado no conjunto C.

Os conjuntos, no código, são expressos por arrays com tamanho dinamicamente alocado, esta é uma abordagem superior à alocação fixa, pois evita usos desnecessários de memória, além de aumentar a flexibilidade do programa, sendo apto para trabalhar com tantos elementos quanto a memória permitir.

O conjunto C é expresso e referenciado por um ponteiro para uma região de memória com tamanho dinamicamente alocado de acordo com a operação que se deseja realizar. Após isso, o conjunto C é exibido na tela. Além disso, as  funções do código baseiam-se nas fórmulas matemáticas de conjuntos, dessa forma, têm a mesma fundamentação lógica. 

O objetivo de se retornar um array como resposta ao invés de somente exibir os resultados em tempo de execução vai além da mera exibição imediata dos resultados. Essa abordagem visa possibilitar a integração das funções em projetos que necessitem realizar operações complexas envolvendo conjuntos de dados, onde apenas exibir resultados na tela não é suficiente. Ao fornecer o resultado como um array, as funções se tornam mais versáteis e adaptáveis, permitindo que sejam utilizadas em contextos diversos dentro de um projeto.

Seguindo essa ideia, a escolha de não implementar a função exit() e optar por retornar códigos de erro evita saídas inesperadas que poderiam impactar negativamente a execução do programa como um todo. E, ao adotar retornos de códigos de erro, as exceções podem ser adequadamente tratadas, contribuindo para a manutenção da integridade do programa, mesmo em situações adversas. Além disso, qualquer memória alocada pelas funções durante os cálculos é liberada o mais rápido possível, até mesmo em casos de falha a memória alocada até o momento da interrupção é liberada, dessa forma não há risco de vazamento de memória ao implementar-se as funções dessa biblioteca.

## Descrição do algoritmo e das estruturas utilizadas

Agora vamos explicar cada parte do código individualmente. 

### Bibliotecas utilizadas

Foram utilizadas somente as bibliotecas padrão do C. A biblioteca stdio.h contém as funções de entrada e saída de dados para o usuário. A biblioteca stdlib.h contém as funções de gerenciamento de memória que são utilizadas para a alocação dinâmica do tamanho dos arrays que representam conjuntos. 

### Funções

Explicando as funções e algoritmos desenvolvidos. 

#### verificaRepeticao:


A função verificaRepeticao desempenha um papel crucial ao verificar a presença de repetições em um array de inteiros até uma determinada posição. Este processo é fundamental para garantir a integridade dos dados e evitar duplicações indesejadas. Ao receber um ponteiro para o início do array vet, um inteiro i indicando a posição máxima de verificação e um valor inteiro elemento a ser verificado, a função entra em ação. Através de um loop for, a função percorre os elementos do array até a posição i, comparando cada elemento com o valor de elemento. Caso uma correspondência seja encontrada, a função retorna -1, indicando a presença de repetição. No entanto, se nenhum elemento repetido for encontrado, a função retorna 0, indicando ausência de repetições até a posição especificada. Essa função é especialmente útil ao garantir que novos elementos a serem inseridos no array não sejam duplicados, evitando assim inconvenientes e inconsistências nos dados armazenados.

#### intersecao:

A função intersecao é responsável por identificar os elementos comuns presentes em dois conjuntos de inteiros representados pelos arrays a e b. Ao receber como entrada os arrays a e b, juntamente com os tamanhos dos conjuntos cardA e cardB, bem como um ponteiro para um ponteiro de array c e um inteiro cardC que armazenarão o resultado, a função inicia sua operação.

O processo começa inicializando *cardC para 0, preparando-se para contar quantos elementos são compartilhados pelos conjuntos. Dois loops for aninhados são usados para percorrer todos os pares possíveis de elementos entre os conjuntos a e b. Cada vez que um par de elementos iguais é encontrado, incrementa-se o valor de *cardC, indicando que um elemento em comum foi encontrado.

Caso *cardC seja maior que 0, isso significa que pelo menos um elemento comum foi encontrado nos conjuntos. Nesse caso, a função aloca memória dinamicamente para o conjunto de interseção c usando malloc. Se a alocação de memória falhar, a função emite uma mensagem de erro e retorna -1.

Após a alocação bem-sucedida, um novo conjunto é construído pela segunda vez por meio de loops aninhados. Os elementos que estão presentes em ambos os conjuntos a e b são copiados para o conjunto c, e o contador contC é usado para controlar a inserção correta no conjunto. Finalmente, o conjunto resultante é ordenado usando a função bubbleSort, para garantir que os elementos estejam em ordem crescente.

#### diferenca:

A função diferenca gera um conjunto que representa a diferença entre dois conjuntos de inteiros, especificamente a diferença A - B ou B - A. Ao receber os arrays a e b, juntamente com os tamanhos dos conjuntos cardA e cardB, um ponteiro para um ponteiro de array c e um inteiro cardC para armazenar o resultado, a função começa seu processo.

Iniciando com a inicialização de *cardC para 0, a função utiliza loops for para percorrer os elementos do conjunto a. Para cada elemento em a, ela verifica se o elemento está presente no conjunto b utilizando o valor val. Se o valor val permanecer 0 após a iteração pelo conjunto b, isso significa que o elemento de a não está presente em b e, portanto, ele deve fazer parte do conjunto de diferença.
Quando um elemento é identificado para o conjunto de diferença, incrementa-se o valor de *cardC para acompanhar o tamanho do conjunto resultante. Se *cardC for maior que 0, a função aloca memória dinamicamente para o conjunto de diferença c usando malloc. Se a alocação falhar, uma mensagem de erro é exibida e a função retorna -1.

Após a alocação de memória bem-sucedida, um novo conjunto é criado da mesma forma que na função intersecao, utilizando loops aninhados para copiar os elementos do conjunto a que não estão presentes no conjunto b. O conjunto resultante é, então, ordenado usando a função bubbleSort para garantir que os elementos estejam em ordem crescente.
soma:

A função soma gera um conjunto que representa a união de dois conjuntos de inteiros. Especificamente, ela calcula a soma de dois conjuntos a e b, formando um novo conjunto que contém todos os elementos de ambos os conjuntos. Ao receber os arrays a e b, os tamanhos dos conjuntos cardA e cardB, um ponteiro para um ponteiro de array c e um inteiro cardC que armazenará o resultado, a função inicia seu processo.

Começando pela inicialização de contC para 0, a função calcula *cardC como a soma dos tamanhos de cardA e cardB, representando o tamanho total do conjunto resultante da união. Em seguida, a função aloca memória dinamicamente para o conjunto de união c usando malloc. Se a alocação falhar, uma mensagem de erro é exibida e a função retorna -1.
Após a alocação de memória bem-sucedida, a função começa a construir o conjunto de união. Ela percorre o conjunto a usando um loop for, copiando cada elemento para o conjunto de união c e incrementando contC. Em seguida, percorre o conjunto b de maneira semelhante, copiando cada elemento para o conjunto c e novamente incrementando contC.

O conjunto resultante, agora contendo todos os elementos de a e b, é ordenado usando a função bubbleSort para garantir que os elementos estejam em ordem crescente.

#### uniao:

A função uniao cria um conjunto que representa a união entre dois conjuntos de inteiros a e b, seguindo a fórmula A + (B - (A ∩ B)). Para realizar essa operação, a função faz uso de outras funções auxiliares, como intersecao, diferenca e soma. Ela recebe os arrays a e b, juntamente com seus tamanhos cardA e cardB, um ponteiro para um ponteiro de array c e um inteiro cardC que armazenarão o resultado da união.

A função começa criando ponteiros temporários iAB e dBIAB para armazenar os resultados da interseção e diferença entre os conjuntos a e b de acordo com a fórmula. Ela calcula os tamanhos cardIAB e cardDBIAB usando as funções auxiliares intersecao e diferenca. Se qualquer uma dessas operações falhar (v == -1), a função libera a memória alocada até esse ponto, caso necessário, e retorna -1 para indicar erro.

Se as operações de interseção e diferença forem bem-sucedidas, a função prossegue para realizar a soma entre o conjunto a e o resultado da diferença B - (A ∩ B). Isso é feito usando a função auxiliar soma. Se a operação de soma falhar (v == -1), a função novamente libera a memória alocada até esse ponto e retorna -1.

Após a operação de soma bem-sucedida, a função libera a memória alocada para os conjuntos intermediários iAB e dBIAB, uma vez que esses resultados não são mais necessários. Em seguida, o conjunto resultante da união é ordenado usando a função bubbleSort para garantir que os elementos estejam em ordem crescente.

#### diferencaSimetrica:

A função diferencaSimetrica desempenha um papel crucial na criação de um conjunto que representa a diferença simétrica entre dois conjuntos de inteiros a e b, seguindo a fórmula (A - B) ∪ (B - A). Para realizar essa operação, a função utiliza outras funções auxiliares, incluindo diferenca e uniao. Ela recebe os arrays a e b, juntamente com seus tamanhos cardA e cardB, um ponteiro para um ponteiro de array c e um inteiro cardC que armazenará o resultado da diferença simétrica.

A função começa criando ponteiros temporários dAB e dBA para armazenar os resultados das diferenças A - B e B - A de acordo com a fórmula. Ela calcula os tamanhos cardDAB e cardDBA usando a função auxiliar diferenca. Se qualquer uma dessas operações falhar (v == -1), a função libera a memória alocada até esse ponto, caso necessário, e retorna -1 para indicar erro.

Se as operações de diferença forem bem-sucedidas, a função prossegue para realizar a união entre os resultados das diferenças A - B e B - A. Isso é feito usando a função auxiliar uniao. Se a operação de união falhar (v == -1), a função novamente libera a memória alocada até esse ponto e retorna -1.

Após a operação de união bem-sucedida, a função libera a memória alocada para os conjuntos intermediários dAB e dBA, uma vez que esses resultados não são mais necessários. Em seguida, o conjunto resultante da diferença simétrica é ordenado usando a função bubbleSort para garantir que os elementos estejam em ordem crescente.

#### produtoCartesiano:

A função produtoCartesiano desempenha um papel crucial na criação do produto cartesiano entre dois conjuntos de inteiros a e b. O produto cartesiano de dois conjuntos é um conjunto de todos os pares ordenados possíveis, onde o primeiro elemento pertence a um conjunto e o segundo elemento pertence ao outro conjunto. Ao receber os arrays a e b, juntamente com seus tamanhos cardA e cardB, um ponteiro para um ponteiro de array c e um inteiro cardC que armazenará o resultado do produto cartesiano, a função inicia seu processo.

A função calcula inicialmente o tamanho necessário para o conjunto resultante do produto cartesiano, que é (cardA * cardB) * 2, já que cada par ordenado ocupa duas posições no array resultante. Em seguida, ela aloca memória dinamicamente para o conjunto de produto cartesiano usando malloc. Se a alocação falhar, a função emite uma mensagem de erro e retorna -1.

Após a alocação de memória bem-sucedida, a função utiliza dois loops aninhados para percorrer todas as combinações possíveis de elementos entre os conjuntos a e b. Para cada par de elementos, a função copia os elementos correspondentes para o conjunto de produto cartesiano c, incrementando cont em duas unidades a cada iteração para acomodar os pares ordenados.

Após preencher o conjunto resultante, ele é ordenado usando a função bubbleSort para garantir que os elementos estejam em ordem crescente.
