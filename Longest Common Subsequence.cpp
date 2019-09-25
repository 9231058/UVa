#include <iostream>
#include <string>

using namespace std;

const int MAX=1000+10;
int D[MAX][MAX];

int main(){
	string S1;
	while(getline(cin,S1)){
		string S2;
		getline(cin,S2);
		int n=S1.size();
		int m=S2.size();
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				D[i][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(S1[i-1]==S2[j-1])
					D[i][j]=D[i-1][j-1]+1;
				else if(D[i-1][j]>=D[i][j-1])
					D[i][j]=D[i-1][j];
				else
					D[i][j]=D[i][j-1];
			}
		}
		cout<<D[n][m]<<endl;
	}
}
