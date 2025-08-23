#include <time.h> 
#include <stdlib.h>
#include "BUSCA.h"

// TAL COISA
void spaw(celula vet[]){
    srand(time(NULL));
    int i = BUSCA_I(vet, 301);
    if(i == -1){
        int linha = rand() % 10;
        int coluna = rand() % 30;
        while(vet[  (linha*30)+coluna  ].corpo == 'O' || vet[  (linha*30)+coluna  ].corpo == 'o'){
            linha = rand() % 10;
            coluna = rand() % 30;
        }
        vet[  (linha*30)+coluna  ].corpo = 'C';
        vet[  (linha*30)+coluna  ].ordem = 301;
    }
    
}