#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DLIM " \n"

int main(void) {
    FILE *fp = fopen("input", "r");
    char buf[4096];
    int total_safe = 0;
    int safe = 1;
    while (fscanf(fp, " %4095[^\n]", buf) == 1) {
        /* No checks, each line has at least 2 */
        char *token1 = strtok(buf, DLIM);
        char *token2 = strtok(NULL, DLIM);
        int mode = atoi(token1) < atoi(token2);
        safe = 1;
        while (safe && token2 != NULL) {
            int diff = atoi(token1) - atoi(token2);
            safe = mode ? diff < 0 : diff > 0;
            if (!safe) break;
            safe = abs(diff) >= 1 && abs(diff) <= 3;
            token1 = token2;
            token2 = strtok(NULL, DLIM);
        }
        total_safe += safe;
    }
    printf("%d\n", total_safe);
    fclose(fp);
    return 0;
}