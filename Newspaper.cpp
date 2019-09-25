#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int A[256];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		getchar();
		for(int i=0;i<256;i++)
			A[i]=0;
		for(int i=0;i<n;i++){
			unsigned char tempc;
			int tempi;
			scanf("%c %d",&tempc,&tempi);
			getchar();
			A[tempc]=tempi;
		}
		int L;
		cin>>L;
		getchar();
		int sum=0;
		for(int i=0;i<L;i++){
			string S;
			getline(cin,S);
			for(int i=0;i<S.size();i++){
				sum+=A[(unsigned char)S[i]];
			}
		}
		printf("%d.%02d$\n",sum/100,sum%100);
	}
}
