#include <stdio.h>
#include <string.h>

#define RED 12
#define GREEN 13
#define BLUE 14

int main(void) {
    char buffer[1024];
    int id, count, sum = 0;
    new: ;
    while (scanf(" Game %d:", &id) == 1) {
        loop: ;
        while (scanf("%d %1023s", &count, buffer) == 2) {
            if (!strncmp(buffer, "green", 5)) {
                if (count > GREEN) {
                    scanf("%*1023[^\n]");
                    goto new;
                }
            }
            else if (!strncmp(buffer, "blue", 4)) {
                if (count > BLUE) {
                    scanf("%*1023[^\n]");
                    goto new;
                }
            }
            else if (!strncmp(buffer, "red", 3)) {
                if (count > RED) {
                    scanf("%*1023[^\n]");
                    goto new;
                }
            }
        }
        int next = getchar();
        if (next == ';') goto loop;
        ungetc(next, stdin);
        sum += id;
    }
    printf("%d\n", sum);
    while (!feof(stdin)) {
        putchar(getchar());
    }
}