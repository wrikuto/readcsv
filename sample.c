#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
bool is_integer(const char *str) 
{
    char *end;
    errno = 0;
    long int val;

	val = strtol(str, &end, 10);
    if (end == str || *end != '\0' || errno == ERANGE) {
        // 変換できなかった、または文字列の途中で変換が停止した
        return (0); // これは整数ではない
    }
    return (1); // 整数である
}

bool	is_float(const char *str)
{
    char *end;
    errno = 0; // エラー値をリセット
    double val = strtod(str, &end);

    if (end == str || *end != '\0' || errno == ERANGE) {
        // 変換できなかった、または文字列の途中で変換が停止した
        return 0; // これは浮動小数点数ではない
    }
    return 1; // 浮動小数点数である
}
int main()
{

	is_float("123");
	// set_char(&line);
	return (0);
}