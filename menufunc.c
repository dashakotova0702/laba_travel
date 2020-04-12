#include "struct.h"

int menu(void) {
        char s[80];
        int c;
        printf("\n1. Ввести тур\n");
        printf("2. Посмотреть все туры\n");
        printf("3. Поиск туров\n");
        printf("4. Удаление тура\n");
        printf("5. Бронирование тура\n");
        printf("6. Выход\n");
        do {
                printf("\nВведите номер нужного пункта: ");
                scanf ("%d", &c);
        } while (c<0 || c>6);
        return c;
}

int searchmenu(void){
        char s[80];
        int c;
        printf("\n1. Страна\n");
        printf("2. Город\n");
        printf("3. Отель\n");
        printf("4. Звезды\n");
        printf("5. Общее количество мест\n");
        printf("6. Свободные места\n");
        printf("7. Выйти\n");
        do {
                printf("\nВведите номер параметра для поиска: ");
                scanf ("%d", &c);
        } while (c<0 || c>7);
        return c;
}
