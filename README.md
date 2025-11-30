<b><h3 align="center">WARNING</h3>
<p align="center">this is a work in progress and is not ready for use</p>

<p align="center">
    <img src="assets/logo_large.png" style="width: 20%" /><br><br>
    a simple, single header extension of the C standard library<br>
</p>

## what is sti?

standard libraries are usually referred to with the abbreviation ***std***... which just so happens to have second meaning that is synonymous with ***sti***.<br>
if you want to keep it PG, you can refer to this library as the ***standard tools implementation*** or something idk, be creative!

***sti*** attempts to add everything that is missing from the C standard library such as dynamic arrays, hashmaps, string manipulation and file / directory management.

***sti*** is single header, cross platform and built with c99, so you shouldn't have any troubles including in your project.

## including in your project

in one .c file, add the following line above the *#include*
```c
#define STI_IMPL
#include <sti.h>
```

## components

### [array](tests/array.c)
sti implements an [stb-like](https://github.com/nothings/stb) array.

```c
// works with any pointer. MUST be initialised to NULL
array(int) array = NULL;

// values can be gotten just like any other array
int value = array[2];
// appends a value to the array
arrput(array, 3);
// removes the value at index i by swapping it with the last value
arrrem(array, 0);
// deletes the value at index i and shifts the array over
arrdel(array, 0);
// sets the capacity of the array
arrsetcap(array, 10);
// sets the length of the array, resizes if necessary
arrsetlen(array, 10);
// frees the array
arrfree(array);
```

### string
string builds off of the array component to create flexible string types similar to something you would find in java.<br>
strings are just char * internally, so you can use them with the standard C string functions.

```c
string str = string("hello");

// get length using standard C strlen
int length = strlen(str);
// get length using strlenq
// more efficient than strlen O(1)
int length = strlenq(str);

// characters can be gotten just like any other array
char character = str[2];
// join two strings together
str = strjoin(str, string(" world"));
// even works with standard c strings
str = strjoin(str, " world");
// appends a character to the array
str = strapp(str, '!');
// checks if two strings are equal, ignoring case
bool equal = strcmpic(str, "");
```

### file

## roadmap

- [ ] arrays
- [ ] strings
- [ ] file utilities
- [ ] directory utilities
- [ ] hashmaps
