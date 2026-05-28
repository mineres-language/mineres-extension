import os
import sys

VERBOSE = "--verbose" in sys.argv

from mylexer.lexer import Lexer, formata_tokens
from myparser.parser import Parser
from ir import formata_codigo
from myinterpreter.interpreter import Interpretador


def log(msg: str):
    if VERBOSE:
        print(msg)


def read_file(arquivo_entrada: str) -> str:
    try:
        with open(arquivo_entrada, "r", encoding="utf-8") as f:
            return f.read()
    except FileNotFoundError:
        print(f"Erro: O arquivo '{arquivo_entrada}' não foi encontrado, uai!")
        sys.exit(1)


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]

    if not args:
        print("Uso: python main.py <arquivo.uai> [--verbose]")
        sys.exit(1)

    arquivo_entrada = args[0]
    fonte = read_file(arquivo_entrada)

    log("-" * 40)
    log("ANÁLISE LÉXICA")
    log("-" * 40)
    lexer = Lexer(fonte)
    if not lexer.tokenizar():
        print("Falha na análise léxica.")
        sys.exit(1)
    log(f"[LEXER] {len(lexer.tokens)} tokens gerados.")

    log("-" * 40)
    log("ANÁLISE SINTÁTICA")
    log("-" * 40)
    parser = Parser(lexer.tokens)
    codigo_ir = parser.iniciar()
    log("[PARSER] Concluído.")

    log("-" * 40)
    log("GERAÇÃO IR")
    log("-" * 40)
    log(f"[IR] {len(codigo_ir)} tuplas geradas.")

    if codigo_ir:
        vm = Interpretador(codigo_ir)
        vm.executar()
    else:
        log("[VM] Código IR vazio, nada a executar.")


if __name__ == "__main__":
    main()