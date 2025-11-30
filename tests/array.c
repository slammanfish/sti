#define STI_IMPL
#include "../sti.h"

int main() {
	array(int) arr = NULL;

	arrsetcap(arr, 9);

	arrput(arr, 10);
	arrput(arr, 0);
	arrput(arr, 230);
	arrput(arr, -45);
	arrput(arr, 1);
	arrput(arr, 468);
	arrput(arr, -765);
	arrput(arr, 2);
	arrput(arr, 28);

	printf("---------\n");
	printf("len: %d, cap: %d\n", arrlen(arr), arrcap(arr));

	for (int i = 0; i < arrlen(arr); i++) {
		printf("- %d\n", arr[i]);
	}

	arrrem(arr, 8);
	arrrem(arr, 7);
	arrrem(arr, 6);
	arrrem(arr, 5);

	printf("---------\n");
	printf("len: %d, cap: %d\n", arrlen(arr), arrcap(arr));

	for (int i = 0; i < arrlen(arr); i++) {
		printf("- %d\n", arr[i]);
	}

	arrsetlen(arr, 0);

	printf("---------\n");
	printf("len: %d, cap: %d\n", arrlen(arr), arrcap(arr));

	for (int i = 0; i < arrlen(arr); i++) {
		printf("- %d\n", arr[i]);
	}

	printf("---------\n");

	arrfree(arr);

	return 0;
}
