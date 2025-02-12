#include <iostream>
using namespace std;
void printarray(int array[], int n) {
	for (int i = 0; i < n; ++i)
	{ cout << " " << array[i]; } cout << "\n";
}
void insertionsort(int array[], int n) {
	for (int i=1; i<n; ++i) {
		int temp=array[i];
		int j=i-1;
		while (j >= 0 && array[j]>temp) {
			array[j+1] = array[j];
			j = j-1;
		} array[j+1] = temp;
	}
}
int main() {
	int data[] = {69,31,6,28,9};
	int n = sizeof(data) / sizeof(data[0]);
	insertionsort(data, n);
	cout << "Sorted Array in Ascending Order:\n";
	printarray(data, n); return 0;
}