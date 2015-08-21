#include "peca.hpp"
#ifndef TABULEIRO_HPP_
#define TABULEIRO_HPP_

struct tabuleiro {
    bool jogavel[8][8];
    struct peca tab[8][8];
};
void imprimetabu(tabuleiro tabu);

#endif /* TABULEIRO_HPP_ */
