#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct vertex{
	int color;
	int part;
};

const int MAX=1000;
vector <int> E[MAX];
vertex V[MAX];

bool BFS(int start);

int main(){
	while(true){
		int n,m;
		cin>>n;
		if(n==0)
			break;
		cin>>m;
		for(int i=0;i<m;i++){
			int v1,v2;
			cin>>v1>>v2;
			E[v1].push_back(v2);
			E[v2].push_back(v1);
		}
		for(int i=0;i<n;i++){
			V[i].color=0;
			V[i].part=-1;
		}
		if(BFS(0))
			cout<<"BICOLORABLE."<<endl;
		else
			cout<<"NOT BICOLORABLE."<<endl;
		for(int i=0;i<n;i++){
			E[i].clear();
		}
	}
}
bool BFS(int start){
	queue <int> Q;
	bool flag=true;
	V[start].part=0;
	Q.push(start);
	while(!Q.empty()){
		int temp=Q.front();
		Q.pop();
		V[temp].color=1;
		for(int i=0;i<E[temp].size();i++){
			if(V[E[temp][i]].color==0){
				if(V[E[temp][i]].part==-1)
					V[E[temp][i]].part=(1-V[temp].part);
				else if(V[E[temp][i]].part!=(1-V[temp].part))
					flag=false;
				Q.push(E[temp][i]);
			}
		}
		V[temp].color=2;
	}
	if(!flag)
		return false;
	else
		return true;
}
