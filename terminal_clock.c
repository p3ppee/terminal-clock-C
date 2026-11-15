#include <stdio.h>
#include <time.h>
#define DIM 100

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
	int hour, min, sec;
	char num_1[DIM + 1];
	int flag, cifra_1h, cifra_2h;
    int cifra_1m, cifra_2m;
    int cifra_1s, cifra_2s;
    int i, j;
	flag = 1;

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


	/*stampo l'ora con un ciclo*/

    cifra_1h = hour /10;
    cifra_2h = hour % 10;
    cifra_1m = min /10;
    cifra_2m = min % 10;
    cifra_1s = sec /10;
    cifra_2s = sec % 10;
    

    /*
    for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
            if (i == cifra_1)
                printf("%d  ", digits[i][j]);
            if ()
        }
    }
    */

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


	return 0;
}