#include "aoc.h"

int main(void) {
    char **a;
    int lines, cols;
    get_input("./input", &a, &lines, &cols);
    char **nodes = malloc(sizeof(char *) * lines);
    for (int i = 0 ; i < lines ; ++i)
        nodes[i] = calloc(sizeof(char), cols);
    for (int i = 0 ; i < lines ; ++i) {
        for (int j = 0 ; j < cols ; ++j) {
            if (isalnum(a[i][j])) {
                for (int k = 0 ; k < lines ;  ++k) {
                    for (int m = 0 ; m < cols ; ++m) {
                        if (a[i][j] == a[k][m]) {
                            /* manhattan */
                            int di = i - k, dj = j - m;
                            /* After new guy */
                            int ni = k - di, nj = m - dj;
                            if (inbounds(lines, cols, ni, nj)
                                && a[ni][nj] != a[i][j]
                                && !nodes[ni][nj]) {
                                nodes[ni][nj] = 1;
                            }
                            /* After old guy */
                            ni = i + di, nj = j + dj;
                            if (inbounds(lines, cols, ni, nj)
                                && a[ni][nj] != a[i][j]
                                && !nodes[ni][nj]) {
                                nodes[ni][nj] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    int count = 0;
    for (int i = 0 ; i < lines ;  ++i)
        for (int j = 0 ; j < cols ; ++j)
            count += nodes[i][j];
    printf("%d\n", count);
}