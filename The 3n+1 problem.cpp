#include <iostream>

using namespace std;

long long num(long long n){
	if(n==1){
		return 1;
	}
	else if(n%2==0){
		return num(n/2)+1;
	}
	else{
		return num(3*n+1)+1;
	}
}

int main(){
	long long i,j;
	while(cin>>i>>j){
		long long n,m;
		n=min(i,j);
		m=max(i,j);
		long long Max=0;
		for(long long i=n;i<=m;++i){
			long long temp=num(i);
			if(Max<temp){
				Max=temp;
			}
		}
		cout<<i<<" "<<j<<" "<<Max<<endl;
	}
}
