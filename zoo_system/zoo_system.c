#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------------------------
//Paulo Daniel Forti da Fonseca
-----------------------------*/

#define N 50

typedef struct info_animal{
    int codigo;
    char nome[N];
    float peso;
    float altura;
    char especie[N];
} info_animal;


int main() {

    info_animal ***zoologico = NULL;
    int opcao, numJaula;
    int numJaulas = 0, numAnimais = 0, numSetores = 0;
    char **nomeSetores = NULL, nomeSetor[N], maisPesado[N], maiorAltura[N];
    float maiorPeso = 0, maisAlto = 0;
    printf("==================================================");

    do {
        printf("\nDigite '0' para sair do programa.\n"
               "1- Inicializacao do sistema: \n"
               "2- Catalogo de setores: \n"
               "3- Inserir animais em uma jaula de um setor: \n"
               "4- Animal mais pesado de um dado setor: \n"
               "5- Inserir novo setor: \n"
               "6- Remover setor: \n"
               "7- Buscar animal mais alto de um setor especifico: \n-> ");

        scanf("%d", &opcao);

        switch (opcao) {

            case 0:; // Sair do programa
                for (int i = 0; i < numSetores; i++) {
                    for (int j = 0; j < numJaulas; j++) {
                        free(zoologico[i][j]);
                    }
                    free(zoologico[i]);
                    free(nomeSetores[i]);
                }
                free(zoologico);
                free(nomeSetores);
                return 0;


            case 1:; // Inicialização do sistema
                printf("\nQuantidade de setores: ");
                scanf("%d", &numSetores);
                printf("Quantidade de jaulas: ");
                scanf("%d", &numJaulas);
                printf("Quantidade de animais: ");
                scanf("%d", &numAnimais);

                zoologico = (info_animal***)malloc(numSetores * sizeof(info_animal**));
                nomeSetores = (char**)malloc(numSetores * sizeof(char*));

                for (int i = 0; i < numSetores; i++) {
                    zoologico[i] = (info_animal**)malloc(numJaulas * sizeof(info_animal*));
                    nomeSetores[i] = (char*)malloc(N * sizeof(char));
                    for (int j = 0; j < numJaulas; j++) {
                        zoologico[i][j] = (info_animal*)calloc(numAnimais,sizeof(info_animal));
                    }
                }
                break;

            case 2:; // Catálogo de Setores

            printf("\n");
                for (int i = 0; i < numSetores; i++) {
                    printf("Insira nome do setor %d: ", i + 1);
                    setbuf(stdin, NULL);
                    gets(nomeSetores[i]);
                }
                break;


            case 3:;//Infos animais
                printf("\nInforme o nome do setor: ");
                setbuf(stdin,NULL);
                gets(nomeSetor);

                int setorEncontrado = -1;
                for(int i = 0; i < numSetores; i++){
                    if(strcmp(nomeSetores[i], nomeSetor) == 0){
                        setorEncontrado = i;
                        break;
                    }
                }
                if(setorEncontrado == -1){
                    printf("Nome do setor invalido.\n");
                    break;
                }

                printf("Informe o numero da jaula: ");
                scanf("%d", &numJaula);
                if (numJaula < 1 || numJaula > numJaulas) {
                    printf("Numero da jaula invalido.\n");
                    break;
                }

                for(int i = 0; i < numAnimais; i++){
                    printf("\nInsira os dados do animal %d: \n", i+1);
                    printf("Codigo: ");
                    scanf("%d", &zoologico[setorEncontrado][numJaula-1][i].codigo);

                    printf("Nome do animal: ");
                    setbuf(stdin, NULL);
                    gets(zoologico[setorEncontrado][numJaula-1][i].nome);

                    printf("Peso: ");
                    scanf("%f", &zoologico[setorEncontrado][numJaula-1][i].peso);

                    printf("Altura (em metros): ");
                    scanf("%f", &zoologico[setorEncontrado][numJaula-1][i].altura);

                    printf("Especie: ");
                    setbuf(stdin, NULL);
                    gets(zoologico[setorEncontrado][numJaula-1][i].especie);
                }
                break;


                case 4:;//Mais pesado
                    printf("\nInsira o nome do setor: ");
                    setbuf(stdin, NULL);
                    gets(nomeSetor);

                    setorEncontrado = -1;
                    for(int i = 0; i < numSetores; i++){
                        if(strcmp(nomeSetores[i], nomeSetor) == 0){
                            setorEncontrado = i;
                            break;
                        }
                    }
                    if(setorEncontrado == -1){
                        printf("Nome de setor invalido.\n");
                        break;
                    }

                    maiorPeso = 0;
                    for(int i = 0; i < numJaulas; i++){
                        for(int j = 0; j < numAnimais; j++){
                            if(zoologico[setorEncontrado][i][j].peso > maiorPeso){
                                maiorPeso = zoologico[setorEncontrado][i][j].peso;
                                strcpy(maisPesado, zoologico[setorEncontrado][i][j].nome);
                            }
                        }
                    }

                    if(maiorPeso > 0){
                        printf("O animal mais pesado do setor '%s' eh o(a): %s com %.2f kg.\n", nomeSetor, maisPesado, maiorPeso);
                    } else {
                        printf("Nao ha animais no setor '%s'.\n", nomeSetor);
                    }
                    break;


            case 5:; // Inserir novo setor
                printf("\nQuantos setores deseja adicionar: ");
                int qtdAdicionadoSetor;
                scanf("%d", &qtdAdicionadoSetor);

                numSetores += qtdAdicionadoSetor;
                zoologico = realloc(zoologico, numSetores * sizeof(info_animal**));
                nomeSetores = realloc(nomeSetores, numSetores * sizeof(char*));

                for (int i = numSetores - qtdAdicionadoSetor; i < numSetores; i++) {
                    zoologico[i] = (info_animal**)malloc(numJaulas * sizeof(info_animal*));
                    nomeSetores[i] = (char*)malloc(N * sizeof(char));
                    for (int j = 0; j < numJaulas; j++) {
                        zoologico[i][j] = (info_animal*)malloc(numAnimais * sizeof(info_animal));
                    }
                }
                printf("Setor(es) adicionado(s).\n");
                break;


            case 6:; // Remover setor
                printf("\nNome do setor a ser removido: ");
                char setorRemover[N];
                setbuf(stdin, NULL);
                gets(setorRemover);
                int removerSetor = -1;

                for (int i = 0; i < numSetores; i++) {
                    if (strcmp(nomeSetores[i], setorRemover) == 0) {
                        removerSetor = i;
                        break;
                    }
                }

                if (removerSetor == -1) {
                    printf("Nome do setor invalido.\n");
                    break;
                }

                // Liberando memoria do setor a ser removido
                for (int j = 0; j < numJaulas; j++) {
                    free(zoologico[removerSetor][j]);
                }
                free(zoologico[removerSetor]);
                free(nomeSetores[removerSetor]);

                // Deslocando setores
                for (int i = removerSetor; i < numSetores - 1; i++) {
                    zoologico[i] = zoologico[i + 1];
                    nomeSetores[i] = nomeSetores[i + 1];
                }

                printf("Setor removido.\n");
                // Realocando para o novo tamanho
                numSetores--;
                zoologico = realloc(zoologico, numSetores * sizeof(info_animal**));
                nomeSetores = realloc(nomeSetores, numSetores * sizeof(char*));
                break;


            case 7:;//Mais alto

                printf("\nInsira o nome do setor: ");
                    setbuf(stdin, NULL);
                    gets(nomeSetor);

                    setorEncontrado = -1;
                    for(int i = 0; i < numSetores; i++){
                        if(strcmp(nomeSetores[i], nomeSetor) == 0){
                            setorEncontrado = i;
                            break;
                        }
                    }
                    if(setorEncontrado == -1){
                        printf("Nome do setor invalido.\n");
                        break;
                    }

                    maisAlto = 0;

                    for(int i = 0; i < numJaulas; i++){
                        for(int j = 0; j < numAnimais; j++){
                            if(zoologico[setorEncontrado][i][j].altura > maisAlto){
                                maisAlto = zoologico[setorEncontrado][i][j].altura;
                                strcpy(maiorAltura, zoologico[setorEncontrado][i][j].nome);
                            }
                        }
                    }

                    if(maisAlto > 0){
                        printf("O animal mais alto do setor '%s' eh o(a): %s com %.2f metros.\n", nomeSetor, maiorAltura, maisAlto);
                    } else {
                        printf("Não ha animais no setor '%s'.\n", nomeSetor);
                    }
                break;

            default:;
                printf("\nOpcao invalida, digite um numero entre 0 e 7.\n");
        }
    } while (opcao != 0);

    return 0;
}
