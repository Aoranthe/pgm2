//GRR 20184567
//Glaide de Lara Oliveira


#ifndef __pgmrot__
#define __pgmtot__
#include "struct.h"

// funcao que acha o novo tamanho da imagem rotacionada
void tamanho(img_pgm *img,img_pgm *nova ,int angulo);
// funcao que rotaciona a nova imagem 
void rotacao(img_pgm *img, img_pgm *nova, int angulo);


#endif
