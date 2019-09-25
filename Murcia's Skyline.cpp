#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX=1000*100;
int A[MAX];
long long W[MAX];
long long WD[MAX];
long long WU[MAX];
int backD[MAX];
int backU[MAX];

int main(){
	int N;
	cin>>N;
	for(int I=0;I<N;I++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>A[i];
			backD[i]=-1;
			backU[i]=-1;
		}
		for(int i=0;i<n;i++){
			cin>>W[i];
			WD[i]=W[i];
			WU[i]=W[i];
		}
		for(int i=0;i<n-1;i++){
			if(W[i]<0)
				continue;
			for(int j=i+1;j<n;j++){
				if(A[i]<A[j]&&W[j]>=0){
					if(WD[i]+W[j]>WD[j]){
						backD[j]=i;
						WD[j]=WD[i]+W[j];
					}
				}
				else if(A[i]>A[j]&&W[j]>=0){
					if(WU[i]+W[j]>WU[j]){
						backU[j]=i;
						WU[j]=WU[i]+W[j];
					}
				}
			}
		}
		long long Wi=0;
		long long Wd=0;
		for(int i=0;i<n;i++)
			if(Wi<WD[i])
				Wi=WD[i];
		for(int i=0;i<n;i++)
			if(Wd<WU[i])
				Wd=WU[i];
		if(Wi>=Wd)
			printf("Case %d. Increasing (%lld). Decreasing (%lld).\n",I+1,Wi,Wd);
		else
			printf("Case %d. Decreasing (%lld). Increasing (%lld).\n",I+1,Wd,Wi);
	}
}
