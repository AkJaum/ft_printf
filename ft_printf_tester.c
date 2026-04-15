#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

enum e_test_id
{
	T_CHAR = 1,
	T_STR,
	T_PTR,
	T_DEC,
	T_INT,
	T_UNSIGNED,
	T_HEX_LOWER,
	T_HEX_UPPER,
	T_PERCENT
};

static int	run_real_call(int test_id)
{
	int			anchor;
	const char	*label;

	anchor = 42;
	label = "joao";
	if (test_id == T_CHAR)
		return (printf("%c", 'A'));
	if (test_id == T_STR)
		return (printf("%s", label));
	if (test_id == T_PTR)
		return (printf("%p", (void *)&anchor));
	if (test_id == T_DEC)
		return (printf("%d", -42));
	if (test_id == T_INT)
		return (printf("%i", 1234));
	if (test_id == T_UNSIGNED)
		return (printf("%u", 4294967295u));
	if (test_id == T_HEX_LOWER)
		return (printf("%x", 48879));
	if (test_id == T_HEX_UPPER)
		return (printf("%X", 48879));
	if (test_id == T_PERCENT)
		return (printf("%%"));
	return (0);
}

static int	run_ft_call(int test_id)
{
	int			anchor;
	const char	*label;

	anchor = 42;
	label = "joao";
	if (test_id == T_CHAR)
		return (ft_printf("%c", 'A'));
	if (test_id == T_STR)
		return (ft_printf("%s", (char *)label));
	if (test_id == T_PTR)
		return (ft_printf("%p", (unsigned long long)&anchor));
	if (test_id == T_DEC)
		return (ft_printf("%d", -42));
	if (test_id == T_INT)
		return (ft_printf("%i", 1234));
	if (test_id == T_UNSIGNED)
		return (ft_printf("%u", 4294967295u));
	if (test_id == T_HEX_LOWER)
		return (ft_printf("%x", 48879));
	if (test_id == T_HEX_UPPER)
		return (ft_printf("%X", 48879));
	if (test_id == T_PERCENT)
		return (ft_printf("%%"));
	return (0);
}

static int	capture_output(int use_ft, int test_id, char *out, size_t out_size)
{
	int		pipefd[2];
	int		saved_stdout;
	int		ret;
	ssize_t	read_bytes;

	ret = 0;
	if (pipe(pipefd) == -1)
		return (-1);
	saved_stdout = dup(STDOUT_FILENO);
	if (saved_stdout == -1)
		return (close(pipefd[0]), close(pipefd[1]), -1);
	fflush(stdout);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return (close(pipefd[0]), close(pipefd[1]), close(saved_stdout), -1);
	close(pipefd[1]);
	if (use_ft)
		ret = run_ft_call(test_id);
	else
		ret = run_real_call(test_id);
	fflush(stdout);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
	read_bytes = read(pipefd[0], out, out_size - 1);
	if (read_bytes < 0)
		read_bytes = 0;
	out[read_bytes] = '\0';
	close(pipefd[0]);
	return (ret);
}

static int	run_one_test(int test_id, const char *title, const char *input, const char *expected_literal)
{
	char	out_printf[256];
	char	out_ft[256];
	char	expected[256];
	int	ret_printf;
	int	ret_ft;
	int	ok;

	ret_printf = capture_output(0, test_id, out_printf, sizeof(out_printf));
	ret_ft = capture_output(1, test_id, out_ft, sizeof(out_ft));
	if (expected_literal)
		snprintf(expected, sizeof(expected), "%s", expected_literal);
	else
		snprintf(expected, sizeof(expected), "%s", out_printf);
	ok = (ret_printf >= 0 && ret_ft >= 0 && strcmp(out_printf, expected) == 0
			&& strcmp(out_ft, expected) == 0 && ret_printf == ret_ft);
	printf("\n=== %s ===\n", title);
	printf("Entrada: %s\n", input);
	printf("Output esperado: %s\n", expected);
	printf("Output da funcao original: %s\n", out_printf);
	printf("Output da ft_printf: %s\n", out_ft);
	if (ok)
		printf("OK\n");
	else
		printf("FALHOU\n");
	return (ok);
}

int	main(void)
{
	int	total;
	int	passed;

	printf("Esse projeto foi feito como parte do curriculo academico de Joao Gabriel\n");
	printf("Reimplementacao da funcao printf: reproduz a impressao formatada com variadic arguments, retornando a quantidade de caracteres impressos.\n");
	total = 9;
	passed = 0;
	passed += run_one_test(T_CHAR, "Teste %c", "ft_printf(\"%c\", 'A')", "A");
	passed += run_one_test(T_STR, "Teste %s", "ft_printf(\"%s\", \"joao\")", "joao");
	passed += run_one_test(T_PTR, "Teste %p", "ft_printf(\"%p\", &valor)", NULL);
	passed += run_one_test(T_DEC, "Teste %d", "ft_printf(\"%d\", -42)", "-42");
	passed += run_one_test(T_INT, "Teste %i", "ft_printf(\"%i\", 1234)", "1234");
	passed += run_one_test(T_UNSIGNED, "Teste %u", "ft_printf(\"%u\", 4294967295u)", "4294967295");
	passed += run_one_test(T_HEX_LOWER, "Teste %x", "ft_printf(\"%x\", 48879)", "beef");
	passed += run_one_test(T_HEX_UPPER, "Teste %X", "ft_printf(\"%X\", 48879)", "BEEF");
	passed += run_one_test(T_PERCENT, "Teste %%", "ft_printf(\"%%\")", "%");
	printf("\n===== SUMARIO =====\n");
	printf("Total de testes: %d\n", total);
	printf("Testes que passaram: %d\n", passed);
	printf("Testes que falharam: %d\n", total - passed);
	if (passed == total)
		return (0);
	return (1);
}