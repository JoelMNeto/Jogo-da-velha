#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

void limpaTela();
void mostraJogo(char casa1, char casa2, char casa3, char casa4, char casa5, char casa6, char casa7, char casa8, char casa9);
void registraJogada(char *casa1, char *casa2, char *casa3, char *casa4, char *casa5, char *casa6, char *casa7, char *casa8, char *casa9, char jogada, char jogador);
int validaJogada(char *casa1, char *casa2, char *casa3, char *casa4, char *casa5, char *casa6, char *casa7, char *casa8, char *casa9, char jogada);
int verificaVencedor(char casa1, char casa2, char casa3, char casa4, char casa5, char casa6, char casa7, char casa8, char casa9, char jogador1, char jogador2);

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");

    char casa1 = '1', casa2 = '2', casa3 = '3',
         casa4 = '4', casa5 = '5', casa6 = '6', casa7 = '7',
         casa8 = '8', casa9 = '9', jogador1, jogador2,
         jogada, resposta;

    int vencedor, jogadaValida = 0;

    do{

        limpaTela();

        printf("\n\t\t___________________________________\n");
        printf("\t\t|                                 |\n");
        printf("\t\t|          JOGO DA VELHA          |\n");
        printf("\t\t|                                 |\n");
        printf("\t\t-----------------------------------\n\n");

        printf("\t\tJOGADOR 1 ESCOLHA [X] OU [O]: ");
        scanf("%c", &jogador1);

        jogador1 = toupper(jogador1);

        getchar();

        while((jogador1 != 'X') && (jogador1 != 'O')){
            printf("\n\t\tOPÇÃO INVÁLIDA, POR FAVOR ESCOLHA [X] OU [O]: ");
            scanf("%c", &jogador1);

            getchar();

            jogador1 = toupper(jogador1);
        }

        if(jogador1 == 'X'){
            jogador2 = 'O';
        }else{
            jogador2 = 'X';   
        }

        printf("\n\t\tO JOGADOR 2 FICOU COM [%c]\n ", jogador2);

        printf("\t\tVAMOS COMEÇAR!\n\n");

        mostraJogo(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);

        do{

            printf("\n\n\t\tJOGADOR 1, SUA VEZ DE JOGAR [DIGITE UM NÚMERO DE 1 A 9 PARA JOGAR]: ");
            scanf("%c", &jogada);
            printf("\n\n");

            getchar();

            limpaTela();

            jogadaValida = validaJogada(&casa1, &casa2, &casa3, &casa4, &casa5, &casa6, &casa7, &casa8, &casa9, jogada);

            while(jogadaValida == 1){
                mostraJogo(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);

                printf("\n\n\t\tESCOLHA OUTRA CASA [DIGITE UM NÚMERO DE 1 A 9]: ");
                scanf("%c", &jogada);
                printf("\n\n");

                limpaTela();

                jogadaValida = validaJogada(&casa1, &casa2, &casa3, &casa4, &casa5, &casa6, &casa7, &casa8, &casa9, jogada);

                getchar();
            }
            
            registraJogada(&casa1, &casa2, &casa3, &casa4, &casa5, &casa6, &casa7, &casa8, &casa9, jogada, jogador1);

            mostraJogo(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
            vencedor = verificaVencedor(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9, jogador1, jogador2);
            
            if(vencedor != 0){
                break;
            }
        
            printf("\n\n\t\tJOGADOR 2, SUA VEZ DE JOGAR [DIGITE UM NÚMERO DE 1 A 9 PARA JOGAR]: ");
            scanf("%c", &jogada);
            printf("\n\n");

            getchar();

            limpaTela();

            jogadaValida = validaJogada(&casa1, &casa2, &casa3, &casa4, &casa5, &casa6, &casa7, &casa8, &casa9, jogada);

            while(jogadaValida == 1){
                mostraJogo(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);

                printf("\n\n\t\tESCOLHA OUTRA CASA [DIGITE UM NÚMERO DE 1 A 9]: ");
                scanf("%c", &jogada);
                printf("\n\n");

                limpaTela();

                jogadaValida = validaJogada(&casa1, &casa2, &casa3, &casa4, &casa5, &casa6, &casa7, &casa8, &casa9, jogada);

                getchar();
            }

            registraJogada(&casa1, &casa2, &casa3, &casa4, &casa5, &casa6, &casa7, &casa8, &casa9, jogada, jogador2);            

            mostraJogo(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9);
            vencedor = verificaVencedor(casa1, casa2, casa3, casa4, casa5, casa6, casa7, casa8, casa9, jogador1, jogador2);

        } while(vencedor == 0);

        if(vencedor == 1){
            printf("\n\n\t\t VITÓRIA DO JOGADOR 1!\n");
        } else if(vencedor == 2){
            printf("\n\n\t\t VITÓRIA DO JOGADOR 2!\n");
        } else if(vencedor == 3){
            printf("\n\n\t\t DEU VELHA.\n");
        }

        printf("\n\n\t\t REINICIAR JOGO? [S/N]: ");
        scanf("%c", &resposta);
        printf("\n\n");
        resposta = toupper(resposta);

    } while(resposta == 'S');
    
    return 0;
}

void mostraJogo(char casa1, char casa2, char casa3, char casa4, char casa5, char casa6, char casa7, char casa8, char casa9){

    printf("\t\t___________________\n");
    printf("\t\t|     |     |     |\n");
    printf("\t\t|  %c  |  %c  |  %c  | \n", casa1, casa2, casa3);
    printf("\t\t|     |     |     |\n");
    printf("\t\t|-----------------|\n");
    printf("\t\t|     |     |     |\n");
    printf("\t\t|  %c  |  %c  |  %c  | \n", casa4, casa5, casa6);
    printf("\t\t|     |     |     |\n");
    printf("\t\t|-----------------|\n");
    printf("\t\t|     |     |     |\n");
    printf("\t\t|  %c  |  %c  |  %c  | \n", casa7, casa8, casa9);
    printf("\t\t|     |     |     |\n");
    printf("\t\t-------------------\n");
}

void registraJogada(char *casa1, char *casa2, char *casa3, char *casa4, char *casa5, char *casa6, char *casa7, char *casa8, char *casa9, char jogada, char jogador){

    switch (jogada) {
        case '1':
            *casa1 = jogador;
            break;
        case '2':
            *casa2 = jogador;
            break;
        case '3':
            *casa3 = jogador;
            break;
        case '4':
            *casa4 = jogador;
            break;
        case '5':
            *casa5 = jogador;
            break;
        case '6':
            *casa6 = jogador;
            break;
        case '7':
            *casa7 = jogador;
            break;
        case '8':
            *casa8 = jogador;
            break;
        default:
            *casa9 = jogador;

            if(jogada != '9'){
                printf("\n\n\t\tJOGADA INVÁLIDA, REGISTRADA NA CASA 9.\n\n");
            }

            break;
    }
    
}

int verificaVencedor(char casa1, char casa2, char casa3, char casa4, char casa5, char casa6, char casa7, char casa8, char casa9, char jogador1, char jogador2){

    if (((jogador1 == casa1) && (jogador1 == casa2) && (jogador1 == casa3)) || ((jogador1 == casa4) && (jogador1 == casa5) && (jogador1 == casa6)) ||
    ((jogador1 == casa7) && (jogador1 == casa8) && (jogador1 == casa9)) || ((jogador1 == casa1) && (jogador1 == casa4) && (jogador1 == casa7)) || 
    ((jogador1 == casa2) && (jogador1 == casa5) && (jogador1 == casa8)) || ((jogador1 == casa3) && (jogador1 == casa6) && (jogador1 == casa9)) ||
    ((jogador1 == casa1) && (jogador1 == casa5) && (jogador1 == casa9)) || ((jogador1 == casa3) && (jogador1 == casa5) && (jogador1 == casa7)) 
    ){
        return 1;
    }

    if (((jogador2 == casa1) && (jogador2 == casa2) && (jogador2 == casa3)) || ((jogador2 == casa4) && (jogador2 == casa5) && (jogador2 == casa6)) ||
    ((jogador2 == casa7) && (jogador2 == casa8) && (jogador2 == casa9)) || ((jogador2 == casa1) && (jogador2 == casa4) && (jogador2 == casa7)) || 
    ((jogador2 == casa2) && (jogador2 == casa5) && (jogador2 == casa8)) || ((jogador2 == casa3) && (jogador2 == casa6) && (jogador2 == casa9)) ||
    ((jogador2 == casa1) && (jogador2 == casa5) && (jogador2 == casa9)) || ((jogador2 == casa3) && (jogador2 == casa5) && (jogador2 == casa7)) 
    ){
        return 2;
    }

    if((!(casa1 == '1')) && (!(casa2 == '2')) && (!(casa3 == '3')) && (!(casa4 == '4')) && (!(casa5 == '5')) && (!(casa6 == '6')) && (!(casa7 == '7')) && 
    (!(casa8 == '8')) && (!(casa9 == '9'))){
        return 3;
    }

    return 0;
}

void limpaTela(){
    #ifdef _WIN64
        system("cls");
    #elif __linux
        system("clear");
    #endif
}

int validaJogada(char *casa1, char *casa2, char *casa3, char *casa4, char *casa5, char *casa6, char *casa7, char *casa8, char *casa9, char jogada){

    switch (jogada) {
        case '1':
            
            if(*casa1 == 'X' || *casa1 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 1 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        case '2':

            if(*casa2 == 'X' || *casa2 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 2 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        case '3':
            
            if(*casa3 == 'X' || *casa3 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 3 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        case '4':

            if(*casa4 == 'X' || *casa4 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 4 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        case '5':
            
            if(*casa5 == 'X' || *casa5 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 5 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        case '6':
            
            if(*casa6 == 'X' || *casa6 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 6 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        case '7':
            
            if(*casa7 == 'X' || *casa7 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 7 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        case '8':

            if(*casa8 == 'X' || *casa8 == 'O'){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 8 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
        default:

            if(jogada == '9' && (*casa9 == 'X' || *casa9 == 'O')){
                printf("\n\n\t\tJOGADA INVÁLIDA, A CASA 9 NÃO ESTÁ VAZIA!\n\n");
                return 1;
            }

            break;
    }

    return 0;
}