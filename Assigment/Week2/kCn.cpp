#include<stdio.h>
#define MAX 1000000007

long kCn[1000][1000];

long ComputekCn(int n, int k){
	if(n == k || k == 0) return 1;
	if(!kCn[k][n]){
		kCn[k][n] = (ComputekCn(n-1,k-1) + ComputekCn(n-1,k))%MAX;
	}
	return kCn[k][n];
 
}
int main(){
	int n, k;
	scanf("%d %d",&k, &n);
	printf("%ld",ComputekCn(n,k));
	return 0;
}
