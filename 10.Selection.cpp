#include <iostream>
using namespace std;
void swap(int *a,int *b)
{ int temp=*a; *a=*b; *b=temp; }
void print_array(int array[],int n) {
	for(int i=0; i<n; ++i)
	{ cout<<" "<<array[i]; } cout<<endl;
}
void selection_sort(int array[],int n) {
	for(int i=0; i<n-1; ++i) {
		int min=i;
		for(int j=i+1; j<n; j++) {
			if(array[j]<array[min])
				min=j;
		} swap(&array[min],&array[i]);
	}
}
int main() {
	int data[] = {69,12,6,16,9};
	int n = sizeof(data)/sizeof(data[0]);
	selection_sort(data,n);
	cout<<"Sorted Array in Ascending Order:\n";
	print_array(data,n); return 0;
}