#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(){
	int op, cont=0;
	while(!cont){
		printf("JOGO DA VELHA!!!\n1 - Jogar\n2 - Instrucoes\n3 - Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Prepare-se para jogar!\n");
				cont++;
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				printf("Regra do jogo aqui...\n");
				system("pause");
				system("cls");
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("Opcao invalida!\n");
				system("pause");
				system("cls");	
				break;
		}
	}
}

char tab [4][4] = {{'#','1','2','3'},
				   {'1','-','-','-'},
				   {'2','-','-','-'},
				   {'3','-','-','-'}};

void tabuleiro(){
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%c ",tab[i][j]);
		}
		printf("\n");
	}
}

void marcarPos(char ins){
	int lin, col, i, j;
	printf("digite a linha e coluna que deseja marcar o %c: ", ins);
	scanf("%d %d", &lin, &col);
	if(verificarJogada(lin, col)){
		tab[lin][col] = ins;
		system("cls");
		tabuleiro();
	}
	else{
		printf("Posicao invalida!");
		system("pause");
		system("cls");
		marcarPos(ins);
	}
}

int venceu(){
	//checando colunas
	if(tab[1][1] == tab[2][1] && tab[2][1] == tab[3][1] && tab[1][1] != '-'){
		printf("%c venceu!", tab[1][1]);
		return 1;
	}	
	else if(tab[1][2] == tab[2][2] && tab[2][2] == tab[3][2] && tab[1][2] != '-'){
		printf("%c venceu!", tab[1][2]);
		return 1;
	}
	else if(tab[1][3] == tab[2][3] && tab[2][3] == tab[3][3] && tab[1][3] != '-'){
		printf("%c venceu!", tab[1][3]);
		return 1;
	}
	//checando linhas
	else if(tab[1][1] == tab[1][2] && tab[1][2] == tab[1][3] && tab[1][1] != '-'){
		printf("%c venceu!", tab[1][1]);
		return 1;
	}
	else if(tab[2][1] == tab[2][2] && tab[2][2] == tab[2][3] && tab[2][1] != '-'){
		printf("%c venceu!", tab[2][1]);
		return 1;
	}
	else if(tab[3][1] == tab[3][2] && tab[3][2] == tab[3][3] && tab[3][1] != '-'){
		printf("%c venceu!", tab[3][1]);
		return 1;
	}
	//checando diagonais
	else if(tab[1][1] == tab[2][2] && tab[2][2] == tab[3][3] && tab[1][1] != '-'){
		printf("%c venceu!", tab[1][1]);
		return 1;
	}
	else if(tab[3][1] == tab[2][2] && tab[2][2] == tab[1][3] && tab[3][1] != '-'){
		printf("%c venceu!", tab[3][1]);
		return 1;
	}
	//ninguem venceu ainda
	return 0;
}

int verificarJogada(int lin, int col){ //verificar posicoes
	if(tab[lin][col]=='-') return 1;
	return 0;
}

int main(){
	int sair = 0, op;
	while(!sair){
		menu();
		tabuleiro();
		while(1){
			marcarPos('X');
			if(venceu())break;
			marcarPos('0');
			if(venceu())break;
		}
		system("pause");
		system("cls");
		printf("Deseja jogar novamente?\n");
		printf("1 - Sim\n2 - Nao\n");
		scanf("%d", &op);
		if(op==2)sair++;
		else system("cls");
	}
	
	return 0;
}

