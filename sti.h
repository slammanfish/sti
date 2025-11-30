#ifndef STI_H
#define STI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//--------------
// array
//--------------

#define STI_ARRAY_INIT_CAP (2)
#define STI_ARRAY_GROW_MULTIPLIER (2)

#define array(T) T *

typedef struct sti_array_header {
	size_t len;
	size_t cap;
} sti_array_header_t;

#define _sti_arr_header(a) ((sti_array_header_t *) (a) - 1)

// gets the length of the array.
#define arrlen(a) \
		((a) ? _sti_arr_header((a))->len : 0)
// gets the capacity of the array.
#define arrcap(a) \
		((a) ? _sti_arr_header((a))->cap : 0)
// puts a value on the end of the array.
// resizes if necessary.
#define arrput(a, v) \
		((arrlen((a)) == arrcap((a)) ? \
			(a) = _sti_arr_grow((a), sizeof(*(a)), (a) ? \
			arrcap((a)) * STI_ARRAY_GROW_MULTIPLIER : STI_ARRAY_INIT_CAP) : 0), \
		(a)[_sti_arr_header((a))->len++] = (v))
// removes the value at index i.
// swaps a[i] with a[len - 1].
// use this if the order of the array is irrelevent,
// otherwise prefer arrdel
// O(1).
#define arrrem(a, i) \
		((a)[i] = (a)[--_sti_arr_header((a))->len])
// deletes the value at index i.
// shifts the rest of the array over.
// use this if the order of the array is important,
// otherwise prefer arrrem
// O(n^2).
#define arrdel(a, i) \
		
// frees the array.
#define arrfree(a) \
		(_sti_arr_free((a)))
// sets the capacity of the array.
#define arrsetcap(a, v) \
		((a) = _sti_arr_grow((a), sizeof(*(a)), v))
// sets the length of the array.
#define arrsetlen(a, v) \
		((a) = _sti_arr_grow((a), sizeof(*(a)), v), _sti_arr_header((a))->len = (v))

void *_sti_arr_grow(void *arr, size_t size, size_t cap);
void _sti_arr_free(void *arr);

//--------------
// impl
//--------------

#ifdef STI_IMPL

void *_sti_arr_grow(void *arr, size_t size, size_t cap) {
	if (cap == 0) {
		return arr;
	}

	sti_array_header_t *header = realloc(
			arr ? _sti_arr_header(arr) : NULL,
			sizeof(sti_array_header_t) + cap * size);

	header->cap = cap;
	header->len = arr ? header->len : 0;

	return header + 1;
}

void _sti_arr_free(void *arr) {
	if (!arr) {
		return;
	}

	free((sti_array_header_t *) (arr) - 1);
}

#endif

//--------------
// hashmap
//--------------

#define hashmap(K, V) struct { K key; V value; } *

//--------------
// impl
//--------------

#ifdef STI_IMPL



#endif

//--------------
// string
//--------------

#include <string.h>
#include <ctype.h>

// strings need to be freed.
typedef char *string;

// creates a string.
#define string(str) (_sti_string_new((str)))
// gets the length of a string.
// faster than strlen.
// O(1).
#define strlenq(str) (arrlen((str)) - 2)

// frees a string.
void strfree(string str);
// appends a character to the end of a string.
// frees str.
string strapp(string str, char c);
// joins two strings together.
// frees a and b
string strjoin(string a, string b);
// compares two strings, ignoring case.
bool strcmpic(string a, string b);

string _sti_string_new(const char *str);
bool _sti_string_valid(string str);

//--------------
// impl
//--------------

#ifdef STI_IMPL

string _sti_string_new(const char *str) {
	string out = NULL;
	size_t len = strlen(str);
	arrsetlen(out, len + 2);
	for (int i = 0; i < len; i++) {
		out[i] = str[i];
	}
	out[len] = '\0';
	out[len + 1] = '\s';
	return out;
}

bool _sti_string_valid(string str) {
	size_t len = strlen(str);
	return str + len + 1 != NULL && str[len + 1] == '\s';
}

void strfree(string str) {
	// this is really hacky and might be error prone
	if (_sti_string_valid(str)) {
		arrfree(str);
	}
}

string strapp(string str, char c) {
	string out = NULL;
	size_t len = strlen(str);
	arrsetlen(out, len + 2);
	for (int i = 0; i < len; i++) {
		out[i] = str[i];
	}
	out[len] = c;
	out[len + 1] = '\0';
	strfree(str);
	return out;
}

string strjoin(string a, string b) {
	string out = NULL;
	size_t alen = strlen(a);
	size_t blen = strlen(b);
	size_t len = alen + blen;
	arrsetlen(out, len + 1);
	for (int i = 0; i < alen; i++) {
		out[i] = a[i];
	}
	for (int i = 0; i < blen; i++) {
		out[alen + i] = b[i];
	}
	out[len] = '\0';
	strfree(a);
	strfree(b);
	return out;
}

bool strcmpic(string a, string b) {
	if (arrlen(a) != arrlen(b)) {
		return false;
	}
	for (int i = 0; i < arrlen(a) - 1; i++) {
		if (tolower(a[i]) != tolower(b[i])) {
			return false;
		}
	}
	return true;
}

#endif

//--------------
// file
//--------------

typedef FILE file_t;

// checks if a file exists
bool fexists(const char *file);
// gets a files size
size_t fsize(file_t *file);
// reads a files contents
string freadall(file_t *file);
string fext(const char *file);
// gets the relative path of a file
string frelpath(const char *file);
// gets the name of a file
string fname(const char *file);

//--------------
// impl
//--------------

#ifdef STI_IMPL

bool fexists(const char *file) {
	file_t *fp = fopen(file, "r");
	bool out = fp != NULL;
	fclose(fp);
	return out;
}

size_t fsize(file_t *file) {
	size_t pos = ftell(file);
	rewind(file);
	fseek(file, 0, SEEK_END);
	size_t size = ftell(file);
	fseek(file, pos, SEEK_SET);
	return size;
}

string freadall(file_t *file) {
	size_t len = fsize(file);
	char *buf = malloc(sizeof(char) * (len + 1));
	size_t n = fread(buf, sizeof(char), len, file);
	buf[n] = '\0';
	string out = string(buf);
	free(buf);
	return out;
}

string frelpath(const char *file) {

}

string fname(const char *file) {

}

#endif

//--------------
// directory
//--------------

//--------------
// impl
//--------------

#ifdef STI_IMPL

#endif

#endif
