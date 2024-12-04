#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* Get input array*/
    FILE *fp = fopen("./input", "r");
    int lines = 1;
    fscanf(fp, " %*[^\n]");
    int perline = ftell(fp); /* So exploitable :D */
    while (!fscanf(fp, " %*[^\n]")) ++lines;
    rewind(fp);
    char **array = malloc(sizeof(char *) * lines);
    for (int i = 0 ; i < lines ; ++i)
        array[i] = malloc(sizeof(char) * perline);
    for (int i = 0 ; i < lines ; ++i)
        fscanf(fp, " %[^\n]", array[i]);
    fclose(fp);
    /* FIND ALL */
    int xmas_c = 0;
    for (int i = 0 ; i < lines ; ++i)
        for (int j = 0 ; j < perline ; ++j)
            if (array[i][j] == 'A') {
                /* Check for out of bounds */
                if (i == 0 || i == lines - 1) continue;
                if (j == 0 || j == perline - 1) continue;
                xmas_c += ((array[i-1][j-1] == 'M'
                        &&  array[i+1][j+1] == 'S')
                        || (array[i-1][j-1] == 'S'
                        &&  array[i+1][j+1] == 'M'))

                        && ((array[i+1][j-1] == 'M'
                        &&  array[i-1][j+1] == 'S')
                        || (array[i+1][j-1] == 'S'
                        &&  array[i-1][j+1] == 'M'));
            }
    printf("%d\n", xmas_c);
    /* Too bored to free */
    return 0;
}