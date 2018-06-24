#include <stdio.h>

int main()
{
    int seconds, s, m, h;
    
    printf("Input seconds: ");
    scanf("%d", &seconds);
    h = seconds / 3600;
    m = (seconds - h * 3600) / 60;
    s = seconds - h * 3600 - m * 60;
    
    printf("%d:%d:%d", h, m, s);
    
    return 0;
}