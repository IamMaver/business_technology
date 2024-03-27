#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int p, int q, int r) {
	int n1 = q - p + 1;

	p--;
	q--;
	r--;
	// Эти три строчки кода введены из-за того, что в задании массив индексируется с 1, но в Си массивы с 0

	int* tempArray = (int*)malloc(n1 * sizeof(int));

	if (tempArray == NULL) {
		printf("There is no memory for temporary array");
		exit(1);
	}

	for (int i = 0; i < n1; i++)
		tempArray[i] = A[p + i];

	int i = 0;
	int j = q + 1;
	int k = p;

	while (i < n1 && j <= r) {
		if (tempArray[i] <= A[j]) {
			A[k] = tempArray[i];
			i++;
		}
		else {
			A[k] = A[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		A[k] = tempArray[i];
		i++;
		k++;
	}

	free(tempArray);
}

void Sort(int A[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2; // Находим середину массива
		Sort(A, p, q);       // Рекурсивно сортируем левую половину
		Sort(A, q + 1, r);    // Рекурсивно сортируем правую половину
		Merge(A, p + 1, q + 1, r + 1);    // Объединяем две отсортированные половины
	}
}

int main() {
	// Пример использования функции Sort с Merge
	int A[] = { 5,2,4,6,1,3,2,6};
	int p = 0;
	int r = 7;

	Sort(A, p, r);

	// Вывод отсортированного массива
	printf("Отсортированный массив: ");
	for (int i = p; i <= r; i++)
		printf("%d ", A[i]);

	return 0;
}
