#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n;
double *a;

double average(int x) {
	double sum = 0;
	for (int i = 0; i < x; i++)
	{
		sum += a[i];
	}

	return sum / x;
}


int main() {

	printf("データの個数を入力してください。\n");
	scanf_s("%d", &n);

	a =(double*) calloc(n, sizeof(double));
	if (a == NULL) {
		printf("配列用の領域が確保できませんでした。\n");
		exit(-1);
	}

	printf("データを%d個入力してください。\n",n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%lf",&a[i]);
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += pow((a[i] - average(n)), 2);
	}
	double ans;
	ans = sqrt(sum / n);

	printf("標準偏差は %lf です。\n", ans);


	free(a);

	return 0;
}

