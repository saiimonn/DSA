#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY '~'
#define DELETED '!'
#define MAX 211

/*********************************/
/*    USER-DEFINED DATA TYPES    */
/*********************************/
typedef struct {
    char elem;
    int frequency;
} Element;

typedef Element Dictionary[MAX];

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D);
int hash(char elem);

/*********************************/
/*          YOUR TASKS           */
/*********************************/

void insert(Dictionary D, char elem);
void delete(Dictionary D, char elem);
bool isMember(Dictionary D, char elem);
bool isAnagram(char* s, char* t);

int main(void) {
    char s1[100], s2[100];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    if (isAnagram(s1, s2)) {
        printf("\"%s\" and \"%s\" are anagrams.\n", s1, s2);
    } else {
        printf("\"%s\" and \"%s\" are NOT anagrams.\n", s1, s2);
    }

    return 0;
}

/*********************************/
/*       HELPER FUNCTIONS        */
/*********************************/
void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) {
        D[i].elem = EMPTY;
        D[i].frequency = 0;
    }
}

int hash(char elem) {
    return ((int)elem) % MAX;
}

/*********************************/
/*          YOUR TASKS           */
/*********************************/


void insert(Dictionary D, char elem) {
    // TODO: Implement insert with linear probing
    int idx = hash(elem);
    int i, deleteIdx = -1;
    for(i = 0; i < MAX && D[idx].elem != EMPTY && D[idx].elem != elem; idx = (idx + 1) % MAX, i++) {
        if(deleteIdx == -1 && D[idx].elem == DELETED) {
            deleteIdx = idx;
        }
    }

    if(D[idx].elem == elem) {
        D[idx].frequency++;
        return;
    }

    if(i != MAX) {
        D[idx].elem = elem;
        D[idx].frequency = 1;
    } else if(deleteIdx != -1) {
        D[deleteIdx].elem = elem;
        D[deleteIdx].frequency = 1;
    }
}

void delete(Dictionary D, char elem) {
    // TODO: Implement delete with linear probing
    int idx = hash(elem);
    int start = idx;
    int i = 0;
    bool isFull = false;

    while(i < MAX && D[idx].elem != EMPTY && !isFull) {
        if(D[idx].elem == elem) {
            D[idx].frequency--;
            if(D[idx].frequency <= 0) {
                D[idx].elem = DELETED;
                D[idx].frequency = 0;
            }
            return;
        }
        idx = (idx + 1) % MAX;
        i++;
        if(idx == start) {
            isFull = true;
        }
    }
}

bool isMember(Dictionary D, char elem) {
    // TODO: Implement membership check
    int idx = hash(elem);
    int stop = hash(elem);
    bool isFull = false;

    while(!isFull && D[idx].elem != elem && D[idx].elem != EMPTY) {
        idx = (idx + 1) % MAX;
        if(idx == stop) {
            isFull = true;
        }
    }

    return D[idx].elem == elem;
}

bool isAnagram(char *s, char *t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    Dictionary D;
    initDict(D);

    for (int i = 0; s[i] != '\0'; i++) {
        insert(D, s[i]);
    }

    for (int i = 0; t[i] != '\0'; i++) {
        delete(D, t[i]);
    }

    for (int i = 0; i < MAX; i++) {
        if (D[i].elem != EMPTY && D[i].elem != DELETED && D[i].frequency != 0) {
            return false;
        }
    }

    return true;
}