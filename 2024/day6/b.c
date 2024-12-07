#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Direction {
    UP = 0x01,
    RIGHT = 0x02,
    DOWN = 0x04,
    LEFT = 0x08
} Direction;

typedef char visit_t[2];

/* Return 1 for loop */
int patrol(char **a, visit_t **v, int i, int j, int l, int c) {
    Direction d = UP;
    int ni, nj;
    while (1) {
        v[i][j][0] = 1;
        v[i][j][1] |= d;
        ni = i + ((d & DOWN) >> 2) - (d & UP);
        nj = j + ((d & RIGHT) >> 1) - ((d & LEFT) >> 3);
        if (ni < 0 || ni >= l || nj < 0 || nj >= c) return 0; /* Out of bounds */
        if (v[ni][nj][0] && (v[ni][nj][1] & d)) return 1; /* Loop */
        if (a[ni][nj] == '#') d = ((d << 1) | (d >> 3)) & 0xF; /* Rotate 90 */
        else {
            i = ni;
            j = nj;
        }
    }
}

int main(void) {
    int lines = 1, perline;
    /* Get input array */
    FILE *fp = fopen("./input", "r");
    fscanf(fp, " %*[^\n]");
    perline = ftell(fp); /* So exploitable :D */
    while (!fscanf(fp, " %*[^\n]")) ++lines;
    rewind(fp);
    char **a = malloc(sizeof(char *) * lines);
    for (int i = 0 ; i < lines ; ++i)
        a[i] = malloc(sizeof(char) * (perline + 1));
    for (int i = 0 ; i < lines ; ++i)
        fscanf(fp, " %[^\n]", a[i]);
    fclose(fp);

    /* Find guard start */
    int start_i, start_j;
    for (int i = 0 ; i < lines ; ++i)
        for (int j = 0 ; j < perline ; ++j)
            if (a[i][j] == '^') {
                start_i = i;
                start_j = j;
            };

    /* Find candidates */
    visit_t **v = calloc(lines, sizeof(visit_t *));
    for (int i = 0 ; i < lines ; ++i)
        v[i] = calloc(perline, sizeof(visit_t));
    patrol(a, v, start_i, start_j, lines, perline);

    /* Try every candidate for loop */
    int count = 0;
    visit_t **tv = calloc(lines, sizeof(visit_t *));
    for (int i = 0 ; i < lines ; ++i)
        tv[i] = calloc(perline, sizeof(visit_t));
    for (int i = 0 ; i < lines ; ++i)
        for (int j = 0 ; j < perline ; ++j)
            if (v[i][j][0] && a[i][j] != '^') {
                a[i][j] = '#';
                count += patrol(a, tv, start_i, start_j, lines, perline);
                a[i][j] = '.';
                for (int k = 0 ; k < lines ; ++k)
                    memset(tv[k], 0, perline * sizeof(visit_t));
            }

    printf("%d\n", count);
    /* Who frees anymore?? */
    return 0;
}