#define STI_IMPL
#include "../sti.h"

int main() {
	string str = string("hello");

	printf("%s, %d, %d\n", str, strlen(str), arrlen(str));

	str = strjoin(str, " world");

	printf("%s, %d, %d\n", str, strlen(str), arrlen(str));

	str = strapp(str, '!');

	printf("%s, %d, %d\n", str, strlen(str), arrlen(str));

	return 0;
}
