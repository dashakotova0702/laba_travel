#include <stdio.h>
#include <stdlib.h>

typedef struct tours {
        int id;
        char country[50];
        char town[50];
        char hotel[50];
        int stars;
        int places;
        int freeplaces;
} tours;
typedef struct str{
        char a[10];
} str;

int menu(void);
void enter(void), read(void);


