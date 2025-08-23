void CIMA(celula vet[], int I, int J, char corpo, int *vida){
    vet[(I*30)+J].corpo = '|';
    vet[(I*30)+J].ordem = -1;
    vet[(I*30)+J].direcao_do_rabo = 0;
    if(I != 0){
        if( (vet[ (I-1)*30 + J  ].corpo == 'C') && (corpo == 'O') )*vida = (*vida+1);
        if( (vet[ (I-1)*30 + J  ].corpo == 'o') && (corpo == 'O') )*vida = 0;
        vet[ (I-1)*30 + J  ].corpo = corpo;
        if(corpo == 'o'){
            vet[ (I-1)*30 + J  ].ordem = 1;
            vet[ (I-1)*30 + J  ].direcao_do_rabo = 'w';
        }else{
            vet[ (I-1)*30 + J  ].ordem = 0;
            vet[ (I-1)*30 + J  ].direcao_do_rabo = 0;
        }
    }else{
        if( (vet[ (9*30) + J ].corpo == 'C') && (corpo == 'O') )*vida = (*vida+1);
        if( (vet[ (9*30) + J ].corpo == 'o') && (corpo == 'O') )*vida = 0;
        vet[ (9*30) + J ].corpo = corpo;
        if(corpo == 'o'){
            vet[ (9*30) + J ].ordem = 1;
        }else{
            vet[ (9*30) + J ].ordem = 0;
            vet[ (9*30) + J ].direcao_do_rabo = 0;
        }
    }
}