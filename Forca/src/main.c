#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include  "../include/DesenharForca.h"
#include "../include/LogicaForca.h"

// 1. Iniciar Jogo
//
void Menu(void){
    printf("---------------\n");
    printf("1.Iniciar Jogo \n");
    printf("2.Regras\n");
    printf("3.Sair\n");
}
void LidarMenu(int opcao){
    switch(opcao){
        case 1:
		Start();
		break;
	case 2:
		break;
	case 3:
		break;
    }
}
int main(void){
    int qtd_erros= 0;
    int opcao;
    Menu();
    do{
    printf("Digite a opção: ");
    scanf("%d", &opcao);
    }while(opcao > 3 || opcao < 1);
    LidarMenu(opcao);
    return 0;
}
