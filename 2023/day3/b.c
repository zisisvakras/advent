#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int issymbol(int ch) {
    return ch == '*';
}

int is_digit(int ch) {
    return ch <= '9' && ch >= '0';
}

int get_num(char **array, int row, int col) {
    while (col != 0 && is_digit(array[row][col - 1])) --col;
    return atoi(array[row] + col);
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
    for (int j = 0 ; j < rows ; ++j) {
        for (int k = 0 ; k < row_size ; ++k) {
            if (issymbol(array[j][k])) {
                int count = 0, temp = 0, to_add = 1;
                #define xmacro(row) \
                if (k != 0)\
                    if (is_digit(array[row][k - 1])) {\
                        int smth = get_num(array, row, k - 1);\
                        if (smth != temp) {\
                            temp = smth;\
                            to_add *= smth;\
                            ++count;\
                        }\
                    }\
                if (k != row_size - 1) {\
                    if (is_digit(array[row][k + 1])) {\
                        int smth = get_num(array, row, k + 1);\
                        if (smth != temp) {\
                            temp = smth;\
                            to_add *= smth;\
                            ++count;\
                        }\
                    }\
                }\
                if (is_digit(array[row][k])) {\
                    int smth = get_num(array, row, k + 1);\
                    if (smth != temp) {\
                        temp = smth;\
                        to_add *= smth;\
                        ++count;\
                    }\
                }

                if (j != 0) xmacro(j - 1);
                if (j != rows - 1) xmacro(j + 1);
                xmacro(j);
                #undef xmacro
                if (count == 2) {
                    sum += to_add;
                }
            }
        }
    }
    printf("%d\n", sum);
    for (int k = 0 ; k < row_size ; ++k) {
        free(array[k]);
    }
    free(array);
    return 0;
}