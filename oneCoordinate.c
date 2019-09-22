// connecting libraries necessary for successful compilation and launch

//stdio.h stands for "standard input output" header file
#include <stdio.h>

// main algorithm implementation invocation functions
void linearTwoPointsExtr();
void linearDeltaSumExtr();
void linearDeltaCoefExtr();
void conicSectionExtr();
void polynomLagrExtr();

// main declarations for global scope usage
int numElem;			// number of elements
float arr[10000 + 5];	// float-type array of 10000 + 5 elements 

// main() is the program entry point
main(){
	//freopen("input.txt", "r", stdin);
	
	// File input declarations
	FILE *fp;
	fp = fopen("input.txt", "r");
	
	// entering data from the file
	int i;
	
	fscanf(fp, "%d", &numElem);
	
	for(i = 0; i < numElem; i++){
		fscanf(fp, "%f", &arr[i]);
	}
	
	// all provided algorithm implementation invocations
	// result outputs are done inside invoked functions
	
	linearTwoPointsExtr();
	linearDeltaSumExtr();
	linearDeltaCoefExtr();
	conicSectionExtr();
	polynomLagrExtr();
	
	return 0;
}
/*
			  Linear extrapolation for two last numbers in the array:
	y1 - value of the array element at a lower index (lower index = first point index)
	longXDelta - difference between index at which value to be extrapolated and first point index
	shortXDelta - difference between index at second point and index at first point
	yDelta - difference between array values at first and second point indices
	result: answer given basing on that function value dependency of argument is linear
*/

void linearTwoPointsExtr(){
	float y1 = arr[numElem - 2];
	float longXDelta = (numElem + 1) - (numElem - 1);
	float shortXDelta = numElem - (numElem - 1);
	float yDelta = arr[numElem - 1] - arr[numElem - 2];
	float result = y1 + longXDelta / shortXDelta * yDelta;
	
	printf("Linear extrapolation result:\t\t\t\t\t       %f\n", result);
}

/*			  Linear delta sum extrapolation:
	delta - sum of all differences between two consecutive array elements
	averageDelta - average of all differences between two consecutive array elements
	result: averageDelta + last array element value
*/

void linearDeltaSumExtr(){
	int i;
	float delta = 0.0, averageDelta, result;
	
	for(i = 1; i < numElem; i++){
		delta += arr[i] - arr[i - 1];
	}
	
	averageDelta = delta / (numElem - 1);
	
	result = arr[numElem - 1] + averageDelta;
	
	printf("Linear delta sum extrapolation result:\t\t\t\t       %f\n", result);
}

/*			  Linear delta coefficient extrapolation:
	delta - sum of all coefficients that represent
		division of current array element on the previous
	averageDelta - average of all coefficients described in delta
	result: last array element value multiplied by averageDelta
*/

void linearDeltaCoefExtr(){
	int i;
	float delta = 0.0, averageDelta, result;
	
	for(i = 1; i < numElem; i++){
		delta += arr[i] / arr[i - 1];
	}
	
	averageDelta = delta / (numElem - 1);
	result = arr[numElem - 1] * averageDelta;
	
	printf("Linear delta average multiplication cofficient extrapolation result:   %f\n", result);
}

/*  		  Conic section extrapolation:
	xt - stores the sum of all five last x coordinates 
		(which is sum of all array element indices from 1 to number of elements inclusive in this specific task)
	yt - stores the sum of last five numbers given in the input 
	xAvg - average x-coordinate value obtained from the numbers in xt
	yAvg - average y-coordinate value obtained from the numbers in yt 
		(five last numbers in the input)
	result: multiplication of x and y coordinate averages
		multiplied by the number of points taken in examination
*/

void conicSectionExtr(){
	float result, xt = 0, yt = 0;
	float yAvg = 0.0, xAvg = 0.0;
	int i;
	
	for(i = numElem - 1; i >= numElem - 5; i--){
		xt += i + 1;
		yt += arr[i];
	}
	
	xAvg = (numElem + 1) / xt;
	yAvg = yt / 5;

	result = yAvg * xAvg * 5;
	
	printf("Conic section extrapolation result:\t\t\t\t       %f\n", result);
} 

/*  		  Lagrange polynomial extrapolation:
	x - point, value at which needs to be extrapolated
	k - Lagrange coefficient obtained by multiplying results
		between all pairs of x-coordinates where one is obligatory not equal to the other
	result: equals to the sum of all k-coefficients multiplied by the current y-coordinate value
*/

void polynomLagrExtr(){						
//FILE *out1 = fopen("test1.txt", "w");
	float result = 0.0;
	float k;															  
	float x = numElem + 1; 						 						  
	int i, j;
	
	for(j = 0; j < numElem; j++){
		k = 1;
		for(i = 0; i < numElem; i++){
			if(i != j){
				k *= (x - (i + 1)) / ((j + 1) - (i + 1));
				//fprintf(out1, "%d %d %f %f\n", i + 1, j + 1, x, k);
			}
		}
		result += arr[j] * k;
	}
	
	printf("Lagrange extrapolation result:\t\t\t\t\t       %f\n", result);
}

