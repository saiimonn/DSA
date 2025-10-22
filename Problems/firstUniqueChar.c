#include <stdio.h>
#include <string.h>

int firstUniqChar(char *);

int main() {
    char *testCases[] = {
        "leetcode",
        "loveleetcode",
        "aabb",
        "xxyz",
        "a",
        ""
    };
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTests; i++) {
        int result = firstUniqChar(testCases[i]);
        printf("Test %d: \"%s\"-> ", i + 1, testCases[i]);
        if (result == -1)
            printf("No unique character found (-1)\n");
        else
            printf("First unique at index %d (character '%c')\n", result, testCases[i][result]);
    }

    return 0;
}

int firstUniqChar(char *s) {
    int result[26] = {0};
    
    for(unsigned int i = 0; i < strlen(s); i++) {
        result[s[i] - 'a']++;
    }

    for(unsigned int i = 0; i < strlen(s); i++) {
        if(result[s[i] - 'a'] == 1) {
            return i;
        }
    }

    return -1;
}