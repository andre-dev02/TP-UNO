#ifndef BARALHO_H
#define BARALHO_H
 
#define MAX 108
 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
 
using namespace std;
 
class carta{
    public:
    int numero;
    int cor;
};
 
class pilha{  
    public:
    int topo;
    carta _carta[MAX];
};
 
void inicializa_pilha(pilha *p){ // inicializa a pilha
    p->topo = -1;
}
 
int pilha_vazia(pilha *p){ // Verificar se a pilha ta vazia
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}
 
int pilha_cheia(pilha *p){  // Verificar se a pilha ta cheia
    if(p->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}
 
int push(pilha *p, carta _carta){ // insere um novo elemento no inicio da pilha
    if(pilha_cheia(p)){
        return 0;
    }else{
        p->topo++;
        p->_carta[p->topo] = _carta;
        return 1;
    }
}
 
int pop(pilha *p, carta *_carta){ // Remove um elemento do inicio da pilha
    if(pilha_vazia(p)){
        return 0;
    }else{
        *_carta = p->_carta[p->topo];
        p->topo--;
        return 1;
    }
}
 
int altura_pilha(pilha *p){ // Imprime a quatidade de cartas e retorna esse valor
    cout << p->topo+1;
    return p->topo+1;
}
 
void carta_mesa (pilha *mesa, pilha *baralho){ // remove determinada carta do baralho e colocar na mesa
    inicializa_pilha(mesa);
    carta _carta;
    pop(baralho,&_carta);
    push(mesa,_carta);
}
 
void imprime_pilha(pilha p){
    carta _carta;
    cout << endl;
    while(!pilha_vazia(&p)){
        pop(&p,&_carta);            
        if (_carta.numero == 66) {
            cout << "Cor = " << _carta.cor << " Numero = Block" << endl;
        }
        if (_carta.numero == 82) {
            cout << "Cor = " << _carta.cor << " Numero = Reverse" << endl;
        }
        if (_carta.numero == 77) {
            cout << "Cor = " << _carta.cor << " Numero = +4" << endl;
        }
        if (_carta.numero == 43) {
            cout << "Cor = " << _carta.cor << " Numero = +2" << endl;
        }
        if (_carta.numero == 84 ){
            cout << "Cor = " << _carta.cor << " Numero = Troca de cor" << endl;
        }
        if (_carta.numero < 10) {
            cout << "Cor = " << _carta.cor << " Numero = " << _carta.numero << endl;
        }
        }
 
    }
                     
bool Existe ( int valores[] , int tam , int valor ){  // se a carta foi inserida no baralho vai retornar true, caso contrario retorna false
    for ( int i = 0 ; i < tam ; i++){
        if(valores[i] == valor )
        return true;    
    }  
    return false;
}  
   
void GerarNumerosAmarelo (int numerosAmarelo[], int quantNumeros , int limiteAmarelo ){    
    int vAmarelo;
 
    for ( int z = 0 ; z < quantNumeros ; z++){
        vAmarelo = rand() % limiteAmarelo; // gera numeros aleatorios entre 0 e 19, menos o numero 10
        while (Existe(numerosAmarelo,z,vAmarelo)) { // Verfica se tem a carta
            vAmarelo = rand() % limiteAmarelo;
        }
        if ( vAmarelo != 10) { // Se a carta for diferente de 10 ela é inserida
        numerosAmarelo[z] = vAmarelo;
    } else {
        z--; // Se for igual a 10 ele nao entra
    }
    }
}
 
//a funçao sera a mesma para as demais cores
 
void GerarNumerosAzul (int numerosAzul[], int quantNumeros , int limiteAzul ){
    int vAzul;
    for ( int x = 0 ; x < quantNumeros ; x++){
        vAzul = rand() % limiteAzul;
        while (Existe(numerosAzul,x,vAzul)) {
            vAzul = rand() % limiteAzul;
        }
        if ( vAzul != 10) {
        numerosAzul[x] = vAzul;
       
    } else {
        x--;
    }
    }
}
 
void GerarNumerosVermelho (int numerosVermelho[], int quantNumeros , int limiteVermelho ){
    int vVermelho;
 
    for ( int _carta = 0 ; _carta < quantNumeros ; _carta++){
        vVermelho = rand() % limiteVermelho;
        while (Existe(numerosVermelho,_carta,vVermelho)) {
            vVermelho = rand() % limiteVermelho;
        }
        if ( vVermelho != 10) {
        numerosVermelho[_carta] = vVermelho;
       
    } else {
        _carta--;
    }
    }
}
 
void GerarNumerosVerde (int numerosVerde[], int quantNumeros , int limiteVerde ){
    int vVerde;
 
    for ( int i = 0 ; i < quantNumeros ; i++){
        vVerde = rand() % limiteVerde;
        while (Existe(numerosVerde,i,vVerde)) {
            vVerde = rand() % limiteVerde;
        }
        if ( vVerde != 10) {
        numerosVerde[i] = vVerde;
       
    } else {
        i--;
    }
    }
}
 
int criar_baralho (pilha *baralho) {
    carta _carta;
    pilha amarelo, azul, vermelho, verde, preto,especiais; // cria as pilhas de cores
 
    inicializa_pilha(&amarelo);
    inicializa_pilha(&azul);
    inicializa_pilha(&vermelho);
    inicializa_pilha(&verde);
    inicializa_pilha(&preto);
    inicializa_pilha(&especiais);
    inicializa_pilha(baralho);
   
    srand(time(NULL));
 
 
/*  --------------------------------------------------------------Amarelo-------------------------------------------------------------- */
 
for ( int w = 0 ; w < 2 ; w++){ // Insere a carta de Bloqueio na pilha especial
    _carta.cor =0;
    _carta.numero = 66;
    push(&especiais, _carta);
}
 
for ( int w = 0 ; w < 2 ; w++){ // insere a carta de Reverse na pilha especial
    _carta.cor = 0;
    _carta.numero = 82;
    push(&especiais, _carta);
}
 
int numerosAmarelo[19];
 
GerarNumerosAmarelo(numerosAmarelo , 19 , 20);
_carta.cor = 0;
for ( int i = 0 ; i < 19 ; i++){
    if ( numerosAmarelo[i] > 10){ // Se a os numeros forem maiores que 10, subtrai 10 (como ta gerando valores aleatorios entre 0 e 19, sao 2 numeros de cada, pra cada cor, e nao teremos o numero 10 porque no UNO so tem uma carta 0 pra cada cor )
        numerosAmarelo[i] = numerosAmarelo[i] - 10;
        _carta.numero = numerosAmarelo[i];                
        push(&amarelo, _carta);
    } else {
        _carta.numero = numerosAmarelo[i]; // Se for menor que 10, entra normal
        push(&amarelo, _carta);
    }
}
    for ( int w = 0 ; w < 2 ; w++){ // Insere a carta +2 na pilha especial
        _carta.cor = 0;
        _carta.numero = 43;
        push(&especiais, _carta);
    }
//a funçao sera a mesma para as cores azul, vermelho e verde
 
/*  --------------------------------------------------------------Azul--------------------------------------------------------------    */  
 
for ( int w = 0 ; w < 2 ; w++){
    _carta.cor = 1;
    _carta.numero = 43;
    push(&especiais, _carta);
}
 
int numerosAzul[19];
GerarNumerosAzul(numerosAzul , 19 , 20);
_carta.cor = 1;
 
for ( int i = 0 ; i < 19 ; i++){
    if ( numerosAzul[i] > 10){
        numerosAzul[i] = numerosAzul[i] - 10;  
        _carta.numero = numerosAzul[i];
        push(&azul, _carta);
    } else {
        _carta.numero = numerosAzul[i];
        push(&azul, _carta);
    }
}
 
for ( int w = 0 ; w < 2 ; w++){
    _carta.cor = 1;
    _carta.numero = 66;
    push(&especiais, _carta);
}
for ( int w = 0 ; w < 2 ; w++){
    _carta.cor = 1;
    _carta.numero = 82;
    push(&especiais, _carta);
}
/*  --------------------------------------------------------------Vermelho--------------------------------------------------------------    */  
 
for ( int w = 0 ; w < 2 ; w++){
    _carta.cor = 2;
    _carta.numero = 66;
    push(&especiais, _carta);
}
    for ( int w = 0 ; w < 2 ; w++){
        _carta.cor = 2;
        _carta.numero = 82;
    push(&especiais, _carta);
}
int numerosVermelho[19];
    GerarNumerosVermelho(numerosVermelho , 19 , 20);
    _carta.cor = 2;
    for ( int i = 0 ; i < 19 ; i++){
        if ( numerosVermelho[i] > 10){
            numerosVermelho[i] = numerosVermelho[i] - 10;  
            _carta.numero = numerosVermelho[i];
            push(&vermelho, _carta);
        } else {
            _carta.numero = numerosVermelho[i];
            push(&vermelho, _carta);
        }
    }
    for ( int w = 0 ; w < 2 ; w++){
        _carta.cor = 2;
        _carta.numero = 43;
        push(&especiais, _carta);
    }
   
/*  --------------------------------------------------------------Verde--------------------------------------------------------------   */  
 
for ( int w = 0 ; w < 2 ; w++){
    _carta.cor = 3;
    _carta.numero = 43;
    push(&especiais, _carta);
}
 
int numerosVerde[19];
    GerarNumerosVerde(numerosVerde , 19 , 20);
    _carta.cor = 3;
    for ( int i = 0 ; i < 19 ; i++){
        if ( numerosVerde[i] > 10){
            numerosVerde[i] = numerosVerde[i] - 10;
            _carta.numero = numerosVerde[i];
            push(&verde, _carta);
        } else {
            _carta.numero = numerosVerde[i];
            push(&verde, _carta);
        }
    }
    for ( int w = 0 ; w < 2 ; w++){
        _carta.cor = 3;
        _carta.numero = 66;
        push(&especiais, _carta);
    }
    for ( int w = 0 ; w < 2 ; w++){
        _carta.cor = 3;
        _carta.numero = 82;
        push(&especiais, _carta);
    }
/*  --------------------------------------------------------------Preto--------------------------------------------------------------   */  
int contW = 4;
int contM = 4;
int auxp = 0;
 
for(int m=0 ; m<8 ; m++){  // insere as carta Troca de cor e +4 aleatoriamente entre 0 e 1
    auxp = rand()%2;  
    if(auxp == 0){
        if(contW > 0  ){
            _carta.cor = 4;
            _carta.numero = 84; // carta Troca de cor => carta T  
            push(&preto,_carta);
            contW--;
        }
    else {
    m--;    
    }
}else if(auxp == 1){
        if(contM > 0){
            _carta.cor = 4;
            _carta.numero = 77;  // carta +4 => carta M
            push(&preto,_carta);
            contM--;
        } else {
        m--;    
        }
    }              
}
 
/*  ------------------------------------------------Insere a carta na pilha do Baralho------------------------------------------------  */  
 
srand(time(NULL));
int aux = 0;
for(int i=0 ; i<108;i++){
    aux = rand()%6;
    if(aux == 0){
        if(!pilha_vazia(&vermelho)){ //quando a pilha vermelha nao ta vazia, retira da pilha e adiciona aleatoriamente na pilha baralho
            pop(&vermelho,&_carta);
            push(baralho,_carta);
        }
        else {
        i--;
        }   //repetir para as demais cores e cartas especiais
    } else if(aux == 1){
        if(!pilha_vazia(&azul)){
            pop(&azul,&_carta);
            push(baralho,_carta);
        }
        else {
        i--;
        }
    } else if(aux == 2){
        if(!pilha_vazia(&amarelo)){
            pop(&amarelo,&_carta);
            push(baralho,_carta);
        }
        else {
        i--;
        }
    } else if(aux == 3){
        if(!pilha_vazia(&verde)){
            pop(&verde,&_carta);
            push(baralho,_carta);
        } else {
        i--;
        }
    }
    if(aux == 4){
        if(!pilha_vazia(&preto)){
            pop(&preto,&_carta);
               push(baralho,_carta);
           } else {
        i--;
        }
    }
    if(aux == 5){
        if(!pilha_vazia(&especiais)){
            pop(&especiais,&_carta); // obs.: guarda as especiais de todas as cores
            push(baralho,_carta);
        } else {
            i--;
        }
    }
}
}
 
#endif
 