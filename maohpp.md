Este arquivo contém todo o código usado em mao.hpp destrinchado, o mao hpp é onde ocorre no código as mudanças das mãos dos jogadores.

- [Struct](#struct)
- [Inicializa](iniciliza)
- [Insere](#insere)
- [Vazia](#vazia)
- [Imprime](#imprime)
- [Tamanho](#tamanho)
- [Acao](#acao)
- [Retiracarta](#retiracarta)
- [Criar_mao](#criar_mao)

---

## Struct

A struct foi utilizada para armazenar as cartas da mão do jogador.

#
 
### Exemplo no cógido:

Progama:
```
struct mao { //mao do jogador
    carta _carta;
    struct mao* prox;
};
typedef struct mao Mao;
};
```

## Inicializa

Função responsável por inicializar a mão do jogador.

#
 
### Exemplo no cógido:

Progama:
```
Mao* inicializa (void){
 return NULL;
}
```

## Insere

Função responsável por inserir a carta na mão. Utilizamos malloc, pois por algum motivo o "new" 
não funcionava no compilador que estávamos usando, ele deixava um "leak" na memória.

#
 
### Exemplo no cógido:

Progama:
```
Mao* insere (Mao* l, carta _carta){ // insere a carta na mao "
 Mao* novo = (Mao*) malloc(sizeof(Mao));
 novo->_carta = _carta;
 novo->prox = l;
 return novo;
}
```

## Vazia

Função responsável por verificar se a mão do jogador está vazia, caso esteja ele vence a partida.

#
 
### Exemplo no cógido:

Progama:
```
int vazia (Mao* l) {//verifica se a mao ta vazia, se sim o jogador vence a partida
 if (l == NULL) {
 return 1;
 }else
 return 0;
}
```

## Imprime

Função responsável por mostrar as cartas do jogador. Observação: No TP foi utilizado a tabela ASCII para ser usado os caracteres nas cartas especiais,
exemplo de como foi a transformação dos caracteres (+, M, R, T, B)

#
 
### Exemplo no cógido:

Progama:
```
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
```

## Tamanho

Função responsável por contar e mostrar na tela quantas cartas o jogador possui.
Caso esteja com 0 é impresso uma imagem da vitória.

#
 
### Exemplo no cógido:

Progama:
```
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
```

## Acao

Função responsável por acionar o "come 2" e o "come 4", caso o jogador receba uma dessas cartas especiais,
é retirado do baralho e inserido na mão desse jogador.

#
 
### Exemplo no cógido:

Progama:
```
Mao* acao(pilha *baralho, Mao *jogador,int numero){ // Se o numero for 43 ou 77  entra na funcao das cartas "+2" e "+4"
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
```

## RetiraCarta

Função responsável por verificar a jogada, caso o jogador tenha jogado a carta errada
é informado na tela uma mensagem, ele perde a vez de jogar e a mesa pega a carta de volta.

#
 
### Exemplo no cógido:

Progama:
```
Mao* retiracarta (Mao* jogador, carta _carta, pilha *mesa, pilha *baralho,int cor, int num) {
 
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
    if(p->_carta.cor != _carta.cor && p->_carta.numero != _carta.numero ){  
        push(mesa,_carta);
        throw invalid_argument("Jogue corretamente a carta! Confira sua cor e numero para jogar");
        //cout << "Jogue corretamente a carta! Confira sua cor e numero para jogar" << endl << endl;
        pop(baralho,&_carta);
        jogador = insere(jogador,_carta);
        Sleep(3000);
     return jogador;
   
    } else { //se o jogador joga a carta certa, esta eh inserida na pilha
    _carta.cor = cor;
    _carta.numero = num;
    push(mesa,_carta);
   
 //encontrou o elemento?
 if (p == NULL)
 return jogador; //nao -> retorna lista original e retira elemento
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
```

## Criar_Mao

Função responsável por tirar a carta do baralho e colocar na mão dos jogadores.
Ela também tira o elemento da pilha e coloca na lista.

#
 
### Exemplo no cógido:

Progama:
```
Mao* criar_mao(pilha *baralho, Mao *jogador) { //tira a carta do baralho e coloca na mao dos jogadores e tira o elemento da pilha e coloca na lista
    carta _carta;
    jogador = inicializa();
       
    for (int i = 0 ; i < 7 ; i++) {
        pop(baralho,&_carta);
        jogador = insere(jogador,_carta);
    }  
   
    return jogador;
}
```
