#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"

typedef struct NO*ArvAVL;
struct NO{
	
	int info;
	int alt//Altura da arvore
	struct NO* esq;
	struct NO* dir;
	
};
ArvAVL*raiz;//Ponteiro para ponteiro
//Calcula a altura de um nó;
int alt_no(Struct NO* no){
	
	if(no==NULL)		
		return -1;
	else
		return no->alt;
	
}
//Calcula o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO* no){
	
	return labs(alt_NO(NO->esq)-alt_NO(no->dir));
	
}
//Calcula o maior valor
int maior(int x, int y){
	
	if(x>y)
		return x;
	else
		return y;
		
}
//rotação a direita
void rotacaoLL(ArvAVL *raiz){
	
	struct NO no;
	no=(*raiz)->esq;
	(*raiz)->esq=no->dir;
	no->dir=*raiz;
	(*raiz)->altura=maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir))+1;
	
	no->altura=maior(altura_NO(no->esq),(*raiz)->altura)+1;
	
	*raiz=no;
	
	
}
//rotação a esquerda
void rotacaoRR(ArvAVL *raiz){
	
	struct NO no;
	no=(*raiz)->dir;
	(*raiz)->dir=no->esq;
	no->esq=*raiz;
	(*raiz)->altura=maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir))+1;
	
	no->altura=maior(altura_NO(no->dir),(*raiz)->altura)+1;
	
	*raiz=no;
	
	
}	
//rotação dupla 
void RotacaoLR(ArvAVL *raiz){
	
	RotacaoRR(&(*raiz)->esq);
	RotacaoLL(raiz);
	
}
//rotacao dupla
void RotacaoRL(ArvAVL *raiz){
	
	RotacaoLL(&(*raiz)->dir);
	RotacaoRR(raiz);
	
	
}
int insere_ArvAVL(ArvAVL *raiz, int valor){
		
		int res;
		if(*raiz==NULL){
			
			struct NO *novo;
			novo=(struct NO*)malloc(sizeof(struct NO));
			if(novo==NULL){
				return 0;
			}
			novo->info=valor;
			novo->altura=0;
			novo->esq=NULL;
			novo->dir=NULL;
			*raiz=novo;
			return 1;
			
			
			
		}
	
		struct NO *atual=*raiz;
		if(valor<atual->info){
			
			if((res=insere_ArvAVL(&(atual->esq),valor))==1){
				
				if(fatorBalanceamento_NO(atual)>=2){
					if(valor<(*raiz)->esq->info){
						RotacaoLL(raiz);
					}
					else{
						
						RotacaoLR(raiz);
						
					}
					
					
				}
				
			}
			
		}
		else{
			
			if(valor>atual->info){
			
				if((res=insere_ArvAVL(&(atual->dir),valor))==1){
					
					if(fatorBalanceamento_NO(atual)>=2){
						if(valor<(*raiz)->dir->info<valor){
							RotacaoRR(raiz);
						}
						else{
							
							RotacaoRL(raiz);
							
						}
						
						
					}
					
				}
			}
			else{
				printf("Valor Duplicado!\n");
				return 0;
				
			}
									
		}
		atual->altura=maior(altura_NO(atual->esq),altura_NO(atual->dir))+1;
		return res;
		
		
	}
	
	
int main(){
	
	int x=insere_ArvAVL(raiz,valor);
	
	int insere_ArvAVL(ArvAVL *raiz, int valor);
	

	
	
	
}
