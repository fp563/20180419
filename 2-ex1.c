#include<stdio.h>

int main() {
	
	int a, b;
	int *p;

	p = &a;

	
	b = *p + 1;

	printf("%d %d %d \n", &a, &b, p);

	p = &b;
	printf("%d %d %d \n", &a,& b, p);

	return 0;
}

