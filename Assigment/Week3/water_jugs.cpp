#include<stdio.h>
#include<math.h>

int snt(int n){
	for(int i = 2;i<=sqrt(n);i++){
		if(n%i == 0) return 0;
	}
	return 1;
}

int tichCacUoc(int k){
	int res = 1;
	for(int i = 2;i<=sqrt(k);i++){
		if(k%i == 0 && snt(i)) res*=i; 
	}
}

int UCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

 
    if (c == a || c == b) {
        printf("1");
        return 1;
    }
   
    if (a > b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int k = UCLN(a, b);

   
    if (c % k != 0) {
        printf("-1");
        return 1;
    }
   
	a = a/k;
	b = b/k;
	c = c/k;
	k = 10000;
	for(int i = 1;i<=b;i++){
		for(int j = 1;j<=a;j++){
			if(abs(a * i - b*j) == c)
			{
				if(k>(i+j)*2-2) k = (i+j) *2 - 2;
			}
		}
	}
	printf("%d", k);
    return 0;
}

