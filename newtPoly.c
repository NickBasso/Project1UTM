#include <stdio.h>

void polynomNewtIntr();

int numElem;		
float arr[10000 + 5];	

main(){
	
	FILE *fp;
	fp = fopen("input.txt", "r");

	int i;
	
	fscanf(fp, "%d", &numElem);
	
	for(i = 1; i <= numElem; i++){
		fscanf(fp, "%f", &arr[i]);
	}
	
	polynomNewtIntr();
	
	return 0;
}

void polynomNewtIntr()
{
    float p[10], f=arr[1], f1=1, f2=0;
    int k=numElem+1,i,j=1;
 
    do
    {
        for (i=1;i<=numElem-1;i++)
        {
            p[i] = ((arr[i+1]-arr[i])/j);
            arr[i]=p[i];
        }
        f1=1;
        for(i=1;i<=j;i++)
            {
                f1*=(k-i);
            }
        f2+=(arr[1]*f1);
        numElem--;
        j++;
    }
 	while(numElem!=1);
    f+=f2;
    printf("Newton Polynomial result:\t\t\t\t %f", f);
}
