//GRR 20184567
//Glaide de Lara Oliveira	


#include "struct.h"
#include <stdlib.h>
#include "pgmrot.h"
#include <math.h>
#include "openimg.h"

int main ()
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
				angulo=atoi(optarg); //converte por sera necessario ser tratado como int
			default:
				fprintf(stderr, "valor invalido ou numero de parametros incorreto");
				return -1;
	    }
	}
	if(angulo==NULL) //para caso não seja passado um valor para o angulo
		angulo=90;
    img_pgm *img=malloc(sizeof(img_pgm));
    parametros(img);
 
	/*FAZER TODAS AS FUNÇÕES RELACIONADAS A ANGULOS*/
    
	escreve_img(img);
    libera_matriz(img);
}
