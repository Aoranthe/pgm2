//GRR 20184567
//Glaide de Lara Oliveira


#ifndef __struct__
#define __struct__		

typedef struct img_pgm
{
	char tipo[2];
	unsigned int linha;
	unsigned int coluna;
	unsigned int cinza;
	unsigned int *matriz;
}img_pgm;


#endif
