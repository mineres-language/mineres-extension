#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Dicionário de Tradução: Minerês -> C
typedef struct {
    char mineiro[50];
    char c_puro[50];
} Dicionario;

Dicionario tabela[] = {
    {"trem_di_numeru", "int"},
    {"trem_cum_virgula", "float"},
    {"trem_discrita", "char*"},
    {"trem_discolhe", "int"},
    {"trosso", "char"},
    {"fica_assim_entao", "="},
    {"uai_se", "if ("},
    {"uai_senão", "else if"},
    {"simbora", ") {"},
    {"cabô", "}"},
    {"cabo", "}"},
    {"oia_proce_ve", "printf"},
    {"xove", "scanf"},
    {"roda_esse_trem", "for"},
    {"enquanto_tiver_trem", "while"},
    {"dependenu", "switch"},
    {"du_casu", "case"},
    {"para_o_trem", "break"},
    {"toca_o_trem", "continue"},
    {"ta_bao", "return"},
    {"veiz", "*"},
    {"sob", "/"},
    {"mema_coisa", "=="},
    {"neh_nada", "!="},
    {"quarque_um", "||"},
    {"vam_marca", "&&"},
    {"bora_cumpade", "int main() {"},
    {"uai", ";"}
};

int total_termos = sizeof(tabela) / sizeof(Dicionario);

void traduzir_palavra(char *palavra, FILE *saida) {
    for (int i = 0; i < total_termos; i++) {
        if (strcmp(palavra, tabela[i].mineiro) == 0) {
            fprintf(saida, "%s ", tabela[i].c_puro);
            return;
        }
    }
    // Se não estiver no dicionário, escreve a palavra como ela é (nomes de variáveis, números, etc)
    fprintf(saida, "%s ", palavra);
}

int main(int argc, char *argv[]) {
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

    if (argc < 2) {
        printf("Erro: Informe o arquivo .uai\n");
        return 1;
    }

    FILE *entrada = fopen(argv[1], "r");
    FILE *saida = fopen("saida.c", "w");

    if (!entrada || !saida) {
        printf("Erro ao abrir arquivos!\n");
        return 1;
    }

    fprintf(saida, "#include <stdio.h>\n#include <stdbool.h>\n\n");

    char palavra[100];
    while (fscanf(entrada, "%s", palavra) != EOF) {
        // Ignorar comentários de bloco "causo"
        if (strcmp(palavra, "causo") == 0) {
            fprintf(saida, "/* ");
            continue;
        }
        if (strcmp(palavra, "fim") == 0) { // Se encontrar "fim do causo"
            char proxima[100];
            fscanf(entrada, "%s", proxima); // do
            fscanf(entrada, "%s", proxima); // causo
            fprintf(saida, " */\n");
            continue;
        }

        traduzir_palavra(palavra, saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("Transpilação concluída com sucesso, sô!\n");
    return 0;
}