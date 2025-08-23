#include "main.h"

int tamanho_da_cobrinha = 2;
int vida = 1;
char direcao = 'd';
char direcao_atual = 'd';
char direcao_anterior = 'd';

void verific(celula vet[], int I, int J, char corpo, char direcao, int ordem){
    if(direcao == pCIMA) CIMA(vet, I, J, corpo, &vida, ordem);
    else if(direcao == pDIREITA) DIREITA(vet, I, J, corpo, &vida, ordem);
    else if(direcao == pBAIXO) BAIXO(vet, I, J, corpo, &vida, ordem);
    else ESQUERDA(vet, I, J, corpo, &vida, ordem);
} 

void mover_rabo(celula vet[]){

    for(int i = 1; i < tamanho_da_cobrinha; i++){
        int linha_do_rabo_de_indice_i = BUSCA_I(vet, i);
        int coluna_do_rabo_de_indice_i = BUSCA_J(vet, i);
        verific(vet, linha_do_rabo_de_indice_i, coluna_do_rabo_de_indice_i, 'o', vet[ (linha_do_rabo_de_indice_i*30) + coluna_do_rabo_de_indice_i].direcao_do_rabo, i);
    }
    
}

//algoritimo: de tras para frente
void atualizar_direcao_do_rabo(celula vet[]){

    int i = tamanho_da_cobrinha;
    i--; // não conta com a cabeça
    while(i != 0){
        if(i == 1){
            int linha_do_rabo_de_indice_i = BUSCA_I(vet, i);
            int coluna_do_rabo_de_indice_i = BUSCA_J(vet, i);
            vet[ (linha_do_rabo_de_indice_i*30) + coluna_do_rabo_de_indice_i ].direcao_do_rabo = direcao_atual;
        }else{
            int linha_do_rabo_de_indice_i = BUSCA_I(vet, i);
            int coluna_do_rabo_de_indice_i = BUSCA_J(vet, i);
            int linha_do_que_esta_atras_do_rabo_de_indice_i = BUSCA_I(vet, i-1);
            int coluna_do_que_esta_atras_do_rabo_de_indice_i = BUSCA_J(vet, i-1);
            vet[ (linha_do_rabo_de_indice_i*30) + coluna_do_rabo_de_indice_i ].direcao_do_rabo = vet[ (linha_do_que_esta_atras_do_rabo_de_indice_i*30) + coluna_do_que_esta_atras_do_rabo_de_indice_i ].direcao_do_rabo;
        }
        i--;
    }
}

int main(){
    while(1){

        int i;
        int j;
        celula vet[300];
        INICIO(vet);
        srand(time(NULL));
        vida = 1;

        FILE *fp;
        fp = fopen("keytmp", "w");
        fputc('d', fp);
        fclose(fp);
        direcao = 'd';
        direcao_anterior = 'd';
        direcao_atual = 'd';
        tamanho_da_cobrinha = 2;

        while(1){
            
            spaw(vet);
            
            PRINT(vet);
            printf("\n %d\n", tamanho_da_cobrinha);
            receber(&direcao);
            system("clear");
            direcao_atual = direcao;

            i = BUSCA_I(vet, 0);
            j = BUSCA_J(vet, 0);

            if(direcao_atual == direcao_anterior){
                verific(vet, i, j, 'O', direcao_atual, 0);
            }else{

                if(direcao == pCIMA){
                    if(direcao_anterior == pBAIXO){ 
                        direcao_atual = pBAIXO;
                        BAIXO(vet, i, j, 'O', &vida, 0);
                    } else CIMA(vet, i, j, 'O', &vida, 0);
                }

                if(direcao == pDIREITA){
                    if(direcao_anterior == pESQUERDA){
                        direcao_atual = pESQUERDA;
                        ESQUERDA(vet, i, j, 'O', &vida, 0);
                    }else DIREITA(vet, i, j, 'O', &vida, 0);
                }

                if(direcao == pBAIXO){
                    if(direcao_anterior == pCIMA){
                        direcao_atual = pCIMA;
                        CIMA(vet, i, j, 'O', &vida, 0);
                    } else BAIXO(vet, i, j, 'O', &vida, 0);
                }
                            
                if(direcao == pESQUERDA){
                    if(direcao_anterior == pDIREITA){
                        direcao_atual = pDIREITA;
                        DIREITA(vet, i, j, 'O', &vida, 0);
                    }else ESQUERDA(vet, i, j, 'O', &vida, 0);
                }

            }

            if(vida == 0){
                printf("PELO AMOR DE DEUS, VOCE FEZ A COBRINHA COMER COCO\n");
                printf("ESPERE 5 SEGUNDOS\n");
                sleep(5);
                break;
            }

            mover_rabo(vet);

            atualizar_direcao_do_rabo(vet);

            direcao_anterior = direcao_atual;

            aumentar(vet, &tamanho_da_cobrinha);

        }

    }


}  


