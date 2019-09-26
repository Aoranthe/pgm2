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
#define max 9
#define lm 3
#define cm 3

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


void efeito(img_pgm *img)
{
    int j, i, c, l;
    l=img->linha;
    c=img->coluna;
    //declaracao da matriz com os valores 0 e 1
    int **m=malloc(lm * sizeof(int*));
    for (int i=0; i<lm; i++)
        m[i]=malloc(cm * sizeof(int));
    //declaracao da matriz que recebera os valores de 2^n
    //talvez nao precise disso
    int **doisN=malloc(lm * sizeof(int*));
    for (int i=0; i<lm; i++)
        doisN[i]=malloc(cm * sizeof(int));
    

    // passar por toda a matriz de 1 até tam-1 chamando a funcao calculo
    for (i=1; i< (l- 1); i++)
    for (j=1; j< (c- 1); j++)
    { //recebe os valores 0 e 1
        m[i][j]=calculo(i,j, img);
        doisN=doisn();
    }


}



//  valor do pixel sera maior ou menor que o valor do meio
int verifica_valor(int a, int b)
{
    if (a > b)
        return 1;
    else 
        return 0;
}

//matriz com 0s e 1s
int calculo(int indiceI, int indiceJ, img_pgm *img)
{
    //valor para o meio e os valores ao lado
    int meio, val, i,j;
    meio=img->matriz[(indiceI* img->coluna) + indiceJ];
    //alocacao da matriz
    int **matriz=malloc(lm * sizeof(int*));
    for (int i=0; i<lm; i++)
        matriz[i]=malloc(cm * sizeof(int));

    //laço para calcular os 0's e 1's
    for (i=(indiceI-1); i< (indiceI+1); i++)
    for (j=(indiceJ-1); j< (indiceJ+1); j++)
    {
        //salva o valor da matriz original
        val=img->matriz[(indiceI * img->coluna)+indiceJ];
        //calcula se é =0 ou =1
        matriz[i][j]=verifica_valor(val,meio);
    }
   
    return matriz;
}


//matriz com 2^n
int doisn()
{
    int **matriz=malloc(lm * sizeof(int*));
    for (int i=0; i<lm; i++)
        matriz[i]=malloc(cm * sizeof(int));
    //variavel usanda para fazer 2^n
    int n=0;
    //laço para calcular 2^n
    for (int i=0; i < 3; i++)
    for (int j=0; j < 3; j++)
    {
        //para caso seja o valor do meio
        if (j == i)
            matriz[i][j]=0;
        else 
        {
            matriz[i][j]=ldois(x);
            n++;
        }
    }
    return matriz;
}

//funcao para calcular 2^n 
int ldois(int x)
{
    int a=2;
    if (x==0)   return 1;
    if (x==1)   return 2;

    else    
        for (int i=2; i < x; i++)
            a=a*a;
    return a;
}