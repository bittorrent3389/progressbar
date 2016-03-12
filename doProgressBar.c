#include <stdio.h>

static inline void doProgess( const char *string, int step, int total ) {
	int width = 50;
	float percent = ( step *  100 ) / total;
	int c =(int) ( (percent / 100) * (float) width);
	printf("%s ", string);
	printf(" %3d%% [", (int)percent);
	//load show bar
	int x;
	for (x = 0; x<c; x++) printf("=");
	for (x = c; x<width; x++) printf(" ");
	//go back to the previous line and clear it.
	printf("]\r");
	fflush(stdout);
}


void main() {
	
	int total = 2;
	int step = 0;

	while ( step < total ) {
		sleep(1);
		step++;
		doProgess( "Progess :", step, total );
	}
	puts("\nover");
}
