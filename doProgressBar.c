#include <stdio.h>

static inline void doProgess( const char *string, int step, int total ) {
	int width = 50;
	float percent = ( (float)step *  100 ) / (float)total;
	int c =(int) ( (percent / 100) * (float) width);
	printf("%s ", string);
	printf(" %3.2f%% [", percent);
	//load show bar
	int x;
	for (x = 0; x<c; x++) printf("=");
	for (x = c; x<width; x++) printf(" ");
	//go back to the previous line and clear it.
	printf("]\r");
	fflush(stdout);
}


void main() {
	printf("%ld \n", (unsigned long)0x10);
	//int total = 40;
	int step = 0;
	int i;
	for ( i = 0; i < 0x10 ; i++ ) {
		sleep(1);
		doProgess( "Progess", i+1, (int) 0x10);
	}
	/*
	while ( step < total ) {
		sleep(1);
		step++;
		doProgess( "Progess :", step, total );
	}
	*/
	puts("\nover");
}
