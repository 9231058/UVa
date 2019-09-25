#include <iostream>

using namespace std;

const int MAX=10000*10;
int A[MAX];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		for(int i=0;i<n-1;i++){
			cin>>A[i];
		}
		long long sum=A[0],max_sum=A[0];
		int max_start=0,start=0;
		int max_end=1,end=1;
		for(int i=1;i<n-1;i++){
			if(sum<0){
				sum=A[i];
				start=i;
				end=i+1;
			}
			else{
				sum+=A[i];
				end++;
			}
			if(sum>max_sum){
				max_sum=sum;
				max_start=start;
				max_end=end;
			}
			if((sum==max_sum)&&(max_end-max_start)<(end-start)){
				max_start=start;
				max_end=end;
			}
			if((sum==max_sum)&&((max_end-max_start)==(end-start))&&(start<max_start)){
				max_start=start;
				max_end=end;
			}
		}
		if(max_sum<=0)
			cout<<"Route "<<i+1<<" has no nice parts"<<endl;
		else
			cout<<"The nicest part of route "<<i+1<<" is between stops "<<max_start+1<<" and "<<max_end+1<<endl;
	}
}
