#include <iostream>

using namespace std;

long long F[2][2]={{1,1},{1,0}};
long long P[20];
long long m;
 
void power(long long n);
void multiply(long long F[2][2],long long M[2][2]);

long long fib(long long n){
  	if(n==0)
      		return 0;
  	power(n-1);
  	return F[0][0];
}
void multiply(long long F[2][2], long long M[2][2]){
  	long long x=F[0][0]*M[0][0]+F[0][1]*M[1][0];
  	long long y=F[0][0]*M[0][1]+F[0][1]*M[1][1];
  	long long z=F[1][0]*M[0][0]+F[1][1]*M[1][0];
  	long long w=F[1][0]*M[0][1]+F[1][1]*M[1][1];
  	F[0][0]=x%P[m];
  	F[0][1]=y%P[m];
  	F[1][0]=z%P[m];
  	F[1][1]=w%P[m];
} 
void power(long long n){
  	long long M[2][2]={{1,1},{1,0}};
	if(n==0){
		F[0][0]=F[1][1]=1;
		F[0][1]=F[1][0]=0;
		return;
	}
	if(n%2==0){
		power(n/2);
		multiply(F,F);
	}
  	else{
		power(n-1);
		multiply(F,M);
	}
}

main(){
	P[0]=1;
	for(int i=0;i<19;i++)
		P[i+1]=2*P[i];
	long long n;
	while(cin>>n>>m){
		cout<<fib(n)<<endl;
	}
}
