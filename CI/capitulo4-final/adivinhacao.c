#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // imprime cabecalho do nosso jogo
    printf("                                                                         \n");
    printf("                                 ,.=,,==. ,,_                            \n");
    printf("            _ ,====, _    |I|`` ||  `|I `|                               \n");
    printf("           |`I|    || `==,|``   ^^   ``  |      Bem vindos ao nosso      \n");
    printf("           | ``    ^^    ||_,===TT`==,,_ |          jogo de adivinhação! \n");
    printf("           |,==Y``Y==,,__| \\L=_-`'   +J/`                               \n");
    printf("            \\|=_  ' -=#J/..-|=_-     =|                                 \n");
    printf("             |=_   -;-='`. .|=_-     =|----T--,                          \n");
    printf("             |=/\\  -|=_-. . |=_-/^\\  =||-|-|::|____                    \n");
    printf("             |=||  -|=_-. . |=_-| |  =|-|-||::\\____                     \n");
    printf("             |=LJ  -|=_-. . |=_-|_| =||-|-|:::::::                       \n");
    printf("             |=_   -|=_-_.  |=_-     =|-|-||:::::::                      \n");
    printf("             |=_   -|=//^\\. |=_-     =||-|-|:::::::                     \n");
    printf("         ,   |/&_,_-|=||  | |=_-     =|-|-||:::::::                      \n");
    printf("      ,--``8%%,/    ',%%||  | |=_-     =||-|-|%%::::::                   \n");
    printf("  ,---`_,888`  ,.'''''`-.,|,|/!,--,.&\\|&\\-,|&#:::::                    \n");
    printf(" |;:;K`__,...;=\\_____,=``           %%%%%%&     %%#,---                 \n");
    printf(" |;::::::::::::|       `'.________+-------\\   ``                        \n");
    printf("/8M%%;:::;;:::::|                  |        `-------                     \n");
    printf("                                                                         \n");

    int segundos = time(0);
    srand(segundos);
    
    int numerogrande = rand();

    int numerosecreto = numerogrande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;

    printf("\nQual o nível de dificuldade?\n");
    printf("(1) Fácil (2) Médio (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numerodetentativas;

    switch(nivel) {
        case 1:
            numerodetentativas = 20;
            break;
        case 2:
            numerodetentativas = 15;
            break;
        default:
            numerodetentativas = 6;
            break;
    }

    for(int i = 1; i <= numerodetentativas; i++) {
        
        printf("\nTentativa %d\n", tentativas);
        printf("Qual o seu chute? ");
        
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0) {
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;
    
        if(acertou) {
            break;
        }
        else if(maior) {
            printf("Seu chute foi maior que o número secreto\n");
        }
        else {
            printf("Seu chute foi menor que o número secreto\n");
        }
    
        tentativas++;
        
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }

    printf("\nFim de jogo!\n");

    if(acertou) {
        printf("\n\\(^-^)/\n\n");
        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }
    else {
        printf("\n¯\\_(ツ)_/¯ \n\n");
        printf("Você perdeu! Tente de novo!\n");
    }

}
