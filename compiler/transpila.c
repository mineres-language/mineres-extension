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
    {"uai_senao", "else if"},
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

    int dentro_de_funcao = 0;
    char palavra[100];
    while (fscanf(entrada, "%255s", palavra) != EOF) {
        // Ignorar comentários de bloco "causo"
        if (strcmp(palavra, "causo") == 0) {
            fprintf(saida, "/* ");
            continue;
        }
        if (strcmp(palavra, "fim_do_causo") == 0) { 
            fprintf(saida, " */\n");
            continue;
        }
        if (strcmp(palavra, "bora_cumpade") == 0) {
        char assinatura[256] = "";
        char buf[256];
        while (fscanf(entrada, "%255s", buf) != EOF) {
            if (strlen(assinatura) > 0)
                strcat(assinatura, " ");
            strcat(assinatura, buf);
            if (strchr(buf, ')') != NULL)
                break;
        }
        if (strncmp(assinatura, "main", 9) == 0) {
            fprintf(saida, "int main() {\n");
        } else {
            fprintf(saida, "int %s {\n", assinatura);
        }
        dentro_de_funcao = 1;
        continue;
    }
    if (strcmp(palavra, "simbora") == 0) {
        if (dentro_de_funcao) {
            dentro_de_funcao = 0;
            continue;
        }
        fprintf(saida, ") { ");
        continue;
    }
    if (strncmp(palavra, "oia_proce_ve", 12) == 0) {
        char buf[1024] = "";
        char token[256];
        int dentro_string = 0;

        // se já veio com ( grudado, pega o resto
        if (strlen(palavra) > 12) {
            strcat(buf, palavra + 12);
            // verifica se abre string e não fecha no mesmo token
            int aspas = 0;
            for (int i = 0; palavra[i+12]; i++)
                if (palavra[i+12] == '"') aspas++;
            if (aspas % 2 == 1) dentro_string = 1;
        }

        while (fscanf(entrada, "%255s", token) != EOF) {
            if (strcmp(token, "uai") == 0)
                break;
            if (dentro_string) {
                strcat(buf, " ");
                strcat(buf, token);
            } else {
                strcat(buf, token);
            }
            // conta aspas para saber se entrou ou saiu da string
            for (int i = 0; token[i]; i++)
                if (token[i] == '"') dentro_string = !dentro_string;
        }
        fprintf(saida, "printf%s ; ", buf);
        continue;
    }

        traduzir_palavra(palavra, saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("Transpilação concluída com sucesso, sô!\n");
    return 0;
}