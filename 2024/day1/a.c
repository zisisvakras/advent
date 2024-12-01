#include <stdio.h>
#include <stdlib.h>

int longcmp(const void *a, const void *b) {
    return *(long*)a - *(long*)b;
}

int main(void) {
    FILE *fp = fopen("./input", "r");
    int lines = 0;
    while (!fscanf(fp, " %*[^\n]")) ++lines;
    rewind(fp);
    long *array1 = malloc(lines * sizeof(long));
    long *array2 = malloc(lines * sizeof(long));
    for (int i = 0 ; i < lines ; ++i)
        fscanf(fp, "%ld%ld", &array1[i], &array2[i]);
    qsort(array1, lines, sizeof(long), longcmp);
    qsort(array2, lines, sizeof(long), longcmp);
    long diff = 0;
    for (int i = 0 ; i < lines ; ++i)
        diff += labs(array1[i] - array2[i]);
    printf("%ld\n", diff);
    free(array1);
    free(array2);
    fclose(fp);
    return 0;
}