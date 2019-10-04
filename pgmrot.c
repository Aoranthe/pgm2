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

int main ( int argc, char **argv)
{	
	int option, angulo;
	// int *angulo=NULL;     
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
	
	// ver quem eh abcd da matriz original
	// ver quem eh abcd na nova matriz
	// calcular o tamanho da nova imagem baseada no desenho vermelho
	rotacao();

    
	escreve_img(img,saida);
    libera_matriz(img);
}

//px1[i]=cose*px[i]-seno*py[i]; //x
//py1[i]=seno*px[i]+cose*py[i]; //y


