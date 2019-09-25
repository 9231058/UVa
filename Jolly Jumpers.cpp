#include <iostream>

using namespace std;

const int MAX=4000*10;
bool B[MAX];
int A[MAX];

int abs(int n){
	return n>0?n:-n;
}

int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		for(int i=0;i<=n;i++){
			B[i]=false;
		}
		for(int i=0;i<n-1;i++){
			B[abs(A[i]-A[i+1])]=true;
			cerr<<abs(A[i]-A[i+1])<<endl;
		}
		bool flag=true;
		for(int i=1;i<=n-1;i++){
			if(B[i]==false){
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<"Jolly"<<endl;
		else
			cout<<"Not jolly"<<endl;
	}
}
