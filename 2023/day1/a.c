#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[1024];
    int sum = 0;
    while (scanf(" %1023[^\n]", buffer) == 1) {
        int len = strlen(buffer), i = 0, digit = 0;
        while (buffer[i] > '9' || buffer[i] < '0') ++i;
        sum += (buffer[i] - '0') * 10;
        printf("%d\n", (buffer[i] - '0'));
        for (; i < len ; ++i) {
            if (buffer[i] <= '9' && buffer[i] >= '0')
                digit = buffer[i];
        }
        sum += (digit - '0');
        //printf("%d\n", (digit - '0'));
    }
    printf("%d\n", sum);
}