#include<stdio.h>
#define MAX 1000000

long number[MAX+1];	
int main(){
	long count[2]= {0, 0};
	long seq_len;
	scanf("%d",&seq_len);
	for(int i = 1;i<=seq_len;i++){
		scanf("%ld",number+i);
		count[number[i]%2]++;
	}
	printf("%ld %ld", count[1], count[0]);
	return 0;
}
