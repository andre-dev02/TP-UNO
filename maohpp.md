Este arquivo contém todo o código usado em mao.hpp destrinchado, o mao hpp é onde ocorre no código as mudanças das mãos dos jogadores.

- [Struct](#struct)
- [Inicializa](iniciliza)
- [Insere](#insere)
- [Vazia](#vazia)
- [Imprime](#imprime)
- [Tamanho](#tamanho)
- [Ação](#acao)
- [Retiracarta](#retiracarta)
- [Criar_mao](#criar_mao)

---

## Struct

A struct foi utilizada para armazenar as cartas da mão do jogador.

Progama:
```struct mao { //mao do jogador
    carta c;
    struct mao* prox;
};
typedef struct mao Mao;
};
```

## Inicializa

Função responsável por inicializar a mão do jogador.

Progama:
```Mao* inicializa (void){
 return NULL;
}
```

## Insere

Função responsável por inserir a carta na mão. Utilizamos malloc, pois por algum motivo o "new" 
não funcionava no compilador que estávamos usando, ele deixava um "leak" na memória.

Progama:
```Mao* insere (Mao* l, carta c){ // insere a carta na mao "
 Mao* novo = (Mao*) malloc(sizeof(Mao));
 novo->c = c;
 novo->prox = l;
 return novo;
}
```

## Vazia

Função responsável para verificar se a mão do jogador está vazia, caso esteja ele vence a partida.

Progama:
```int vazia (Mao* l) {//verifica se a mao ta vazia, se sim o jogador vence a partida
 if (l == NULL) {
 return 1;
 }else
 return 0;
}
```

## Imprime

Função responsável para mostrar as cartas do jogador. Observação: No TP foi utilizado a tabela ASCII para ser usado os caracteres nas cartas especiais,
exemplo de como foi a transformação dos caracteres (+, M, R, T, B)

Progama:
```void imprime (Mao* l) { //mostra as cartas do jogador
 Mao* p;
 for (p = l; p != NULL; p = p->prox) {
        if (p->c.numero == 66) {
            cout << "Cor = " << p->c.cor << " Numero = Block" << endl;
        }
        if (p->c.numero == 82) {
            cout << "Cor = " << p->c.cor << " Numero = Reverse" << endl;
        }
        if (p->c.numero == 77) {
            cout << "Cor = " << p->c.cor << " Numero = +4" << endl;
        }
        if (p->c.numero == 43) {
            cout << "Cor = " << p->c.cor << " Numero = +2" << endl;
        }
        if (p->c.numero == 84) {
            cout << "Cor = " << p->c.cor << " Numero = Troca de cor" << endl;  
        }
        if (p->c.numero < 10) {
            cout << "Cor = " << p->c.cor << " Numero = " << p->c.numero << endl;
        }
        }
}
```

## Tamanho

Função responsável para contar e mostrar na tela quantas cartas o jogador possui.
Caso esteja com 0 é impresso uma imagem da vitória.

Progama:
```int tamanho(Mao* l, int id) { // Conta e mosta na tela quantas cartas o jogador tem
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

## Ação

Função responsável para acionar o "come 2" e o "come 4", caso o jogador receba uma dessas cartas especiais,
é retirado do baralho e inserido na mão desse jogador

Progama:
```Mao* acao(pilha *baralho, Mao *jogador,int numero){ // Se o numero for 43 ou 77  entra na funcao das cartas "+2" e "+4"
    carta c;
    if (numero == 43){
    for (int i = 0 ; i < 2 ; i++){
    pop(baralho,&c);
    jogador = insere(jogador ,c);
        }
    }
   
    if (numero == 77){
    for (int i = 0 ; i < 4 ; i++){
    pop(baralho,&c);
    jogador = insere(jogador ,c);
        }
    }
   
    return jogador;
}
```

## RetiraCarta

Função responsável para verificar a jogada, caso o jogador tenha jogado a carta errada
é informado na tela uma mensagem, ele perde a vez de jogar e a mesa pega a carta de volta

Progama:
```Mao* retiracarta (Mao* jogador, carta c, pilha *mesa, pilha *baralho,int cor, int num) {
 
 Mao* ant = NULL;
 Mao* p = jogador;
 
 
 while (p != NULL && (p->c.numero != c.numero)  ) { //verificar a cor
 ant = p;
 p = p->prox;
}
 
 
while (p != NULL && (p->c.cor != c.cor ) ) { //verificar o numero        
 ant = p;
 p = p->prox;
}
 
 
        pop(mesa,&c); //verifica as cartas da mesa
    if(p->c.cor != c.cor && p->c.numero != c.numero ){  
        push(mesa,c);
        cout << "Nao tente roubar jogue somente a carta certa!" << endl << endl;
        pop(baralho,&c);
        jogador = insere(jogador,c);
        Sleep(3000);
     return jogador;
   
    } else { //se o jogador joga a carta certa, esta eh inserida na pilha
    c.cor = cor;
    c.numero = num;
    push(mesa,c);
   
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

Função responsável por tirar a carta do baralho e coloca na mão dos jogadores e tira o elemento da pilha e coloca na lista.

Progama:
```Mao* criar_mao(pilha *baralho, Mao *jogador) { //tira a carta do baralho e coloca na mao dos jogadores e tira o elemento da pilha e coloca na lista
    carta c;
    jogador = inicializa();
       
    for (int i = 0 ; i < 7 ; i++) {
        pop(baralho,&c);
        jogador = insere(jogador,c);
    }  
   
    return jogador;
}
```
