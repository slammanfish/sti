#define STI_IMPL
#define STI_ARRAY
#include "../sti.h"

int main() {
	int *arr = NULL;

	arrput(arr, 10);
	arrput(arr, 0);
	arrput(arr, 230);
	arrput(arr, -45);
	arrput(arr, 1);
	arrput(arr, 468);
	arrput(arr, -765);
	arrput(arr, 2);
	arrput(arr, 28);

	for (int i = 0; i < arrlen(arr); i++) {
		printf("%d\n", arr[i]);
	}

	arrfree(arr);

	return 0;
}
