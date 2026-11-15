#include <stdio.h>
#include <time.h>
#define DIM 100

const char *digits[10][5] = {
    // 0
    {
        " ██████ ",
        "██    ██",
        "██    ██",
        "██    ██",
        " ██████ "
    },

    // 1
    {
        "   ██   ",
        " ████   ",
        "   ██   ",
        "   ██   ",
        " ██████ "
    },

    // 2
    {
        " ██████ ",
        "██    ██",
        "     ██ ",
        "  ████  ",
        "████████"
    },

    // 3
    {
        "███████ ",
        "      ██",
        " ██████ ",
        "      ██",
        "███████ "
    },

    // 4
    {
        "██    ██",
        "██    ██",
        "████████",
        "      ██",
        "      ██"
    },

    // 5
    {
        "████████",
        "██      ",
        "███████ ",
        "      ██",
        "███████ "
    },

    // 6
    {
        " ██████ ",
        "██      ",
        "███████ ",
        "██    ██",
        " ██████ "
    },

    // 7
    {
        "████████",
        "     ██ ",
        "    ██  ",
        "   ██   ",
        "  ██    "
    },

    // 8
    {
        " ██████ ",
        "██    ██",
        " ██████ ",
        "██    ██",
        " ██████ "
    },

    // 9
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
	int flag;
	flag = 1;

	orario = time(NULL);

	struct tm *local_time;

	local_time = localtime(&orario);

	printf("anno: %d\n", local_time->tm_year + 1900);
	printf("mese: %d\n", local_time->tm_mon + 1);
	printf("giorno: %d\n", local_time->tm_mday);

	printf("%d:%d \n", local_time->tm_hour, local_time->tm_min);

	hour = (*local_time).tm_hour;
	min = (*local_time).tm_min;
	sec = (*local_time).tm_sec;



	if (hour == 16) {
		printf(" ██  ██████\n███ ██\n ██ ███████\n ██ ██    ██\n ██  ██████");
	}
	printf("%s")


	/*stampo l'ora con un ciclo*/





	while (flag) {
		if (hour > 0)
			flag = 1;
		else
			flag = 0;

		if (flag == 1){

		}







	}

	return 0;
}