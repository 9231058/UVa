#include <iostream>

using namespace std;

const int MAX=1000*10+10;
int A[MAX];

int main(){
	while(true){
		int n;
		cin>>n;
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			cin>>A[i];
		}
		int sum=A[0];
		int max_sum=A[0];
		for(int i=1;i<n;i++){
			if(sum<0)
				sum=A[i];
			else
				sum+=A[i];
			if(sum>max_sum)
				max_sum=sum;
		}
		if(max_sum>0)
			cout<<"The maximum winning streak is "<<max_sum<<"."<<endl;
		else
			cout<<"Losing streak."<<endl;
	}
}
