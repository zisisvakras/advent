#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_digit(char *buffer, int start, int len) {
    if (buffer[start] <= '9' && buffer[start] >= '0')
        return buffer[start] - '0';
    switch (buffer[start]) {
        case 'o': // two three
            if (len - start >= 3 && !strncmp(buffer + start, "one",3)) return 1;
            break;
        case 't': // two three
            if (len - start >= 3 && !strncmp(buffer + start, "two",2)) return 2;
            if (len - start >= 5 && !strncmp(buffer + start, "three",5)) return 3;
            break;
        case 'f': // two three
            if (len - start >= 4 && !strncmp(buffer + start, "four",4)) return 4;
            if (len - start >= 4 && !strncmp(buffer + start, "five",4)) return 5;
            break;
        case 's': // two three
            if (len - start >= 3 && !strncmp(buffer + start, "six",3)) return 6;
            if (len - start >= 5 && !strncmp(buffer + start, "seven",5)) return 7;
            break;
        case 'e': // two three
            if (len - start >= 5 && !strncmp(buffer + start, "eight",5)) return 8;
            break;
        case 'n': // two three
            if (len - start >= 3 && !strncmp(buffer + start, "nine",4)) return 9;
            break;
        default:
            return 0;
    }
    return 0;
}

int main(void) {
    char buffer[1024];
    int sum = 0;
    while (scanf(" %1023[^\r\n]", buffer) == 1) {
        int len = strlen(buffer), i = 0, digit = 0, temp;
        while (!(temp = is_digit(buffer, i, len))) ++i;
        sum += temp * 10;
        digit = temp;
        printf("%s %d", buffer, temp);
        for (; i < len ; ++i) {
            if ((temp = is_digit(buffer, i, len)))
                digit = temp;
        }
        sum += digit;
        printf("%d\n", digit);
    }
    printf("%d\n", sum);
}