#include <iostream>

using namespace std;

const int MAX=100;
int A[MAX];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int L,num=0;
		cin>>L;
		for(int j=0;j<L;j++)
			cin>>A[j];
		for(int j=L-1;j>=0;j--){
			for(int k=0;k<j;k++){
				if(A[k]>A[k+1]){
					num++;
					int temp=A[k];
					A[k]=A[k+1];
					A[k+1]=temp;
				}
			}
		}
		cout<<"Optimal train swapping takes "<<num<<" swaps."<<endl;
	}
}
