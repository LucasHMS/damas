//============================================================================
// Name        : main.cpp
// Author      : Lucas
// Version     : 0.1
// Copyright   :
// Description : Main File
//============================================================================

#include<iostream>
#include <stdlib.h>
#include "tabuleiro.hpp"
#include "peca.hpp"
#include "move.hpp"
#include "iniciatab.hpp"

using namespace std;

int main (){
	struct tabuleiro tabu; //TABULEIO QUE VAI SER USADO NO JOGO

	int 	i=0,		//CONTADOR BASICO PARA DETEMINAR A VEZ DE CADA JOGADOR
			j,	  		//VARIVEL QUE VERIFICA, NA FUN��O DE MOVIMENTO, SE A JOGADA TEVE ERRO OU FOI VALIDA
			iO,jO,		//COORDENADAS DA PE�A A SER MOVIDA
			iF,jF,		//COORDENADAS PARA ONDE A PE�A VAI SER MOVIDA
			p1=0, p2=0; //PONTUA��O PARA CADA JOGADOR


	tabu=iniciatab(tabu); //INICIALIZA O TABULEIRO COM AS PARTES JOGAVEIS E AS PE�AS EM SUAS POSI��ES INICIAIS E RETORNA O MESMO

	imprimetabu(tabu);	//IMPRIME O TABULEIRO NA TELA

	cout<< "\n\n\t\t\t\tINSTRUCOES:\n1- TIRE PAR OU IMPAR PARA DECIDIR QUEM COMECA\n2- CASO NAO TENHA MAIS MOVIMENTOS POSSIVEIS PRESIONE crtl+c PARA FINAIZAR O JOGO\n\n";


	while (1){
		p1=0;	//RESETA A PONTUA��O O JOGADOR 1
		p2=0;	//RESETA A PONTUA��O O JOGADOR 1
		j=1;


		////////	DETERMINA QUAL JOGADOR JOGA E PEDE AS COORDENADAS DA PE�A E DA POSI��O QUE RECEBE ESSA PE�A		/////////
		if (i%2==0)
			cout<< "\nVEZ DO JOGADOR 1 (x)\n";
		else
			cout<< "\nVEZ DO JOGADOR 2 (o)\n";

		cout << "\nDigite a linha da peca que deseja mover: ";
		cin>> iO;
		iO-=1;
		cout << "\nDigite a coluna da peca que deseja mover: ";
		cin>> jO;
		jO-=1;
		cout << "\nDigite a linha para onde deseja mover: ";
		cin>> iF;
		iF-=1;
		cout << "\nDigite a coluna para onde deseja mover: ";
		cin>> jF;
		jF-=1;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		///////////////		TESTA A VEZ DE CADA JOGADOR	E A EXISTENCIA DA PECA ESCOLHIDA, CASO POSITIVO, CHAMA A FUN��O DE MOVIMENTA��O		////////////////
		if(i%2==0&&tabu.tab[iO][jO].presenca==1){
			tabu=move(iO,jO,iF,jF,tabu,&j);
			if (j==0)
				i--;
			else if (j==2){
				system("cls");
				imprimetabu(tabu);
				cout<< "\n\t\t\tJOGADOR 1 TEM MAIS UMA JOGADA!!\n";
				i--;
			}
		}
		else if (i%2==0&&tabu.tab[iO][jO].presenca==2){
			system("cls");
			imprimetabu(tabu);
			cout<< "\n\t\t\tESSA PECA NAO EH SUA!!\n";
			i--;
		}

		else if(i%2!=0&&tabu.tab[iO][jO].presenca==2){
			tabu=move(iO,jO,iF,jF,tabu,&j);
			if (j==0)
				i--;
			else if (j==2){
				system("cls");
				imprimetabu(tabu);
				cout<< "\n\t\t\tJOGADOR 2 TEM MAIS UMA JOGADA!!\n";
				i--;
			}
		}
		else if (i%2!=0&&tabu.tab[iO][jO].presenca==1){
			system("cls");
			imprimetabu(tabu);
			cout<< "\n\t\t\tESSA PECA NAO EH SUA!!\n";
			i--;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		///////////			CASO N�O ENTRE EM NENHUMA DAS CONDI��ES ANTERIORES, VERIFICA CASOS ESPECIAIS DE ERRO NA SELE��O DA PE�A E POSI��O FINAL		///////////
		else if (iO<1||jO<1||iO>8||jO>8||!tabu.jogavel[iO][jO]||!tabu.jogavel[iF][jF]||tabu.tab[iO][jO].presenca==0){
			system("cls");
			imprimetabu(tabu);
			cout<< "\n\t\t\tNAO EH POSSIVEL ULTILZAR ESSA CASA!\n";
			i--;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



		i++; //INCREMENTA O CONTADOR PARA AS JOGADAS DE CADA UM



		//////		CONTA QUANTAS PE�AS RESTAM PARA CADA JOGADOR 	//////
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				if (tabu.tab[i][j].presenca==1)
					p1++;
				else if (tabu.tab[i][j].presenca==2)
					p2++;
			}
		}
		/////////////////////////////////////////////////////////////////


		if(p1==0||p2==0)	break;//VERIFICA SE ALGUEM GANHOU E QUEBRA O LA�O PARA FINALIZAR O JOGO

	}

	//////	VERIFICA QUEM VENCEU E ENCERRA A EXECU��O DO CODIGO 	//////
	if (p1==0)
		cout<< "\n\t\t\tJOGADOR 2 VENCEU COM "<< i<<" JOGADAS!\n";
	else if (p2==0)
		cout<< "\n\t\t\tJOGADOR 1 VENCEU COM "<< i<<" JOGADAS!\n";
	//////////////////////////////////////////////////////////////////////

	return 0;
}
