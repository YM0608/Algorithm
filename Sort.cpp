//Exchange, Quick, Merge Sort

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
using namespace std;
ifstream ifs("input.txt");

void Exchange_Sort(int arr[], int length) {
	int temp;
	for (int i = 0; i < (length - 1); i++)
	{
		for (int j = (i + 1); j < length; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void Quick_Sort(int array[], int start, int end) {

	if (start >= end) return;
	int pivot = array[start];
	int p = start + 1, q = end;
	while (p <= q) {
		while (array[p] <= pivot) { if (p > q) break; p++; }
		while (array[q] > pivot) { if (p > q) break; q--; }
		if (p >= q) break;
		swap(&array[p], &array[q]);
	}
	if (array[start] > array[q]) swap(&array[start], &array[q]);
	Quick_Sort(array, start, q - 1);
	Quick_Sort(array, q + 1, end);
}
void Merge(int arr[], int left, int mid, int right) {
	int temp[310000];
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mid)temp[k++] = arr[i++];
	while (j <= right)temp[k++] = arr[j++];
	for (int a = left; a <= right; a++)arr[a] = temp[a];

}
void Merge_Sort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Merge_Sort(arr, left, mid);
		Merge_Sort(arr, mid + 1, right);
		Merge(arr, left, mid, right);
	}
}
int main(void)
{
	int n1, n2, n3, n4, n5, n6;
	double ave1, ave2, ave3 = 0;
	int start, end;
	ifs >> n1 >> n2 >> n3 >> n4 >> n5 >> n6;
	int *arr = new int[n6];
	int *arr2 = new int[n6];
	srand((unsigned)time(NULL));
	printf("                 N=%d   |   N=%d   |   N=%d\n", n1, n2, n3);
	printf("Exchange Sort ");
	for (int i = 0; i < n1; i++) {
		arr[i] = i;
	}
	start = clock();
	Exchange_Sort(arr, n1);
	end = clock();
	printf("%5lf ", (double)(end - start));
	for (int i = 0; i < n2; i++) {
		arr[i] = i;
	}
	start = clock();
	Exchange_Sort(arr, n2);
	end = clock();
	printf("%9lf  ", (double)(end - start));
	for (int i = 0; i < n3; i++) {
		arr[i] = i;
	}
	start = clock();
	Exchange_Sort(arr, n3);
	end = clock();
	printf("%9lf\n", (double)(end - start));

	for (int i = 0; i < n1; i++) {
		arr2[i] = i;
	}
	printf("Quick Sort    ");
	start = clock();
	Quick_Sort(arr2, 0, n1 - 1);
	end = clock();
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n2; i++) {
		arr2[i] = i;
	}
	start = clock();
	Quick_Sort(arr2, 0, n2 - 1);
	end = clock();
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n3; i++) {
		arr2[i] = i;
	}
	start = clock();
	Quick_Sort(arr2, 0, n3 - 1);
	end = clock();
	printf("%9lf\n\n", (double)(end - start));
	printf("                N=%d  |   N=%d   |   N=%d\n", n4, n5, n6);
	for (int i = 0; i < n4; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n4 - 1);
	end = clock();
	ave1 += (end - start);
	printf("Merge Sort    ");
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n5; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n5 - 1);
	end = clock();
	ave2 += (end - start);
	printf("%9lf  ", (double)(end - start));
	for (int i = 0; i < n6; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n6 - 1);
	end = clock();
	ave3 += (end - start);
	printf("%8lf\n", (double)(end - start));
	for (int i = 0; i < n4; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n4 - 1);
	end = clock();
	ave1 += (end - start);
	printf("              ");
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n5; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n5 - 1);
	end = clock();
	ave2 += (end - start);
	printf("%9lf  ", (double)(end - start));
	for (int i = 0; i < n6; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n6 - 1);
	end = clock();
	ave3 += (end - start);
	printf("%8lf\n ", (double)(end - start));
	for (int i = 0; i < n4; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n4 - 1);
	end = clock();
	ave1 += (end - start);
	printf("             ");
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n5; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n5 - 1);
	end = clock();
	ave2 += (end - start);
	printf("%9lf  ", (double)(end - start));
	for (int i = 0; i < n6; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Merge_Sort(arr2, 0, n6 - 1);
	end = clock();
	ave3 += (end - start);
	printf("%8lf\n", (double)(end - start));
	ave1 = ave1 / (3);
	ave2 = ave2 / (3);
	ave3 = ave3 / (3);
	printf("average       %8lf  %10lf  %10lf\n\n", ave1, ave2, ave3);
	ave1 = 0; ave2 = 0; ave3 = 0;
	printf("Quick Sort    ");
	for (int i = 0; i < n4; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n4 - 1);
	end = clock();
	ave1 += (end - start);
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n5; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n5 - 1);
	end = clock();
	ave2 += (end - start);
	printf("%7lf  ", (double)(end - start));
	for (int i = 0; i < n6; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n6 - 1);
	end = clock();
	ave3 += (end - start);
	printf("%9lf\n", (double)(end - start));
	printf("              ");
	for (int i = 0; i < n4; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n4 - 1);
	end = clock();
	ave1 += (end - start);
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n5; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n5 - 1);
	end = clock();
	ave2 += (end - start);
	printf("%7lf  ", (double)(end - start));
	for (int i = 0; i < n6; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n6 - 1);
	end = clock();
	ave3 += (end - start);
	printf("%9lf\n", (double)(end - start));
	printf("              ");
	for (int i = 0; i < n4; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n4 - 1);
	end = clock();
	ave1 += (end - start);
	printf("%8lf  ", (double)(end - start));
	for (int i = 0; i < n5; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n5 - 1);
	end = clock();
	ave2 += (end - start);
	printf("%7lf  ", (double)(end - start));
	for (int i = 0; i < n6; i++) {
		arr2[i] = rand();
	}
	start = clock();
	Quick_Sort(arr2, 0, n6 - 1);
	end = clock();
	ave3 += (end - start);
	printf("%9lf\n", (double)(end - start));
	ave1 = ave1 / (3);
	ave2 = ave2 / (3);
	ave3 = ave3 / (3);
	printf("average       %9lf  %8lf  %9lf\n", ave1, ave2, ave3);

	return 0;
}