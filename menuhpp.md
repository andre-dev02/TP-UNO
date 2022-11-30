Este arquivo contém todo o código usado em menu.hpp destrinchado.

- [Menu_De_Ajuda](#menu_de_ajuda)

O menu foi criado com a função de ajudar o usuário e apresentar uma interface interativa.
Nele contém as informações básicas das cartas e das cores, além de instruções para pegar uma carta do monte

#
 
### Exemplo no cógido:

Progama:
```
void ajuda (int opc){
 
setlocale(LC_ALL,"");
    cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
    cout << setw(150) << "-------------------------------------- H E L P -----------------------------------------------" << endl << endl;
 
    cout << setw(150) << "Esta é uma versão adaptada de um dos jogos mais famosos de todos e tempos.                    " << endl;
    cout << setw(150) << "Nosso jogo promete diversão para dois oponentes que se enfrentarão                            " << endl;
    cout << setw(150) << "até que um dos deles fique sem nenhuma carta, garantindo assim a vitória.                     " << endl;
    cout << setw(150) << "Cada cor é representada por um número de 0 a 4 e o valor das cartas é representado            " << endl;
    cout << setw(150) << "por seus respectivos números ou por sua letra inicial, no caso das cartas especiais           " << endl << endl;
 
    cout << setw(150) << " _____                           _____                                                        " << endl;
    cout << setw(150) << "|     |                         |     |                                                       " << endl;
    cout << setw(150) << "|  C  | 0 -> Amarelo            |  C  | +  -> O próximo jogador ganha duas cartas do monte    " << endl;
    cout << setw(150) << "|  O  | 1 -> Azul               |  A  | M  -> O próximo jogador ganha quatro do cartas monte  " << endl;
    cout << setw(150) << "|  R  | 2 -> vermelho           |  R  | B  -> Bloqueia o próximo jogador a jogadar            " << endl;
    cout << setw(150) << "|  E  | 3 -> verde              |  T  | R  -> Inverte a ordem de jogada                       " << endl;
    cout << setw(150) << "|  S  | 4 -> Preto              |  A  | T  -> Troca a cor da rodada                           " << endl;
    cout << setw(150) << "|     |                         |  S  |                                                       " << endl;
    cout << setw(150) << "| ___ |                         | ___ |                                                       " << endl << endl;
 
    cout << setw(150) << "Para jogar basta digitar o número da cor e o valor da carta, ex.: 0 4 (carta                  " << endl;
    cout << setw(150) << "numero 4 amarela), 2 B (carta de bloqueio Vermelha).                                          " << endl;
    cout << setw(150) << "Se precisar pegar uma carta do monte, digite 5 5. Agora eh so se divertir!!!                  " << endl;
    cout << setw(150) << "-------------------------------------- H E L P -----------------------------------------------" << endl << endl;
```
