Este arquivo contém todo o código usado em baralho.hpp destrinchado.

- [Classes](#classes)
- [Inicializa_pilha](#inicializa_pilha)
- [Pilha_vazia](#pilha_vazia)
- [Pilha_cheia](#pilha_cheia)
- [Push](#push)
- [Pop](#pop)
- [Altura_pilha](#altura_pilha)
- [Carta_mesa](#carta_mesa)
- [Imprime_pilha](#imprime_pilha)
- [Existe](#existe)
- [GerarNumerosAmarelo](#gerarnumerosamarelo)
- [GerarNumerosAzul](#gerarnumerosazul)
- [GerarNumerosVermelho](#gerarnumerosvermelho)
- [GerarNumerosVerde](#gerarnumerosverde)
- [Criar_baralho](#criar_baralho)

---

## Classes

As classes foram utilizadas para armazenar os dados das cartas e da pilha de cartas.

#
 
### Exemplo no cógido:

Programa:
```class carta{
    public:
    int numero;
    int cor;
};
 
class pilha{  
    public:
    int topo;
    carta c[MAX];
};
```

## Inicializa_pilha

Função que tem como base inicializar a pilha de cartas.

#
 
### Exemplo no cógido:

Programa:
```void inicializa_pilha(pilha *p){ // inicializa a pilha
    p->topo = -1;
}
```

## Pilha_vazia

Função responsável para verificar se a pilha está vazia ou não.

#
 
### Exemplo no cógido:

Progama:
```int pilha_vazia(pilha *p){ // Verificar se a pilha ta vazia
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}
```

## Pilha_cheia

Função responsável para verificar se a pilha está cheia ou não.

#
 
### Exemplo no cógido:

Progama:
```int pilha_cheia(pilha *p){  // Verificar se a pilha ta cheia
    if(p->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}
```

## Push

Função responsável para inserir no topo da pilha um novo elemento.

#
 
### Exemplo no cógido:

Progama:
```int push(pilha *p, carta c){ // insere um novo elemento no inicio da pilha
    if(pilha_cheia(p)){
        return 0;
    }else{
        p->topo++;
        p->c[p->topo] = c;
        return 1;
    }
}
```

## Pop

Função responsável para remover um elemento do início da pilha.

#
 
### Exemplo no cógido:

Progama: 
```int pop(pilha *p, carta *c){ // Remove um elemento do inicio da pilha
    if(pilha_vazia(p)){
        return 0;
    }else{
        *c = p->c[p->topo];
        p->topo--;
        return 1;
    }
}
```
## Altura_pilha

Função responsável para retornar o valor da altura da pilha.

#
 
### Exemplo no cógido:

Progama:
```int altura_pilha(pilha *p){ // Imprime a quatidade de cartas e retorna esse valor
    cout << p->topo+1;
    return p->topo+1;
}
```

## Carta_mesa

Função responsável para remover uma carta do baralho e colocar na mesa.

#
 
### Exemplo no cógido:

Progama:
```void carta_mesa (pilha *mesa, pilha *baralho){ // remove determinada carta do baralho e colocar na mesa
    inicializa_pilha(mesa);
    carta c;
    pop(baralho,&c);
    push(mesa,c);
}
```

## Imprime_pilha

Função responsável para imprimir a pilha de cartas.

#
 
### Exemplo no cógido:

Progama:
```void imprime_pilha(pilha p){
    carta c;
    cout << endl;
    while(!pilha_vazia(&p)){
        pop(&p,&c);            
        if (c.numero == 66) {
            cout << "Cor = " << c.cor << " Numero = Block" << endl;
        }
        if (c.numero == 82) {
            cout << "Cor = " << c.cor << " Numero = Reverse" << endl;
        }
        if (c.numero == 77) {
            cout << "Cor = " << c.cor << " Numero = +4" << endl;
        }
        if (c.numero == 43) {
            cout << "Cor = " << c.cor << " Numero = +2" << endl;
        }
        if (c.numero == 84 ){
            cout << "Cor = " << c.cor << " Numero = Troca de cor" << endl;
        }
        if (c.numero < 10) {
            cout << "Cor = " << c.cor << " Numero = " << c.numero << endl;
        }
        }
 
    }
```

## Existe

Função booleana responsável para informar se a carta foi ou não inserida no baralho.

#
 
### Exemplo no cógido:

Progama:
```bool Existe ( int valores[] , int tam , int valor ){  // se a carta foi inserida no baralho vai retornar true, caso contrario retorna false
    for ( int i = 0 ; i < tam ; i++){
        if(valores[i] == valor )
        return true;    
    }  
    return false;
}  
```

## GerarNumerosAmarelo

Função responsável para gerar cartas amarelas de forma aleatória.

#
 
### Exemplo no cógido:

Progama:
```void GerarNumerosAmarelo (int numerosAmarelo[], int quantNumeros , int limiteAmarelo ){    
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
```

## GerarNumerosAzul

Função responsável para gerar cartas azuis de forma aleatória.

#
 
### Exemplo no cógido:

Progama:
```void GerarNumerosAzul (int numerosAzul[], int quantNumeros , int limiteAzul ){
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
```

## GerarNumerosVermelho

Função responsável para gerar cartas vermelhas de forma aleatória.

#
 
### Exemplo no cógido:

Progama:
```void GerarNumerosVermelho (int numerosVermelho[], int quantNumeros , int limiteVermelho ){
    int vVermelho;
 
    for ( int c = 0 ; c < quantNumeros ; c++){
        vVermelho = rand() % limiteVermelho;
        while (Existe(numerosVermelho,c,vVermelho)) {
            vVermelho = rand() % limiteVermelho;
        }
        if ( vVermelho != 10) {
        numerosVermelho[c] = vVermelho;
       
    } else {
        c--;
    }
    }
}
```

## GerarNumerosVerde

Função responsável para gerar cartas verdes de forma aleatória.

#
 
### Exemplo no cógido:

Progama:
```
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
```

## Criar_baralho

Função longa que tem como base criar o baralho.

Vamos dividí-la em partes, para facilitar a compreensão.

#
 
### Exemplo no cógido:

+ Parte inicial da função:
```int criar_baralho (pilha *baralho) {
    carta c;
    pilha amarelo, azul, vermelho, verde, preto,especiais; // cria as pilhas de cores
 
    inicializa_pilha(&amarelo);
    inicializa_pilha(&azul);
    inicializa_pilha(&vermelho);
    inicializa_pilha(&verde);
    inicializa_pilha(&preto);
    inicializa_pilha(&especiais);
    inicializa_pilha(baralho);
   
    srand(time(NULL));
```
+ Agora é a parte responsável para gerar as cartas amarelas da função:

#
 
### Exemplo no cógido:

```/*  --------------------------------------------------------------Amarelo-------------------------------------------------------------- */
 
for ( int w = 0 ; w < 2 ; w++){ // Insere a carta de Bloqueio na pilha especial
    c.cor =0;
    c.numero = 66;
    push(&especiais, c);
}
 
for ( int w = 0 ; w < 2 ; w++){ // insere a carta de Reverse na pilha especial
    c.cor = 0;
    c.numero = 82;
    push(&especiais, c);
}
 
int numerosAmarelo[19];
 
GerarNumerosAmarelo(numerosAmarelo , 19 , 20);
c.cor = 0;
for ( int i = 0 ; i < 19 ; i++){
    if ( numerosAmarelo[i] > 10){ // Se a os numeros forem maiores que 10, subtrai 10 (como ta gerando valores aleatorios entre 0 e 19, sao 2 numeros de cada, pra cada cor, e nao teremos o numero 10 porque no UNO so tem uma carta 0 pra cada cor )
        numerosAmarelo[i] = numerosAmarelo[i] - 10;
        c.numero = numerosAmarelo[i];                
        push(&amarelo, c);
    } else {
        c.numero = numerosAmarelo[i]; // Se for menor que 10, entra normal
        push(&amarelo, c);
    }
}
    for ( int w = 0 ; w < 2 ; w++){ // Insere a carta +2 na pilha especial
        c.cor = 0;
        c.numero = 43;
        push(&especiais, c);
    }
//a funçao sera a mesma para as cores azul, vermelho e verde
```
+ Agora é a parte responsável para gerar as cartas azuis da função:

#
 
### Exemplo no cógido:

```/*  --------------------------------------------------------------Azul--------------------------------------------------------------    */  
 
for ( int w = 0 ; w < 2 ; w++){
    c.cor = 1;
    c.numero = 43;
    push(&especiais, c);
}
 
int numerosAzul[19];
GerarNumerosAzul(numerosAzul , 19 , 20);
c.cor = 1;
 
for ( int i = 0 ; i < 19 ; i++){
    if ( numerosAzul[i] > 10){
        numerosAzul[i] = numerosAzul[i] - 10;  
        c.numero = numerosAzul[i];
        push(&azul, c);
    } else {
        c.numero = numerosAzul[i];
        push(&azul, c);
    }
}
 
for ( int w = 0 ; w < 2 ; w++){
    c.cor = 1;
    c.numero = 66;
    push(&especiais, c);
}
for ( int w = 0 ; w < 2 ; w++){
    c.cor = 1;
    c.numero = 82;
    push(&especiais, c);
}
```
+ Agora é a parte responsável para gerar as cartas vermelhas da função:

#
 
### Exemplo no cógido:

```/*  --------------------------------------------------------------Vermelho--------------------------------------------------------------    */  
 
for ( int w = 0 ; w < 2 ; w++){
    c.cor = 2;
    c.numero = 66;
    push(&especiais, c);
}
    for ( int w = 0 ; w < 2 ; w++){
        c.cor = 2;
        c.numero = 82;
    push(&especiais, c);
}
int numerosVermelho[19];
    GerarNumerosVermelho(numerosVermelho , 19 , 20);
    c.cor = 2;
    for ( int i = 0 ; i < 19 ; i++){
        if ( numerosVermelho[i] > 10){
            numerosVermelho[i] = numerosVermelho[i] - 10;  
            c.numero = numerosVermelho[i];
            push(&vermelho, c);
        } else {
            c.numero = numerosVermelho[i];
            push(&vermelho, c);
        }
    }
    for ( int w = 0 ; w < 2 ; w++){
        c.cor = 2;
        c.numero = 43;
        push(&especiais, c);
    }
```
+ Agora é a parte responsável para gerar as cartas verdes da função:

#
 
### Exemplo no cógido:

```/*  --------------------------------------------------------------Verde--------------------------------------------------------------   */  
 
for ( int w = 0 ; w < 2 ; w++){
    c.cor = 3;
    c.numero = 43;
    push(&especiais, c);
}
 
int numerosVerde[19];
    GerarNumerosVerde(numerosVerde , 19 , 20);
    c.cor = 3;
    for ( int i = 0 ; i < 19 ; i++){
        if ( numerosVerde[i] > 10){
            numerosVerde[i] = numerosVerde[i] - 10;
            c.numero = numerosVerde[i];
            push(&verde, c);
        } else {
            c.numero = numerosVerde[i];
            push(&verde, c);
        }
    }
    for ( int w = 0 ; w < 2 ; w++){
        c.cor = 3;
        c.numero = 66;
        push(&especiais, c);
    }
    for ( int w = 0 ; w < 2 ; w++){
        c.cor = 3;
        c.numero = 82;
        push(&especiais, c);
    }
```
+ Agora é a parte responsável para gerar as cartas pretas da função:

#
 
### Exemplo no cógido:

```/*  --------------------------------------------------------------Preto--------------------------------------------------------------   */  
int contW = 4;
int contM = 4;
int auxp = 0;
 
for(int m=0 ; m<8 ; m++){  // insere as carta Troca de cor e +4 aleatoriamente entre 0 e 1
    auxp = rand()%2;  
    if(auxp == 0){
        if(contW > 0  ){
            c.cor = 4;
            c.numero = 84; // carta Troca de cor => carta T  
            push(&preto,c);
            contW--;
        }
    else {
    m--;    
    }
}else if(auxp == 1){
        if(contM > 0){
            c.cor = 4;
            c.numero = 77;  // carta +4 => carta M
            push(&preto,c);
            contM--;
        } else {
        m--;    
        }
    }              
}
```
+ Agora são inseridas essas cartas na pilha do baralho:

#
 
### Exemplo no cógido:

```srand(time(NULL));
int aux = 0;
for(int i=0 ; i<108;i++){
    aux = rand()%6;
    if(aux == 0){
        if(!pilha_vazia(&vermelho)){ //quando a pilha vermelha nao ta vazia, retira da pilha e adiciona aleatoriamente na pilha baralho
            pop(&vermelho,&c);
            push(baralho,c);
        }
        else {
        i--;
        }   //repetir para as demais cores e cartas especiais
    } else if(aux == 1){
        if(!pilha_vazia(&azul)){
            pop(&azul,&c);
            push(baralho,c);
        }
        else {
        i--;
        }
    } else if(aux == 2){
        if(!pilha_vazia(&amarelo)){
            pop(&amarelo,&c);
            push(baralho,c);
        }
        else {
        i--;
        }
    } else if(aux == 3){
        if(!pilha_vazia(&verde)){
            pop(&verde,&c);
            push(baralho,c);
        } else {
        i--;
        }
    }
    if(aux == 4){
        if(!pilha_vazia(&preto)){
            pop(&preto,&c);
               push(baralho,c);
           } else {
        i--;
        }
    }
    if(aux == 5){
        if(!pilha_vazia(&especiais)){
            pop(&especiais,&c); // obs.: guarda as especiais de todas as cores
            push(baralho,c);
        } else {
            i--;
        }
    }
}
}
```
