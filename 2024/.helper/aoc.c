#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void get_input(char *filename, char ***array_r, int *lines_r, int *cols_r) {
    /* Get input array */
    FILE *fp = fopen(filename, "r");
    int lines = 1;
    fscanf(fp, " %*[^\n]");
    int perline = ftell(fp);
    while (!fscanf(fp, " %*[^\n]")) ++lines;
    rewind(fp);
    char **array = malloc(sizeof(char *) * lines);
    for (int i = 0 ; i < lines ; ++i)
        array[i] = malloc(sizeof(char) * perline);
    for (int i = 0 ; i < lines ; ++i) {
        char buf[4096] = {0};
        fscanf(fp, " %4095[^\n]", buf);
        memcpy(array[i], buf, perline);
    }
    fclose(fp);
    *array_r = array;
    *lines_r = lines;
    *cols_r = perline;
}

void print_array(char **a, int lines, int cols) {
    for (int i = 0 ; i < lines ; ++i) {
        for (int j = 0 ; j < cols ; ++j)
           putchar(a[i][j]);
        putchar('\n');
    }
}

int digits(intmax_t num) {
    int res = 1;
    while (num /= 10) ++res;
    return res;
}