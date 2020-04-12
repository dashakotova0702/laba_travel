#include "struct.h"
#include <string.h>

void c1(void){
        FILE  *fp;
        if (fp=fopen("tours.bin", "rb") == NULL)
		printf ("Файл пуст");
        else {
		fp = fopen("tours.bin", "rb");
		tours t;
        	char *a;
        	a=(char*)malloc(10);
        	printf("\nТуры в какую страны вывести?: ");
        	scanf("%s", a);
		int cnt;
        	while (!feof(fp)){
                	cnt=fread(&t, sizeof(t), 1, fp);
                	if (strcmp (t.country, a)==0 && cnt==1)
                        	printf("%s %s %s %d звезд, %d мест, %d свободных мест\n", t.country, t.town, t.hotel, t.stars, t.places, t.freeplaces);
        	}
        	fclose(fp);
        	free(a);
	}
}

void c2(void){
        FILE  *fp;
	if (fp=fopen("tours.bin", "rb") == NULL)
                printf ("Файл пуст");
        else {
        	fp = fopen("tours.bin", "rb");
        	tours t;
        	char *a;
        	a=(char*)malloc(10);
        	printf("\nТуры в какой город вывести?: ");
        	scanf("%s", a);
        	int cnt;
                while (!feof(fp)){
                        cnt=fread(&t, sizeof(t), 1, fp);
                        if (strcmp (t.town, a)==0 && cnt==1)
                        	printf("%s %s %s %d звезд, %d мест, %d свободных мест\n", t.country, t.town, t.hotel, t.stars, t.places, t.freeplaces);
        	}
        	fclose(fp);
        	free(a);
	}
}

void c3(void){
        FILE  *fp;
	if (fp=fopen("tours.bin", "rb") == NULL)
                printf ("Файл пуст");
        else {
	        fp = fopen("tours.bin", "rb");
        	tours t;
        	char *a;
        	a=(char*)malloc(10);
        	printf("\nТуры в какой отель вывести?: ");
        	scanf("%s", a);
        	int cnt;
                while (!feof(fp)){
                        cnt=fread(&t, sizeof(t), 1, fp);
                        if (strcmp (t.hotel, a)==0 && cnt==1)
                        	printf("%s %s %s %d звезд, %d мест, %d свободных мест\n", t.country, t.town, t.hotel, t.stars, t.places, t.freeplaces);
        	}
        	fclose(fp);
        	free(a);
	}
}

void c4(void){
        FILE  *fp;
	if (fp=fopen("tours.bin", "rb") == NULL)
                printf ("Файл пуст");
        else {
	        fp = fopen("tours.bin", "rb");
        	tours t;
        	int b;
        	printf("\nС каким количеством звезд отели вывести?: ");
        	scanf("%d", &b);
		int cnt;
        	while (!feof(fp)){
                	cnt=fread(&t, sizeof(t), 1, fp);
                	if (t.stars==b && cnt==1)
                	        printf("%s %s %s %d звезд, %d мест, %d свободных мест\n", t.country, t.town, t.hotel, t.stars, t.places, t.freeplaces);
        	}
        	fclose(fp);
	}
}

void c5(void){
        FILE  *fp;
	if (fp=fopen("tours.bin", "rb") == NULL)
                printf ("Файл пуст");
        else {
	        fp = fopen("tours.bin", "rb");
        	tours t;
        	int b;
        	printf("\nОтели со сколькими местами вывести?: ");
        	scanf("%d", &b);
        	int cnt;
                while (!feof(fp)){
                        cnt=fread(&t, sizeof(t), 1, fp);
                        if (t.places==b && cnt==1)
                        	printf("%s %s %s %d звезд, %d мест, %d свободных мест\n", t.country, t.town, t.hotel, t.stars, t.places, t.freeplaces);
        	}
        	fclose(fp);
	}
}

void c6(void){
        FILE  *fp;
	if (fp=fopen("tours.bin", "rb") == NULL)
                printf ("Файл пуст");
        else {
	        fp = fopen("tours.bin", "rb");
        	tours t;
        	int b;
        	printf("\nСколько свободных мест должно быть в отеле?: ");
        	scanf("%d", &b);
        	int cnt;
                while (!feof(fp)){
                        cnt=fread(&t, sizeof(t), 1, fp);
                        if (t.freeplaces>=b && cnt==1)
                        	printf("%s %s %s %d звезд, %d мест, %d свободных мест\n", t.country, t.town, t.hotel, t.stars, t.places, t.freeplaces);
        	}
        	fclose(fp);
	}
}

void search(void){
        char choice;
        for(;;) {
                choice = searchmenu();
                switch(choice) {
                        case 1: c1();
                                break;
                        case 2: c2();
                                break;
                        case 3: c3();
                                break;
                        case 4: c4();
                                break;
                        case 5: c5();
                                break;
                        case 6: c6();
                                break;
                        case 7: main();
                                break;
                }
        }
}

