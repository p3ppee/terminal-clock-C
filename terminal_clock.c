#include <stdio.h>
#include <sys/ioctl.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h> 


const char *punti[5] = {
    "        ",
    "   ██   ",
    "        ",
    "   ██   ",
    "        "
};

const char *digits[10][5] = {
    // 0
    {
        " ██████ ",
        "██    ██",
        "██    ██",
        "██    ██",
        " ██████ "
    },

    {
        "   ██   ",
        " ████   ",
        "   ██   ",
        "   ██   ",
        " ██████ "
    },

    {
        " ██████ ",
        "██    ██",
        "     ██ ",
        "  ████  ",
        "████████"
    },

    {
        "███████ ",
        "      ██",
        " ██████ ",
        "      ██",
        "███████ "
    },

    {
        "██    ██",
        "██    ██",
        "████████",
        "      ██",
        "      ██"
    },

    {
        "████████",
        "██      ",
        "███████ ",
        "      ██",
        "███████ "
    },

    {
        " ██████ ",
        "██      ",
        "███████ ",
        "██    ██",
        " ██████ "
    },

    {
        "████████",
        "     ██ ",
        "    ██  ",
        "   ██   ",
        "  ██    "
    },

    {
        " ██████ ",
        "██    ██",
        " ██████ ",
        "██    ██",
        " ██████ "
    },

    {
        " ██████ ",
        "██    ██",
        " ███████",
        "      ██",
        " ██████ "
    }
};


int main() {
	time_t orario;
    struct winsize w;
    int righe, colonne;
    int righetot, colonnetot;
    int x, y;
	int hour, min, sec;
	int flag, cifra_1h, cifra_2h;
    int cifra_1m, cifra_2m;
    int cifra_1s, cifra_2s;
    int i, j;
	flag = 1;

    /*righe e colonne utilizzate dal print dell'orologio*/
    righe = 5;
    colonne = 78;

    ioctl(0, TIOCGWINSZ, &w);
    righetot = w.ws_row;
    colonnetot = w.ws_col;

    /*calcolo dove iniziare a stampare l'orologio*/
    x = (colonnetot - colonne) / 2;
    y = (righetot - righe) /2;

    /*printf("\033[31m");*/ /*colore rosso*/
    system("clear");

    while (flag) {
        printf("\033[2J");
        /*printf("\033[H"); serve a portare il cursore in alto a sinistra del terminale */
        printf("\033[%d;%dH", y, x); /*porto il cursore nelle coordinate x, y */
    	orario = time(NULL);

    	struct tm *local_time;

    	local_time = localtime(&orario);

        /*
    	printf("anno: %d\n", local_time->tm_year + 1900);
    	printf("mese: %d\n", local_time->tm_mon + 1);
    	printf("giorno: %d\n", local_time->tm_mday);

    	printf("%d:%d \n", local_time->tm_hour, local_time->tm_min);
        */

    	hour = (*local_time).tm_hour;
    	min = (*local_time).tm_min;
    	sec = (*local_time).tm_sec;


    	/*stampo l'ora con un ciclo for*/

        cifra_1h = hour /10;
        cifra_2h = hour % 10;
        cifra_1m = min /10;
        cifra_2m = min % 10;
        cifra_1s = sec /10;
        cifra_2s = sec % 10;
        

        printf("\n");
        for (j = 0; j < 5; j++){
            printf("%s  ", digits[cifra_1h][j]);
            printf("%s  ", digits[cifra_2h][j]);
            printf("%s  ", punti[j]);
            printf("%s  ", digits[cifra_1m][j]);
            printf("%s  ", digits[cifra_2m][j]);
            printf("%s  ", punti[j]);
            printf("%s  ", digits[cifra_1s][j]);
            printf("%s  ", digits[cifra_2s][j]);
            printf("\n");
        } 
        printf("\n");
        sleep(1);
        /* posso anche usare system("clear");, con la libreria stdlib.h*/
    }

	return 0;
}