#include <stdio.h>

typedef unsigned int MESSAGE;

int findHELP(MESSAGE m) {
    int helps = 0;
    int count1 = 0;

    while (m > 0) {
        if (m & 1) count1++;
        else {
            if (count1 >= 3) helps++;
            count1 = 0;
        }
        m >>= 1;
    }

    // Check if trailing bits were a HELP
    if (count1 >= 3) helps++;

    return helps;
}

int findUNDERCOVER(MESSAGE m) {
    int undercover = 0;

    unsigned int prev = 0, curr = 0, next = 0;

    curr = m & 1;      // bit 0
    m >>= 1;
    next = m & 1;      // bit 1

    for (int i = 1; m > 0; i++) {
        prev = curr;
        curr = next;
        m >>= 1;
        next = m & 1;

        if (prev == 1 && curr == 0 && next == 1)
            undercover++;
    }

    return undercover;
}

int findSIGNALNOTFOUND(MESSAGE m) {
    int snf = 0;

    unsigned int prev = 0, curr = 0, next = 0;

    curr = m & 1;      // bit 0
    m >>= 1;
    next = m & 1;      // bit 1

    for (int i = 1; m > 0; i++) {
        prev = curr;
        curr = next;
        m >>= 1;
        next = m & 1;

        if (prev == 0 && curr == 1 && next == 0)
            snf++;
    }

    return snf;
}

int main() {
    MESSAGE signal;

    printf("INPUT THE SIGNAL MESSAGE: ");
    scanf("%u", &signal);

    printf("\n\n[ANALYZING MESSAGE WITH CODE %u...]\n\n", signal);
    printf("NUMBER OF HELPS: %i\n", findHELP(signal));
    printf("NUMBER OF UNDERCOVERS: %i\n", findUNDERCOVER(signal));
    printf("NUMBER OF SIGNAL LOSSES: %i\n", findSIGNALNOTFOUND(signal));

    return 0;
}