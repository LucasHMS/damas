#include<iostream>
#include <stdlib.h>
#include "tabuleiro.hpp"
#include "peca.hpp"

using namespace std;

void imprimetabu(tabuleiro tabu){
	char esp=219;
	for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if ((i%2==0&&j%2==0)||(i%2!=0&&j%2!=0))
            	tabu.jogavel [i][j]=false;
            else
            	tabu.jogavel [i][j]=true;

        }
    }

	cout << "\t\t\t    1  2  3  4  5  6  7  8";
	cout << endl;
	cout << "\t\t\t   ------------------------";
	cout << endl;
    for (int i=0;i<8;i++){
		cout <<"\t\t\t"<< i+1 << " |";
		for (int j=0;j<8;j++){

            if (!tabu.jogavel [i][j])
                cout << esp<<esp<<esp ;
            else if (tabu.tab[i][j].presenca==1 && !tabu.tab[i][j].dama )
            	cout << " x" << " ";
            else if (tabu.tab[i][j].presenca==1 && tabu.tab[i][j].dama )
            	cout << " X" << " ";
            else if (tabu.tab[i][j].presenca==2 && !tabu.tab[i][j].dama )
            	cout << " o" << " ";
            else if (tabu.tab[i][j].presenca==2 && tabu.tab[i][j].dama )
            	cout << " O" << " ";
            else
             	cout << "  " << " ";
            }
		cout << "|";
         cout<<endl;
        }
	cout << "\t\t\t   ------------------------";
}
