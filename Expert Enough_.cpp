#include <iostream>
#include <string>

using namespace std;

const int MAX=1000*1000+10;
string S[MAX];
int H[MAX];
int L[MAX];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>S[i]>>L[i]>>H[i];
		}
		int q;
		cin>>q;
		for(int i=0;i<q;i++){
			int p;
			cin>>p;
			string c;
			bool least_one=false;
			bool more_one=false;
			for(int j=0;j<n;j++){
				if(p>=L[j]&&p<=H[j]){
					if(least_one==true)
						more_one=true;
					least_one=true;
					c=S[j];
				}
			}
			if(least_one==false||more_one==true)
				cout<<"UNDETERMINED"<<endl;
			else
				cout<<c<<endl;
		}
		if(i!=N-1)
			cout<<endl;
	}
}
