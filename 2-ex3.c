#include<stdio.h>
#include<stdlib.h>

int main() {
	
	int a[2];
	int *p;

	p = calloc(2, sizeof(int));

	if (p == NULL) {
		printf("ERROR");
		return 0;
	}
	a[0] = 1;
	a[1] = 2;
	*p = a[0];
	*(p + 1) = a[1];
	printf("%d, %d, %d, %d", &a[0], &a[1], p, (p + 1));
	free(p);

	return 0;
}

