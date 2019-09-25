#include <iostream>

using namespace std;

const int MAX=100;
int A[MAX];
int D[MAX];
int base[MAX];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int temp;
		cin>>temp;
		base[i+1]=temp-1;
	}
	int temp;
	while(cin>>temp){
		A[temp-1]=1;
		D[0]=1;
		for(int i=1;i<N;i++){
			int temp;
			cin>>temp;
			A[temp-1]=i+1;
			D[i]=1;
		}
		for(int i=0;i<N-1;i++){
			for(int j=i+1;j<N;j++){
				if(base[A[i]]<base[A[j]]){
					if(D[i]+1>D[j]){
						D[j]=D[i]+1;
					}
				}
			}
		}
		int Max=0;
		for(int i=0;i<N;i++){
			if(D[i]>Max){
				Max=D[i];
			}
		}
		cout<<Max<<endl;
	}
}
