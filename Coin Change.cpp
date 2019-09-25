#include <iostream>

using namespace std;

const int MAX=1000*100;
long long D[MAX+1];
int C[5]={50,25,10,5,1};

int main(){
	int n;
	while(cin>>n){
		D[0]=1;
		for(int i=1;i<=n;i++)
			D[i]=0;
		for(int i=0;i<5;i++){
			int c=C[i];
			for(int j=c;j<=n;j++)
				D[j]+=D[j-c];
		}
		cout<<D[n]<<endl;
	}
}
