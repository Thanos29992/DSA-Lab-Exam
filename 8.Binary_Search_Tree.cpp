#include <iostream>
using namespace std;
class RUKH {
    public:
	    int data; RUKH *left, *right;
	    RUKH(int val)
		{ data=val; left=right=NULL; }
};
void in_oda(RUKH* jara) {
	if(jara==NULL)return; in_oda(jara->left);
	cout<<jara->data<<" "; in_oda(jara->right);
}
RUKH* INS(RUKH* jara,int val) {
	if(jara==NULL)
		return new RUKH(val);
	if(jara->data<val)
		jara->right=INS(jara->right,val);
	else
		jara->left=INS(jara->left,val);
	return jara;
}
bool SRC(RUKH* jara,int val) {
	if(jara==NULL) return false;
	if(jara->data==val) return true;
	if(jara->data<val) return SRC(jara->right,val);
	return SRC(jara->left,val);
}
RUKH* SUCC(RUKH* curr) {
	// 
	curr=curr->right;
	while(curr!=NULL && curr->left != NULL)
		curr=curr->left;
	return curr;
}
void DEL(RUKH* &jara, int val) {
	if(jara==NULL) return ;
	if(jara->data>val) { DEL(jara->left,val); }
	else if(jara->data<val) { DEL(jara->right,val); }
	else {
		if(jara->left==NULL) {
			RUKH* temp = jara->right;
			delete jara; jara = temp;
		}
		else if(jara->right==NULL) {
			RUKH* temp = jara->left;
			delete jara; jara = temp;
		}
		else {
			RUKH* suc = SUCC(jara);
			jara->data = suc->data;
			DEL(jara->right, suc->data);
		}
	}
}
int main() {
	RUKH* jara = new RUKH(50);
	INS(jara,30); INS(jara,20); INS(jara,40);
	INS(jara,70); INS(jara,60); INS(jara,80);
	in_oda(jara); cout<<endl;
	cout<<"69 "<<(SRC(jara,69)?"Found\n":"Not Found\n");
	cout<<"50 "<<(SRC(jara,50)?"Found\n":"Not Found\n");
	DEL(jara,20); in_oda(jara); cout<<endl;
	DEL(jara,70); in_oda(jara); return 0;
}