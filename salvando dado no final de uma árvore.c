#include<stdio.h>
typedef struct bloco{
    int dado;
    struct bloco *esq, *dir;
}No;

int insereABB(No **raiz, int dado){
    No *aux;
    if(!*raiz){
        (*raiz)=(No*)malloc(sizeof(No));
        if(*raiz==NULL){
        return(0);}
        (*raiz)->dado=dado;
        (*raiz)->esq=(*raiz)->dir=NULL;
    }
    if((*raiz)->dado > dado){
        if((*raiz)->esq==NULL){
            aux=(No*)malloc(sizeof(No));
            if(aux==NULL){
                return(0);}
            aux=NULL;
            aux->dado = dado;
            (*raiz)->esq = aux;
        }
    }
        else{
            while((*raiz)->esq!=NULL){
                insereABB((*raiz)->esq, dado);
                if((*raiz)->esq==NULL){
                    aux=(No*)malloc(sizeof(No));
                    if(aux==NULL){
                        return(0);}
                    aux=NULL;
                    aux->dado = dado;
                    (*raiz)->esq = aux;
                }
            }
        }
    if((*raiz)->dado < dado){
        if((*raiz)->dir==NULL){
            aux=(No*)malloc(sizeof(No));
            if(aux==NULL){
                return(0);}
            aux=NULL;
            aux->dado = dado;
            (*raiz)->dir = aux;
        }
    }
        else{
            while((*raiz)->dir!=NULL){
                insereABB((*raiz)->dir, dado);
                if((*raiz)->esq==NULL){
                    aux=(No*)malloc(sizeof(No));
                    if(aux==NULL){
                        return(0);}
                    aux=NULL;
                    aux->dado = dado;
                    (*raiz)->dir = aux;
                }
            }
        }
    int main(){
        No *arv=NULL;
        int d,n,t=1,x;
        printf("digite o numero de numeros a serem salvos: ");
        scanf("%d", &n);
        for(t=1;t<=n;t++){
            printf("digite um numero: ");
            scanf("%d", &d);
            x=insereABB(&arv,d);
            if(x==1){
                printf("SUCESSO!!!");}
            else{
                printf("FALHA!!!");}
        }
        return 0;
    }
    }
