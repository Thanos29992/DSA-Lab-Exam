#include<iostream>
using namespace std;
void T_hanoi(int n,string s,string d,string a) {
    if(n==1) {
        cout<<"Moved disk 1 from "<<s<<" to "<<d<<endl;
        return;
    }
    T_hanoi( n-1,s,a,d);
    cout<<"Moved disk "<< n <<" from "<<s<<" to "<<d<<"."<<endl;
    T_hanoi( n-1,a,d,s);
}
int main() {
    int n;
    cout<<"Enter number:";
    cin>>n;
    T_hanoi(n,"Source","Destination","Auxillary");
    return 0;
}