//GRR 20184567
//Glaide de Lara Oliveira	


#include "struct.h"
#include <stdlib.h>
#include "pgmrot.h"
#include <math.h>
#include "openimg.h"
#include <getopt.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#define tam 4
#define pi 3.1415
#define rad(a) ((a*pi)/180)

int main (int argc, char **argv)
{	
	int option, angulo;
	char *entrada=NULL;
	char *saida=NULL;	
	
	while((option=getopt(argc,argv,"i:o:")) > 0)
	{
	    switch (option)
	    {
			/******MUDAR AS OPÇÕES DE LEITURA*******/
	        case 'i':
	            entrada=optarg; //caso tenha a opção -i
	        break;	

	        case 'o':
	            saida=optarg; //caso tenha a opção -o
	        break;

			case 'a': 
			{	//caso n seja passado um valor
				if (optarg==NULL)
					angulo=90; 
				 
				else //converte para ser tratado como int
					angulo=atoi(optarg);
			}
			default:
				fprintf(stderr, "Entrada invalida.\n");
				return -1;
	    }
	}

	
    img_pgm *img=malloc(sizeof(img_pgm));
    parametros(img,entrada);

	/*FAZER TODAS AS FUNÇÕES RELACIONADAS A ANGULOS*/
	
	img_pgm *nova;
	
	// achar o novo tamanho da matriz
	nova->matriz=tamanho(img,angulo);
	// calcular o tamanho da nova imagem baseada no desenho vermelho
	// rotacao();

    
	escreve_img(img,saida);
    libera_matriz(img);
}

img_pgm *tamanho(img_pgm *img, int angulo)
{	
	int vlin[tam]={0,0,img->linha,img->coluna};
	int vcol[tam]={0,img->coluna,0,img->linha};
	
	// ira salvos os novos angulos
	int vl[tam];
	int vc[tam];
	
	//calculo pq é em radianos
	float x=rad(angulo);

	// calcula o novo angulo de cada coordenada 
	for (int i=0; i<tam; i++)
	{
		vl[i]=round((vlin[i] * cos(x)) - (vcol[i] * sin(x)));
		vc[i]=round((vlin[i] * sin(x)) + (vcol[i] * cos(x)));
	}

	/*o maior e menor valor dira qual eh o novo tamamho da imagem*/

	// fazer a diferença de do maior para ter os novos tamanhos


// precisa retornar uma nova img alocada
}

// void rotacao(img_pgm *img)
//rotacao conta feita x'=x*cos()-y*sin() e y'=x*sin()+y*cos()

