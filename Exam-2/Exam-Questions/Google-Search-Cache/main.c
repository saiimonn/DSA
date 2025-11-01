#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "types.h"

/**
 * @brief Simple hash function (DJB2) to generate an index for the key.
 * @param str The input key string.
 * @return The hash index [0, HASH_BUCKETS - 1].
 */
unsigned int hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % HASH_BUCKETS;
}

/**
 * @brief Runs a specific test case from the original sequential tests.
 * @param cache Pointer to the HashTable instance.
 * @param test_id The ID of the test to run (1 to 5).
 */
void run_test_case(HashTable *cache, int test_id) {
    char **fetched_results = NULL;
    const char *query_to_test = NULL;
    bool insertion_success = false;

    // Note: Tests 2 and 3 depend on test 1 being run first.
    // Tests 4 and 5 depend on tests 1-3 having run.

    switch (test_id) {
        case 1:
            // --- Test 1: New Key (Cache MISS -> Insert calls DB FETCH -> Cache INSERT) ---
            printf("\n--- Test 1: New Key Insertion (famous cse concepts) ---\n");
            query_to_test = "famous cse concepts";

            fetched_results = lookup_cache(cache, query_to_test);

            if (fetched_results == NULL) {
                printf("  [Lookup Status] Key '%s' MISS. Attempting to fetch and insert (DB QUERY in progress)...\n", query_to_test);

                insertion_success = insert_cache(cache, query_to_test);

                if (insertion_success) {
                    printf("  [Insert Status] Insertion successful (DB fetched and cached).\n");
                } else {
                    printf("  [Insert Status] Insertion failed (DB fetch returned no results).\n");
                }

                fetched_results = lookup_cache(cache, query_to_test);
            } else {
                printf("  [Lookup Status] Key '%s' HIT. Returning cached results (ERROR: Should have been a MISS).\n", query_to_test);
            }
            print_results(query_to_test, fetched_results);
            break;

        case 2:
            // --- Test 2: Existing Key (Expected Cache HIT) ---
            printf("\n--- Test 2: Existing Key Lookup (famous cse concepts) ---\n");
            query_to_test = "famous cse concepts";

            // Lookup (Should be a HIT now, if Test 1 was run)
            fetched_results = lookup_cache(cache, query_to_test);

            if (fetched_results != NULL) {
                printf("  [Lookup Status] Key '%s' HIT. Returning cached results.\n", query_to_test);
            } else {
                 printf("  [Lookup Status] Key '%s' MISS (ERROR: Test 1 must be run first).\n", query_to_test);
            }
            print_results(query_to_test, fetched_results);
            break;

        case 3:
            // --- Test 3: Redundant Insertion Test (Expected Skip) ---
            printf("\n--- Test 3: Redundant Insertion Test (famous cse concepts) ---\n");
            query_to_test = "famous cse concepts";

            insertion_success = insert_cache(cache, query_to_test);

            if (insertion_success) {
                printf("  [Insert Status] Insertion was logically skipped because key '%s' already exists.\n", query_to_test);
            } else {
                printf("  [Insert Status] Error: Insertion failed for existing key.\n");
            }

            printf("  Note: No DB fetch occurred. Cache results are unchanged.\n");

            fetched_results = lookup_cache(cache, query_to_test);
            print_results(query_to_test, fetched_results);
            break;

        case 4:
            // --- Test 4: Another New Key (Cache MISS -> Insert calls DB FETCH -> Cache INSERT) ---
            printf("\n--- Test 4: Another New Key Insertion (latest google earnings report) ---\n");
            query_to_test = "latest google earnings report";

            fetched_results = lookup_cache(cache, query_to_test);

            if (fetched_results == NULL) {
                printf("  [Lookup Status] Key '%s' MISS. Attempting to fetch and insert (DB QUERY in progress)...\n", query_to_test);

                insertion_success = insert_cache(cache, query_to_test);

                if (insertion_success) {
                    printf("  [Insert Status] Insertion successful (DB fetched and cached).\n");
                } else {
                    printf("  [Insert Status] Insertion failed (DB fetch returned no results).\n");
                }

                fetched_results = lookup_cache(cache, query_to_test);
            } else {
                printf("  [Lookup Status] Key '%s' HIT. Returning cached results (ERROR: Should have been a MISS).\n", query_to_test);
            }
            print_results(query_to_test, fetched_results);
            break;

        case 5:
            // --- Test 5: Non-existent Key (Cache MISS -> DB No Results) ---
            printf("\n--- Test 5: Non-existent Key (unrelated cat facts) ---\n");
            query_to_test = "unrelated cat facts";

            fetched_results = lookup_cache(cache, query_to_test);

            if (fetched_results == NULL) {
                printf("  [Lookup Status] Key '%s' MISS. Attempting to fetch and insert (DB QUERY in progress)...\n", query_to_test);

                insertion_success = insert_cache(cache, query_to_test);

                if (insertion_success) {
                    printf("  [Insert Status] Error: This should not happen. Insertion successful.\n");
                } else {
                    printf("  [Insert Status] Insertion aborted because DB returned no valid results.\n");
                }

                fetched_results = lookup_cache(cache, query_to_test);
            } else {
                printf("  [Lookup Status] Key '%s' HIT. Returning cached results (ERROR: Key should not exist).\n", query_to_test);
            }
            print_results(query_to_test, fetched_results);
            break;

        default:
            printf("\nInvalid choice. Please enter a number between 1 and 5 (or 0 to exit).\n");
            break;
    }
}

int main() {
    HashTable search_cache;
    init_cache(&search_cache);
    int choice = -1;

    printf("Google Cache Simulation using Open Hashing Dictionary\n");
    printf("----------------------------------------------------\n");
    printf("Note: Test Cases 2 and 3 require Test 1 to be run first.\n");

    while (choice != 0) {
        printf("\nSelect a test case to run:\n");
        printf("1. Run Test 1: New Key Insertion (famous cse concepts)\n");
        printf("2. Run Test 2: Existing Key Lookup (Expected HIT)\n");
        printf("3. Run Test 3: Redundant Insertion (Expected SKIP)\n");
        printf("4. Run Test 4: Second New Key Insertion (latest google earnings report)\n");
        printf("5. Run Test 5: Non-existent Key (DB No Results)\n");
        printf("0. Exit and Free Memory\n");
        printf("Enter choice: ");

        // Ensure only one integer is read
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            // Clear the input buffer to prevent infinite loop
            while (getchar() != '\n');
            choice = -1; // Reset choice
            continue;
        }

        if (choice == 0) {
            break;
        }

        run_test_case(&search_cache, choice);
    }

    // Clean up memory before exiting
    free_cache(&search_cache);

    return 0;
}