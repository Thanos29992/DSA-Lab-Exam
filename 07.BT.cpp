#include <iostream>
using namespace std;
class RUKH {
    public:
	    int data; RUKH *left, *right;
	    RUKH(int val)
		{ data=val; left=right=NULL; }
};
void in_oda(RUKH* jara) {
	if(jara==NULL) return;
	in_oda(jara->left);
	cout<<jara->data<<" ";
	in_oda(jara->right);
}
void pre_oda(RUKH* jara) {
	if(jara==NULL) return;
	cout<<jara->data<<" ";
	pre_oda(jara->left);
	pre_oda(jara->right);
}
void post_oda(RUKH* jara) {
	if(jara==NULL) return;
	post_oda(jara->left);
	post_oda(jara->right);
	cout<<jara->data<<" ";
}
int main() {
	RUKH* jara = new RUKH(69);
	jara->left = new RUKH(6);
	jara->right = new RUKH(9);
	jara->left->left = new RUKH(32);
	cout<<"In-order Traversal:\n"; 
	in_oda(jara); cout<<endl;
	cout<<"Pre-order Traversal:\n";
	pre_oda(jara); cout<<endl;
	cout<<"Post-order Traversal:\n";
	post_oda(jara);
}