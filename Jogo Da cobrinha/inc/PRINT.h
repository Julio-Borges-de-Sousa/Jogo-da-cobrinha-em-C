#include <stdio.h>

void PRINT(celula vet[]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 30; j++){
            printf("%c ", vet[  (i*30)+j  ].corpo);
        }
        printf("\n");
    }
}