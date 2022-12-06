#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "mao.hpp"
#include "baralho.hpp"

TEST_CASE("Teste Criar mao") {
    CHECK(criar_mao (44, 0) == 7); //ver se tem 7 cartas na mao do jogaor1
    CHECK(criar_mao (20, 0) == 7); //ver se tem 7 cartas na mao do jogaor2
}

TEST_CASE("Teste retira a carta") {
    CHECK(retiracarta(5, c [4], 10, 44, 0, 7) == 4); //ver se a carta é da cor e número - testar a cor
    CHECK(retiracarta(5, c [7], 5, 12, 2, 9) == 4); //ver se a carta é da cor e número - testar o numero

}

TEST_CASE("Testar vazia") {
    CHECK (vazia(l = NULL) == 1); //ver se está vazia - se sim é o vencedor
    CHECK (vazia(l = 1) == 0); //ver se não está (com 2 carta) - segue o jogo normal
    CHECK (vazia(l = 2) == 0); //ver se não está (com 1 carta) - segue o jogo normal
    CHECK (vazia(l = 7) == 0); 
    CHECK (vazia(l = 15) == 0); 
}

TEST_CASE("Teste pop") {
    CHECK(pop(p = 0, c = 0 0) == 0); //pilha vazia retorna 0
    CHECK(pop(p = 0, c = 2 1) == 0); 
    CHECK(pop(p = 20, c = 3 0) == 1);//pilha não vazia remove carta do topo
    CHECK(pop(p = 45, c = 1 3) == 1);
}

TEST_CASE("Teste pilha vazia") {
    CHECK(pilha_vazia(p = 108) == 1); //passar por toda a lista - se tiver vazia = 1 - nullptr
    CHECK(pilha_vazia(p = 0) == 0); //passar por toda a lista - se não tiver vazia = 0 
}

TEST_CASE("Teste Altura da Pilha"){ //Imprime a quantidade de cartas e retorna o valor
    CHECK(altura_pilha(p = 53) == 54); // chamar cheia
    CHECK(altura_pilha(p = 10) == 11); // chamar vazia
    CHECK(altura_pilha(p = 0) == 1); // chamar vazia
}

TESTE_CASE("Testar tamanho") {
    CHECK(tamanho(0, 1) == 0); //- Teste 1: se tem 9 posição -> mostra que tem 9 cartas - Jogador 1
    CHECK(tamanho(0, 2) == 0); //- Teste 2:  se tem 9 posição -> mostra que tem 9 cartas - Jogador 2
    CHECK(tamanho(1, 1) == 1);
    CHECK(tamanho(1, 2) == 1);
    CHECK(tamanho(20, 2) == 20);
    CHECK(tamanho(7, 2) == 7);

}
