#ifndef STI_H
#define STI_H

#include <stdio.h>
#include <stdlib.h>

//--------------
// array
//--------------
#define STI_ARRAY_INIT_CAP (2)
#define STI_ARRAY_GROW_MULTIPLIER (2)

typedef struct sti_array_header {
	size_t len;
	size_t cap;
} sti_array_header_t;

#define _sti_header(a) ((sti_array_header_t *) (a) - 1)

#define arrlen(a) \
		((a) ? _sti_header((a))->len : 0)
#define arrcap(a) \
		((a) ? _sti_header((a))->cap : 0)
#define arrput(a, v) \
		((arrlen((a)) == arrcap((a)) ? \
			(a) = _sti_grow((a), sizeof(*(a)), (a) ? \
			arrcap((a)) * STI_ARRAY_GROW_MULTIPLIER : STI_ARRAY_INIT_CAP) : 0), \
		(a)[_sti_header((a))->len++] = (v))
#define arrrem(a)
#define arrdel(a)
#define arrfree(a) \
		(free(a), (a) = NULL)
#define arrsetcap(a, v) \
		((a) = _sti_grow((a), sizeof(*(a)), v))
#define arrsetlen(a, v) \
		((a) = _sti_grow((a), sizeof(*(a)), v), _sti_header((a))->len = (v))

void *_sti_grow(void *arr, size_t size, size_t cap);

//--------------
// impl
//--------------
#ifdef STI_IMPL

void *_sti_grow(void *arr, size_t size, size_t cap) {
	if (cap == 0) {
		return arr;
	}

	sti_array_header_t *header = realloc(
			arr ? _sti_header(arr) : NULL,
			sizeof(sti_array_header_t) + cap * size);

	header->cap = cap;
	header->len = arr ? header->len : 0;

	return header + 1;
}

#endif

//--------------
// string
//--------------

#include <string.h>
#include <ctype.h>

//--------------
// impl
//--------------
#ifdef STI_IMPL



#endif

// typedef char *string;

// // gets the lowercase form of string.
// // allocates a char *
// char *strtolow(const char *str);
// // gets the uppercase form of string.
// // allocates a char *
// char *strtoup(const char *str);
// // compares two strings ignoring case
// // returns 0 when strings are equal
// int strcmpic(const char *a, const char *b);

// typedef FILE file_t;

// // checks if a file exists
// int fexists(const char *file);
// // gets the size of a file in bytes
// size_t fsize(file_t *file);
// // reads the contents of a file.
// // allocates a char *
// char *freadall(file_t *file);
// // gets the extension of a file.
// // allocates a char *
// char *fext(const char *file);
// // gets the relative path of a file.
// // allocates a char *
// char *frelpath(const char *file);
// // gets the name of a file.
// // allocates a char *
// char *fname(const char *file);

// // makes a directory
// void dmake(const char *dir);

#endif
