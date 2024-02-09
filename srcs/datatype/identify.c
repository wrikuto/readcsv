#include "../../inc/readcsv.h"

bool is_integer(const char str[RD_SIZE]) 
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

bool	is_char(const char str[RD_SIZE])
{
	size_t	i = 0;

	while (str[i] != '\0')
	{
		if (isalpha(str[i]) || (33 <= str[i] && str[i] <= 47) || \
		(91 <= str[i] && str[i] <= 96) || (123 <= str[i] && str[i] <= 126))
			return (1);
	}
	return (0);
}

bool	is_float(const char str[RD_SIZE])
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