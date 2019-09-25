#include <iostream>
#include <string>

using namespace std;

int main(){
	string S1;
	if(cin>>S1)
		while(true){
			string S2;
			cin>>S2;
			int index=0;
			bool flag=true;
			for(int i=0;i<S1.size();i++){
				while(S2[index]!=S1[i]){
					if(index==S2.size()){
						flag=false;
						break;
					}
					index++;
				}
				index++;
				if(flag==false)
					break;
			}
			if(cin>>S1){
				if(flag)
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;
			}
			else{
				if(flag)
					cout<<"Yes"<<endl;
				else
					cout<<"No"<<endl;
				break;
			}
		}
}
