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
	nova=tamanho(img,nova,angulo);

	// nova->matriz=calloc(altura*largura, sizeof(int));
	nova->matriz=calloc(nova->linha * nova->coluna, sizeof(int));

	//função que ira calcular cada novo pixel
	rotacao(img,nova,angulo);

    
	escreve_img(img,saida);
    libera_matriz(img);
}

img_pgm *tamanho(img_pgm *img,img_pgm *nova ,int angulo)
{	
	int altura, largura;
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

	qsort(vl,4,sizeof(int),compara);
	qsort(vc,4,sizeof(int),compara);

	// fazer a diferença de do maior para ter os novos tamanhos

	//diferença de x é a nova altura e de y é a nova largura
	altura=vl[3]-vl[0];
	largura=vc[3]-vc[0];

	//aloca um espaço para a nova matriz rotacionada
	nova->linha=altura;
	nova->coluna=largura;
	nova->cinza=img->cinza;

	return nova;

// precisa retornar uma nova img alocada
}

void rotacao(img_pgm *img, img_pgm *nova, int angulo)
{
	int x=rad(angulo);
	// novas variaveis de indice
	int indI, indJ;
	
	int c=img->coluna;
	
	for (int i=0; i<img->linha; i++)
	for (int j=0; i<img->coluna; j++)
	// o que eu recebo sao os indices rotacionados
	{
		// vl[i]=round((vlin[i] * cos(x)) - (vcol[i] * sin(x)));
		indI=round((img->matriz[(i*c)+j] * cos(x)) - (img->matriz[(i*c)+j] * sin(x)));
		// vc[i]=round((vlin[i] * sin(x)) + (vcol[i] * cos(x)));
		indJ=round((img->matriz[(i*c)+j] * sin(x)) + (img->matriz[(i*c)+j] * cos(x)));
		nova->matriz[(indI * nova->coluna) + indJ]= img->matriz[(i*img->coluna)+j];

	}
}
//rotacao conta feita x'=x*cos()-y*sin() e y'=x*sin()+y*cos()

