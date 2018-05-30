#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
	char name[32];
	int *subject;
}seimitsu;




int main() {
	//宣言
	seimitsu *student;
	int SUM=0;
	int pn, sn;
	printf("人数を入力してください。:");
	scanf_s("%d", &pn);
	printf("\n");
	printf("科目数を入力してください。:");
	scanf_s("%d", &sn);
	printf("\n");
	

	//アドレス確保
	student = (seimitsu*) calloc(pn, sizeof(seimitsu));
	if (student == NULL) {
		printf("配列用の領域が確保できませんでした。\n");
		exit(-1);
	}
	for (int i = 0; i < pn; i++)
	{
		student[i].subject =(int*) calloc(sn, sizeof(int));
		if (student[i].subject == NULL) {
			printf("配列用の領域が確保できませんでした。\n");
			exit(-1);
		}
	}

	//入力
	
	for (int i = 0; i < pn; i++)
	{
		printf("%d人目の名前を入力してください。:", i+1);
		scanf_s("%s", student[i].name);
		printf("\n");
	}
	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < sn; j++)
		{
			printf("%d人目の%d教科目の点数を入力してください。:", i+1,j+1);
			scanf_s("%d", student[i].subject[j]);
			printf("\n");
		}
	}

	//計算と出力
	for (int i = 0;	i < pn; i++)
	{
		int sum = 0;
		for (int j = 0; j < sn; j++)
		{
			sum += student[i].subject[j];
		}
		SUM += sum;
		double ave = sum*1.0 / sn;
		printf("%s : Sum %d, Average : %lf\n", student[i].name, sum, ave);
	}

	printf("Total : Sum %d, Average : %lf\n", SUM, SUM*1.0/(pn*sn));
	




	//アドレス解放
	for (int i = 0; i < pn; i++)
	{
		free(student[i].subject);
	}
	free(student);


	return 0;
}

