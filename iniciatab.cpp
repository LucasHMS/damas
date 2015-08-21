/*
 * iniciatab.cpp
 *
 *  Created on: 17/06/2015
 *      Author: Lucas
 */

#include<iostream>
#include <stdlib.h>
#include "tabuleiro.hpp"
#include "peca.hpp"

using namespace std;

struct tabuleiro iniciatab(tabuleiro tabu){
	for (int i=0;i<8;i++){
	        for (int j=0;j<8;j++){
	            if ((i%2==0&&j%2==0)||(i%2!=0&&j%2!=0))
	            	tabu.jogavel [i][j]=false;
	            else{
	            	tabu.jogavel [i][j]=true;
	            }

	        }
	    }
		for (int i=0;i<8;i++){
			for (int j=0;j<8;j++){
				tabu.tab[i][j].presenca=0;
				tabu.tab[i][j].dama=false;
			}
		}
		for (int i=0;i<3;i++){
			for (int j=0;j<8;j++){
				if (tabu.jogavel[i][j])
					tabu.tab[i][j].presenca=1;
				else
					tabu.tab[i][j].presenca=0;
			}
		}

		for (int i=5;i<8;i++){
			for (int j=0;j<8;j++){
				if (tabu.jogavel[i][j])
					tabu.tab[i][j].presenca=2;
				else
					tabu.tab[i][j].presenca=0;
			}
		}
	return tabu;
}
