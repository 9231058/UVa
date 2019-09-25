#include <iostream>
#define int long long

using namespace std;

const int MAX=100+10;
const int INF=999999999;
int A[MAX];

main(){
	int input;
	while(cin>>input){
		int index=0;
		while(true){
			A[index]=input;
			cin>>input;
			index++;
			if(input==-999999)
				break;
		}
		int n=index;
		int Max=-INF;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				int prud=1;
				for(int k=i;k<=j;k++)
					prud*=A[k];
				if(prud>Max)
					Max=prud;
			}
		}
		cout<<Max<<endl;
	}
}
