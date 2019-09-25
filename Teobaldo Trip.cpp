#include <iostream>

using namespace std;

const int MAX=1000+10;
bool A[MAX][MAX];
bool temp[MAX][MAX];
int N;

void multi(bool op1[MAX][MAX],bool op2[MAX][MAX]);

void power(int n){
	if(n==0){
		for(int i=0;i<N;i++)
			temp[i][i]=1;
		return;
	}
	else if(n%2==0){
		power(n/2);
		multi(temp,temp);
	}
	else{
		power(n-1);
		multi(temp,A);
	}
}
void multi(bool op1[MAX][MAX],bool op2[MAX][MAX]){
	bool T[MAX][MAX];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			T[i][j]=0;
			for(int k=0;k<N;k++){
				T[i][j]+=op1[i][k]*op2[k][j];
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			temp[i][j]=T[i][j];
		}
	}
}
int main(){
	while(true){
		int m;
		cin>>N>>m;
		if(N==0&&m==0)
			break;
		for(int i=0;i<m;i++){
			int v1,v2;
			cin>>v1>>v2;
			A[v1-1][v2-1]=1;
			A[v2-1][v1-1]=1;
		}
		int S,E,D;
		cin>>S>>E>>D;
		power(D);
		if(temp[S-1][E-1])
			cout<<"Yes, Teobaldo can travel."<<endl;
		else
			cout<<"No, Teobaldo can not travel."<<endl;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				temp[i][j]=0;
				A[i][j]=0;
			}
		}
	}
}
