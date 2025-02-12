#include <iostream>
#include <vector>
using namespace std;
void mergesorts(int array[], int p,int q,int r) {
	int n1=q-p+1; int n2=r-q;
	vector<int> L(n1); vector<int> M(n2);
    for (int i=0; i<n1; i++)
	    L[i]=array[p+i];
	for(int j = 0; j<n2;j++) 
	    M[j]=array[q+1+j];
	int i=0, j = 0,k=p;
	while(i<n1&&j<n2) {
	    if(L[i]<=M[j]) { array[k]=L[i]; i++; }
	    else { array[k]=M[j]; j++; } k++;
	}
	while(i<n1) { array[k]=L[i]; i++; k++; }
	while(j<n2) { array[k]=M[j]; j++; k++; }
}
void mergesort(int array[], int l,int r) {
	if(l<r) {
		int m=l+(r-l)/2; mergesort(array,l,m);
		mergesort(array,m+1,r); mergesorts(array,l,m,r);
	}
}
void printarray(int array[], int n) {
    cout << "Sorted Array in Ascending Order:\n";
	for (int i = 0; i < n; ++i) { cout<<array[i]<<" "; } cout<<endl;
}
int main() {
	int X[] = {69,5,6,3,9}, s=sizeof(X)/sizeof(X[0]);
	mergesort(X,0,s-1); printarray(X, s);
}