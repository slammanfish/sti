#define STI_IMPL
#include "../sti.h"

int main() {
	string str = strnew("hello world");

	printf("%s, %d, %d\n", str, strlen(str), arrlen(str));

	str = strapp(str, '!');

	printf("%s, %d, %d\n", str, strlen(str), arrlen(str));


	return 0;
}
