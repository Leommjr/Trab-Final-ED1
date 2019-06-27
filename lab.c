/**
* @brief Pegar imagem binária com um labirinto represenado pelos valor 1 na imagem
*        e retornando outra imagem com o caminho certo representado pelos valores 2.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "DynamicStack.h"
#include "lab.h"


void lab(char *userparam, char *userparam2){
  FILE *arquivo_txt;
  int *matriz, band;
  Stack *prox;
  struct aluno p, p_atual;
  prox = stack_create();
  arquivo_txt = fopen(userparam,"r");
  if(arquivo_txt == NULL)
  {
      printf("O arquivo %s não existe, tente novamente!\n",userparam);
      exit(-1);
  }else{
          int Nlin = 0;
          int Ncol = 1;

           char c;
           while((c = fgetc(arquivo_txt)) != EOF)
           {
              if(c == '\n'){
                  Nlin++;
              }
              if(Nlin== 1 && c == '\t' || Nlin==1 && c == ' ')
                  Ncol++;
           }

          matriz = (int*)malloc(Nlin*Ncol*sizeof(int));
          if(!matriz){
            puts("memory error\n");
            exit(1);
          }
          fclose(arquivo_txt);
          arquivo_txt = fopen(userparam,"r");
          if(arquivo_txt == NULL){
          	puts("Não foi possivel abrir o arquivo\n");
          	exit(1);
          }
          for(int i = 0; i < Nlin; i++){
              for(int j = 0; j < Ncol; j++){
                  fscanf(arquivo_txt,"%d",&matriz[i*Ncol+j]);
               }
           }
         fclose(arquivo_txt);
         for(int i = 0; i < Nlin; i++){
         	for(int j = 0; j < Ncol; j++){
         		if(j==1 && matriz[i*Ncol+j] == 1){
         			p.x = i;
         			p.y = j;
         			//encontrando a entrada
         		}
         	}	
         }
         stack_push(prox, p);
         stack_top(prox,&p_atual);
         matriz[p.x*Ncol + p.y] = 3;
         while(p_atual.y != Ncol-2){
         	//matriz[p.x*Ncol + p.y] = 3;
         	//checando ponto de cima
         		p.x = p_atual.x-1;
	            p.y = p_atual.y;
	            if(matriz[p.x*Ncol + p.y] == 1 && matriz[p.x*Ncol + p.y] != 3){
	            	matriz[p.x*Ncol + p.y] = 3;
	            	stack_push(prox, p);
	            	band = 1;
	                	
	            }else{
	         //checando o ponto de trás
	            p.x = p_atual.x;
	            p.y = p_atual.y-1;
	            if(matriz[p.x*Ncol + p.y] == 1 && matriz[p.x*Ncol + p.y] != 3){
	            	matriz[p.x*Ncol + p.y] = 3;
	                stack_push(prox, p);
	                band = 1;
	            }else{
	         //checando o ponto de baixo
	            p.x = p_atual.x+1;
	            p.y = p_atual.y;
	            if(matriz[p.x*Ncol + p.y] == 1 && matriz[p.x*Ncol + p.y] != 3){
	            	matriz[p.x*Ncol + p.y] = 3;
	                stack_push(prox, p);
	                band = 1;
	            }else{
	         //checando o ponto da frente
	            p.x = p_atual.x;
	            p.y = p_atual.y+1;
	            if(matriz[p.x*Ncol + p.y] == 1 && matriz[p.x*Ncol + p.y] != 3){
	            	matriz[p.x*Ncol + p.y] = 3;
	                stack_push(prox, p);
	                band = 1;
	            }
	          }//else
	         }//else
	        }//else
	            if(band == 1){
                	stack_top(prox, &p_atual);
	            }
                else{
                	stack_pop(prox);
                	stack_top(prox, &p_atual);
                }
                band = 0;
         }
         while(stack_empty(prox) != 1){
         	stack_top(prox, &p);
         	matriz[p.x*Ncol + p.y] = 2;
         	stack_pop(prox);
         }
         for(int i = 0; i < Nlin; i++){
         	for(int j = 0; j < Ncol; j++){
         		 if(matriz[i*Ncol+j] == 3 || matriz[i*Ncol+j] == 1){
         		 	matriz[i*Ncol+j] = 0;
         		 }
         	}
        }

         arquivo_txt = fopen(userparam2,"w");
         if(arquivo_txt == NULL){
         	puts("Não foi possivel abrir o arquivo\n");
         	exit(1);
         }
         for(int i = 0; i < Nlin; i++){
              for(int j = 0; j < Ncol; j++){
                  fprintf(arquivo_txt, "%d ", matriz[i*Ncol+j]);
               }
               fprintf(arquivo_txt,"\n");
            }  
        }
  fclose(arquivo_txt);

}
