#include <stdio.h>
#include <stdlib.h>

int digits(long num) {
    int res = 1;
    while (num /= 10) ++res;
    return res;
}

int check(long *l, long size, long res) {
    for (long i = 0 ; i < (1 << (size * 2)) ; ++i) {
        long temp = l[0];
        for (long j = 0 ; j < size - 1 ; ++j) {
            char op = (i >> (j * 2)) & 3;
            if (op == 0) temp *= l[j + 1];
            else if (op == 1) temp += l[j + 1];
            else if (op == 2) {
                int dig = digits(l[j + 1]);
                for (int k = 0 ; k < dig ; ++k)
                    temp *= 10;
                temp += l[j + 1];
            }
            else goto next; /* Bad operator */
        }
        if (temp == res) return 1;
        next:;
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