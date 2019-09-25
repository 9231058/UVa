#include <iostream>
#include <queue>

using namespace std;

const int MAX=10000+10;
const int LOCK=9999;

int main(){
	int test=0;
	while(true){
		int L,U,R;
		cin>>L>>U>>R;
		if(L==0&&U==0&&R==0)
			break;
		//if(test!=0)
		//	cout<<endl;
		test++;
		int step[MAX];
		for(int i=0;i<R;i++){
			cin>>step[i];
		}
		int color[MAX]={0};
		int dis[MAX]={0};
		queue <int> Q;
		Q.push(L);
		color[L]=1;
		dis[L]=0;
		int flag=false;
		while(!Q.empty()){
			int start=Q.front();
			Q.pop();
			if(start==U){
				flag=true;
			}
			for(int i=0;i<R;i++){
				if(color[(start+step[i])%(LOCK+1)]==0){
					color[(start+step[i])%(LOCK+1)]=1;
					Q.push((start+step[i])%(LOCK+1));
					dis[(start+step[i])%(LOCK+1)]=dis[start]+1;
				}
			}
			color[start]=2;
		}
		if(flag)
			cout<<"Case "<<test<<": "<<dis[U]<<endl;
		else
			cout<<"Case "<<test<<": "<<"Permanently Locked"<<endl;
	}
}
