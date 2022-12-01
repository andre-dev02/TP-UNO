- [TestePilhaVazia](#testepilhavazia)
- [TestePilhaCheia](#testepilhacheia)
- [TestePush](#testepush)
- [TestePop](#testepop)
- [TesteAlturaPilha](#testealturapilha)
- [TesteVazia](#testevazia)
- [TesteTamanho](#testetamanho)
- [Testeacao](#testeacao)
- [TesteRetiraCarta](#testeretiracarta)
- [TesteCriarMao](#testecriarmao)

## TestePilhaVazia

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "baralho.hpp"

TEST_CASE("Teste pilha vazia") {
    CHECK(pilha_vazia(p = 108) == 1); //passar por toda a lista - se tiver vazia = 1 - nullptr
    CHECK(pilha_vazia(p = 0) == 0); //passar por toda a lista - se não tiver vazia = 0 
}
```

## TestePilhaCheia

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "baralho.hpp"

TEST_CASE("Teste Pilha Cheia") {
    CHECK(pilha_cheia(p = 107) == 1); //se o (maximo - 1) for igual ao fim ou topo da pilha retornar verdadeiro 
    CHECK(pilha_cheia(p = 0) == 0); //se o (maximo - 1) for diferente ao fim ou topo da pilha retornar Falso 
    
}
```

## TestePush

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "baralho.hpp"

TEST_CASE("Teste push") {
    CHECK(push(p = 108, c = 2 2) == 0); // Pilha cheia retorna 0
    CHECK(push(p = 12, c = 0 3) == 1); // se não estiver cheia add nova carta
    CHECK(push(p = 0, c = 0 4) == 1);
    CHECK(push(p = 53, c = 1 2) == 1);
}
```

## TestePop

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "baralho.hpp"

TEST_CASE("Teste pop") {
    CHECK(pop(p = 0, c = 0 0) == 0); //pilha vazia retorna 0
    CHECK(pop(p = 0, c = 2 1) == 0); 
    CHECK(pop(p = 20, c = 3 0) == 1);//pilha não vazia remove carta do topo
    CHECK(pop(p = 45, c = 1 3) == 1);
}
```

## TesteAlturaPilha

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "baralho.hpp"

TEST_CASE("Teste Altura da Pilha"){ //Imprime a quantidade de cartas e retorna o valor
    CHECK(altura_pilha(p = 53) == 54); // chamar cheia
    CHECK(altura_pilha(p = 10) == 11); // chamar vazia
    CHECK(altura_pilha(p = 0) == 1); // chamar vazia
}
```

## TesteVazia

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "mao.hpp"

TESTE_CASE("Testar vazia") {
    CHECK (vazia(l = NULL) == 1); //ver se está vazia - se sim é o vencedor
    CHECK (vazia(l = 1) == 0); //ver se não está (com 2 carta) - segue o jogo normal
    CHECK (vazia(l = 2) == 0); //ver se não está (com 1 carta) - segue o jogo normal
    CHECK (vazia(l = 7) == 0); 
    CHECK (vazia(l = 15) == 0); 
}
```

## TesteTamanho

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "mao.hpp"

TESTE_CASE("Testar tamanho") {
    CHECK(tamanho(0, 1) == 0); //- Teste 1: se tem 9 posição -> mostra que tem 9 cartas - Jogador 1
    CHECK(tamanho(0, 2) == 0); //- Teste 2:  se tem 9 posição -> mostra que tem 9 cartas - Jogador 2
    CHECK(tamanho(1, 1) == 1);
    CHECK(tamanho(1, 2) == 1);
    CHECK(tamanho(20, 2) == 20);
    CHECK(tamanho(7, 2) == 7);

}
```

## TesteAcao

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "mao.hpp"

TEST_CASE("Teste acao") {
    CHECK(acao(12, 2, 43) == 4); //add 2 cartas na pilha - qual o primeiro int? Quantas cartas tem na pilha?
    CHECK(acao(16, 7, 43) == 9); //add 4 cartas na pilha 
    CHECK(acao(50, 6, 77) == 10); 
    CHECK(acao(50, 13, 77) == 17); //muda cor 
}
```

## TesteRetiraCarta

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "mao.hpp"

TEST_CASE("Teste retira a carta") {
    CHECK(retiracarta(5, c [4], 10, 44, 0, 7) == 4); //ver se a carta é da cor e número - testar a cor
    CHECK(retiracarta(5, c [7], 5, 12, 2, 9) == 4); //ver se a carta é da cor e número - testar o numero

}
```

## TesteCriarMao

#  

### 

Exemplo no cógido:  

Progama:
```
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "mao.hpp"

TEST_CASE("Teste Criar mao") {
    CHECK(criar_mao (44, 0) == 7); //ver se tem 7 cartas na mao do jogaor1
    CHECK(criar_mao (20, 0) == 7); //ver se tem 7 cartas na mao do jogaor2
}
```
