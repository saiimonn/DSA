#include <stdio.h>
#include <string.h>
#include "../Exam-1/Stack/Activities/Abstraction/stack-array.h"

char *minimumRemove(char *); 

int main() {
    Stack S;
    initialize(&S);

    minimumRemove("(a(b(c)d)"); //expected output: a(b(c)d)
}

char *minimumRemove(char *s) { //leetcode implementation
    if(*s != '\0') {
        char *min = (char*)malloc(sizeof(char) * strlen(s));
        if(min != NULL) {
            char stack[strlen(s)];
            int top = -1;
            int i;
            for(i = 0; s[i] != '\0'; i++) {
                if(s[i] == '(') {
                    stack[++top] = s[i];
                }
            }
        }
    }
}

// char *minimumRemove(char *s) { //stack implementation
//     if(*s != '\0') {
//         char *min = (char*)malloc(sizeof(char) * strlen(s));
//         if(min != NULL) {
//             Stack st;
//             initialize(&st);
//             int i;
//             for(i = 0; s[i] != '\0'; i++) {
                
//             }
//         }
//     }
// }