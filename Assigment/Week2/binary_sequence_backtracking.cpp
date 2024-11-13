#include<stdio.h>
#define MAX 100

int a[MAX];

int check[2];
void ghinhan(int n){
	for(int i = 1;i<=n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}

int main(){
	int n;
	scanf("%d",&n);
	int k = 1;
	for(int i = 0;i<=1;i++){
		while(k>0){
			if(k == n) 
			{
			ghinhan(n);
			break;
		}
			else{
				a[k] = i;
				k++;
			}
		k--;	
		}
	}
	return 0;	
}
