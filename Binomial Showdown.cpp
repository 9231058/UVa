#include <iostream>

using namespace std;

int gcd(int a,int b);
void divByGcd(int &a,int &b);

int main(){
	while(true){
		int n,k;
		cin>>n>>k;
		if(n==0&&k==0)
			break;
		if(k>n/2)
			k=n-k;
		int numerator=1,denominator=1,toMul,toDiv;
		for(int i=k;i>0;i--){
			toMul=n-k+i;
			toDiv=i;
			divByGcd(toMul,toDiv);
			divByGcd(numerator,toDiv);
			divByGcd(toMul,denominator);
			numerator*=toMul;
			denominator*=toDiv;
		}
		cout<<numerator/denominator<<endl;
	}
}
int gcd(int a,int b){
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
void divByGcd(int &a,int &b){
	int g=gcd(a,b);
	a/=g;
	b/=g;
}
