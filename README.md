# damas
Jogo de Damas

Jogo desenvolvido como trabalho final do primeiro semestre do curso de cinência da computação da 
Universidade Federal de Ouro Preto(UFOP).

CARACTERISTICAS:
- O direcionamento da peça é feito pela entrada de suas coordenadas
- A unica forma de se finalizar o jogo é comendo todas as peças do adversário
- Quando uma peça se torna DAMA ela só poderá se movimentar uma casa por vez, diferentemente do jogo tradicional, onde 
a dama pode percorrer várias casas na mesma jogada.

BUGs:
- Ao testar a possibilidade de um segundo movimento para um mesmo jogador poode acontecer falso-positivo
- Quando o jogador tem a confirmação de um segundo movimento valido, ele pode mover qualquer peça que seja sua, 
mesmo não sendo a peça para qual foi testado o segundo movimento,e desde que a movimentação com a peça escolida 
seja valida o programa irá aceitar.
