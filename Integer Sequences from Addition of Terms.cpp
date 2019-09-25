#include <iostream>

using namespace std;

const int MAX=1000;
int A[MAX];

long long power(int n,int m){
	if(m==0)
		return 1;
	if(m%2==1)
		return n*power(n,m-1);
	else{
		long long temp=power(n,m/2);
		return temp*temp;
	}
}
long long value(int x,int n){
	long long answer=0;
	for(int i=0;i<=n;i++)
		answer+=A[i]*power(x,i);
	return answer;
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			cin>>A[i];
		}
		int d;
		int k;
		cin>>d>>k;
		int check;
		if(k%d==0)
			check=k/d;
		else
			check=k/d+1;
		int index=1;
		int sum=0;
		while(check>sum){
			sum+=index;
			index++;
		}
		cerr<<index-1<<endl;
		cout<<value(index-1,n)<<endl;
	}
}
