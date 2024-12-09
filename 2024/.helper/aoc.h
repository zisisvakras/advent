#ifndef AOC_H_
#define AOC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define inbounds(lines, cols, i, j) \
((i) >= 0 && (i) < (lines) && (j) >= 0 && (j) < (cols))

void get_input(char *filename, char ***array_r, int *lines_r, int *columns_r);
void print_array(char **a, int lines, int cols);
int digits(intmax_t num);

#endif /* AOC_H_ */