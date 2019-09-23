//GRR 20184567
//Glaide de Lara Oliveira


#include "openimg.h"
#include <stdlib.h>
#include "struct.h"
#include "pgmlbp.h"
#include <string.h>
#include <getopt.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
 
int main (int argc, char **argv)
{
   
    int option; 
    
    char *entrada=NULL;
    char *saida=NULL;
    
    while((option=getopt(argc,argv,"i:o:")) > 0)
    {
        switch (option)
        {
            case 'i':
                entrada=optarg; //caso tenha a opção -i
            break;
            
            case 'o':
                saida=optarg; //caso tenha a opção -o
            break;
        }
    }
     

    img_pgm *img=malloc(sizeof(img_pgm)); //aloca um espaço de memoria para a matriz que ira receber a imagem
    parametros(img,entrada); //funcao que salva os parametros da imagem
    //efeito lbp
    efeito(img);

    escreve_img(img,saida); //salva a nova imagem invertida
    libera_matriz(img);
}

// função utilizada para saber se o
//  valor do pixel sera maior ou menor que o valor do meio
int verifica_valor(int a, int b)
{
    if (a > b)
        return 1;
    else 
        return 0;
}

void efeito(img_pgm *img)
{
    // passar por toda a matriz de 1 até tam-1 chamando a funcao calculo

}

void calculo(int indice, img_pgm *img)
{
    // alocacao para um espaço onde
    //  serão calculados os efeitos
    int matriz=(int *)malloc( 9* sizeof(int));
    int matriz2=(int *)malloc( 9* sizeof(int));
    
    int i,j;
    for (i=(indice -1); i<(indice +1) ; i++)
    {
        //fazer a subtração aqui e gerar 
        // uma nova matriz para fazer os calculos

    }


    free(matriz);
    free(matriz2);

}