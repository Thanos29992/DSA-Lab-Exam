#include <iostream>
using namespace std;
void bubblesort(int array[],int n) {
	for(int i=0; i<n-1; i++) {
		for(int j=0; j<n-1; ++j) {
			if(array[j]>array[j+1]) {
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}
void printarray(int array[],int n) {
	for(int i=0; i<n; ++i)
	{ cout<<" "<<array[i]; }
	cout<<"\n";
}
int main() {
	int data[] = {69,32,6,35,-9};
	int n = sizeof(data)/sizeof(data[0]);
	bubblesort(data,n);
	cout<<"Sorted Array in Ascending Order:\n";
	printarray(data,n); return 0;
}