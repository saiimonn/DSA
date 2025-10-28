#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20
#define PERSONS 3

typedef struct {
    int id;
    char name[100];
    int earnings; // in millions
    float rating;
} Movie;

typedef struct {
    char name[30];
    int favorites[SIZE]; // 0 - didn't like the movie, 1 - liked the movie
} Person;

// Function prototypes
void displayMovies(Movie movies[]);
void displayFriendsSummary(Person f);
void displaySet(int set[], Movie movies[]);
void unionSet(int A[], int B[], int C[]);
void intersectionSet(int A[], int B[], int C[]);
void differenceSet(int A[], int B[], int C[]);
void analysis(Movie movies[], Person friends[]);
void preferences(Movie movies[], Person friends[]);

int main(void) {
    Movie movies[SIZE] = {
        {0, "Rogue One: A Star Wars Story", 1057, 7.6},
        {1, "The Amazing Spider-Man", 758, 6.3},
        {2, "Pirates of the Caribbean: The Curse of the Black Pearl", 654, 7.2},
        {3, "Avatar: The Way of Water", 2343, 8.1},
        {4, "Justice League", 661, 6.7},
        {5, "Furious 7", 1515, 7.5},
        {6, "Wicked", 752, 8.7},
        {7, "Beauty and the Beast", 1266, 8.2},
        {8, "The Lord of the Rings: The Two Towers", 938, 9.1},
        {9, "Kung Fu Panda 2", 665, 7.9},
        {10, "The Twilight Saga: New Moon", 711, 6.0},
        {11, "Ant-Man and the Wasp", 622, 7.2},
        {12, "Forrest Gump", 678, 9.8},
        {13, "Dune: Part Two", 714, 9.3},
        {14, "2012", 791, 7.6},
        {15, "Barbie", 1447, 8.0},
        {16, "Oppenheimer", 975, 9.1},
        {17, "The Hunger Games: Mockingjay - Part 1", 758, 7.6},
        {18, "Mission: Impossible - Fallout", 824, 7.5},
        {19, "Frozen", 1286, 7.2}
    };

    Person A = {"Hank Garrison",
        {1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0}};
    Person B = {"Helen Bernard",
        {1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1}};
    Person C = {"Lee Potter",
        {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0}};

    Person friends[PERSONS] = {A, B, C};

    printf("=== MY FRIENDS' FAVORITE FILMS! ===\n\n");
    displayMovies(movies);
    printf("\n");

    for (int i = 0; i < PERSONS; i++)
        displayFriendsSummary(friends[i]);

    printf("\n[WHAT DID THEY LIKE?]\n");
    preferences(movies, friends);

    printf("\n[FILM PREFERENCE ANALYSIS]\n");
    analysis(movies, friends);
}

// Function stubs (unchanged)
void displayMovies(Movie movies[]) {
    printf("ID | Movie Title | Earnings (M) | Rating\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d | %-55s | %4d | %.1f\n",
               movies[i].id,
               movies[i].name,
               movies[i].earnings,
               movies[i].rating);
    }
}

void displayFriendsSummary(Person f) {
    printf("Name: %s\n", f.name);
    printf("Favorites: { ");
    for (int i = 0; i < SIZE; i++)
        if (f.favorites[i] == 1)
            printf("%d ", i);
    printf("}\n");
}

void displaySet(int set[], Movie movies[]) {
    for (int i = 0; i < SIZE; i++) {
        if (set[i] == 1)
            printf("> %s\n", movies[i].name);
    }
    printf("\n");
}

void unionSet(int A[], int B[], int C[]) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] | B[i];
    }
}

void intersectionSet(int A[], int B[], int C[]) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] & B[i];
    }
}

void differenceSet(int A[], int B[], int C[]) {
    for (int i = 0; i < SIZE; i++) {
        C[i] = A[i] & ~B[i];
    }
}

void preferences(Movie movies[], Person friends[]) {
    printf("\nMovies at least one of them liked:\n");
    int Un[SIZE];
    int Un2[SIZE];
    unionSet(friends[0].favorites, friends[1].favorites, Un);
    unionSet(friends[2].favorites, Un, Un2);
    displaySet(Un2, movies);

    printf("\nMovies they all liked: \n");
    int In1[SIZE];
    int In2[SIZE];
    intersectionSet(friends[0].favorites, friends[1].favorites, In1);
    intersectionSet(friends[2].favorites, In1, In2);
    displaySet(In2, movies);

    printf("\nMovies at least two of them liked: \n");
    int AB[SIZE], BC[SIZE], AC[SIZE], temp[SIZE], temp2[SIZE], result[SIZE];
    intersectionSet(friends[0].favorites, friends[1].favorites, AB);
    intersectionSet(friends[1].favorites, friends[2].favorites, BC);
    intersectionSet(friends[0].favorites, friends[2].favorites, AC);
    unionSet(AB, BC, temp);
    unionSet(temp, AC, temp2);
    differenceSet(temp2, In2, result);
    displaySet(result, movies);

    printf("\nMovies only one of them liked:\n");
    int onlyOne[SIZE];
    differenceSet(Un2, temp2, onlyOne);
    displaySet(onlyOne, movies);
}

void analysis(Movie movies[], Person friends[]) {
    int In1[SIZE], In2[SIZE];
    intersectionSet(friends[0].favorites, friends[1].favorites, In1);
    intersectionSet(friends[2].favorites, In1, In2);

    int Un1[SIZE], Un2[SIZE];
    unionSet(friends[0].favorites, friends[1].favorites, Un1);
    unionSet(friends[2].favorites, Un1, Un2);
  
    // ---- Certified Fan Favorites ----
    printf("\n------ CERTIFIED FAN FAVORITES ------\n");
    printf("(At least 2 liked it, rating > 7, earnings > 800M)\n");


    int atLeastTwo[SIZE], AB[SIZE], BC[SIZE], AC[SIZE], temp[SIZE], result[SIZE];
    intersectionSet(friends[0].favorites, friends[1].favorites, AB);
    intersectionSet(friends[1].favorites, friends[2].favorites, BC);
    intersectionSet(friends[0].favorites, friends[2].favorites, AC);
    unionSet(AB, BC, temp);
    unionSet(temp, AC, atLeastTwo);

    for(int i = 0; i < SIZE; i++) {
        if(atLeastTwo[i] == 1 && (movies[i].earnings > 800 && movies[i].rating > 7)) {
            result[i] = 1;
        } else {
          result[i] = 0;
        }
    }
    displaySet(result, movies);

    // ---- Underrated Gems ----
    printf("------ UNDERRATED GEMS ------\n");
    printf("(At most 2 liked it, rating > 8.5, earnings < 750M)\n");

    int onlyOne[SIZE];
    differenceSet(Un2, In2, onlyOne);

    int result2[SIZE];
    for(int i = 0; i < SIZE; i++) {
      if(onlyOne[i] == 1 && movies[i].rating > 8.5 && movies[i].earnings < 750) {
        result2[i] = 1;
      } else {
        result2[i] = 0;
      }
    }
    displaySet(result2, movies);
}