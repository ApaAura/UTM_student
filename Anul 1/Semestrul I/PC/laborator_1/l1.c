#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float a, b, t, w, s;

void readData(){
    printf("Introduceti valoarea lui A: ");
    scanf("%f",&a); 
    printf("Introduceti valoarea lui B: ");   
    scanf("%f",&b);  
    printf("Introduceti valoarea lui T: ");  
    scanf("%f",&t);    
}

float S(){
    s = exp(-b*t)*sin(a*t+b)-sqrt(abs(b*t+a));
    return s;
}

float W(){
    w = b*sin(a*t*t*cos(2*t))-1;
    return w;
}

void showData(){
    printf("S(%.2f, %.2f, %.2f) = %.2f\n", a, b, t, S());
    printf("W(%.2f, %.2f, %.2f) = %.2f", a, b, t, W());
}

int main()
{
    readData();
    showData();
    return 0;
}