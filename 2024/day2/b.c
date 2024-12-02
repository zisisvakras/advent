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
        int last = strlen(buf);
        /* Do 2 loops for each mode */
        for (int m = 1 ; m >= 0 ; --m) {
            /* No checks, each line has at least 3 */
            char *token1 = strtok(buf, DLIM);
            char *token2 = strtok(NULL, DLIM);
            int chance = 1;
            safe = 1;
            while (safe && token2 != NULL) {
                int diff = atoi(token1) - atoi(token2);
                safe = m ? diff < 0 : diff > 0;
                if (safe) safe = abs(diff) >= 1 && abs(diff) <= 3;
                if (!safe) {
                    if (!chance) break;
                    chance = 0;
                    safe = 1;
                    /* If not the beginning just abandon token2 */
                    if (token1 != buf) {
                        token2 = strtok(NULL, DLIM);
                        continue;
                    }
                    /* Decide which to abandon */
                    char *token3 = strtok(NULL, DLIM); /* Every line has 3 */
                    diff = atoi(token1) - atoi(token3);
                    int temp = m ? diff < 0 : diff > 0;
                    if (temp) temp = abs(diff) >= 1 && abs(diff) <= 3;
                    if (!temp) token1 = token2; /* Abandon token1 */
                    token2 = token3;
                    continue;
                }
                token1 = token2;
                token2 = strtok(NULL, DLIM);
            }
            total_safe += safe;
            if (safe) break;
            /* Restore string for round 2 :) */
            for (int i = 0 ; i < last - 1 ; ++i)
                if (buf[i] == '\0') buf[i] = ' ';
        }
    }
    printf("%d\n", total_safe);
    fclose(fp);
    return 0;
}