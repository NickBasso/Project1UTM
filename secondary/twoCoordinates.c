#include <stdio.h>

void linearExtr(float x1, float y1, float x2, float y2, float x);
void polyInterLagr(float x, float (*farr)[2], int num);
void conicSection(float x, float (*farr)[2], int num);

main(){
	//freopen("input.txt", "r", stdin);
	// File input declarations
	FILE *fp;
	fp = fopen("input.txt", "r");
	
	// Core data variables declaration
	int num, i;
	float x;
	
	// Core data input and its outpout to the console for reliability verification
	fscanf(fp, "%d", &num);										// number of points
	printf("Number of (x,y) coordinate pairs is ->  %d\n\n", num);
	
	float farr[num][2];	// declaration of a float array dest designed for (x, y) data coordinates
	printf("Point coordinates data avaible (x,y):\n");
	
	for(i = 0; i < num; i++){
		//fscanf(fp, "%f%f", &farr[i][0], &farr[i][1]);
		fscanf(fp, "%f", &farr[i][1]);
		farr[i][0] = i + 1;
		
		printf("(%.1f  ;  %.1f)\n", farr[i][0], farr[i][1]);
	}
	//fscanf(fp, "%f", &x);
	x = num + 1;
	printf("\nThe x coordinate value at which needs to be predicted is - >   %.2f\n\n", x);
	printf("\n\n");
	
	//linear and Lagrange polynomial extrapolation invocation
	linearExtr(farr[num - 2][0], farr[num - 2][1], farr[num - 1][0], farr[num - 1][1], x);
	polyInterLagr(x, farr, num);
	conicSection(x, farr, num);
	
	//printf("%d", 2|3);
	
	return 0;
}

// this procedure prints the extrapolation result using linear method
void linearExtr(float x1, float y1, float x2, float y2, float x){
	float res = y1 + (x - x1) / (x2 - x1) * (y2 - y1);
	
	printf("Linear extrapolation result for x = %f is ->  %f\n", x, res);
}

// this procedure prints the extrapolation result using	interpolation polynomial in the Lagrange form method

void polyInterLagr(float x, float (*farr)[2], int num){			//float (*farr)[2] = float farr[][2]
//FILE *out2 = fopen("test2.txt", "w");
	float res = 0.0;
	float k;
	int i, j;
	
	for(j = 0; j < num; j++){
		k = 1;
		for(i = 0; i < num; i++){
			if(i != j){
				k *= (x - farr[i][0]) / (farr[j][0] - farr[i][0]);
				//fprintf(out2, "%f %f %f %f\n", farr[i][0], farr[j][0], x, k);
			}
		}
		res += farr[j][1] * k;
	}
	
	printf("Lagrange extrapolation result for x = %f is ->  %f\n", x, res);
}

// this procedure prints the extrapolation result using conic section method (my version of algo)

void conicSection(float x, float (*farr)[2], int num){
	float res, xt = 0, yt = 0;
	int i;
	
	for(i = num - 1; i >= num - 5; i--){
		xt += farr[i][0];
		yt += farr[i][1];
	}
	
	res = (yt / 5) * (x / xt * 5);
	
	printf("Conic section extrapolation result for x = %f is ->  %f\n", x, res);
}
