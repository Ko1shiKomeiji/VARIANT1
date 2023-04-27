#include "funcs1.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    node *L1 = NULL;
    struct Data data;
    int i;

    srand(time(NULL));

    while ((data.f = (rand()%100)) < 90) {
        for (i = 0; i < 2; i++)
            data.s[i] = ((char)(65 + rand()%25));
        L1 = add_head(L1, &data);
    }

    lprint(L1);
    L1 = reverse(L1);
    lprint(L1);

    return 0;
}