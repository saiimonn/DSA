// Write your boilerplate code here...
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum
{
    POWER_RANGER,
    MONSTER,
    ZORD,
    ZORD_PILOT,
    KAIJU,
    MEGAZORD
}combatant_state;

typedef struct node
{
    combatant_state combatant;
    struct node* link;
}*combatants;


//Functions to implement
combatant_state transform(combatant_state combatant);
void enterPhaseTwo(combatants battle, combatant_state (*toPhaseTwo)(combatant_state));

//Don't worry about these ones
char* toString(combatant_state combatant);
void printBattle(combatants battle, const char* label);

combatants newCombatant(combatant_state combatant, combatants link);
combatants newBattleRandom(int numberOfCombatants);

void endBattle(combatants* battle);
void showResult(int testCaseNum);


int main()
{
    int testCase, randSeed;
    printf("Enter test case number: ");
    scanf("%d", &testCase);
    printf("Enter seed: ");
    scanf("%d", &randSeed);

    srand(randSeed);
    showResult(testCase);

    return 0;
}


//Functions to implement
combatant_state transform(combatant_state combatant)
{
    combatant_state state = combatant;
    if(combatant == POWER_RANGER) state = ZORD_PILOT;
    else if(combatant == ZORD_PILOT) state = MONSTER;
    else if(combatant == MONSTER) state = KAIJU;
    else if(combatant == ZORD) state = MEGAZORD;

    return state;
}

void enterPhaseTwo(combatants battle, combatant_state (*toPhaseTwo)(combatant_state))
{
    if(battle != NULL) {
        battle->combatant = toPhaseTwo(battle->combatant);
        enterPhaseTwo(battle->link, toPhaseTwo);
    }
}

//Don't worry about these ones
char* toString(combatant_state combatant)
{
    char* string = (char*)calloc(sizeof(char), strlen("Power Ranger") + 1);
    switch(combatant)
    {
        case POWER_RANGER: strcpy(string, "Power Ranger"); break;
        case MONSTER: strcpy(string, "Monster"); break;
        case ZORD: strcpy(string, "Zord"); break;
        case ZORD_PILOT: strcpy(string, "Zord Pilot"); break;
        case KAIJU: strcpy(string, "Kaiju"); break;
        case MEGAZORD: strcpy(string, "Megazord"); break;
    }
    return string;
}
void printBattle(combatants battle, const char* label)
{
    printf("\n%s:\n", label);
    for(; battle != NULL; battle = battle->link)
    {
        char* state = toString(battle->combatant);
        printf("Combatant: %s\n", state);
        free(state);
    }
}

combatants newCombatant(combatant_state combatant, combatants link)
{
    combatants newNode = (combatants)malloc(sizeof(struct node));
    newNode->combatant = combatant;
    newNode->link = link;

    return newNode;
}
combatants newBattleRandom(int numberOfCombatants)
{
    combatants newBattle = NULL;
    for(int i = 0; i < numberOfCombatants; i++)
    {
        newBattle = newCombatant(rand() % 3, newBattle);
    }

    return newBattle;
}

void endBattle(combatants* battle)
{
    while(*battle != NULL)
    {
        combatants del = *battle;
        *battle = (*battle)->link;
        free(del);
    }
}
void showResult(int testCaseNum)
{
    combatants battle;
    switch(testCaseNum)
    {
        case 1:
        battle = newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(MONSTER, 
                newCombatant(ZORD, NULL)))))));
        break;

        case 2:
        battle = newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(POWER_RANGER,
                newCombatant(MONSTER, 
                newCombatant(MONSTER,
                newCombatant(ZORD,
                newCombatant(ZORD, NULL)))))))));
        break;

        case 3:
        battle = NULL;
        break;

        default:
        battle = newBattleRandom(rand() % 10);
        break;
    }

    printBattle(battle, "Phase 1");
    enterPhaseTwo(battle, transform);
    printBattle(battle, "Phase 2");
}
