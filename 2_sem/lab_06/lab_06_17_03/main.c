#include <stdio.h>

#include <stdlib.h>


#include "func.h"

#define N 100


int main()

{

	FILE *f = fopen("data.txt", "r");
    
	float a[N];
    
	float *ae;
    
	ae = a;
    
	float result;
    
	while (fscanf(f, "%f", ae))
    
	{
        
		if (feof(f))
            
			break;
        
		ae++;
        
		if ((ae - a) == N)
            
			break;
    
	}
    
	result = func(a, ae);
    
	printf("\nResult: %f", result);
    
	return 0;

}
