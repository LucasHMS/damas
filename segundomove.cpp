/*
 * segundomove.cpp
 *
 *  Created on: 19/06/2015
 *      Author: Lucas
 */
#include<iostream>
#include <stdlib.h>
#include "tabuleiro.hpp"
#include "peca.hpp"
#include "segundomove.hpp"

using namespace std;

int segundomove(tabuleiro tabu,int iF,int jF){
	int a=-1;
	///////////// OBSERVAÇÃO	///////////
	//	iF e jF, NESSA FUNÇÃO, AGORA SE  //
	//	REFEREM A POSIÇÕES INICIAIS		 //
	///////////////////////////////////////

	a=-1;
	//////////////	PEÇAS DE CIMA	/////////////////
	if (tabu.tab[iF][jF].presenca==1){
		if (((tabu.tab[iF+1][jF+1].presenca==2)&&(!tabu.tab[iF][jF].dama))&&(tabu.tab[iF+2][jF+2].presenca==0))
			a=2;

		else if (((tabu.tab[iF+1][jF-1].presenca==2)&&(!tabu.tab[iF][jF].dama))&&(tabu.tab[iF+2][jF-2].presenca==0))
			a=2;


		////// DAMA	///////
		else if (((tabu.tab[iF+1][jF+1].presenca==2||tabu.tab[iF-1][jF+1].presenca==2))&&(tabu.tab[iF][jF].dama)){
			if ((tabu.tab[iF+2][jF+2].presenca==0)&&(tabu.tab[iF+1][jF+1].presenca==2))
				a=2;
			else if ((tabu.tab[iF+2][jF+2].presenca==0)&&(tabu.tab[iF+1][jF-1].presenca==2))
				a=2;
			else if ((tabu.tab[iF-2][jF+2].presenca==0)&&(tabu.tab[iF-1][jF+1].presenca==2))
				a=2;
			else if ((tabu.tab[iF-2][jF+2].presenca==0)&&(tabu.tab[iF-1][jF-1].presenca==2))
				a=2;
			else a=-1;
		}
		else if (((tabu.tab[iF+1][jF-1].presenca==2||tabu.tab[iF-1][jF-1].presenca==2))&&(tabu.tab[iF][jF].dama)){
			if ((tabu.tab[iF+2][jF-2].presenca==0)&&(tabu.tab[iF+1][jF-1].presenca==2))
				a=2;
			else if ((tabu.tab[iF+2][jF-2].presenca==0)&&(tabu.tab[iF+1][jF+1].presenca==2))
				a=2;
			else if ((tabu.tab[iF-2][jF-2].presenca==0)&&(tabu.tab[iF-1][jF+1].presenca==2))
				a=2;
			else if ((tabu.tab[iF-2][jF-2].presenca==0)&&(tabu.tab[iF-1][jF-1].presenca==2))
				a=2;

			else a=-1;
		}
		else a=-1;
	}



	//////////////	PEÇAS DE BAIXO	/////////////////
	else if (tabu.tab[iF][jF].presenca==2){
		if (((tabu.tab[iF-1][jF+1].presenca==1)&&(!tabu.tab[iF][jF].dama))&&(tabu.tab[iF-2][jF+2].presenca==0))
			a=2;

		else if (((tabu.tab[iF-1][jF-1].presenca==1)&&(!tabu.tab[iF][jF].dama))&&(tabu.tab[iF-2][jF-2].presenca==0))
			a=2;


		////// DAMA	//////////
		else if (((tabu.tab[iF+1][jF+1].presenca==1||tabu.tab[iF-1][jF+1].presenca==1))&&(tabu.tab[iF][jF].dama)){
			if ((tabu.tab[iF+2][jF+2].presenca==0)&&(tabu.tab[iF+1][jF+1].presenca==1))
				a=2;
			else if ((tabu.tab[iF+2][jF+2].presenca==0)&&(tabu.tab[iF+1][jF-1].presenca==1))
				a=2;
			else if ((tabu.tab[iF-2][jF+2].presenca==0)&&(tabu.tab[iF-1][jF+1].presenca==1))
				a=2;
			else if ((tabu.tab[iF-2][jF+2].presenca==0)&&(tabu.tab[iF-1][jF-1].presenca==1))
				a=2;
			else a=-1;
		}
		else if (((tabu.tab[iF+1][jF-1].presenca==1||tabu.tab[iF-1][jF-1].presenca==1))&&(tabu.tab[iF][jF].dama)){
			if ((tabu.tab[iF+2][jF-2].presenca==0)&&(tabu.tab[iF+1][jF-1].presenca==1))
				a=2;
			else if ((tabu.tab[iF+2][jF-2].presenca==0)&&(tabu.tab[iF+1][jF+1].presenca==1))
				a=2;
			else if ((tabu.tab[iF-2][jF-2].presenca==0)&&(tabu.tab[iF-1][jF+1].presenca==1))
				a=2;
			else if ((tabu.tab[iF-2][jF-2].presenca==0)&&(tabu.tab[iF-1][jF-1].presenca==1))
				a=2;
			else a=-1;
		}
		else a=-1;
	}
	return a;
}


