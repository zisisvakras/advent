#include <stdio.h>
#include <string.h>

int main(void) {
    int sum = 0, id;
    int multi[208][2];
    for (int i = 0 ; i < 208 ; ++i) {
        multi[i][0] = 1; /* Instances */
        multi[i][1] = 0; /* Wins */
    }
    while (scanf(" Card %d:", &id) == 1) {
        --id;
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
        multi[id][1] = count;
    }
    for (int i = 0 ; i < 208 ; ++i) {
        int wins = multi[i][1];
        if (wins == 0) continue;
        for (int j = 1 ; j <= wins ; ++j) {
            multi[i + j][0] += multi[i][0];
        }
    }
    for (int i = 0 ; i < 208 ; ++i) {
        sum += multi[i][0];
    }
    printf("%d\n", sum);
}