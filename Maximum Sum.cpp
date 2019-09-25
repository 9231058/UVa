#include <iostream>

using namespace std;

const int MAX=100+10;
int A[MAX][MAX];
long long D[MAX][MAX];
long long max_sum_all;

long long squareSum(int i,int j,int k);
void D1(int i,int j,int n);


int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	for(int i=0;i<n;i++){
		long long sum=0;
		for(int j=0;j<n;j++){
			if(i>0)
				D[i][j]=D[i-1][j]+sum+A[i][j];
			else
				D[i][j]=sum+A[i][j];
			sum=sum+A[i][j];
		}
	}
	max_sum_all=A[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			D1(i,j,n);
		}
	}
	cout<<max_sum_all<<endl;
}
void D1(int i,int j,int n){
	long long sum=squareSum(i,j,0);
	long long max_sum=squareSum(i,j,0);
	for(int k=1;k<n;k++){
		if(sum<0)
			sum=squareSum(i,j,k);
		else
			sum+=squareSum(i,j,k);
		if(sum>max_sum)
			max_sum=sum;
	}
	if(max_sum>max_sum_all)
		max_sum_all=max_sum;
}
long long squareSum(int i,int j,int k){	//|i| bigger than |j|
	if(i==j)
		return A[i][k];
	if(j>0&&i>0&&k>0)
		return D[i][k]-D[i][k-1]-D[j-1][k]+D[j-1][k-1];
	else if(j>0&&i>0)
		return D[i][k]-D[j-1][k];
	else if(i>0&&k>0)
		return D[i][k]-D[i][k-1];
	else if(i>0)
		return D[i][k];
}
