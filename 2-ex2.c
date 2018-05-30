#include<stdio.h>

int main() {
	
	int a[2];
	int *p;

	p = a;
	a[0] = 1;
	*(p + 1) = a[0] + 1;

	printf("%d, %d, %d, %d", &a[0], &a[1], p, (p + 1));

	return 0;
}

