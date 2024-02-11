#include "../../inc/readcsv.h"

bool is_integer(const char *str) 
{
    char *end;
    errno = 0;
    long int val;

    // 文字列が空、または符号のみの場合は早期リターン
    if (*str == '\0' || (str[0] == '+' || str[0] == '-') && !isdigit(str[1]))
        return false;
	val = strtol(str, &end, 10);
    if (end == str || *end != '\0' || errno == ERANGE) {
        // 変換できなかった、または文字列の途中で変換が停止した
        return (false); // これは整数ではない
    }
    return (true); // 整数である
}

bool	is_float(const char *str)
{
    char *end;
    errno = 0; // エラー値をリセット
    double val;

    if (*str == '\0' || (str[0] == '+' || str[0] == '-') && !isdigit(str[1]))
        return false;
    val = strtod(str, &end);

    if (end == str || *end != '\0' || errno == ERANGE) {
        // 変換できなかった、または文字列の途中で変換が停止した
        return (false); // これは浮動小数点数ではない
    }
    return (true); // 浮動小数点数である
}

bool	is_char(const char *str)
{
	size_t	i = 0;

	while (str[i] != '\0')
	{
		if (isdigit(str[i]) == 0 && str[i] != '.')
			return (true);
        i++;
	}
	return (false);
}
