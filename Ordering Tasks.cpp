#include <iostream>
#include <vector>

using namespace std;

const int MAX=100+10;
vector <int> EI[MAX];
vector <int> EO[MAX];
int color[MAX];
int n,m;

void DFS(int start);
bool check_vertex(int vertex);

int main(){
	while(true){
		cin>>n>>m;
		if(n==0&&m==0)
			break;
		for(int i=0;i<n;i++){
			EI[i].clear();
			EO[i].clear();
		}
		for(int i=0;i<m;i++){
			int V1,V2;
			cin>>V1>>V2;
			EI[V2-1].push_back(V1-1);
			EO[V1-1].push_back(V2-1);
		}
		for(int i=0;i<n;i++){
			if(EI[i].size()==0){
				DFS(i);
				for(int i=0;i<n;i++){
					color[i]=0;
				}
			}
		}
		cout<<endl;
	}
}
void DFS(int start){
	color[start]=1;
	cout<<start+1<<" ";
	for(int i=0;i<EO[start].size();i++){
		if(color[EO[start][i]]==0){
			if(check_vertex(EO[start][i]))
				DFS(EO[start][i]);
		}
	}
	color[start]=2;
}
bool check_vertex(int vertex){
	for(int i=0;i<EI[vertex].size();i++)
		if(!color[EI[vertex][i]])
			return false;
	return true;
}
