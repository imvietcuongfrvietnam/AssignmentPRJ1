#include<stdio.h>
#define MAX 20

int res[MAX];

void ghinhan(int n){
	for(int i = 0;i<n;i++){
		printf("%d",res[i]);
	}
	printf("\n");
}

void Try(int k, int n){
	if(k == n) {
	ghinhan(n);
	return;}
	for(int i = 0;i<=1;i++){
		res[k] = i;
		Try(k+1,n);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	Try(0,n);
}
