/*
 * come.cpp
 *
 *  Created on: 17/06/2015
 *      Author: Lucas
 */
#include<iostream>
#include <stdlib.h>
#include "tabuleiro.hpp"
#include "peca.hpp"

using namespace std;

struct tabuleiro come(tabuleiro tabu, int x,int y,int iF,int jF,int iO,int jO){
	if(tabu.tab[iO][jO].presenca==1){
		if (tabu.tab[iO][jO].dama){
			if (tabu.tab[x][y].dama){
				tabu.tab[iF][jF].dama=false;
				tabu.tab[x][y].dama=false;
			}
			tabu.tab[iO][jO].presenca=0;
			tabu.tab[iF][jF].presenca=1;
			tabu.tab[x][y].presenca=0;
			tabu.tab[iO][jO].dama=false;
			tabu.tab[iF][jF].dama=true;
		}
		else{
			if (tabu.tab[x][y].dama){
				tabu.tab[iF][jF].dama=false;
				tabu.tab[x][y].dama=false;
			}
			tabu.tab[iO][jO].presenca=0;
			tabu.tab[iF][jF].presenca=1;
			tabu.tab[x][y].presenca=0;
			tabu.tab[iO][jO].dama=false;
		}
	}
	else if(tabu.tab[iO][jO].presenca==2){
		if (tabu.tab[iO][jO].dama){
			if (tabu.tab[x][y].dama){
				tabu.tab[iF][jF].dama=false;
				tabu.tab[x][y].dama=false;
			}
			tabu.tab[iO][jO].presenca=0;
			tabu.tab[iF][jF].presenca=2;
			tabu.tab[x][y].presenca=0;
			tabu.tab[iO][jO].dama=false;
			tabu.tab[iF][jF].dama=true;
		}
		else{
			if (tabu.tab[x][y].dama){
				tabu.tab[iF][jF].dama=false;
				tabu.tab[x][y].dama=false;
			}
			tabu.tab[iO][jO].presenca=0;
			tabu.tab[iF][jF].presenca=2;
			tabu.tab[x][y].presenca=0;
			tabu.tab[iO][jO].dama=false;
		}
	}
	return tabu;
}


