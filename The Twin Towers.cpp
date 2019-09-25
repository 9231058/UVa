#include <iostream>

using namespace std;

const int MAX=100+10;
int A[MAX];
int B[MAX];
int D[MAX][MAX];

int main(){
	int i=1;
	while(true){
		int n,m;
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++)
			cin>>A[i];
		for(int i=0;i<m;i++)
			cin>>B[i];
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				D[i][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(A[i-1]==B[j-1])
					D[i][j]=D[i-1][j-1]+1;
				else if(D[i-1][j]>=D[i][j-1])
					D[i][j]=D[i-1][j];
				else
					D[i][j]=D[i][j-1];
			}
		}
		cout<<"Twin Towers #"<<i<<endl;
		cout<<"Number of Tiles : "<<D[n][m]<<endl;
		cout<<endl;
		i++;
	}
}		
