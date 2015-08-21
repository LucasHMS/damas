#include<iostream>
#include <stdlib.h>
#include "tabuleiro.hpp"
#include "peca.hpp"
#include "move.hpp"
#include "segundomove.hpp"
#include "come.hpp"

using namespace std;

struct tabuleiro move (int iO, int jO, int iF, int jF,tabuleiro tabu, int * j){
	int x,y;
	system ("cls");
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
            if ((i%2==0&&j%2==0)||(i%2!=0&&j%2!=0))
            	tabu.jogavel [i][j]=false;
            else
            	tabu.jogavel [i][j]=true;

        }
    }
    if(((tabu.tab[iO][jO].presenca==1)||(tabu.tab[iO][jO].presenca==2))&&(tabu.jogavel[iO][jO])&&(tabu.jogavel[iF][jF])){


    				///////	PEÇAS DE CIMA	/////////
    	if ((tabu.tab[iO][jO].presenca==1)&&(tabu.tab[iF][jF].presenca==0)){


    		///////	MOVIMENTAÇÃO DE UMA PEÇA NÃO DAMA SEM COMER UMA PEÇA	////////////
    		if (((tabu.jogavel[iF][jF])&&(!tabu.tab[iO][jO].dama))&&(iF==iO+1&&(jF==jO+1||jF==jO-1))){

    			if (iF==7){	//CASO A MOVIMENTAÇÃO SEJA VALIDA E ESSA PEÇA VÁ PARA A ULTIMA CASA, ELA EH TRANSFOMADA EM DAMA
    				tabu.tab[iF][jF].dama=true;
    			}


    			///////	MOVIMENTAÇÃO FEITA NORMALMENTE ///////////
    				tabu.tab[iF][jF].presenca=tabu.tab[iO][jO].presenca;
    				tabu.tab[iO][jO].presenca=0;
    				tabu.tab[iO][jO].dama=false;

    		}


    									//////////////	TRATA OS CASOS DE COMER PEÇAS 	/////////////
    			//////// NAO DAMA -> TESTA SE EXISTE UMA PEÇA PARA COMER ///////////
    		else if (((tabu.jogavel[iF][jF])&&(!tabu.tab[iO][jO].dama))&&(iF==iO+2&&(jF==jO+2||jF==jO-2))){
    			if ((jF==jO+2)&&(tabu.tab[iO+1][jO+1].presenca==2)){
    				x=iO+1;y=jO+1;
    				tabu=come(tabu,x,y,iF,jF,iO,jO );
        			if (iF==7){	//CASO A MOVIMENTAÇÃO SEJA VALIDA E ESSA PEÇA VÁ PARA A ULTIMA CASA, ELA EH TRANSFOMADA EM DAMA
        				tabu.tab[iF][jF].dama=true;
        			}
        			*j=segundomove(tabu,iF,jF);
    			}
    			else if ((jF==jO-2)&&(tabu.tab[iO+1][jO-1].presenca==2)){
    				x=iO+1;y=jO-1;
    				tabu=come(tabu,x,y,iF,jF,iO,jO );

        			if (iF==7){	//CASO A MOVIMENTAÇÃO SEJA VALIDA E ESSA PEÇA VÁ PARA A ULTIMA CASA, ELA EH TRANSFOMADA EM DAMA
        				tabu.tab[iF][jF].dama=true;
        			}
        			*j=segundomove(tabu,iF,jF);

    			}
    			else if (((jF==jO+2)&&(tabu.tab[iO+1][jO+1].presenca!=2))||((jF==jO-2)&&(tabu.tab[iO+1][jO-1].presenca!=2))){
        			cout<< "\n\t\t\tNAO EH POSSIVEL MOVER PARA ESSA CASA!\n";
        			*j=0;
    			}
    		}


			//////// DAMA -> TESTA SE EXISTE UMA PEÇA PARA COMER ///////////
    		else if (((tabu.jogavel[iF][jF])&&(tabu.tab[iO][jO].dama))&&((iF==iO+2||iF==iO-2)&&(jF==jO+2||jF==jO-2))){

    			if ((iF==iO+2&&jF==jO+2)&&(tabu.tab[iO+1][jO+1].presenca==2)){
    				x=iO+1;y=jO+1;
    				tabu=come(tabu,x,y,iF,jF,iO,jO );
    				*j=segundomove(tabu,iF,jF);
        		}
    			else if ((iF==iO+2&&jF==jO-2)&&(tabu.tab[iO+1][jO-1].presenca==2)){
    				x=iO+1;y=jO-1;
    				tabu=come(tabu,x,y,iF,jF,iO,jO );
    				*j=segundomove(tabu,iF,jF);
            	}
        		else if ((iF==iO-2&&jF==jO-2)&&(tabu.tab[iO-1][jO-1].presenca==2)){
        			x=iO-1;y=jO-1;
        			tabu=come(tabu,x,y,iF,jF,iO,jO );
        			*j=segundomove(tabu,iF,jF);
        		}
        		else if ((iF==iO-2&&jF==jO+2)&&(tabu.tab[iO-1][jO+1].presenca==2)){
        			x=iO-1;y=jO+1;
        			tabu=come(tabu,x,y,iF,jF,iO,jO );
        			*j=segundomove(tabu,iF,jF);
        		}
        	}
    		///////////////////////////////////////////////////////////////////////////////////////////////////////////////


    		//////////	MOVIMENTAÇÃO SEM COMER, CASO A PEÇA SEJA DAMA	///////////
    		else if (((tabu.jogavel[iF][jF])&&(tabu.tab[iO][jO].dama))&&((iF==iO+1||iF==iO-1)&&(jF==jO+1||jF==jO-1))){
    			tabu.tab[iF][jF].presenca=tabu.tab[iO][jO].presenca;
    			tabu.tab[iO][jO].presenca=0;
    			tabu.tab[iO][jO].dama=false;
    			tabu.tab[iF][jF].dama=true;
    		}
    		else{
    			cout<< "\n\t\t\tNAO EH POSSIVEL MOVER PARA ESSA CASA!\n";
    			*j=0;
    		}

    	}


    				/////////	PEÇAS DE BAIXO	//////////
    	else if ((tabu.tab[iO][jO].presenca==2)&&(tabu.tab[iF][jF].presenca==0)) {


    		///////	MOVIMENTAÇÃO DE UMA PEÇA NÃO DAMA SEM COMER UMA PEÇA	////////////
    		if (((tabu.jogavel[iF][jF])&&(!tabu.tab[iO][jO].dama))&&(iF==iO-1&&(jF==jO+1||jF==jO-1))){

    			if (iF==0){	//	CASO A MOVIMENTAÇÃO SEJA VALIDA E ESSA PEÇA VÁ PARA A ULTIMA CASA, ELA EH TRANSFOMADA EM DAMA
    				tabu.tab[iF][jF].dama=true;
    			}

    			///////	MOVIMENTAÇÃO FEITA NORMALMENTE ///////////
    			tabu.tab[iF][jF].presenca=tabu.tab[iO][jO].presenca;
    			tabu.tab[iO][jO].presenca=0;
    			tabu.tab[iO][jO].dama=false;

    		}


    								//////////////	TRATA OS CASOS DE COMER PEÇAS 	/////////////
		//////// NAO DAMA -> TESTA SE EXISTE UMA PEÇA PARA COMER ///////////
		else if (((tabu.jogavel[iF][jF])&&(!tabu.tab[iO][jO].dama))&&(iF==iO-2&&(jF==jO+2||jF==jO-2))){
			if ((jF==jO+2)&&(tabu.tab[iO-1][jO+1].presenca==1)){
				x=iO-1;y=jO+1;
				tabu=come(tabu,x,y,iF,jF,iO,jO );

				if (iF==0){	//	CASO A MOVIMENTAÇÃO SEJA VALIDA E ESSA PEÇA VÁ PARA A ULTIMA CASA, ELA EH TRANSFOMADA EM DAMA
					tabu.tab[iF][jF].dama=true;
				}
				*j=segundomove(tabu,iF,jF);

			}
			else if ((jF==jO-2)&&(tabu.tab[iO-1][jO-1].presenca==1)){
				x=iO-1;y=jO-1;
				tabu=come(tabu,x,y,iF,jF,iO,jO );

				if (iF==0){	//	CASO A MOVIMENTAÇÃO SEJA VALIDA E ESSA PEÇA VÁ PARA A ULTIMA CASA, ELA EH TRANSFOMADA EM DAMA
					tabu.tab[iF][jF].dama=true;
				}
				*j=segundomove(tabu,iF,jF);

			}
			else if (((jF==jO+2)&&(tabu.tab[iO-1][jO+1].presenca!=1))||((jF==jO-2)&&(tabu.tab[iO-1][jO-1].presenca!=1))){
    			cout<< "\n\t\t\tNAO EH POSSIVEL MOVER PARA ESSA CASA!\n";
    			*j=0;
			}
		}


		//////// DAMA -> TESTA SE EXISTE UMA PEÇA PARA COMER ///////////
		else if (((tabu.jogavel[iF][jF])&&(tabu.tab[iO][jO].dama))&&((iF==iO+2||iF==iO-2)&&(jF==jO+2||jF==jO-2))){

			if ((iF==iO+2&&jF==jO+2)&&(tabu.tab[iO+1][jO+1].presenca==1)){
				x=iO+1;y=jO+1;
				tabu=come(tabu,x,y,iF,jF,iO,jO );
				*j=segundomove(tabu,iF,jF);
    		}
			else if ((iF==iO+2&&jF==jO-2)&&(tabu.tab[iO+1][jO-1].presenca==1)){
				x=iO+1;y=jO-1;
				tabu=come(tabu,x,y,iF,jF,iO,jO );
				*j=segundomove(tabu,iF,jF);
        	}
    		else if ((iF==iO-2&&jF==jO-2)&&(tabu.tab[iO-1][jO-1].presenca==1)){
    			x=iO-1;y=jO-1;
    			tabu=come(tabu,x,y,iF,jF,iO,jO );
    			*j=segundomove(tabu,iF,jF);
    		}
    		else if ((iF==iO-2&&jF==jO+2)&&(tabu.tab[iO-1][jO+1].presenca==1)){
    			x=iO-1;y=jO+1;
    			tabu=come(tabu,x,y,iF,jF,iO,jO );
    			*j=segundomove(tabu,iF,jF);
    		}
    	}
    	///////////////////////////////////////////////////////////////////////////////////////////////////////////////


    		//////////	MOVIMENTAÇÃO SEM COMER, CASO A PEÇA SEJA DAMA	///////////
    		else if (((tabu.jogavel[iF][jF])&&(tabu.tab[iO][jO].dama))&&((iF==iO+1||iF==iO-1)&&(jF==jO+1||jF==jO-1))){
    			tabu.tab[iF][jF].presenca=tabu.tab[iO][jO].presenca;
    			tabu.tab[iO][jO].presenca=0;
    			tabu.tab[iO][jO].dama=false;
    			tabu.tab[iF][jF].dama=true;

    		}

    		else{
    			cout<< "\n\t\t\tNAO EH POSSIVEL MOVER PARA ESSA CASA!\n";
    			*j=0;
    		}
    	}
    	else{
    		cout<< "\n\t\t\tNAO EH POSSIVEL MOVER PARA ESSA CASA!\n";
    		*j=0;
    	}


    }
    else {
    	cout<< "\n\t\t\tNAO EXISTE UMA PECA NESSA CASA!\n";
    	*j=0;
    }


    imprimetabu(tabu);
    return tabu;
}
