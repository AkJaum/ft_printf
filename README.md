# ft_printf

Implementacao do projeto `ft_printf`: uma reimplementacao da funcao `printf` da libc com um subconjunto de conversores.
Para rodar ela rapidamente apenas use (make) e depois (make m) no terminal.

## Sobre o projeto

O objetivo deste projeto e recriar o comportamento basico do `printf`, usando `variadic arguments` (`stdarg.h`) e escrevendo na saida padrao com `write`.

A funcao principal exposta e:

```c
int ft_printf(const char *format, ...);
```

Assim como o `printf` original, ela retorna a quantidade de caracteres impressos.

## Conversores suportados

Esta implementacao suporta:

- `%c` -> caractere
- `%s` -> string
- `%p` -> ponteiro
- `%d` -> decimal (int)
- `%i` -> inteiro (int)
- `%u` -> unsigned decimal
- `%x` -> hexadecimal minusculo
- `%X` -> hexadecimal maiusculo
- `%%` -> imprime `%`

## Comportamentos implementados

- Strings nulas (`NULL`) em `%s` imprimem `(null)`.
- Ponteiro nulo (`NULL`) em `%p` imprime `(nil)`.
- `%p` para ponteiros validos imprime com prefixo `0x`.

## O que NAO esta implementado

Por escopo do projeto, esta versao nao implementa os recursos avancados do `printf`, como:

- Flags (`-`, `+`, `0`, `#`, espaco)
- Width (largura minima)
- Precision
- Length modifiers (`l`, `ll`, `h`, etc.)

## Estrutura do projeto

- `ft_printf.c` -> parser do format e despacho dos tipos
- `ft_printf.h` -> prototipos
- `ft_putchar.c` -> impressao de caractere
- `ft_putstr.c` -> impressao de string
- `ft_putnbr.c` -> impressao de inteiro com sinal
- `ft_putunsigned.c` -> impressao de unsigned int
- `ft_puthex.c` -> impressao hexadecimal (`x`/`X`)
- `ft_putpointer.c` -> impressao de ponteiros (`%p`)
- `Makefile` -> build da biblioteca

## Compilacao

Na raiz do projeto:

```bash
make
```

Isso gera a biblioteca estatica:

- `libftprintf.a`

Comandos disponiveis no Makefile:

```bash
make        # compila a lib
make clean  # remove .o
make fclean # remove .o e .a
make re     # rebuild completo
```

## Como usar

1. Inclua o header no seu codigo:

```c
#include "ft_printf.h"
```

2. Compile seu programa linkando com `libftprintf.a`:

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o app
```

### Exemplo simples

```c
#include "ft_printf.h"

int main(void)
{
    int n = 42;
    char *msg = "Hello";

    ft_printf("msg: %s\n", msg);
    ft_printf("n: %d\n", n);
    ft_printf("hex: %x\n", n);
    ft_printf("ptr: %p\n", &n);
    ft_printf("percent: %%\n");
    return (0);
}
```

## Retorno da funcao

`ft_printf` retorna o total de caracteres escritos na saida padrao.

Exemplo:

```c
int count;

count = ft_printf("Oi %s!\n", "42");
/* count recebe o numero de caracteres impressos */
```

## Observacao

Este README documenta o estado atual da implementacao presente neste repositorio.