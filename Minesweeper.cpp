#include <iostream>

using namespace std;

const int MAX=100*10;
int A[MAX][MAX];
bool B[MAX][MAX];

int main(){
	int index=0;
	while(true){
		int n,m;
		cin>>n>>m;
		if(n==0||m==0)
			break;
		if(index!=0)
			cout<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char temp;
				cin>>temp;
				A[i][j]=0;
				if(temp=='*')
					B[i][j]=true;
				else
					B[i][j]=false;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(B[i][j]==false){
					if(i<n-1&&B[i+1][j])
						A[i][j]++;
					if(i<n-1&&j>0&&B[i+1][j-1])
						A[i][j]++;
					if(i<n-1&&j<m-1&&B[i+1][j+1])
						A[i][j]++;
					if(j<m-1&&B[i][j+1])
						A[i][j]++;
					if(j>0&&B[i][j-1])
						A[i][j]++;
					if(i>0&&j>0&&B[i-1][j-1])
						A[i][j]++;
					if(i>0&&B[i-1][j])
						A[i][j]++;
					if(i>0&&j<m-1&&B[i-1][j+1])
						A[i][j]++;
				}
			}
		}
		cout<<"Field #"<<index+1<<":"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(B[i][j])
					cout<<"*";
				else
					cout<<A[i][j];
			}
			cout<<endl;
		}
		index++;
	}
}
