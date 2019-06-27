/*
Tad operações com matrizes

Vinícius Lopes Dias

Nenhum bug encontrado
25/04/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tmat2d.h"
#include "DynamicStack.h"


struct tmat2d{
    int *valores;
    int nlinhas;
    int ncolunas;
};

tmat2d *cria_matriz(int linhas, int colunas){
    tmat2d *matriz = NULL;
    matriz = malloc(sizeof(tmat2d));
    if(matriz == NULL){
        return NULL;
    }else{
        matriz->valores = malloc(linhas*colunas*sizeof(int));
        if(matriz->valores == NULL){
            return NULL;
        }else{
            matriz->nlinhas = linhas;
            matriz->ncolunas = colunas;
        }
    }
return matriz;
}

void libera_matriz(tmat2d *matriz){

free(matriz->valores);
free(matriz);

}
int escreve_elem(tmat2d *m, int i, int j, int elem){
    if(m == NULL || m->valores == NULL){
        return -1;
    }
    else if(i >= m->nlinhas || i < 0 || j >= m->ncolunas || j < 0){
        return -1;
    }
    else{
        m->valores[i*m->ncolunas+j] = elem;
        return 0;
    }
}

int acessa_elem(tmat2d *m, int i, int j, int *valor){
    if(m != NULL || m->valores != NULL || i < m->nlinhas || j < m->ncolunas){
        *valor = m->valores[i*m->ncolunas+j];
        return 0;
    }
    else
        return -1;
}

int preenche_aleatorio(tmat2d *m, int maximo, int minimo){
    if(m != NULL || m->valores != NULL){
        srand(time(NULL));
        int elementos;
        elementos = m->ncolunas*m->nlinhas;
        for(int i = 0; i < elementos; i++)
            m->valores[i] = (rand() % (maximo - minimo) + 1);
        return 0;
    }
    else
        return -1;
}

int soma_matrizes(tmat2d *mat1, tmat2d *mat2, tmat2d *resultado){
    if(mat1 != NULL && mat2 != NULL){
        if(mat1->nlinhas != mat2 ->nlinhas || mat1->ncolunas != mat2->ncolunas){
            return -1;
        }
        else{
            if(resultado == NULL){
                return -1;
            }
            else{
                int elementos;
                elementos = mat1->ncolunas*mat1->nlinhas;
                resultado->valores = malloc(elementos*sizeof(int));
                if(resultado->valores == NULL){
                    return -1;
                    }
                else{
                    for(int i = 0; i < elementos; i++)
                        resultado->valores[i] = mat1->valores[i] + mat2->valores[i];
                    return 0;
                    }
                }
            }
        }
}

int mult_matrizes(tmat2d *mat1, tmat2d *mat2, tmat2d *resultado)
{
    if (mat1 != NULL && mat2 != NULL)
    {
        if (mat1->ncolunas != mat2->nlinhas || mat1->nlinhas != resultado->nlinhas || mat2->ncolunas != resultado->ncolunas)
        {
            return -1;
        }
        else
        {
            int elementos;
            resultado->nlinhas = mat1->nlinhas;
            resultado->ncolunas = mat2->ncolunas;
            elementos = mat1->nlinhas * mat2->ncolunas;
            resultado->valores = malloc(elementos * sizeof(int));
            if (resultado->valores == NULL)
            {
                return -1;
            }
            else
            {
                for (int i = 0; i < resultado->nlinhas; i++)
                    for (int j = 0; j < resultado->ncolunas; j++)
                    {
                        resultado->valores[i * resultado->ncolunas + j] = 0; // zera para acumular o somatorio
                        for (int k = 0; k < resultado->ncolunas; k++)
                            resultado->valores[i * resultado->ncolunas + j] += mat1->valores[i * mat1->ncolunas + k] * mat2->valores[k * mat2->ncolunas + j];
                    }
            }
            return 0;
        }
    }
}

int mult_const(tmat2d *m, int multiplicador, tmat2d *resultado){
    int num_elementos;
    if(m == NULL || m->valores == NULL || resultado == NULL){
        return -1;
    }else{
        num_elementos = m->nlinhas * m->ncolunas;
        for(int i = 0; i < num_elementos; i++)
            resultado->valores[i] = m->valores[i] * multiplicador;
        return 0;
    }
}

int traco_matriz(tmat2d *m, int *traco){
    if(m != NULL && m->valores != NULL){
        *traco = 0;
        for(int i = 0; i < m->nlinhas; i++){
            for(int j = 0; j < m->ncolunas; j++){
                if(i==j){
                    *traco += m->valores[i*m->ncolunas+j];
                }
            }
        }
        return 0;
    }else
        return -1;
}

int *soma_linhas(tmat2d *mat1){
    if(mat1 != NULL && mat1->valores != NULL){
        int *vetlin = NULL;
        vetlin = malloc(mat1->nlinhas*sizeof(int));
        if(vetlin != NULL){
            for(int i = 0; i < mat1->nlinhas;i++)
                vetlin[i] = 0;
            for(int i = 0; i < mat1->nlinhas; i++){
                for(int j = 0; j < mat1->ncolunas; j++)
                    vetlin[i] += mat1->valores[i*mat1->ncolunas+j];
            }
        return vetlin;
        }
    }else{
    return NULL;
    }
}

int *soma_colunas(tmat2d *mat1){
    if(mat1 != NULL && mat1->valores != NULL){
        int *vetcol = NULL;
        vetcol = malloc(mat1->nlinhas*sizeof(int));
        if(vetcol != NULL){
            for(int i = 0; i < mat1->nlinhas;i++)
                vetcol[i] = 0;
            for(int i = 0; i < mat1->nlinhas; i++){
                for(int j = 0; j < mat1->ncolunas; j++)
                    vetcol[i] += mat1->valores[j*mat1->ncolunas+i];
            }
        return vetcol;
        }
    }else{
    return NULL;
    }
}

void imprime_matriz(tmat2d *matriz){
    if(matriz == NULL || matriz->valores == NULL){
        return;
    }else{
    int i;
    int j;
    int k = 0;
    for(i = 0; i < matriz->nlinhas; i++){
        for(j = 0; j < matriz->ncolunas; j++){
            printf("%d\t", matriz->valores[k]);
            k++;
            }
        printf("\n");
        }
    }
}




/**
* @brief Parâmetro open e convert do trabalho final
*
* Abre arquivos tipo texto e tipo binário ou converte
* arquivo em txt para bin
*/

/*
Abre um arquivo txt e copia para uma matriz (no formato de vetor)
*/

tmat2d *open_file_txt(char *userparam){
  FILE *arquivo_txt;
  tmat2d *matriz1;
  int *matriz;
  arquivo_txt = fopen(userparam,"r");
  if(arquivo_txt == NULL)
  {
      printf("O arquivo %s não existe, tente novamente!\n",userparam);
      exit(-1);
  }else{
          printf("Arquivo lido com sucesso\n\n");
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
		  fclose(arquivo_txt);
		  matriz1 = cria_matriz(Nlin,Ncol);
          matriz = (int*)malloc(Nlin*Ncol*sizeof(int*));
          if(!matriz){
            puts("memory error\n");
            exit(1);
          }
          arquivo_txt = fopen(userparam,"r");
          for(int i = 0; i < Nlin; i++)
              for(int j = 0; j < Ncol; j++){
                  fscanf(arquivo_txt,"%d",&matriz[i*Ncol+j]);
               }
  }
  fclose(arquivo_txt);
    for(int i = 0; i < Nlin; i++)
        for(int j = 0; j < Ncol; j++){
			escreve_elem(matriz1,i,j,matriz[i*Ncol+j]);
			}
  free(matriz);
  return matriz1;
}

/*
Abre um arquivo binario e copia para uma matriz (no formato de vetor)
*/

tmat2d *open_file_bin(char *userparam){
	FILE *arquivo_bin;
    int *matriz;
	tmat2d *matriz1;
    arquivo_bin = fopen(userparam,"rb");
    if(arquivo_bin == NULL)
    {
        printf("O arquivo %s não existe, tente novamente!\n",userparam);
        exit(-1);
    }else{
            printf("Arquivo lido com sucesso\n\n");
            int Nlin = 0;
            int Ncol = 0;
            
            if(fread(&Nlin,sizeof(int), 1, arquivo_bin)!= 1){
                if(feof(arquivo_bin)){
                    puts("Erro ao ler número de linhas\n");
                    exit(1);
                }
            }
            if(fread(&Ncol,sizeof(int), 1, arquivo_bin)!= 1){
                if(feof(arquivo_bin)){
                    puts("Erro ao ler número de colunas\n");
                    exit(1);
                }
            }
			matriz1 = cria_matriz(Nlin, Ncol);
            matriz = (int*)malloc(Nlin*Ncol*sizeof(int));
            if(!matriz){
            	puts("memory error\n");
            	exit(1);
            }
            if(fread(matriz,sizeof(int), Nlin*Ncol, arquivo_bin)!= 1){
                if(feof(arquivo_bin)){
                    puts("Erro ao ler o arquivo\n");
                    exit(1);
                }
            }
			for(int i = 0; i < Nlin; i++)
				for(int j = 0; j < Ncol; j++){
					escreve_elem(matriz1,i,j,matriz[i*Ncol+j]);
			}
    }
	free(matriz);
    fclose(arquivo_bin);
	return matriz1;
}

/*
Salva uma matriz em modo binario e exclui a anterior.
*/


void convert_file(char *userparam, char*userparam2, tmat2d *mat){
    FILE *arquivo_txt;
	
	arquivo_txt = fopen(userparam2,"wb");
	
	if(arquivo_txt == NULL){
		printf("O arquivo %s não existe, tente novamente!\n",userparam);
		exit(1);
		}
		else{
			if(fwrite(&mat->nlinhas, sizeof(int), 1, arquivo_txt)!= 1){puts("Erro ao escrever número de linhas\n"); exit(1);}
			if(fwrite(&mat->ncolunas, sizeof(int), 1, arquivo_txt)!= 1){puts("Erro ao escrever número de colunas\n"); exit(1);}
			for(int i = 0; i < mat->nlinhas; i++){
				for(int j = 0; j < mat->ncolunas; j++){
					if(fwrite(&mat->valores[i*mat->ncolunas+j], sizeof(int), 1, arquivo_txt)!= 1){puts("Erro ao escrever no arquivo\n"); exit(1);}
				}
			}
		fclose(arquivo_txt);
	//Remove o arquivo original
	arquivo_txt = fopen(userparam, "r");
	remove(userparam);
	fclose(arquivo_txt);
	}
}

/**
Salva uma matriz em um arquivo binario
*/

void save_bin(char*userparam2, tmat2d *mat){
    FILE *arquivo_txt;
	
	arquivo_txt = fopen(userparam2,"wb");
	
	if(arquivo_txt == NULL){
		printf("O arquivo %s não existe, tente novamente!\n",userparam);
		exit(1);
		}
		else{
			if(fwrite(&mat->nlinhas, sizeof(int), 1, arquivo_txt)!= 1){puts("Erro ao escrever número de linhas\n"); exit(1);}
			if(fwrite(&mat->ncolunas, sizeof(int), 1, arquivo_txt)!= 1){puts("Erro ao escrever número de colunas\n"); exit(1);}
			for(int i = 0; i < mat->nlinhas; i++){
				for(int j = 0; j < mat->ncolunas; j++){
					if(fwrite(&mat->valores[i*mat->ncolunas+j], sizeof(int), 1, arquivo_txt)!= 1){puts("Erro ao escrever no arquivo\n"); exit(1);}
				}
			}
	fclose(arquivo_txt);
	}
}


/**
* @brief Realiza a segmentação da imagem binária.
*/


void segment(tmat2d *mat, int valor){
    int num;
    for(int i = 0; i < mat->nlinhas; i++)
        for(int j = 0; j < mat->ncolunas; j++){
            acessa_elem(mat,i,j,&num);
            if(num > valor)
                escreve_elem(mat,i,j,1);
            else
                escreve_elem(mat,i,j,0);
        }
}


/*
Conex
*/
void connected(char *userparam2, tmat2d *mat){
        tmat2d *matconex;
		struct aluno p, p_atual;
		int label = 1;
		Stack *prox;
		
		matconex = cria_matriz(mat->nlinhas, mat->ncolunas);
        preenche_aleatorio(matconex, 0, 0);
        prox = stack_create();
        for(int i = 1; i < mat->nlinhas-1; i++){
			for(int j = 1; j < mat->ncolunas-1; j++){
				p.x = i;
                p.y = j;
                if(mat->valores[p.x*(mat->ncolunas-1) + p.y] == 1 && matconex->valores[p.x*(ncol-1) + p.y] == 0 ){
					matconex->valores[p.x*(ncol-1) + p.y] = label;
	                stack_push(prox, p);
	                while(stack_empty(prox) != 1){
	                	stack_top(prox, &p_atual);
	                	stack_pop(prox);
	                	p.x = p_atual.x-1;
	                	p.y = p_atual.y;
	                	if(mat->valores[p.x*(mat->ncolunas-1) + p.y] == 1 && matconex->valores[p.x*(ncol-1) + p.y] == 0 ){
	                		matconex->valores[p.x*(ncol-1) + p.y]
	                		stack_push(prox, p);
	                		}
	                		p.x = p_atual.x;
	                		p.y = p_atual.y-1;
	                		if(mat->valores[p.x*(mat->ncolunas-1) + p.y] == 1 && matconex->valores[p.x*(ncol-1) + p.y] == 0 ){
	                			matconex->valores[p.x*(ncol-1) + p.y]
	                			stack_push(prox, p);
	                		}
	                		p.x = p_atual.x;
	                		p.y = p_atual.y+1;
	                		if(mat->valores[p.x*(mat->ncolunas-1) + p.y] == 1 && matconex->valores[p.x*(ncol-1) + p.y] == 0 ){
	                			matconex->valores[p.x*(ncol-1) + p.y]
	                			stack_push(prox, p);
	                		}
	                		p.x = p_atual.x+1;
	                		p.y = p_atual.y;
	                		if(mat->valores[p.x*(mat->ncolunas-1) + p.y] == 1 && matconex->valores[p.x*(ncol-1) + p.y] == 0 ){
	                			matconex->valores[p.x*(ncol-1) + p.y]
	                			stack_push(prox, p);
	                		}                			
					}//while
	               label += 1;
            	}
			}
		}
	libera_matriz(matconex);	
    stack_free(prox);
	save_bin(userparam2, matconex);
	
}





void imprime_arq(int *vet, int nlin, int ncol){
            printf("Numero de linhas: %d\n",nlin);
            printf("Numero de colunas: %d\n",ncol);

            printf("Imagem:\n\n\n");
            for(int i = 0; i < nlin; i++)
            {
                for(int j = 0; j < ncol; j++)
                {
                    printf("%d\t ",vet[i*ncol+j]);
                }
                printf("\n");
            }

}
