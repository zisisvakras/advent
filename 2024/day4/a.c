#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UL,
    UR,
    DL,
    DR
} Direction;

int lines = 1, perline;

int find_xmas(char **a, int i, int j, char f, Direction d) {
    if (i < 0 || i >= lines
     || j < 0 || j >= perline
     || a[i][j] != f) return 0;
    else if (a[i][j] == 'S') return 1;
    switch (f) {
        case 'X': f = 'M'; break;
        case 'M': f = 'A'; break;
        case 'A': f = 'S'; break;
    }
    switch (d) {
        case UP: return find_xmas(a, i-1, j, f, d);
        case DOWN: return find_xmas(a, i+1, j, f, d);
        case LEFT: return find_xmas(a, i, j-1, f, d);
        case RIGHT: return find_xmas(a, i, j+1, f, d);
        case UL: return find_xmas(a, i-1, j-1, f, d);
        case UR: return find_xmas(a, i-1, j+1, f, d);
        case DL: return find_xmas(a, i+1, j-1, f, d);
        case DR: return find_xmas(a, i+1, j+1, f, d);
    }
}

int main(void) {
    /* Get input array*/
    FILE *fp = fopen("./input", "r");
    fscanf(fp, " %*[^\n]");
    perline = ftell(fp); /* So exploitable :D */
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
            if (array[i][j] == 'X')
                for (int k = 0 ; k < 8 ; ++k)
                    xmas_c += find_xmas(array, i, j, 'X', k);
    printf("%d\n", xmas_c);
    /* Too bored to free */
    return 0;
}