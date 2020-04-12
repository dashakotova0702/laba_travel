#include "struct.h"
#include <string.h>

void enter(void)
{
        FILE *fp; //открываем файл
        tours t;
        fp = fopen("tours.bin", "ab");
        printf("Введите страну: ");
        scanf("%s", t.country);
        printf("Введите город: ");
        scanf("%s", t.town);
        printf("Введите отель: ");
        scanf("%s", t.hotel);
        printf("Сколько звезд у отеля?: ");
	      scanf("%d", &t.stars);
        printf("Сколько мест в отеле?: ");
        scanf("%d", &t.places);
        printf("Сколько свободных мест в отеле?: ");
        scanf("%d", &t.freeplaces);
        fwrite(&t, sizeof(t), 1, fp); //записываем в файл структуру
        fclose(fp); //закрываем файл
}

void read(void) {
        FILE  *fp;
	int cnt;
        if (fp=fopen("tours.bin", "rb") == NULL)
		printf("Файл пуст");
	else {
		fp = fopen("tours.bin", "rb");
        	tours t;
        	while (!feof(fp)){
                	cnt=fread(&t, sizeof(t), 1, fp);
//			printf("%d", cnt);
			if (cnt==1)
                		printf("%s %s %s %d звезд, %d мест, %d свободных мест\n", t.country, t.town, t.hotel, t.stars, t.places, t.freeplaces);
        	}
        	fclose(fp);
	}
}

void reserv(void){
	FILE  *fp;
        if (fp=fopen("tours.bin", "rb") == NULL)
		printf("Файл пуст");
	else {
		fp = fopen("tours.bin", "rb");
        	tours *t;
		t=(tours*)malloc(sizeof(tours)*100);
		printf("Какой отель хотите забронировать?: ");
		char *hotel;
		hotel=(char*)malloc(10);
		scanf("%s", hotel);
		printf("Сколько мест нужно забронировать?: ");
		int pl, i=0, c=-1;
		scanf("%d", &pl);
		int cnt;
        	while (!feof(fp)){
                	cnt=fread(&t[i], sizeof(t[i]), 1, fp); //считываем с файла структуру
                	if (strcmp(t[i].hotel, hotel)==0 && cnt==1) //когда найдется нужный отель, запоминаем i
                        	c=i;
                	i++;
        	}
		if (c=-1)
			printf("Ошибка");
		else {
			if (t[c].freeplaces<pl)
				printf("Недостаточно мест в отеле. Невозможно забронировать");
			else {
				t[c].freeplaces=t[c].freeplaces-pl;
				printf("Вы успешно забронировали %d мест(а) в отеле %s", pl, t[c].hotel);
			}
			for (i; i>=0; i--){
				fwrite(&t[i], sizeof(t[i]), 1, fp);
			}
		}
        	fclose(fp);
		free(hotel);
		free(t);
	}
}

void del(void){
	FILE  *fp;
        if (fp=fopen("tours.bin", "rb") ==  NULL)
		printf("Файл пуст");
        else {
		fp = fopen("tours.bin", "rb");
		tours *t;
		t=(tours*)malloc(sizeof(tours)*100);
		printf("Какой отель вы хотите удалить?: ");
		char *hotel;
		hotel=(char*)malloc(10);
		scanf("%s", hotel);
		int i=0, c=-1, cnt;
		while (!feof(fp)){
                	cnt=fread(&t[i], sizeof(t[i]), 1, fp); //считываем с файла структуру
			if (strcmp(t[i].hotel, hotel)==0 && cnt==1) //когда найдется нужный отель, запоминаем i
				c=i;
			i++;
		}
		if (c!=-1){
			fp = fopen("tours.bin", "wb");
			for (i; i>=0; i--){
				if(i!=c && t[i].stars!=0)
					fwrite(&t[i], sizeof(t[i]), 1, fp); //записываем структуру без этой строчки
			}
		}
		fclose(fp);
		free(t);
		free(hotel);
	}
}
