//GRR 20184567
//Glaide de Lara Oliveira


#ifndef __pgmrot__
#define __pgmtot__
#include "struct.h"

//funcao que passa por toda a matriz calculando o novo valor
unsigned int* walk_matriz(img_pgm *img, unsigned int angulo, int l, int c);
//funcao que calcula a nova coordenada
int c_angx(unsigned int angulo,unsigned int i, unsigned int j);
//funcao que calcula a nova coordenada
int c_angy(unsigned int angulo,unsigned int i, unsigned int j);
//para calcular nova linha e largura
unsigned int lc(img_pgm *img, unsigned int angulo);
//funcao que acha novos paramentros da matriz
int linha(img_pgm *img, unsigned int angulo);
int coluna(img_pgm *img, unsigned int angulo);
#endif
