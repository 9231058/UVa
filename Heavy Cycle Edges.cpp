#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
	int start;
	int end;
	int weight;
};

const int MAX=25*1000*10;
edge E[MAX];
int color[MAX];

bool edge_cmp(edge a,edge b){
	if(a.weight>b.weight)
		return false;
	return true;
}
int find(int x){
	if(color[x]<0)
		return x;
	return color[x]=find(color[x]);
}
bool merge(int x,int y){
	int X=find(x);
	int Y=find(y);
	if(X!=Y){
		color[X]+=color[Y];
		color[Y]=X;
		return true;
	}
	return false;
}

int main(){
	int n,m;
	while(true){
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++){
			color[i]=-1;
		}
		for(int i=0;i<m;i++){
			int start,end,weight;
			cin>>start>>end>>weight;
			E[i].start=start;
			E[i].end=end;
			E[i].weight=weight;
		}
		sort(E,E+m,edge_cmp);
		vector <int> ans;
		for(int i=0;i<m;i++){
			if(!merge(E[i].start,E[i].end)){
				ans.push_back(E[i].weight);
			}
		}
		if(ans.size()==0)
			cout<<"forest"<<endl;
		else{
			for(int i=0;i<ans.size()-1;i++)
				cout<<ans[i]<<" ";
			cout<<ans[ans.size()-1]<<endl;
		}
	}
}
