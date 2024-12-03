#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *fp = fopen("./input", "r");
    fseek(fp, 0, SEEK_END);
    long isize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char *input = malloc(isize);
    /* Its reg file it will work :pray: */
    fread(input, isize, 1, fp);
    fclose(fp);
    long res = 0;
    for (long i = 0 ; i < isize ; ++i) {
        char num1[10], num2[10], e[2];
        if (sscanf(input + i, "mul(%[0-9],%[0-9]%1[)]", num1, num2, e) == 3) {
            res += atoll(num1) * atoll(num2);
        }
    }
    printf("%ld\n", res);
    free(input);
    return 0;
}