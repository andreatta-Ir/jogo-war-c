#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[50];
    char cor[10];
    int tropas;
    char continente[20];
} Territorio;

#define NUM_TERRA_TOT 10
#define NUM_TERRA_ASIA 4
#define NUM_TERRA_AM_SUL 3

Territorio *territorios;

void inicializarTerritorios() {
    territorios = (Territorio *)malloc(NUM_TERRA_TOT * sizeof(Territorio));
    if (territorios == NULL) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    strcpy(territorios[0].nome, "China");
    strcpy(territorios[0].cor, "neutro");
    territorios[0].tropas = 5;
    strcpy(territorios[0].continente, "Asia");

    strcpy(territorios[1].nome, "India");
    strcpy(territorios[1].cor, "neutro");
    territorios[1].tropas = 4;
    strcpy(territorios[1].continente, "Asia");

    strcpy(territorios[2].nome, "Japao");
    strcpy(territorios[2].cor, "neutro");
    territorios[2].tropas = 3;
    strcpy(territorios[2].continente, "Asia");

    strcpy(territorios[3].nome, "Coreia");
    strcpy(territorios[3].cor, "neutro");
    territorios[3].tropas = 2;
    strcpy(territorios[3].continente, "Asia");

    strcpy(territorios[4].nome, "Brasil");
    strcpy(territorios[4].cor, "neutro");
    territorios[4].tropas = 4;
    strcpy(territorios[4].continente, "AmericaSul");

    strcpy(territorios[5].nome, "Argentina");
    strcpy(territorios[5].cor, "neutro");
    territorios[5].tropas = 3;
    strcpy(territorios[5].continente, "AmericaSul");

    strcpy(territorios[6].nome, "Venezuela");
    strcpy(territorios[6].cor, "neutro");
    territorios[6].tropas = 2;
    strcpy(territorios[6].continente, "AmericaSul");

    strcpy(territorios[7].nome, "EUA");
    strcpy(territorios[7].cor, "neutro");
    territorios[7].tropas = 6;
    strcpy(territorios[7].continente, "AmericaNorte");

    strcpy(territorios[8].nome, "Mexico");
    strcpy(territorios[8].cor, "neutro");
    territorios[8].tropas = 3;
    strcpy(territorios[8].continente, "AmericaNorte");

    strcpy(territorios[9].nome, "Russia");
    strcpy(territorios[9].cor, "neutro");
    territorios[9].tropas = 5;
    strcpy(territorios[9].continente, "Europa");
}

void cadastrarTerritorio(int indice) {
    if (indice < 0 || indice >= NUM_TERRA_TOT) {
        printf("Índice inválido!\n");
        return;
    }
    printf("Digite o nome do território: ");
    scanf("%s", territorios[indice].nome);
    printf("Digite a cor (jogador): ");
    scanf("%s", territorios[indice].cor);
    printf("Digite o número de tropas: ");
    scanf("%d", &territorios[indice].tropas);
    printf("Digite o continente: ");
    scanf("%s", territorios[indice].continente);
    printf("Território atualizado!\n");
}

void exibirTerritorios() {
    printf("\n=== Lista de Territórios ===\n");
    for (int i = 0; i < NUM_TERRA_TOT; i++) {
        printf("ID: %d | Nome: %s | Cor: %s | Tropas: %d | Continente: %s\n",
               i, territorios[i].nome, territorios[i].cor, territorios[i].tropas, territorios[i].continente);
    }
    printf("============================\n\n");
}

void atacar(Territorio *atacante, Territorio *defensor) {
    if (atacante->tropas < 2) {
        printf("Ataque falhou: atacante precisa de pelo menos 2 tropas!\n");
        return;
    }
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Não pode atacar território aliado!\n");
        return;
    }

    printf("\n=== Simulando Ataque: %s (atacante) vs %s (defensor) ===\n", atacante->nome, defensor->nome);

    while (atacante->tropas > 1 && defensor->tropas > 0) {
        int perda = rand() % 2;
        if (perda == 0) {
            atacante->tropas--;
            printf("Atacante perde 1 tropa. Tropas restantes: %d\n", atacante->tropas);
        } else {
            defensor->tropas--;
            printf("Defensor perde 1 tropa. Tropas restantes: %d\n", defensor->tropas);
        }
    }

    if (atacante->tropas > 1) {
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas - 1;
        atacante->tropas = 1;
        printf("Vitória! %s conquistado por %s.\n", defensor->nome, atacante->cor);
    } else {
        printf("Derrota! Ataque repelido.\n");
    }
    printf("==============================\n\n");
}

int verificarVitoria(const char *corJogador) {
    int controleAsia = 0;
    int controleAmSul = 0;

    for (int i = 0; i < NUM_TERRA_TOT; i++) {
        if (strcmp(territorios[i].continente, "Asia") == 0) {
            if (strcmp(territorios[i].cor, corJogador) == 0) {
                controleAsia++;
            }
        }
    }
    if (controleAsia == NUM_TERRA_ASIA) {
        printf("Missão Ásia concluída para %s!\n", corJogador);
    } else {
        printf("Faltam %d territórios na Ásia para %s.\n", NUM_TERRA_ASIA - controleAsia, corJogador);
        return 0;
    }

    for (int i = 0; i < NUM_TERRA_TOT; i++) {
        if (strcmp(territorios[i].continente, "AmericaSul") == 0) {
            if (strcmp(territorios[i].cor, corJogador) == 0) {
                controleAmSul++;
            }
        }
    }
    if (controleAmSul == NUM_TERRA_AM_SUL) {
        printf("Missão América do Sul concluída para %s!\n", corJogador);
        return 1;
    } else {
        printf("Faltam %d territórios na América do Sul para %s.\n", NUM_TERRA_AM_SUL - controleAmSul, corJogador);
        return 0;
    }
}

void liberarMemoria() {
    free(territorios);
    printf("Memória liberada.\n");
}

int main() {
    srand(time(NULL));

    printf("Bem-vindo ao Jogo War em C!\n");
    printf("Este programa implementa cadastro de territórios, ataques e missões estratégicas.\n\n");

    inicializarTerritorios();

    int opcao;
    char corJogador[10];
    int idAtacante, idDefensor;

    do {
        printf("Menu:\n1. Exibir territórios\n2. Cadastrar/atualizar território (por ID)\n3. Realizar ataque (digite IDs)\n4. Verificar vitória para um jogador (digite cor)\n5. Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirTerritorios();
                break;
            case 2:
                printf("Digite o ID do território (0-%d): ", NUM_TERRA_TOT - 1);
                scanf("%d", &idAtacante);
                cadastrarTerritorio(idAtacante);
                break;
            case 3:
                printf("Digite ID do atacante: ");
                scanf("%d", &idAtacante);
                printf("Digite ID do defensor: ");
                scanf("%d", &idDefensor);
                if (idAtacante >= 0 && idAtacante < NUM_TERRA_TOT && idDefensor >= 0 && idDefensor < NUM_TERRA_TOT) {
                    atacar(&territorios[idAtacante], &territorios[idDefensor]);
                } else {
                    printf("IDs inválidos!\n");
                }
                break;
            case 4:
                printf("Digite a cor do jogador: ");
                scanf("%s", corJogador);
                if (verificarVitoria(corJogador)) {
                    printf("Vitória para %s! Jogo concluído.\n", corJogador);
                }
                break;
            case 5:
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 5);

    exibirTerritorios();
    liberarMemoria();
    return 0;
}

