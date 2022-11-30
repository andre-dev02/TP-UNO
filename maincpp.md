Este arquivo contém todo o código usado em na main.cpp destrinchado e detalhado.

- [Jogar](#jogar)
- [Main](#main)

### Jogar

Função longa responsável por toda a jogabilidade do usuário.
Dividiremos em partes para facilitar a compreensão.

#
 
Em primeiro lugar, é feito um loop a partir de um for para imprimir uma interface que
apresenta as informações da mesa e da mão do jogador

### Exemplo no cógido:

Progama: 
```
void jogar (pilha *baralho, pilha *mesa, Mao *jogador1, Mao *jogador2, int vez){
    carta c;
    int cor,cor2;
    char num,num2;
    vez = 1;
    int id = 1;
    int id2 = 2;
 
    for( ; ; ){ //for em loop
        if ( vez == 1) {
            do {
            cout << endl;
 
            tamanho(jogador1,id); //mostra quantidade de cartas e quem ganhou
 
            cout << "__________________CARTA NA MESA:________________" << endl;
            imprime_pilha(*mesa); // mostra a carta que ta na mesa
            cout << "_________________________________________________" << endl << endl;
 
            cout << "_________________________________________________" << endl;
            cout << "| Dica:                                         |" << endl;
            cout << "|      - Digite 5 5 para comprar uma carta      |" << endl;
            cout << "|      - Use o teclado em letras maiusculas     |" << endl;
            cout << "|      - O num. 0 representa a cor Amarela      |" << endl;
            cout << "|      - O num. 1 -> representa a cor Azul      |" << endl;
            cout << "|      - O num. 2 -> representa a cor vermelho  |" << endl;
            cout << "|      - O num. 3 -> representa a cor verde     |" << endl;
            cout << "|      - O num. 4 -> representa a cor Preto     |" << endl;
            cout << "|                    (cartas especiais)         |" << endl;
            cout << "|_______________________________________________|";
 
            cout << endl << "________________CARTAS DO JOGADOR 1:_____________" << endl;
            imprime(jogador1);  // mostra em tela as cartas que esta na mao do jogador1
```

#

Em segundo lugar, é impresso na tela a vez do jogador jogar a carta, e, a partir dessa escolha, é computado a jogada

#
 
### Exemplo no cógido:

Progama: 
```
cout << endl << endl << "ESCOLHA UMA CARTA PARA JOGAR: ";
            cin >> cor >> num;
 
            if ( num > 47 ){
                if ( num <= 57) {
                    num = num - 48;  //achar os numeros de 0-9 usando a tabela ASCII
                }
            }
            if ( num > 97 ){
                if ( num <= 115) {
                num = num - 32; //obter o alfabeto em maiusculo usando a tabela ASCII
                }
            }
            system ("cls");
            }
 
            while (cor > 6);
            if ( num == 77 || num == 82 || num == 84 || num == 66 || num == 43|| num < 10) {
                if ( cor == 5) {  //compra carta
                    pop(baralho,&c);
                    jogador1 = insere(jogador1,c);
                    vez++;
                } else {  
                    c.cor = cor;
                    c.numero = num;
                    jogador1 = retiracarta(jogador1,c,mesa,baralho,c.cor,c.numero); // tira a carta da mao do jogador
                    jogador2 = acao(baralho,jogador2,num); // se a carta for + (43) ou M (77) o proximo jogador compra uma carta
                    vez++;  //a vez de jogar passa a ser do proximo jogado
                    if ( num == 66 || num == 82){ //Na tabela ASCII o 66 eh o B(carta Block) e o 82 eh o R(cartaReverse)
                        vez = 1; // se o jogador bloquear o proximo, ele jogda novamente ( se fosse 4 jogaodores vez receberia +2 )
                    }
                    tamanho(jogador1,id);
                    fflush(stdin);
                    system ("cls");
                }
            } else {
                vez = 1; // se o jogador jogar uma carta que nao esta em sua mao
            }  
        }
```
#

E, por fim, é impresso as mesmas coisas só que agora para o jogador 2.

#
 
### Exemplo no cógido:

Progama: 
```
 /*------------------------------------------------------------------------------------------------*/
     //os comandos do jogador1 se repetem para o jagador2, porem, houve mudancas de variaveis pra facilitar
        if ( vez == 2) {
            do {
                tamanho(jogador2,id2);
                cout << endl << "_________________CARTA NA MESA:_________________" <<endl;
                imprime_pilha(*mesa);
                cout << "_________________________________________________" << endl << endl;
 
                cout << "_________________________________________________" << endl;
                cout << "| Dica:                                         |" << endl;
                cout << "|      - Digite 5 5 para comprar uma carta      |" << endl;
                cout << "|      - Use o teclado em letras maiusculas     |" << endl;
                cout << "|      - O num. 0 representa a cor Amarela      |" << endl;
                cout << "|      - O num. 1 -> representa a cor Azul      |" << endl;
                cout << "|      - O num. 2 -> representa a cor vermelho  |" << endl;
                cout << "|      - O num. 3 -> representa a cor verde     |" << endl;
                cout << "|      - O num. 4 -> representa a cor Preto     |" << endl;
                cout << "|                    (cartas especiais)         |" << endl;
                cout << "|_______________________________________________|";
 
                cout << endl << "______________CARTAS DO JOGADOR 2:__________" << endl;
 
                imprime(jogador2);
                cout << endl << endl << "ESCOLHA UMA CARTA PARA JOGAR: ";
                cin >> cor2 >> num2;
                cout << cor2 << num2;  
 
                if ( num2 > 47 ){
                    if ( num2 < 58) {
                        num2 = num2 - 48;  
                    }
                }
                if ( num2 > 97 ){
                    num2 = num2 -32;
                }
                system ("cls");
            }
 
            while (cor2 > 6 && num > 10);
            if ( num == 77 || num == 82 || num == 84 || num == 66 || num == 43|| num < 10) {
                if ( cor2 == 5) {
                    pop(baralho,&c);
                    jogador2 = insere(jogador2,c);
                    vez--;
                }
                else {
                    c.cor = cor2;
                    c.numero = num2;
                    jogador2 = retiracarta(jogador2,c,mesa,baralho,c.cor,c.numero);
                    jogador1 = acao(baralho,jogador1,num2);
                    vez--;
 
                    if ( num2 == 66 || num2 == 82){
                        vez = 2;
                    }
                    tamanho(jogador2,id2);
                    fflush(stdin);
                    system ("cls");
                }
            } else {
                vez = 2;
            }
        }
    }
}
```
#

### Main

Função main, responsável por imprimir a interface do menu, iniciar a mesa, o baralho, a mão do jogador 1, a mão do jogador 2
e possibilitar opções para os jogadores escolherem (Jogar, Sair, Ajuda).

#
 
### Exemplo no cógido:

Progama:
```
int main () {
//deixar em tela cheia
    keybd_event ( VK_MENU, 0x36, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
 
    pilha mesa;
    pilha baralho;
    Mao* jogador1;
    Mao* jogador2;
    int vez;
 /* ------------------------------------------------------Logo e Menu------------------------------------------------   */char opc=1;
    Sleep(200);
    system ("cls");
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BPB@@@@@@@@@&GJ~:.7@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&5^...!#@@&B57^....::.?@@@@@@&&#BGG@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@@#J?P&@@B7....::.:!~:......:::::.7?!~^:......~@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@&7....:7^.....:::::.....:...::::::........::::.&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@5:....:.......:::.::....::.....:::......:::.:::.7BB##&&&@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@B~....:::.^!!~.....^^^^^:::....:::::::.::::....:.:......::::^~~Y@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@&7.....:..:YJ77JJ...?^!J7^!.:...:7~~~:^^:::::....:::.............:@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@Y:.........5?!!!!5~.:J77~!~:...:::.:~^^:.::::.....:::::...........!@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@G^.....:....~P7JJ??P~.::7:~7~!^..::::!:^:....::::^:^^:^^::::.....:..!#&@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@#!..:.::~Y5:.:^##&G?YP.:.7J!7!!!:^^.:.~!~:...::::~~^^^^^^~:^.......:::..:^!YG#@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@?.....~!!!7Y?.:.Y&&BYY:...:::::..!?:.:::::::::~^:::^^^::^^::::.:^^::::::.......:~?5B&@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@P:......J^^Y#!!..:.~77~:.:.:::::..!J~::::::::^~~^..:::^^^^^::::::!::^~:^:::............P@@@@@@@" << endl;
    cout << setw(150) << "@@@#~.......:::.7!~:........::.^::::..!J~.::::..:~~^:.::::::::::..::~^^^^:::::::::::::..::.:&@@@@@@@" << endl;
    cout << setw(150) << "@&?..:::::..::^~^....:.::::::..P:::..!?!..::...^~^:.::::::::..:::::~^^:^^::..:::::::::::...#@@@@@@@@" << endl;
    cout << setw(150) << "5:.:::^:::::::::::::::.~~.::..^#^.:.~?7...::.:~~:.:::::..::::::::::::^^^::..:::::......::::P@@@@@@@@" << endl;
    cout << setw(150) << ".....::^:~:::^..::::::.^B^.:..7#^.::??::.::.^~~:::::::.::::::.....::::^^^^^^^^^^::::....:::.:J&@@@@@" << endl;
    cout << setw(150) << "&5^...:^::^^^^:..:::::..BJ.::.?#~:.!?!.:.::^~~::::::::^::.::::::^^^^^^:::::::::::::^^^^^::::...!B@@@" << endl;
    cout << setw(150) << "@@@#J^..^^^:::::::::::..?B:.:.?#G^:?J:::..^~~::::.::^:::::^^^^^:::::^:::::::::::::::::::^^^:.....^5&" << endl;
    cout << setw(150) << "@@@@@@B7:..::::::.:^:::::B?...!#&7:??.::.:~~::::::^:::^^^^:::::.:~~^::::::::::::::::::::::^^::::...:" << endl;
    cout << setw(150) << "@@@@@@@@&P~...::::.:^^.:.!#^..:B&5^?7.:..~~:::..:::^^^:::::::::~7^:.:::^^:::^::::::::::::::^^:::..~G" << endl;
    cout << setw(150) << "@@@@@@@@@@@&Y~..::..^^^.:.YB:..Y&B~?7.:.^~~.:::^:^^^:::::::::::7~:::^:::7!:::^::::::::::::.^^:..^G@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@#?:...:^^^::.5G:.:B&7??.:.~~^...:^^^:::::::::^!^^!!:.:^::~!^:::^:::::::::::.:^^.:P@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@G!:..:^^:..YB~.~#J7?~..^~:..:^^:::::::::::!!:::~~^:::::::::^:::::::::::::^:^5@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@&5~.:^^:..7GJ.^Y:??^.:^!YGBGJ^.::::::~~:~!:::^:^~~^:.::^:::::::::::::^:^5@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@@@@#J^:^^:.:YP7..:7?.~G#&&&&#P!::::::~~^::~^:::::::::::::::::::::::^:^Y&@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@@@@@@#Y~^^^:.:7^.:.:7###&&#BG55::::::::^~^::^~^:::::::::::::::::^^::J&@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@@@@&&&&#P?~^^:...:.7#####BGG5P5..::::::.:^~~^::^:::::::::::::^^^::?&@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@@@@&&&&##BBPY7~^:::.?&####BBGPPG!.:::::::::.::~~^:::::::::^^^^::..7&@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@@@&&&&&&##BGPY??7~!~:J######BBGPPJ:.^^^^::::::::::::^^^^^^^^:::...7#@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@@@&&######BGP5J?7~!P##G######BBGP5J~..::::::^^^^^^^^:^::::::::::..!#@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@@@&&&####BBGP5YJ?!^?B#&#####BBBGGPY?!...:::::.:::::::::^^:...:::..!#@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@@@&&&&&##BGPJ?77!~^!P###BB####BBGP5Y?J#Y^..:::::::::::::^^^^^^.::.:B@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@@&#&&&###BBBBGY!^^75B#BBGB#####BBGP5?P@@@@B!:..::...::::^^~:~^::::.#@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@&##&####BBGBGGGPJ?JPGGP5G######BBG5JG@@@@@@@&J^.....::^~^:~~:..:..G@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@&###&&##BB##BBBGGPY?^~?JJP#######BG5JB@@@@@@@@@@@P~...:::::^^..^!^^P@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@####&&&###BBBGGGG55J!^!!!5######BBGPJJB@@@@@@@@@@@@@#7:..::::.^P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@&######&&&#####BBBGPJ~^7YB######BBGPYJ?P@@@@@@@@@@@@@@@&5^...:5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@########&#####BBBBBBGGG#######BBGG5?J7P@@@@@@@@@@@@@@@@@@B5G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@&#############BBBBBBB####&###BBBG5J?J7??YG@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@################B##########BBBGPY?J77!!!!G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@###########################BBGPY??J77!!!!#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@&B########################BBGP5J??J?!!!7P@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@BBBB#####################BBGP5J??J!~!75@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@#BBB####################BBGGPP5J?J!~75@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@&BBBB##################BBBGGP5Y?7J7Y#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@BBBBB################BBBBGP5YJ?7Y&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << setw(150) << "@@@@@@@@#BBB#################BBBBGP5Y?77G@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    Sleep(2000);
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
 
    system("cls");
    do {
        cout << endl << endl;
        cout << endl << endl;
        cout << endl << endl;
        cout << setw(120) << "         T R A B A L H O    P R A T I C O      " << endl;
        cout << setw(120) << "     Programacao e Desenvoldimento de Software II " << endl;
        cout << setw(120) << "          Prof. Gleison S. D. Mendonca            " << endl << endl << endl << endl;
 
        cout << setw(120) << "         UU     UU     NN     N      OOOO      " << endl;
        cout << setw(120) << "         UU     UU     NN NN  N    OO    OO    " << endl;
        cout << setw(120) << "         UU     UU     NN  NN N    OO    OO    " << endl;
        cout << setw(120) << "           UUUUU       NN    NN      OOOO      " << endl << endl << endl;
 
        cout << setw(120) << "__________________ Menu Inicial _______________" << endl << endl;
 
        cout << setw(120) << "   Use o teclado em maiusculas durante o jogo  " << endl<< endl;
 
        cout << setw(120) << "                     A - Ajuda                 " << endl;
        cout << setw(120) << "                     J - Jogar                 " << endl;
        cout << setw(120) << "                     S - Sair                  " << endl;
        cout << setw(120) << "_______________________________________________" << endl << endl;
 
        cout << setw(120) << "        Escolha uma opcao:                     ";
        cin >> opc;
 
     //Selecao do menu
        switch (opc) {
            case 'A': {
                system("cls");
                ajuda(opc); // chama a funao que ensinar o jogador a jogar
                system("PAUSE");
                system("cls");
                break;
            }
            case 'J' : {
                system("cls");  
                criar_baralho(&baralho); //cria o baralho, passando a pilha de variavel baralho
                carta_mesa(&mesa,&baralho);  //carta da mesa que inicia o jogo
                jogador1 = criar_mao(&baralho,jogador1); //cria as cartas para o jogador 1
                jogador2 = criar_mao(&baralho,jogador2); //cria as cartas para o jogador 2
                cout << endl;
                imprime_pilha(baralho);
            }
            jogar (&baralho,&mesa,jogador1,jogador2,vez);
            Sleep(3000);
            break;
 
            case 'S': {
                system("cls");
                return 0; // fecha o jogo
                break;
            }
 
            default: {
                cout << setw(150) << " Erro: Escolha uma opcao correta ## Dica use o teclado com letra maiuscula ## "<<endl;
                Sleep(500);
                system("cls");
            }
 
        }
    } while (opc != 'S');
}
```
