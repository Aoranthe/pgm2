//GRR 20184567
//Glaide de Lara Oliveira	


#include "struct.h"
#include <stdlib.h>
#include "pgmrot.h"
#include <math.h>
#include "openimg.h"

int main (){
    img_pgm *img=malloc(sizeof(img_pgm));
    parametros(img);
    unsigned int angulo; //angulo para calcular 
		
    printf("entre com o angulo desejado:\n");
    scanf("%u",&angulo);
  //int l=linha(img,angulo);
  //int c=coluna(img, angulo);
		unsigned int l=img->linha + (img->linha/2);
		unsigned int c=img->coluna + (img->coluna/2);
    walk_matriz(img,angulo,l,c);
    img->coluna=c;
    img->linha=l;
    escreve_img(img);
    libera_matriz(img);
}
//funcao que calculna nova linha
/* toda essa parte comentada está errada
int linha(img_pgm *img, unsigned int angulo){
		int i=0;
    int j=0;
    int n_linha;
	  int cx=c_angx(angulo,i,img->coluna);//primeira linha/ ultima coluna
		int cy=c_angy(angulo,i,img->coluna);
	  int llx=c_angx(angulo,img->linha,j);//ultima linha/primeira coluna
		int lly=c_angy(angulo,img->linha,j);    
		if (cy>lly) 
		if (newc>newll) n_linha= newc-newll;
		else if (newll>newc) n_linha=newll-newc;
    return n_linha;
}*/

//funcao que calcula nova coluna
/* toda essa parte comentada está errada
int coluna(img_pgm *img, unsigned int angulo){
    int i=0;
	  int j=0;
	  int n_coluna;
    int lx=c_angx(angulo,i,j);//primeira linha/coluna
		int ly=c_angy(angulo,i,j);
    int ccx=c_angx(angulo,img->linha, img->coluna);//ultima linha/ ult coluna
		int ccy=c_angy(angulo,img->linha, img->coluna);
		if (newcc>newl) n_coluna= newcc-newl;
		else if (newl>newcc) n_coluna=newl-newcc;
    return n_coluna;
} */

//fazer funcao que corre por toda a matriz e chama o calc_ang
unsigned int* walk_matriz(img_pgm *img, unsigned int angulo, int l, int c){
	unsigned int i,j;
	unsigned int *matriz_rot=calloc(l * c, sizeof(unsigned int));
  
//percorre pela nova matriz
    for (i=0; i<l;i++) {
        for (j=0; j<c; j++){
            int x=c_angx(-angulo,i,j);//onde fica na matriz original
            int y=c_angy(-angulo,i,j);
            //calculo das novas coordenadas para gerar a nova matriz
            if (x>=0 && x<img->coluna && y>=0 && y<img->linha){    
                unsigned int pixel=img->matriz[(x*img->coluna)+y];
                matriz_rot[(i*c)+j]=pixel;
            }   
						else matriz_rot[(i*c)+j]=255;
        }
    }   
    img->matriz=calloc(l * c, sizeof(unsigned int));
    for (i=0; i<l;i++) 
        for (j=0; j<c; j++)
          img->matriz[(i*c)+j]=matriz_rot[(i*c)+j];
    
    return img->matriz;
}

//tenho que receber as coordenads que eu vou  usar pra calcular o angulo
//funcao que calcula angulo de i
int c_angx(unsigned int angulo,unsigned int i, unsigned int j){
    float b=((angulo*3.14)/180); //calculo pq é em radianos
    int x=round(i*cos(b)-j*sin(b)); //funcao que arredonda
    return x;
}
//funcao que calcula angulo de j
int c_angy(unsigned int angulo,unsigned int i, unsigned int j){
    float b=((angulo*3.14)/180);//calculo pq é em radianos
    int y=round(i*sin(b)+j*cos(b));
    return y;
}
//rotacao conta feita x'=x*cos()-y*sin() e y'=x*sin()+y*cos()


//gcc -o inverte nega.c open.c arquivo
