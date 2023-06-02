#include <stdlib.h>
#include <stdio.h>

int main(){
    char posicoes[3][3];
    char simb, sgameon[3], si[3],sj[3];
    int gameon = 1, vitoria = 0;
    int i, j, count;
    char barrav = 179, barrah = 196, ligacao = 197;

    while (gameon){
        printf("JOGO DA VELHA!!\n(1) Jogar \n(0) Sair \n");
        fflush(stdin);
        fgets(sgameon, 3, stdin);
        
         if (sgameon[0] != '0' && sgameon[0] != '1'){
            system("cls");
            printf("Erro -> Simbolo incorreto\n");
            continue;
        }
        gameon = atoi(sgameon);
        system("cls");

        if (gameon==0)
            break;
        
        while (1){ 
            printf ("Escolha seu simbolo (X ou O):\n");
            fflush(stdin);
            simb = getchar();
            getchar(); // pegar o \n 
            if(simb == 'x' || simb == 'X'){
                simb = 'X';
                system("cls");
                break;
            }
            else if(simb == 'o' || simb == 'O'){
                simb = 'O';
                system("cls");
                break;
            }
                printf("Erro -> Simbolo incorreto\n");
        }
        //inicializa a matriz com ' ' em todas as posicoes
        for(i=0;i<3;i++){
            for (j=0;j<3;j++){
                posicoes[i][j] = 32;
            }
        }

        for(count=1;count<10;count++){ //contador de rodadas
            printf("Rodada %d. Vez de %c.\n",count,simb);
            printf("Digite a posicao desejada:\n (1,2,3)Linha\n");
            fgets(si,3,stdin);

            printf("(1,2,3)Coluna\n");
            fgets(sj,3,stdin);

            if((si[0]!='1' && si[0]!='2' && si[0]!='3') || (sj[0]!='1' && sj[0]!='2' && sj[0]!='3')){
                printf("Erro -> Simbolo invalido!\n");
                count--;
                continue;
            }

            i = atoi(si) - 1;
            j = atoi(sj) - 1;

            if(posicoes[i][j] == 'X' || posicoes[i][j] == 'O'){
                printf("Erro -> Posicao ja preenchida!\n");
                count--;
                continue;
            }
            else{
                posicoes[i][j] = simb;
                system("cls");
                //printa o tabuleiro na tela
                for(i=0;i<3;i++){
                    for(j=0;j<3;j++){
                        if(j==0 || j==1) 
                            printf(" %c %c", posicoes[i][j],barrav);   
                        else
                            printf(" %c \n", posicoes[i][j]);
                    }
                    if (i<2){
                        for(j=0;j<2;j++)
                              printf("%c%c%c%c",barrah,barrah,barrah,ligacao);
                        printf("%c%c%c\n",barrah,barrah,barrah);
                    }
                }
                printf("\n");

                //antes da quinta jogada, n tem como ganhar
                if(count < 5) {
                    if(simb == 'X')
                        simb = 'O';
                    else
                        simb = 'X';
                    continue;
                }

                for (i=0; i<3; i++){
                    if ((posicoes[i][0] == posicoes[i][1]) && (posicoes[i][0]==posicoes[i][2])&&((posicoes[i][0] == 'X')||(posicoes[i][0] == 'O')))
                        vitoria =1;
                    
                }
                for (j=0; j<3; j++){
                    if ((posicoes[0][j] == posicoes[1][j]) && (posicoes[0][j]==posicoes[2][j]) && ((posicoes[0][j] == 'X')||(posicoes[0][j] == 'O')))
                        vitoria = 1;
                    
                }
                if(((posicoes[0][0] == posicoes[1][1] && posicoes[0][0] == posicoes[2][2]) || (posicoes[2][0] == posicoes[1][1] && posicoes[2][0] == posicoes[0][2]))
                &&((posicoes[1][1] == 'X')||(posicoes[1][1] == 'O')))
                    vitoria = 1;
                
                if(vitoria==1)
                    break;


                //troca de time no fim do turno
                if(simb == 'X')
                    simb = 'O';
                else
                    simb = 'X';
            }
        }
            if(vitoria == 1){
                if(simb == 'X'){
                   printf("\nO JOGADOR X VENCEU!\n");
                   printf("O JOGADOR O PERDEU!\n\n"); 
                }
                else{
                    printf("\nO JOGADOR O VENCEU!\n");
                    printf("O JOGADOR X PERDEU!\n\n");
                }
            }

            else
                printf("DEU VELHA!\n");
        
    }
    return 0;
}
