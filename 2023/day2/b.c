#include <stdio.h>
#include <string.h>

// #define RED 12
// #define GREEN 13
// #define BLUE 14

int main(void) {
    char buffer[1024];
    int id, count, sum = 0;
    while (scanf(" Game %d:", &id) == 1) {
        int green = 0, blue = 0, red = 0;
        loop: ;
        while (scanf("%d %1023s", &count, buffer) == 2) {
            if (!strncmp(buffer, "green", 5)) {
                if (count > green) {
                    green = count;
                }
            }
            else if (!strncmp(buffer, "blue", 4)) {
                if (count > blue) {
                    blue = count;
                }
            }
            else if (!strncmp(buffer, "red", 3)) {
                if (count > red) {
                    red = count;
                }
            }
        }
        int next = getchar();
        if (next == ';') goto loop;
        ungetc(next, stdin);
        sum += green * blue * red;
    }
    printf("%d\n", sum);
    while (!feof(stdin)) {
        putchar(getchar());
    }
}