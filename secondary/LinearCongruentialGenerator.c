#include <stdio.h>
#include <time.h>
 
int rseed = 0;
time_t seconds;
 
#define RAND_MAX ((1U << 20) - 1)
 
inline int rand(){
	return (rseed = (rseed * 199999 + 2531011) & RAND_MAX) >> 7;
}

 
int main(){
	FILE *fp = fopen("input.txt", "w");
	int i;
	int num = 5; 												// num -> number of points to be generated
	seconds = time(NULL) * 295;
	rseed = seconds;
	//printf("rand max is %d\n", RAND_MAX);
 	
 	fprintf(fp, "%d\n", num);
	for (i = 0; i < num; i++)
		fprintf(fp, "%d\n", rand());
	fprintf(fp, "\n%d %d", rand(), rand());
 
	return 0;
}
