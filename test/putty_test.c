#define _POSIX_C_SOURCE 200809L

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "../src/putty.c"

#define PI 3.14159265358979323846

int main(int argc, char *argv[])
{
	Win win;
	char s;

	show_scr();
	get_win_title(&win);

	sleep(3);
	//scanf("%1s", &s);
	exit_scr();

	return 0;
}
