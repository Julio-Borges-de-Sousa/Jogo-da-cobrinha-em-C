#include "main.h"

int tamanho_da_cobrinha = 2;
int vida = 1;
char direcao = 'd';
char direcao_atual = 'd';
char direcao_anterior = 'd';
int cont = 0;
int flag_se_tamanho_aumentou = 0;

void verific(celula vet[], int I, int J, char corpo, char direcao){
    if(direcao == pCIMA) CIMA(vet, I, J, corpo, &vida);
    else if(direcao == pDIREITA) DIREITA(vet, I, J, corpo, &vida);
    else if(direcao == pBAIXO) BAIXO(vet, I, J, corpo, &vida);
    else ESQUERDA(vet, I, J, corpo, &vida);
} 

int main(){
    while(1){

        int i;
        int j;
        celula vet[300];
        INICIO(vet);
        srand(time(NULL));
        vida = 1;
        cont = 0;

        FILE *fp;
        fp = fopen("keytmp", "w");
        fputc('d', fp);
        fclose(fp);
        direcao = 'd';
        direcao_anterior = 'd';
        direcao_atual = 'd';

        while(1){
            
            cont+=1;
            spaw(vet);
            if(cont == 3){
                vida = 1;
                cont = 0;
            }
            
            PRINT(vet);
            receber(&direcao);
            system("clear");
            direcao_atual = direcao;

            i = BUSCA_I(vet, 'O', 0);
            j = BUSCA_J(vet, 'O', 0);

            if(direcao_atual == direcao_anterior){
                verific(vet, i, j, 'O', direcao_atual);
            }else{

                if(direcao == pCIMA){
                    if(direcao_anterior == pBAIXO){ 
                        direcao_atual = pBAIXO;
                        BAIXO(vet, i, j, 'O', &vida);
                    } else CIMA(vet, i, j, 'O', &vida);
                }

                
                if(direcao == pDIREITA){
                    if(direcao_anterior == pESQUERDA){
                        direcao_atual = pESQUERDA;
                        ESQUERDA(vet, i, j, 'O', &vida);
                    }else DIREITA(vet, i, j, 'O', &vida);
                }

                if(direcao == pBAIXO){
                    if(direcao_anterior == pCIMA){
                        direcao_atual = pCIMA;
                        CIMA(vet, i, j, 'O', &vida);
                    } else BAIXO(vet, i, j, 'O', &vida);
                }
                            
                if(direcao == pESQUERDA){
                    if(direcao_anterior == pDIREITA){
                        direcao_atual = pDIREITA;
                        DIREITA(vet, i, j, 'O', &vida);
                    }else ESQUERDA(vet, i, j, 'O', &vida);
                }

            }

            if(vida == 0){
                printf("PELO AMOR DE DEUS, VOCE FEZ A COBRINHA COMER COCO\n");
                printf("ESPERE 5 SEGUNDOS\n");
                sleep(5);
                break;
            }

            i = BUSCA_I(vet, 'o', 1);
            j = BUSCA_J(vet, 'o', 1);
            verific(vet, i, j, 'o', direcao_anterior);
            direcao_anterior = direcao_atual;

            if(vida == 2 && flag_se_tamanho_aumentou == 0)aumentar(vet);
            
            if(vida == 2) flag_se_tamanho_aumentou = 1;
            else flag_se_tamanho_aumentou = 0;

        }

    }


}  


