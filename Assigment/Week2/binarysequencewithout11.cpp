#include<stdio.h>
#define MAX 21

int res[MAX];

void ghinhan(int n){
	for(int i = 1;i<=n;i++){
		printf("%d",res[i]);
	}
	printf("\n");
}

void Try(int k, int n){
	if(k == n+1){
		ghinhan(n);
		return;
	}
	for(int i = 0;i<=1;i++){
		if(res[k-1]*i){
			break;
		}
		res[k] = i;
		Try(k+1,n);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	res[0] = 0;
	Try(1,n);
}
