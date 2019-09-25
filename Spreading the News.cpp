#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX=2500*10+10;
vector <int> E[MAX];

int main(){
	int employe;
	cin>>employe;
	for(int i=0;i<employe;i++){
		int N;
		cin>>N;
		for(int j=0;j<N;j++){
			int V;
			cin>>V;
			E[i].push_back(V);
		}
	}
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int start;
		cin>>start;
		int color[MAX]={0};
		int dis[MAX]={0};
		queue <int> Q;
		Q.push(start);
		color[start]=1;
		dis[start]=0;
		int max_boom_day=0;
		int boom[MAX]={0};
		int max_boom=0;
		while(!Q.empty()){
			int start=Q.front();
			Q.pop();
			color[start]=2;
			int temp=0;
			for(int i=0;i<E[start].size();i++){
				if(color[E[start][i]]==0){
					temp++;
					color[E[start][i]]=1;
					Q.push(E[start][i]);
					dis[E[start][i]]=dis[start]+1;
				}
			}
			boom[dis[start]]+=temp;
		}
		for(int i=0;i<MAX;i++){
			if(max_boom<boom[i]){
				max_boom=boom[i];
				max_boom_day=i;
			}
		}
		if(max_boom==0){
			cout<<0<<endl;
		}
		else{
			cout<<max_boom<<" "<<max_boom_day+1<<endl;
		}
	}
}
