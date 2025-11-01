#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

void init_cache(HashTable *table) {
    for (int i = 0; i < HASH_BUCKETS; i++) {
        table->buckets[i] = NULL;
    }
}

char **lookup_cache(HashTable *table, const char *key) {
    unsigned int idx = hash(key);
    CacheEntry *trav = table->buckets[idx];

    while (trav != NULL) {
        if (strcmp(trav->key, key) == 0) {
            return trav->results;
        }
        trav = trav->next;
    }

    return NULL;
}

bool insert_cache(HashTable *table, const char *key) {
    unsigned int idx = hash(key);
    CacheEntry *trav = table->buckets[idx];

    while (trav != NULL) {
        if (strcmp(trav->key, key) == 0) {
            return true;
        }
        trav = trav->next;
    }

    char **arr = simulate_database_fetch(key);
    if (arr == NULL) return false; 

    CacheEntry *newNode = (CacheEntry *)malloc(sizeof(CacheEntry));
    if (newNode == NULL) return false;

    newNode->key = strdup(key); 

    newNode->results = (char **)malloc(RESULT_COUNT * sizeof(char *));
    if (newNode->results == NULL) {
        free(newNode->key);
        free(newNode);
        return false;
    }

    for (int i = 0; i < RESULT_COUNT; i++) {
        newNode->results[i] = strdup(arr[i]); 
    }

    newNode->next = table->buckets[idx];
    table->buckets[idx] = newNode;

    cleanup_fetched_results(arr);

    return true;
}