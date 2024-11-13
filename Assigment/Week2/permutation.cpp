#include<stdio.h>
#define MAX 40
int check[MAX];

int res[MAX];
void ghinhan(int n){
	for(int i = 1;i<n;i++){
		printf("%d ", res[i]);
	}
	printf("\n");
}

void Try(int k, int n){
	if(k == n){
		ghinhan(n);
		return;
	}
	for(int i = 2;i<=n;i++){
		if(check[i] == 0){
			res[k] = i;
			check[i] = 1;
			Try(k+1, n);
			check[i] = 0;
		}
		else continue;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	
	Try(1,n);
	
}
