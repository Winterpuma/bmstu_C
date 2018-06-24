
#include <stdio.h>

#include <stdlib.h>



float func(const float *ab, const float *ae)

{
    
	float element = 1;
    
	float sum = 0;
    
	while (ab < ae)
    
	{
        
		element *= *ab;
        
		sum += element;
        
		if (*ab < 0)
            
			break;
        
		ab++;
    
	}
    
	return sum;

}