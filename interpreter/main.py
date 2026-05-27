# interpreter/main.py
import os
import sys

# ---------------------------------------------------------------------------
# Flags de execução
#   --verbose  →  exibe os logs do pipeline (LEXER, PARSER, IR)
#   --save-ir  →  salva os arquivos de saída intermediários em disco
# ---------------------------------------------------------------------------
VERBOSE  = "--verbose"  in sys.argv
SAVE_IR  = "--save-ir"  in sys.argv

from lexer.lexer import Lexer, formata_tokens
from parser.parser import Parser
from ir import formata_codigo
from interpreter.interpreter import Interpretador


def log(msg: str):
    """Imprime apenas se o modo verbose estiver ativo."""
    if VERBOSE:
        print(msg)


def read_file(arquivo_entrada: str) -> str:
    try:
        with open(arquivo_entrada, "r", encoding="utf-8") as f:
            return f.read()
    except FileNotFoundError:
        print(f"Erro: O arquivo '{arquivo_entrada}' não foi encontrado, uai!")
        sys.exit(1)


def analise_lexica(fonte: str, arquivo_saida: str) -> list:
    lexer = Lexer(fonte)
    if lexer.tokenizar():
        if SAVE_IR:
            os.makedirs(os.path.dirname(arquivo_saida), exist_ok=True)
            with open(arquivo_saida, "w", encoding="utf-8") as f:
                f.write(formata_tokens(lexer.tokens))
        log(f"  [LEXER] Sucesso! {len(lexer.tokens)} tokens gerados.")
        return lexer.tokens
    else:
        print("  [LEXER] Falha na análise léxica.")
        sys.exit(1)


def analise_sintatica(tokens: list) -> list:
    parser = Parser(tokens)
    codigo_ir = parser.iniciar()
    log("  [PARSER] Análise sintática concluída com sucesso!")
    return codigo_ir


def gera_ir(codigo_ir: list, arquivo_saida: str):
    if not codigo_ir:
        log("  [IR] Nenhum código intermediário a gerar.")
        return

    if SAVE_IR:
        os.makedirs(os.path.dirname(arquivo_saida), exist_ok=True)
        with open(arquivo_saida, "w", encoding="utf-8") as f:
            f.write(formata_codigo(codigo_ir))
        log(f"  [IR] Sucesso! {len(codigo_ir)} tuplas geradas, salvas em {arquivo_saida}.")
    else:
        log(f"  [IR] Sucesso! {len(codigo_ir)} tuplas geradas.")


def main():
    # ------------------------------------------------------------------
    # Resolve o arquivo de entrada:
    #   1. Primeiro argumento posicional (ignora flags que começam com --)
    #   2. Fallback para o caminho padrão de desenvolvimento
    # ------------------------------------------------------------------
    args_posicionais = [a for a in sys.argv[1:] if not a.startswith("--")]

    if args_posicionais:
        arquivo_entrada = args_posicionais[0]
    else:
        arquivo_entrada = "interpreter/data/entrada.uai"

    # Arquivos de saída intermediários (só usados com --save-ir)
    base_dir         = os.path.dirname(arquivo_entrada)
    arquivo_saida    = os.path.join(base_dir, "saida.uai")
    arquivo_saida_ir = os.path.join(base_dir, "saida_ir.uai")

    if VERBOSE:
        print("-" * 40)
        print(" " * 11 + "MINERES INTERPRETER")
        print("-" * 40 + "\n")
        print(f"  Arquivo de entrada: {arquivo_entrada}\n")

    # Leitura do arquivo
    fonte = read_file(arquivo_entrada)

    # -----------------------------------
    # Análise Léxica
    log(" " * 7 + "-" * 5 + " ANÁLISE LÉXICA (LEXER) " + "-" * 5)
    tokens = analise_lexica(fonte, arquivo_saida)
    log("\n" + "-" * 40 + "\n")

    # -----------------------------------
    # Análise Sintática
    log(" " * 7 + "-" * 5 + " ANÁLISE SINTÁTICA (PARSER) " + "-" * 5)
    codigo_ir = analise_sintatica(tokens)
    log("\n" + "-" * 40 + "\n")

    # -----------------------------------
    # Geração de Código Intermediário
    log(" " * 2 + "-" * 5 + " GERAÇÃO DE CÓDIGO INTERMEDIÁRIO " + "-" * 5)
    gera_ir(codigo_ir, arquivo_saida_ir)
    log("\n" + "-" * 40 + "\n")

    # -----------------------------------
    # Execução (Máquina Virtual)
    if codigo_ir:
        vm = Interpretador(codigo_ir)
        vm.executar()
    else:
        log("  [VM] Execução ignorada (código IR vazio).")


if __name__ == "__main__":
    main()