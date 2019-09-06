//GRR 20184567
//Glaide de Lara Oliveira

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "openimg.h"
#define max 1024


void parametros(img_pgm *img, char *nome)
{
    FILE *pgm;
    if (nome==NULL)
        pgm=stdin;
    else
        pgm=fopen(nome,"r+");
    verifica(pgm); 
    ignora_comentario(pgm);
    fscanf(pgm,"%s\n",img->tipo);
    ignora_comentario(pgm);
    fscanf(pgm,"%i %i\n", &img->coluna, &img->linha);
    ignora_comentario(pgm);
    fscanf(pgm,"%i\n",&img->cinza);
    ignora_comentario(pgm);
    img=aloca(img,pgm);
    fclose(pgm);
}   


void verifica (FILE *pgm)
{
    if (pgm==NULL)
    { 
            printf("Erro, formado invalido!\n");//caso exista algum erro na leitura da imagem
            exit(1); //sai da funcao para nao fazer mais coisas
    }
}


img_pgm  *aloca (img_pgm *img, FILE *pgm)
{
    img->matriz = calloc( img->linha * img->coluna, sizeof(unsigned int));
    
    for (int i=0; i<img->linha;i++)
        for (int j=0; j<img->coluna;j++)
            fscanf(pgm,"%u", &img->matriz[(i*img->coluna)+j]);

    return img;
}

void libera_matriz(img_pgm *img)
{
    free(img->matriz);
}


/*aqui vai usar um valor que eu pego da linha de comando*/
void escreve_img (img_pgm *img, char *saida)
{
    FILE *pgm;
    if (saida==NULL) //para caso nao tenha um nome no -o
        pgm=stdout;
    else
        pgm=fopen(saida,"w+"); //abro a imagem e salva em *pgm
    fprintf(pgm,"%s\n",img->tipo); 
    fprintf(pgm,"%i %i\n", img->coluna, img->linha);
    fprintf(pgm,"%u \n",img->cinza);
    for (int i=0; i<img->linha; i++)
        for (int j=0; j<img->coluna; j++)
            fprintf(pgm, "%i ", img->matriz[(i*img->coluna) + j]);
}

void ignora_comentario(FILE *pgm)
{
    char lixo;
    lixo=getc(pgm); //recebe um caracter da imagem 
    if (lixo == '#') //compara para saber se é um comentario
        while (lixo != '\n') //se for percorre ate o fim da linha
            lixo=getc(pgm);
          
}
