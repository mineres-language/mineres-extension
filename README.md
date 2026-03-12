# 🧀 Minerês para VS Code

O **Minerês** é uma extensão que traz o suporte oficial para a linguagem de programação que une a lógica computacional ao carisma do dialeto mineiro. Desenvolvida para fins acadêmicos, ela transforma o código em um verdadeiro "causo".

---

## 📖 Elementos da Linguagem (Dicionário Oficial)

Abaixo, a especificação completa da sintaxe Minerês:

### 🔹 Estruturas e Fluxo
| Categoria | Elemento (C/Python) | Escolha Minerês |
| :--- | :--- | :--- |
| **Controle** | `if / else` | `uai_se / uai_senão` |
| | `for` | `roda_esse_trem` |
| | `while` | `enquanto_tiver_trem` |
| | `switch case` | `dependenu / du_casu` |
| **Fluxo** | `return` | `ta bao` |
| | `break` | `para_o_trem` |
| | `continue` | `toca_o_trem` |
| | `Função` | `bora cumpade ( )` |

### 🔹 Variáveis e Dados
| Tipo | Equivalente | Escolha Minerês |
| :--- | :--- | :--- |
| `int` | Inteiro | `trem_di_numeru` |
| `float` | Real | `trem_cum_virgula` |
| `string` | Texto | `trem_discrita` |
| `boolean` | Lógico | `trem_discolhe` |
| `char` | Caractere | `trosso` |

### 🔹 Operadores e Sintaxe
| Categoria | Símbolo Original | Escolha Minerês |
| :--- | :--- | :--- |
| **Atribuição** | `=` | `fica_assim_entao` |
| **Comparação** | `==` / `!=` | `mema_coisa / neh_nada` |
| **Lógicos** | `or / not / and` | `quarque_um / vam_marca / tamem` |
| | `xor` | `um_o_oto` |
| **Aritméticos** | `* / /` | `veiz / sob` |
| **E/S** | `scan / print` | `xove / oia_proce_ve` |
| **Escopo** | `{ } / ;` | `simbora / cabô / uai` |
| **Comentário**| `/* ... */` | `causo ... fim do causo` |

---

## 🚀 Exemplo de Código

```
// ---------------------------------------------------
// TESTE GERAL DA LINGUAGEM MINERÊS
// ---------------------------------------------------

causo
  Este é um comentário de múltiplas linhas.
  Aqui a gente testa se o bloco fica verdinho
  do jeito que tem que ser!
fim do causo

bora_cumpade testando_tudo()
simbora
    
    // --- VARIÁVEIS, DADOS E BASES NUMÉRICAS ---
    trem_di_numeru inteiro fica_assim_entao 10 uai
    trem_di_numeru octal fica_assim_entao 017 uai
    trem_di_numeru hexa fica_assim_entao 0x10F uai
    trem_cum_virgula real fica_assim_entao 3.14 uai
    trem_discrita texto fica_assim_entao "Olá, mundo!" uai
    trem_discolhe booleano fica_assim_entao 1 uai
    trosso letrinha fica_assim_entao 'A' uai

    // --- ENTRADA E SAÍDA ---
    oia_proce_ve "Digite um numero: " uai
    xove inteiro uai

    // --- OPERADORES ARITMÉTICOS ---
    inteiro fica_assim_entao inteiro + 5 - 2 veiz 3 sob 2 uai
    inteiro fica_assim_entao inteiro % 2 / 1 uai
    
    // --- ESTRUTURAS DE CONTROLE (if/else) E OPERADORES LÓGICOS/RELACIONAIS ---
    uai_se ( inteiro mema_coisa 10 tamem booleano neh_nada 0 )
    simbora
        oia_proce_ve "Deu certim!" uai
    cabô
    uai_senão
    simbora
        uai_se ( inteiro < 5 quarque_um inteiro > 20 )
        simbora
            oia_proce_ve "Tá fora do prumo!" uai
        cabo
    cabo

    // Testando operadores lógicos diferentões
    trem_discolhe teste_louco fica_assim_entao (10 <= 20) um_o_oto vam_marca (5 >= 3) uai

    // --- LAÇO WHILE (enquanto_tiver_trem) ---
    enquanto_tiver_trem ( inteiro <> 0 )
    simbora
        inteiro fica_assim_entao inteiro - 1 uai
        uai_se ( inteiro mema_coisa 5 )
        simbora
            toca_o_trem uai 
        cabo
    cabo

    // --- LAÇO FOR (roda_esse_trem) ---
    roda_esse_trem ( trem_di_numeru i fica_assim_entao 0 uai i < 5 uai i fica_assim_entao i + 1 )
    simbora
        uai_se ( i mema_coisa 3 )
        simbora
            para_o_trem uai 
        cabo
    cabo

    // --- SWITCH CASE (dependenu / du_casu) ---
    dependenu ( inteiro )
    simbora
        du_casu 1:
            oia_proce_ve "Deu um" uai
            para_o_trem uai
        du_casu 2:
            oia_proce_ve "Deu dois" uai
            para_o_trem uai
    cabo

    // --- RETORNO DE FUNÇÃO ---
    ta_bao 0 uai
cabo
```

## 👥 Equipe de Desenvolvimento

[Celso Vinícius Sudário Fernandes](https://github.com/celzin)

[Maria Eduarda Teixeira Souza](https://github.com/dudatsouza)

[Pedro Henrique Pires Dias](https://github.com/peudias)