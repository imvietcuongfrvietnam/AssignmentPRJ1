//C 
#include <stdio.h> 
#define MAX 1000000

int number[MAX+1];
int main() 
{ 
    long n;
    long long count = 0;
    scanf("%d",&n);
    for(long i = 1;i<=n;i++){
        scanf("%d", number+i);
        count += number[i];
        
    }
    printf("%ld",count);
    
}
