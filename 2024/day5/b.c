#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    char bef[100][100] = {0}; /* List all values before bef[i] */
    /* Find rule count */
    int rules = 0;
    FILE *fp = fopen("./input", "r");
    while (!feof(fp)) rules += fgetc(fp) == '|';
    rewind(fp);
    int num1, num2;
    for (int i = 0 ; i < rules ; ++i)
        if (fscanf(fp, "%d|%d", &num1, &num2) == 2)
            bef[num2][num1] = 1;
    /* Get updates */
    int updates[30], up_i = 0;
    int middle = 0;
    char comma[2];
    while (1) {
        int r = fscanf(fp, "%d%1[,]", &num1, comma);
        if (r == 2) {
            updates[up_i++] = num1;
        } else if (r == 1) {
            updates[up_i++] = num1;
            int is_fine = 1;
            for (int i = 0 ; i < up_i ; ++i) {
                for (int j = i + 1 ; j < up_i ; ++j) {
                    if (bef[updates[i]][updates[j]])
                        is_fine = 0;
                }
            }
            if (is_fine) {
                up_i = 0;
                continue;
            }
            /* bsort */
            for (int i = 0 ; i < up_i ; ++i) {
                for (int j = i + 1 ; j < up_i ; ++j) {
                    if (bef[updates[i]][updates[j]]) {
                        int temp = updates[i];
                        updates[i] = updates[j];
                        updates[j] = temp;
                    }
                }
            }
            middle += updates[up_i / 2];
            up_i = 0;
        }
        else break;
    }
    printf("%d\n", middle);
}