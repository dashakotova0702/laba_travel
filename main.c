#include <stdlib.h>
#include <stdio.h>

int main(void) {
        char choice;
        for(;;) {
                choice = menu();
                switch(choice) {
                        case 1: enter();
                                break;
                        case 2: read();
                                break;
                        case 3: search();
				break;
			case 4: del();
				break;
			case 5: reserv();
				break;
			case 6: exit(0);
                                break;
			default: printf("Неправильно введено значение");
				break;
                }
        }

        return 0;
}

