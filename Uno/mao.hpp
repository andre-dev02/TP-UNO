#ifndef MAO_H
#define MAO_H
#include "baralho.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
 
using namespace std;
 
struct mao { //mao do jogador
    carta _carta;
    struct mao* prox;
};
typedef struct mao Mao;
 
Mao* inicializa (void){
 return NULL;
}
 
Mao* insere (Mao* l, carta _carta){ // insere a carta na mao "
 Mao* novo = (Mao*) malloc(sizeof(Mao));
 novo->_carta = _carta;
 novo->prox = l;
 return novo;
}
 
int vazia (Mao* l) {//verifica se a mao ta vazia, se sim o jogador vence a partida
 if (l == NULL) {
 return 1;
 }else
 return 0;
}
//No TP foi utilizado a tabela ASCII para ser usado os caracteres nas cartas especiais,
// exemplo de como foi a transformação dos caracteres (+, M, R, T, B)
 
void imprime (Mao* l) { //mostra as cartas do jogador
 Mao* p;
 for (p = l; p != NULL; p = p->prox) {
        if (p->_carta.numero == 66) {
            cout << "Cor = " << p->_carta.cor << " Numero = Block" << endl;
        }
        if (p->_carta.numero == 82) {
            cout << "Cor = " << p->_carta.cor << " Numero = Reverse" << endl;
        }
        if (p->_carta.numero == 77) {
            cout << "Cor = " << p->_carta.cor << " Numero = +4" << endl;
        }
        if (p->_carta.numero == 43) {
            cout << "Cor = " << p->_carta.cor << " Numero = +2" << endl;
        }
        if (p->_carta.numero == 84) {
            cout << "Cor = " << p->_carta.cor << " Numero = Troca de cor" << endl;  
        }
        if (p->_carta.numero < 10) {
            cout << "Cor = " << p->_carta.cor << " Numero = " << p->_carta.numero << endl;
        }
        }
}
 
int tamanho(Mao* l, int id) { // Conta e mosta na tela quantas cartas o jogador tem
    int cont=0;
   
    Mao* p;
    p = l;
   
    while (p!=NULL) {
        cont++;
        p=p->prox;
    }
    cout << "Numero de cartas: " << cont << endl << endl;
 
    if ( cont == 0 ){ // Se o jogador ganha
        system("cls");
       
        cout << setw(120) << "         UU     UU     NN     N      OOOO      |" << endl;
        cout << setw(120) << "         UU     UU     NN NN  N    OO    OO    |" << endl;
        cout << setw(120) << "         UU     UU     NN  NN N    OO    OO    |" << endl;
        cout << setw(120) << "           UUUUU       NN    NN      OOOO      o" << endl << endl << endl;
 
        cout << setw(120) << "                  Vitoria do jogador " << id << "!"<< endl;
        cout << setw(120) << "                        PARABENS!!!";
        exit(0); // Fecha o jogo
    }
    return cont;
}
 
 
Mao* acao(pilha *baralho, Mao *jogador,int numero){ // Condições para entra nas funções das cartas "+2" e "+4"
    carta _carta;
    if (numero == 43){
    for (int i = 0 ; i < 2 ; i++){
    pop(baralho,&_carta);
    jogador = insere(jogador ,_carta);
        }
    }
   
    if (numero == 77){
    for (int i = 0 ; i < 4 ; i++){
    pop(baralho,&_carta);
    jogador = insere(jogador ,_carta);
        }
    }
   
    return jogador;
}
 
Mao* retiracarta (Mao* jogador, carta _carta, pilha *mesa, pilha *baralho,int cor, int num) { // Ação para retirar a carta da mão do jogador
 
 Mao* ant = NULL;
 Mao* p = jogador;
 
 
 while (p != NULL && (p->_carta.numero != _carta.numero)  ) { //verificar a cor
 ant = p;
 p = p->prox;
}
 
 
while (p != NULL && (p->_carta.cor != _carta.cor ) ) { //verificar o numero        
 ant = p;
 p = p->prox;
}
 
 
        pop(mesa,&_carta); //verifica as cartas da mesa
 try{
    if(p->_carta.cor != _carta.cor && p->_carta.numero != _carta.numero ){  //se o jogador joga a carta errada recebe essa mensagem
        push(mesa,_carta);
        throw invalid_argument("");
        //cout << "Jogue corretamente a carta! Confira sua cor e numero para jogar" << endl << endl;
        pop(baralho,&_carta);
        jogador = insere(jogador,_carta);
        Sleep(3000);
     return jogador;
   
    } else { //se o jogador joga a carta correta deve ser inserida na pilha
    _carta.cor = cor;
    _carta.numero = num;
    push(mesa,_carta);
     
    }catch(invalid_argument &e){
     cout << "Jogue corretamente a carta! Confira sua cor e numero para jogar" << endl << endl;
    }
   

 if (p == NULL)
 return jogador; //retorna lista original e retira elemento
 if (ant == NULL) { // retira elemento do inicio
 jogador = p->prox;
 }
 else { // retira elemento do meio da lista
 ant->prox = p->prox;
 }
 free(p);
 return jogador;
}
}
//}
 
 
Mao* criar_mao(pilha *baralho, Mao *jogador) { //tira a carta do baralho e coloca na mao dos jogadores
    carta _carta;
    jogador = inicializa();
       
    for (int i = 0 ; i < 7 ; i++) {
        pop(baralho,&_carta);
        jogador = insere(jogador, _carta);
    }  
   
    return jogador;
}
 
 
 
#endif
