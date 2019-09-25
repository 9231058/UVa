#include <iostream>

using namespace std;

const int MAX=1000;
const int MOD=1000*1000;
int D[MAX][MAX];

int main(){
	while(true){
		int n,m;
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				D[i][j]=0;
		for(int i=1;i<=m;i++)
			D[0][i]=1;
		for(int i=1;i<=n;i++)
			D[i][1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=0;k<=n;k++){
					if(i>=k&&j>1){
						D[i][j]+=(D[i-k][j-1]%MOD);
						D[i][j]%=MOD;
					}
				}
			}
		}
		cout<<D[n][m]%MOD<<endl;
	}
}	
