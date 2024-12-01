#include <stdio.h>
#include <stdlib.h>

/* Input is small just do n^2 */
int main(void) {
    FILE *fp = fopen("./input", "r");
    int lines = 0;
    while (!fscanf(fp, " %*[^\n]")) ++lines;
    rewind(fp);
    long *array1 = malloc(lines * sizeof(long));
    long *array2 = malloc(lines * sizeof(long));
    for (int i = 0 ; i < lines ; ++i)
        fscanf(fp, "%ld%ld", &array1[i], &array2[i]);
    long sim = 0;
    for (int i = 0 ; i < lines ; ++i) {
        long csim = 0;
        for (int j = 0 ; j < lines ; ++j)
            csim += array2[j] == array1[i];
        sim += array1[i] * csim;
    }
    printf("%ld\n", sim);
    free(array1);
    free(array2);
    fclose(fp);
    return 0;
}