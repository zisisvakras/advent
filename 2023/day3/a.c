#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Input is 140 chars per row
typedef unsigned long long bitmap_row[3];

#define set_one(bitmap, row, col) bitmap[row][col >> 6] |= 1ULL << (col & 0x3F);
#define is_one(bitmap, row, col) ((bitmap[row][col >> 6] >> (col & 0x3F)) & 1)

int issymbol(int ch) {
    if (ch <= '9' && ch >= '0') return 0;
    if (ch == '.') return 0;
    return 1;
}

int is_digit(int ch) {
    return ch <= '9' && ch >= '0';
}

int digits(int num) {
    int res = 1;
    while (num /= 10) ++res;
    return res;
}

int main(void) {
    char buffer[1024], **array = malloc(sizeof(char*));
    int rows = 0, row_size, sum = 0;
    while (scanf(" %1023[^\n]", buffer) == 1) {
        array = realloc(array, (rows + 1) * sizeof(char*));
        row_size = strlen(buffer);
        array[rows] = malloc((row_size + 1) * sizeof(char));
        memcpy(array[rows++], buffer, row_size + 1);
    }
    bitmap_row *bitmap = calloc(rows, sizeof(bitmap_row));
    for (int j = 0 ; j < rows ; ++j) {
        for (int k = 0 ; k < row_size ; ++k) {
            if (issymbol(array[j][k])) {
                #define xmacro(row) \
                if (k != 0)\
                    set_one(bitmap, row, k - 1);\
                if (k != row_size - 1)\
                    set_one(bitmap, row, k + 1);\
                set_one(bitmap, row, k);
                if (j != 0) xmacro(j - 1);
                if (j != rows - 1) xmacro(j + 1);
                xmacro(j);
                #undef xmacro
            }
        }
    }
    for (int j = 0 ; j < rows ; ++j) {
        for (int k = 0 ; k < row_size ; ++k) {
            if (is_digit(array[j][k])) {
                if (is_one(bitmap, j, k)) {
                    while (k != 0 && is_digit(array[j][k - 1])) --k;
                    int to_add = atoi(array[j] + k);
                    k += digits(to_add);
                    sum += to_add;
                }
            }
        }
    }
    printf("%d\n", sum);
    free(bitmap);
    for (int k = 0 ; k < row_size ; ++k) {
        free(array[k]);
    }
    free(array);
    return 0;
}