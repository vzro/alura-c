#include <stdio.h>

int main() {
    printf("*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação! *\n");
    printf("*******************************************\n");

    int numerosecreto = 42;
    int chute;
    
    printf("Qual o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d\n", chute);
}