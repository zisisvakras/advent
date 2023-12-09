#include <stdio.h>
#include <string.h>

int main(void) {
    int sum = 0, id;
    while (scanf(" Card %d:", &id) == 1) {
        int count = 0;
        int winning[10];
        for (int i = 0 ; i < 10 ; ++i)
            scanf("%d", &winning[i]);
        scanf(" |");
        for (int i = 0 ; i < 25 ; ++i) {
            int temp;
            scanf("%d", &temp);

            for (int j = 0 ; j < 10 ; ++j) {
                if (temp == winning[j]) ++count;
            }
        }
        if (count) sum += 1 << (count - 1);
    }
    printf("%d\n", sum);
}