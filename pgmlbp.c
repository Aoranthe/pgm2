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
    int j, i, col, lin;
    // passar por toda a matriz de 1 até tam-1 chamando a funcao calculo
    lin=img->linha;
    col=img->coluna;
    for (i=1; i< (lin - 1); i++)
    for (j=1; j< (col - 1); j++)
    {
        calculo(i,j, img);
    }

}

void calculo(int indiceI, int indiceJ, img_pgm *img)
{
    // variaveis utilizadas
    int col=img->coluna;
    int i,j;

    // matriz contera os valores com 0 e 1
    int matriz=malloc( 9* sizeof(int));
    
    int matriz2=malloc( 9* sizeof(int));

    // valor do meio da matriz original
    int meio=img->matriz[(indiceI * img->coluna) + indiceJ];


    for (i=0; i < 3; i++)
    for (j=0; j < 3; j++)
    {
        //essa matriz recebe os 0 e 1
        matriz[(i * 3) + j]=verifica_valor(img->matriz[(indiceI * col) + indiceJ], meio);
    }


    free(matriz);
    free(matriz2);

}