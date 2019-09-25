#include <iostream>
#include <vector>
#include <memory.h>
#include <fstream>

using namespace std;

ofstream fout("primes.out");
const int MAX=1000*1000*1000+10;
vector <bool> prime;
vector <int> primeV;

void prime_gen(int n){
	prime[0]=true;
	for(int i=2;i*i<=n;i++)
		if(!prime[i]){
			for(int j=2;i*j<=n;j++)
				prime[i*j]=true;
			fout<<i<<" , ";
		}
}
void prime_factors(int n){
	if(n<0){
		cout<<"-1 * ";
		n*=-1;
	}
	int i=0;
	while((primeV[i])*(primeV[i])<=n){
		if(n%primeV[i]==0){
			n/=primeV[i];
			cout<<primeV[i]<<" * ";
			i=0;		}
		else
			i++;
	}
	if(n>1)
		cout<<n;
	cout<<endl;
}
int main(){
	prime.resize(MAX+1);
	prime_gen(MAX);
	cerr<<"salam"<<endl;
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;
		cout<<n<<" = ";
		prime_factors(n);
	}
}
