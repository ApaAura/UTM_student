#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float pi = 3.141592f;
float a = 1.65f;

float Q(float x)
{
    if(x<1.4f)
    {
        return pi * pow(x,2) - (7/pow(x,2));
    }
    else if(x == 1.4f)
    {
        return a * pow(x,3) + 7* sqrt(x);
    }
    return log(x + 7 * sqrt(abs(x+a)));
}
 
void displayInterval(float start, float finish, float step)
{
    //display interval using for
    for (float j = start; j <= finish; j += step)
    {
        printf("Q(%0.2f) = %0.4f\n", j, Q(j));
    }

    //display interval using while
    float i = start;
    while(i <= finish)
    {
        printf("Q(%0.2f) = %0.4f\n", i, Q(i));
        i += step;
    }

    //display interval using do while
    float k = start;
    do
    {
        printf("Q(%0.2f) = %0.4f\n", k, Q(k));
        k += step;
    } while (k <= finish);
}

int main()
{
    displayInterval(0.7f, 2.0f, 0.1f);
    return 0;
}