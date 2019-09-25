#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		long long n;
		cin>>n;
		vector <int> V;
		if(n==0){
			cout<<"Case #"<<i+1<<": 0"<<endl;
			continue;
		}
		while(n!=0){
			V.push_back(abs(n%(-2)));
			if(n<0&&((-n)%2==1))
				n=n/(-2)+1;
			else
				n=n/(-2);
		}
		cout<<"Case #"<<i+1<<": ";
		for(int i=V.size()-1;i>=0;i--){
			cout<<V[i];
		}
		cout<<endl;
	}
}
