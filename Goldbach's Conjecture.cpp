#include <iostream>

using namespace std;

const int MAX=1000*1000+10;
bool prime[MAX];

void prime_gen(int n){
	for(int i=2;i<=n;i++)
		prime[i]=true;
	for(int i=2;i*i<=n;i++)
		if(prime[i])
			for(int j=2;i*j<=n;j++)
				prime[i*j]=false;
}

int main(){
	prime_gen(MAX);
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;
		if(n==4){
			cout<<"4 = 2 + 2"<<endl;
			continue;
		}
		int index1=0,index2=0;
		for(int i=3;i<=(n/2);i++){
			if(prime[i]&&prime[n-i]){
				index1=i;
				index2=n-i;
				break;
			}
		}
		cout<<n<<' '<<'='<<' '<<index1<<' '<<'+'<<' '<<index2<<endl;
	}
}
