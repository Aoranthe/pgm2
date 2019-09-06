//GRR 20184567
//Glaide de Lara Oliveira


#include "openimg.h"
#include <stdlib.h>
#include "struct.h"
#include "pgmnega.h"
#include <string.h>
#include <getopt.h>
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
 
int main (int argc, char **argv)
{
    //jeito de abrir a imagem ainda esta errado
    int option; 
    
    char *entrada=NULL;
    char *saida=NULL;
    
    while((option=getopt(argc,argv,"i:o:")) > 0)
    {
        switch (option)
        {
            //fazer aquelas coisas de caso n tenha um valor estipulado, para pegar a entrada padrão
            //ver com o professor como passa arquivos stdin
            //ver como faz makefile
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
    inverte_img(img); //funcao que faz o calculo da inversao
    escreve_img(img,saida); //salva a nova imagem invertida
    libera_matriz(img);
}

//fazer uma funcao que subtrai os valores
void inverte_img(img_pgm *img)
{
    for (int i=0; i<img->linha; i++) 
        for (int j=0; j<img->coluna; j++)
            img->matriz[(i*img->coluna)+j]= img->cinza - img->matriz[(i*img->coluna)+j];

}
