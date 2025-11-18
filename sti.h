#ifndef STI_H
#define STI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct str {
	char *data;
	size_t len;
} str;

#define str(s) (str) { .data = s, .len = strlen(s) }

str strapp(str a, str b);

// gets the lowercase form of string.
// allocates a char *
char *strtolow(const char *str);
// gets the uppercase form of string.
// allocates a char *
char *strtoup(const char *str);
// compares two strings ignoring case
// returns 0 when strings are equal
int strcmpic(const char *a, const char *b);

typedef FILE file_t;

// checks if a file exists
int fexists(const char *file);
// gets the size of a file in bytes
size_t fsize(file_t *file);
// reads the contents of a file.
// allocates a char *
char *freadall(file_t *file);
// gets the extension of a file.
// allocates a char *
char *fext(const char *file);
// gets the relative path of a file.
// allocates a char *
char *frelpath(const char *file);
// gets the name of a file.
// allocates a char *
char *fname(const char *file);

// makes a directory
void dmake(const char *dir);

#endif
