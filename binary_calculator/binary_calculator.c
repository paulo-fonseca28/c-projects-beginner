#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*-----------------------------
//Paulo Daniel Forti da Fonseca
-----------------------------*/

#define TAM 66

long long int binarioDecimal(char *x) {
    int acumuladorBinario = 0;
    int potencia = 1;
    int tamanho = strlen(x) - 1;
    for (int i = tamanho; i >= 1; i--) {
        acumuladorBinario += (x[i] - '0') * potencia; // -'0' converte o char para int
        potencia *= 2;            
    }
    if(x[0] == '1')
        return -acumuladorBinario;
    return acumuladorBinario;
}

void decimalBinario(long long int x, char *y) {
    int negativo = 0;
    if (x < 0) {
        negativo = 1;
        x = -x; 
    }

    int i = 0;
    while (x > 0) {
        y[i++] = (x % 2) + '0';// +'0' converte o int em char
        x /= 2;
    }

    //Define o sinal do nro
    if (negativo)
        y[i++] = '1';
    else
        y[i++] = '0';

    y[i] = '\0';

    // Inverte a string
    for (int j = 0, k = i - 1; j < k; j++, k--) {
        char temp = y[j];
        y[j] = y[k];
        y[k] = temp;
    }
}

    long long int potencia(long long int x, long long int y){
        if( y < 0){
            return 0;
        }
        long long int resultado = 1;
            for(int i = 0; i < y; i++){
                resultado *= x;
            }
        return resultado;
    }

    long long int fatorial(long long int x){
        if(x == 0){
            return 1;
        }
        return x*fatorial(x-1);
    }

char *decimalParaHexadecimal(unsigned long long int x) {
    char *hexadecimal = malloc(TAM * sizeof(char));
    if (hexadecimal == NULL) {
        exit(1);
    }
    sprintf(hexadecimal, "%llx" , x); 
    return hexadecimal;
}

char *decimalParaOctal(long unsigned int x) {
    char *octal = malloc(TAM * sizeof(char));
    if (octal == NULL) {
        exit(1);
    }
    sprintf(octal, "%lo", x); 
    return octal;
}

int main() {

    char binario1[TAM] = {0}, binario2[TAM] = {0}, binarioResultante[TAM] = {0};  //Inicializa a string com '\0'
    long long int decimal1, decimal2, decimalResultante;
    int opcao;

    printf("\nO primeiro digito do binario, sera responsavel pelo sinal positivo/negativo do numero.");
do {
        printf("\nLembre-se: O maior valor em binario suportado sao 63 numeros '1' consecutivos ou 64 caracteres incluindo o valor '0' para positivo e o valor '1' para negativo.\n"
        "Digite:\n0 para sair do programa.\n1 para Somar.\n2 para Subtrair.\n3 para Multiplicar.\n4 para Dividir.\n"
        "5 para o Resto da Divisão.\n6 para a Potência.\n7 para o Valor Absoluto(sem Sinal).\n8 para o Valor em Fatorial.\n"
        "9 para Converter o numero binário em Decimal.\n10 para Converter o numero binario em Hexadecimal.\n11 para Converter o numero binario em Octal.\n");
        printf("-> ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch (opcao) {
            case 0:

                break;

            case 1:
                printf("\nDigite o primeiro numero em binario:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                printf("Digite o segundo numero em binario:\n");
                fgets(binario2, TAM, stdin);
                binario2[strcspn(binario2, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                decimal2 = binarioDecimal(binario2);
                decimalResultante = decimal1 + decimal2;

                decimalBinario(decimalResultante, binarioResultante);
                printf("Binario resultante da soma eh: %s\n", binarioResultante);
                break;

            case 2:
                printf("\nDigite o primeiro numero em binario:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                printf("Digite o segundo numero em binario:\n");
                fgets(binario2, TAM, stdin);
                binario2[strcspn(binario2, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                decimal2 = binarioDecimal(binario2);
                decimalResultante = decimal1 - decimal2;

                decimalBinario(decimalResultante, binarioResultante);
                printf("Binario resultante da subtracao eh: %s\n", binarioResultante);
                break;

            case 3:
                printf("\nDigite o primeiro numero em binario:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                printf("Digite o segundo numero em binario:\n");
                fgets(binario2, TAM, stdin);
                binario2[strcspn(binario2, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                decimal2 = binarioDecimal(binario2);
                decimalResultante = decimal1 * decimal2;

                decimalBinario(decimalResultante, binarioResultante);
                printf("Binario resultante da multiplicacao eh: %s\n", binarioResultante);

                break;

            case 4:
                printf("\nDigite o primeiro numero em binario:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                printf("Digite o segundo numero em binario:\n");
                fgets(binario2, TAM, stdin);
                binario2[strcspn(binario2, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                decimal2 = binarioDecimal(binario2);
                decimalResultante = decimal1 / decimal2;

                decimalBinario(decimalResultante, binarioResultante);
                printf("Binario resultante da divisao eh: %s\n", binarioResultante);
                break;

            case 5:
                printf("\nDigite o primeiro numero em binario:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                printf("Digite o segundo numero em binario:\n");
                fgets(binario2, TAM, stdin);
                binario2[strcspn(binario2, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                decimal2 = binarioDecimal(binario2);
                decimalResultante = decimal1 % decimal2;

                decimalBinario(decimalResultante, binarioResultante);
                printf("Binario resultante do resto da divisao eh: %s\n", binarioResultante);

                break;

            case 6:
                printf("\nDigite o primeiro numero em binario (base da operacao):\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                printf("Digite o segundo numero em binario (expoente da operacao):\n");
                fgets(binario2, TAM, stdin);
                binario2[strcspn(binario2, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                decimal2 = binarioDecimal(binario2);
                    if(decimal2 < 0){
                        printf("NNao e permitido um expoente negativo.\n");
                        break;
                }
                decimalResultante = potencia(decimal1,decimal2);

                decimalBinario(decimalResultante, binarioResultante);
                printf("Binario resultante da potencia eh: %s\n", binarioResultante);

                break;

            case 7:
                printf("\nDigite o numero em binario:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                if (strlen(binario1) > 0) {
                    memmove(binario1, binario1 + 1, strlen(binario1));
                }
                printf("O valor do binario absoluto eh: %s\n", binario1);

                break;

            case 8:
                printf("\nDigite o numero em binario:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                if(decimal1 < 0){
                    printf("Nao pode ter fatorial com numeros negativos.\n");
                    break;
                }
                decimalResultante = fatorial(decimal1);
                decimalBinario(decimalResultante, binarioResultante);

                printf("O valor fatorial do binario eh: %s\n", binarioResultante);

                break;

            case 9:
                printf("\nDigite o numero em binario, para sabermos qual eh o seu valor em Decimal:\n");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;

                decimal1 = binarioDecimal(binario1);
                printf("O valor decimal do binario eh: %lld\n", decimal1);

                break;

            case 10:;
                char *hexadecimal;

                printf("\nDigite um numero binario: ");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;
                
                decimal1 = binarioDecimal(binario1);

                hexadecimal = decimalParaHexadecimal(decimal1);

                printf("O valor em hexadecimal eh: %s\n", hexadecimal);

                    free(hexadecimal);
                break;

            case 11:;
                char *octal;

                printf("\nDigite um numero binario: ");
                fgets(binario1, TAM, stdin);
                binario1[strcspn(binario1, "\n")] = 0;
                
                decimal1 = binarioDecimal(binario1);

                octal = decimalParaOctal(decimal1);

                printf("O valor em octal eh: %s\n", octal);

                    free(octal);

                break;
            
            default:
                printf("Opcao invalida, digite um numero entre 0 e 11.\n");
        }
        
    }while(opcao != 0);

    printf("\nSaiu do Programa.\n");
    return 0;
}
