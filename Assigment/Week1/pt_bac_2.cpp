//C 
#include <stdio.h> 
#include<math.h>
int main() 
{ 
    int a,  b,  c;
    scanf("%d %d %d", &a, &b, &c);
    double delta = b*b - 4*a*c;
    if(delta<0) printf("NO SOLUTION");
    else if(delta == 0) printf("%0.2lf",-(1.00*b)/(2*a));
    else printf("%0.2lf %0.2lf",  (-b - sqrt(delta))/(2*a),(-b + sqrt(delta))/(2*a));
}
