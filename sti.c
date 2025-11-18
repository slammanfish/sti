#include "sti.h"

// char *strtolow(const char *str) {
// 	size_t len = strlen(str);
// 	char *low = malloc(len + 1);
// 	for (int i = 0; i < strlen(str); i++) {
// 		low[i] = toupper(str[i]);
// 	}
// 	low[len] = '\0';
// 	return low;
// }

// char *strtoup(const char *str) {
// 	size_t len = strlen(str);
// 	char *up = malloc(len + 1);
// 	for (int i = 0; i < strlen(str); i++) {
// 		up[i] = toupper(str[i]);
// 	}
// 	up[len] = '\0';
// 	return up;
// }

// int strcmpic(const char *a, const char *b) {
// 	size_t lena = strlen(a);
// 	size_t lenb = strlen(b);
// 	if (lena == lenb) {
// 		for (int i = 0; i < lena; i++) {
// 			if (tolower(a[i]) != tolower(b[i])) {
// 				return 1;
// 			}
// 		}
// 	} else {
// 		return 1;
// 	}
// 	return 0;
// }

// int fexists(const char *file) {
// 	file_t *fp = fopen(file, "r");
// 	int res = fp != NULL;
// 	fclose(fp);
// 	return res;
// }

// size_t fsize(file_t *file) {
// 	size_t pos = ftell(file);
// 	rewind(file);
// 	fseek(file, 0, SEEK_END);
// 	size_t size = ftell(file);
// 	fseek(file, pos, SEEK_SET);
// 	return size;
// }

// char *freadall(file_t *file) {
// 	size_t len = fsize(file);
// 	char *buf = malloc(sizeof(char) * (len + 1));
// 	size_t n = fread(buf, sizeof(char), len, file);
// 	buf[n] = '\0';
// 	return buf;
// }

// char *fext(const char *file) {

// }

// char *frelpath(const char *file) {

// }

// char *fname(const char *file) {

// }

// void dmake(const char *dir) {

// }
