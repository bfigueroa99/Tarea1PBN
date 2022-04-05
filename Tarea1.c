#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



int imprimir(char lista[12][33]){
    for (int i1=0;i1<11;i1++){
        for (int i2=0;i2<=33;i2++){

            if(((i2==0)||(i2==33))&&(i1!=0)&&(i1!=11)){
                lista[i1][i2] = (i1-1);
                printf("%d",lista[i1][i2]);
            }

            else {
                printf("%c",lista[i1][i2]);
            }
        }
        printf("\n");
    }
    return 0;
}

int numerosaleatorios(int d,int h){ //numeros aleatorios entre d y h
    time_t t;
    srand((unsigned) time(&t));
    int r = rand()%(h+1); //resultado
    while(r<d){
        r = rand()%(h+1);
        }
    return(r);
}

void colocarmurallas(char lista[12][33]){
    //primero verifico y borro las M que hay
    for (int i1=0;i1<11;i1++){
        for (int i2=0;i2<=33;i2++){
            if (lista[i1][i2] == 'M') lista[i1][i2] == '_';
            }
        }
    
    //y ahora coloco de nuevo las murallas
    for(int i=0;i<2;i++){
        int loop = 1;
        while (loop == 1){
            int p = numerosaleatorios(0,1); //para elegir si ubicarla de manera (0)horizontal o (1)vertical
                if (p == 1){
                    int a = (numerosaleatorios(1,10))*3;
                    int b = numerosaleatorios(1,9);
                    if ((lista[a][b] != 'G')||(lista[a][b] != 'R')||(lista[a][b] != 'M')||(lista[a][b+1] != 'G')||(lista[a][b+1] != 'R')||(lista[a][b+1] != 'M')){
                        lista[a][b] = 'M';
                        lista[a][b+1] = 'M';
                        loop = 0;
                        }
                    }
                if (p == 0){
                    int a = (numerosaleatorios(1,9))*3;
                    int b = numerosaleatorios(1,10);
                    if ((lista[a][b] != 'G')||(lista[a][b] != 'R')||(lista[a][b] != 'M')||(lista[a+3][b] != 'G')||(lista[a+3][b] != 'R')||(lista[a+3][b] != 'M')){
                        lista[a][b] = 'M';
                        lista[a+3][b] = 'M';
                        loop = 0;
                        }
                    }
            }
        }
    return 0;
    }


int main(int argc,  char **argv){
    char tablero[12][33]; //primero creo el tablero

    for (int i1=0;i1<12;i1++){
        for (int i2=0;i2<=33;i2++){

            if(((i2==0)||(i2==33))&&(i1!=0)&&(i1!=11)){
                tablero[i1][i2] = (i1-1);
                printf("%d",tablero[i1][i2]);
            }

            else if((i2==1)||(i2==32)||(((i1==0)||(i1==11))&&((i2<3)||(i2==4)||(i2==5)||(i2==7)||(i2==8)||(i2==10)||(i2==11)||(i2==13)||(i2==14)||(i2==16)||(i2==17)||(i2==19)||(i2==20)||(i2==22)||(i2==23)||(i2==25)||(i2==26)||(i2==28)||(i2==29)||(i2>=31)))){
                tablero[i1][i2] = ' ';
                printf("%c",tablero[i1][i2]);

            }

            else if(((i1!=0)||(i1!=11))&&((i2==2)||(i2==5)||(i2==8)||(i2==11)||(i2==14)||(i2==17)||(i2==20)||(i2==23)||(i2==26)||(i2==29))){
                tablero[i1][i2] = '[';
                printf("%c",tablero[i1][i2]);
            }

            else if(((i1!=0)||(i1!=11))&&((i2==4)||(i2==7)||(i2==10)||(i2==13)||(i2==16)||(i2==19)||(i2==22)||(i2==25)||(i2==28)||(i2==31))){
                tablero[i1][i2] = ']';
                printf("%c",tablero[i1][i2]);
            }

            else if(((i1==0)||(i1==11))&&((i2==3)||(i2==6)||(i2==9)||(i2==12)||(i2==15)||(i2==18)||(i2==21)||(i2==24)||(i2==27)||(i2==30))){
                tablero[i1][i2] = 64+(i2/3);
                printf("%c",tablero[i1][i2]);

            }

            else {
                tablero[i1][i2] = '_';
                printf("%c",tablero[i1][i2]);
                }
            
        }
        printf("\n");
    }

    colocarmurallas(tablero);
    imprimir(tablero);

    return 0;
}