
void save_txt(char*userparam2, tmat2d *mat){
    FILE *arquivo_txt;
	
	arquivo_txt = fopen(userparam2,"w");
         if(arquivo_txt == NULL){
         	puts("Não foi possivel abrir o arquivo\n");
         	exit(1);
         }
         for(int i = 0; i < mat->nlinhas; i++){
              for(int j = 0; j < mat->ncolunas; j++){
                  fprintf(arquivo_txt, "%d ", mat->valores[i*mat->ncolunas+j]);
               }
               fprintf(arquivo_txt,"\n");
            }  
        }
  fclose(arquivo_txt);
}


void lab(char *userparam, tmat2d *matriz){
  FILE *arquivo_txt;
  int Ncol, Nlin;
  tmat2d *matfinal;
  Stack *prox;
  struct aluno p, p_atual;
  Ncol = mat->ncolunas;
  Nlin = mat->nlinhas;
  matfinal = cria_matriz(matriz->nlinhas, matriz->ncolunas);
  preenche_aleatorio(matfinal, 0, 0);

  prox = stack_create();

         for(int i = 0; i < matriz->nlinhas; i++){
         	for(int j = 0; j < matriz->ncolunas; j++){
         		if(j==1 && matriz->valores[i*matriz->ncolunas+j] == 1){
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
        for(int i = 0; i < Nlin; i++){
         	for(int j = 0; j < Ncol; j++){
         	matfinal->valores[i*Ncol+j] = matriz->valores[i*Ncol+j];
         	}
        }
	save_txt(userparam, matfinal);
}
