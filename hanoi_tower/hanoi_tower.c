#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------
//Paulo Daniel Forti da Fonseca
-----------------------------*/

int main(){

    int A[5] = {1,2,3,4,5};
    int B[5] = {0,0,0,0,0};
    int C[5] = {0,0,0,0,0};

    int *pontA = A;
    int *pontB = NULL;
    int *pontC = NULL;

    int temp, contador = 0;

    char jogada[4];

    //Instruções para o usuário.
    printf("Digite:\nAB para mover o valor da primeira coluna para a segunda.");
    printf("\nAC para mover o valor da primeira coluna para a terceira.");
    printf("\nBA para mover o valor da segunda coluna para a primeira.");
    printf("\nBC para mover o valor da segunda coluna para a terceira.");
    printf("\nCA para mover o valor da terceira coluna para a primeira.");
    printf("\nCB para mover o valor da terceira coluna para a segunda.");

    printf("\n\nDigite 10 para desistir.\n\n");

    while (!(C[4] == 1)){

        if(contador == 0)
            printf("Torre de Hanoi: \n");

        for(int i = 4;i >= 0; i--) //Imprime os elementos de cada torre (A,B,C);
            printf("%d %d %d\n", A[4-i], B[i], C[i]);

        printf("\n");

        if(contador == 0)
             printf("Digite uma jogada (exemplo: AB): ");
        else
            printf("Digite uma jogada: ");


        scanf("%2s", jogada);


        if(strlen(jogada) == 2){

            if(jogada[0] == '1' && jogada[1] == '0'){
                printf("\nDesistiu.\n");
                return 0;
            }

            if(
                (jogada[0] == 'A' && A[4] != 0) || (jogada[0] == 'B' && B[0] != 0) || (jogada[0] == 'C' && C[0] != 0)){

                if(jogada[0] == 'A' && jogada[1] == 'B'){

                        if(pontB == NULL)
                            pontB = B;

                        if((*pontA < *(pontB-1)) || B[0] == 0){

                        temp = *pontA;
                        *pontA = *pontB;
                        *pontB = temp;

                        pontA++;
                        pontB++;
                        contador++;

                        if(A[4] == 0)
                            pontA = NULL;
                        }else
                            printf("Jogada Invalida!\n\n");
                            

                }else if(jogada[0] == 'A' && jogada[1] == 'C'){

                        if(pontC == NULL)
                            pontC = C;

                        if((*pontA < *(pontC-1)) || C[0] == 0){

                        temp = *pontA;
                        *pontA = *pontC;
                        *pontC = temp;

                        pontA++;
                        pontC++;
                        contador++;

                        if(A[4] == 0)
                            pontA = NULL;
                        }else
                            printf("Jogada Invalida!\n\n");

                }else if(jogada[0] == 'B' && jogada[1] == 'A'){

                        if(pontA == NULL){
                            pontA = &A[4];
                            temp = *(pontB-1);
                            *(pontB-1) = *(pontA);
                            *(pontA) = temp;
                            pontB--;
                        }else if((*(pontB-1) < *(pontA)) || A[4] == 0){
                        temp = *(pontB-1);
                        *(pontB-1) = *(pontA-1);
                        *(pontA-1) = temp;

                        pontB--;
                        pontA--;
                        }else
                            printf("Jogada Invalida!\n\n");

                        if(B[0] == 0)
                            pontB = NULL;

                }else if(jogada[0] == 'B' && jogada[1] == 'C'){

                        if(pontC == NULL)
                            pontC = C;

                        if((*(pontB-1) < *(pontC-1)) || C[0] == 0){
                        temp = *(pontB-1);
                        *(pontB-1) = *pontC;
                        *pontC = temp;

                        pontB--;
                        pontC++;
                        }else
                            printf("Jogada Invalida!\n\n");

                        if(B[0] == 0)
                            pontB = NULL;

                }else if(jogada[0] == 'C' && jogada[1] == 'A'){

                        if(pontA == NULL){
                            pontA = &A[4];
                            temp = *(pontC-1);
                            *(pontC-1) = *(pontA);
                            *(pontA) = temp;
                            pontC--;
                        }else if((*(pontC-1) < *(pontA)) || A[4] == 0){
                        temp = *(pontC-1);
                        *(pontC-1) = *(pontA-1);
                        *(pontA-1) = temp;

                        pontC--;
                        pontA--;
                        }else
                            printf("Jogada Invalida!\n\n");

                        if(C[0] == 0)
                            pontC = NULL;

                }else if(jogada[0] == 'C' && jogada[1] == 'B'){

                        if(pontB == NULL)
                            pontB = B;

                        if((*(pontC-1) < *(pontB-1)) || B[0] == 0){
                        temp = *(pontC-1);
                        *(pontC-1) = *pontB;
                        *pontB = temp;

                        pontB++;
                        pontC--;
                        }else
                            printf("Jogada Invalida!\n\n");

                        if(C[0] == 0)
                            pontC = NULL;
                }else{
                printf("Jogada Invalida!\n\n");
                contador++;
            }
            }else{
                printf("Jogada Invalida!\n\n");
                contador++;
            }
        }else{
            printf("Jogada Invalida!\n\n");
            while(getchar() != '\n')
                contador++;
        }
    }

    for(int i = 4;i >= 0; i--)
        printf("%d %d %d\n", A[4-i], B[i], C[i]);

    printf("\nParabens, voce ganhou!\n");

    return 0;
}