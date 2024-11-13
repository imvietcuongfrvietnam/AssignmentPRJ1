#include<stdio.h>

long fibo[21];

int fibec(int n){
	if(n == 1 || n == 0){
		fibo[n] = n;
	}
	else if( !fibo[n] ){
		fibo[n] = fibec(n-1) + fibec(n-2);
	}
	return fibo[n];
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%ld",fibec(n-1));
}
