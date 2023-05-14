#include <stdlib.h>
#include <stdio.h>

int main (){
 char posicoes[3][3];
 char simb[3], sgameon[3], sj[3],sk[3];
 int gameon = 1, vitoria = 0;
 int i, j, k;
 int escolha_j, escolha_k;

 while (gameon){
    printf("JOGO DA VELHA!!\n(1) Jogar \n(0) Sair \n");
    fflush(stdin);
    fgets(sgameon, 3, stdin);
    gameon = atoi(sgameon);

    if (gameon==0)
        break;
    
    while (1){
        printf ("Escolha seu simbolo (X ou O):\n");
        fflush(stdin);
        fgets (simb, 3, stdin);
        if(simb[0] == 'x' || simb[0] == 'X'){
            simb[0] = 'X';
            break;
        }
        else if(simb[0] == 'o' || simb[0] == 'O'){
            simb[0] = 'O';
            break;
        }
            printf("Erro -> Símbolo incorreto\n");
    }

    for(j=0;j<3;j++){
        for (k=0;k<3;k++){
            posicoes[j][k] = 'e';
        }
    }

    k=0;

    for(i=1;i<10;i++){
        printf("Rodada %d. Vez de %c.\n",i,simb[0]);
        printf("Digite a posição desejada:\n (1,2,3)Linha\n (1,2,3)Coluna\n");
        fflush(stdin);
        fgets(sj,3,stdin);
        fflush(stdin);
        fgets(sk,3,stdin);
        j = atoi(sj) - 1;
        k = atoi(sk) - 1;

        if(posicoes[j][k] == 'X' || posicoes[j][k] == 'O'){
            printf("Erro -> Posicao ja preenchida!\n");
            i--;
            continue;
        }
        else
            posicoes[j][k] = simb[0];


        //antes da quinta jogada, n tem como ganhar
        if(i < 5) {
            if(simb[0] == 'X')
                simb[0] = 'O';
            else
                simb[0] = 'X';
            continue;

        }
        
        if(posicoes[j][0] == posicoes[j][1] && posicoes[j][0] == posicoes [j][2]){
            vitoria = 1;
            break;
        }    

        if(posicoes[0][k] == posicoes[1][k] && posicoes[0][k] == posicoes [2][k]){
            vitoria = 1;
            break;
        }

        if(j!=1 && k!=1 && k!=j)//fowardslash
            if(posicoes[0][2] == posicoes[1][1] && posicoes[0][2] == posicoes [2][0]){
                vitoria = 1;
                break;
            }
        
        if(j!=1 && k!=1 && k==j)//backslash
             if(posicoes[0][0] == posicoes[1][1] && posicoes[0][0] == posicoes [2][2]){
                vitoria = 1;
                break;
            }
        

        if(j==1 && k==1){  //ambas diagonais
            if(posicoes[0][2] == posicoes[1][1] && posicoes[0][2] == posicoes [2][0]){
                vitoria = 1;
                break;
            }
            if(posicoes[0][0] == posicoes[1][1] && posicoes[0][0] == posicoes [2][2]){
                vitoria = 1;
                break;
            }
        }

        //troca de time no fim do turno
        if(simb[0] == 'X')
            simb[0] = 'O';
        else
            simb[0] = 'X';
    }

    if(vitoria == 1){
        printf("======================================================\n");
        printf("O JOGADOR %c VENCEU!\n", simb[0]);
        printf("======================================================\n");
        }else
            printf("DEU VELHA!\n");
 }
 
 return 0;
}