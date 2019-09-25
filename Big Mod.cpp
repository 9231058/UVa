#include <iostream>

using namespace std;

long long bigMod(long long B,long long P,long long M);
long long square(long long N);

int main(){
	int i=0;
	long long B,P,M;
	while(cin>>B>>P>>M){
		cout<<bigMod(B,P,M)<<endl;
	}
}
long long bigMod(long long B,long long P,long long M){
	if(P==0){
		return 1;
	}
	else if(P%2==0){
		return square(bigMod(B,P/2,M))%M;
	}
	else{
		return ((B%M)*bigMod(B,P-1,M))%M;
	}
}
long long square(long long N){
	return N*N;
}
