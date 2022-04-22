#include <stdio.h>
#include <math.h>
#include <malloc.h>

#define N 10
void prog9_7() {
	int a[N];
	int i;
	int c = 0;
	for (i = 0; i < N; i++) {
		printf("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < N; i++) {
		printf("%d ", a[i]);
		int k = 31;
		while (k > 0) {
			if (pow(2, k) == a[i]) {
				c++;	
			}
			k--;
		}
		int l = 19;
		while (l > 0) {
			if (pow(3, l) == a[i]) {
				c++;
			}
			l--;
		}
	}
	printf("\n %d numbers", c);
}

void prog9_9() {
	const int x = 3, y = 2;
	int mas[x];
	for (int l = 0; l < x; l++) {
		mas[l] = 0;
	}
	int** array = (int**)malloc(sizeof(int*) * x);
	for (int i = 0; i < x; i++) {
		array[i] = (int*)malloc(sizeof(int) * y);
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			printf("arr[%d][%d]= ", i, j);
			scanf_s("%d", & array[i][j]);
		}
	}
	for (int i = 0; i < x; i++) {
		printf("\n");
		for (int j = 0; j < y; j++) {
			printf("%d ",array[i][j]);
		}
	}
	printf("\nchange array\n");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (array[i][j] == 0) {
				free(array[i]);
				mas[i]=1;
			}
		}
	}
	for (int i = 0; i < x; i++) {
		printf("\n");
		if (mas[i]==1) {
			continue;
		}
		for (int j = 0; j < y; j++) {
			printf("%d ", array[i][j]);
		}
	}
}


//int main() {
	//prog9_7();
	//prog9_9();
//}