#include <stdio.h>
#include <stdlib.h>

int check(long *l, long size, long res) {
    for (long i = 0 ; i < (1 << size) ; ++i) {
        long temp = l[0];
        for (long j = 0 ; j < size - 1 ; ++j) {
            char op = (i >> j) & 1;
            if (op) temp *= l[j + 1];
            else temp += l[j + 1];
        }
        if (temp == res) return 1;
    }
    return 0;
}

int main(void) {
    /* So bored */
    FILE *fp = fopen("./input", "r");
    int *sizes = calloc(850, sizeof(int));
    long *res = malloc(850 * sizeof(long));
    long **array = malloc(850 * sizeof(long*));
    for (int i = 0 ; i < 850 ; ++i)
        array[i] = malloc(20 * sizeof(long));
    long num1, num2, r, row = -1;
    while ((r = fscanf(fp, "%ld:%ld", &num1, &num2)) > 0) {
        if (r == 2) {
            ++row;
            res[row] = num1;
            array[row][sizes[row]++] = num2;
        }
        else array[row][sizes[row]++] = num1;
    }
    long total = 0;
    for (int i = 0 ; i < 850 ; ++i)
        if (check(array[i], sizes[i], res[i]))
            total += res[i];
    printf("%ld\n", total);
}