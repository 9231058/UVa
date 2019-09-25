#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>

using namespace std;

const int MAX=1000;

int main(){
	int test=0;
	while(true){
		int NC;
		cin>>NC;
		if(NC==0)
			break;
		map <int,int> M;
		int node_number=0;
		vector <int> E[MAX];
		for(int i=0;i<NC;i++){
			int C1,C2;
			cin>>C1>>C2;
			if(M.find(C1)==M.end()){
				M.insert(pair <int,int> (C1,node_number));
				node_number++;
			}
			if(M.find(C2)==M.end()){
				M.insert(pair <int,int> (C2,node_number));
				node_number++;
			}
			E[M[C1]].push_back(M[C2]);
			E[M[C2]].push_back(M[C1]);
		}
		while(true){
			int start,TTL;
			cin>>start>>TTL;
			if(start==0&&TTL==0)
				break;
			test++;
			int color[MAX]={0};
			int dis[MAX]={0};
			int node=0;
			queue <int> Q;
			Q.push(M[start]);
			color[M[start]]=1;
			dis[M[start]]=0;
			while(!Q.empty()){
				int start=Q.front();
				Q.pop();
				for(int i=0;i<E[start].size();i++){
					if(color[E[start][i]]==0){
						color[E[start][i]]=1;
						Q.push(E[start][i]);
						dis[E[start][i]]=dis[start]+1;
					}
				}
				if(dis[start]<=TTL)
					node++;
				color[start]=2;
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",test,node_number-node,start,TTL);
		}
	}
}
