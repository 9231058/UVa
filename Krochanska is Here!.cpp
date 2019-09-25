#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX=1000*100+100;
vector <int> E[MAX];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int n,m;
		cin>>n>>m;
		bool see[MAX]={0};
		bool important[MAX]={0};
		vector <int> E[MAX];
		for(int i=0;i<m;i++){
			int V1,V2=0;
			while(cin>>V1&&V1!=0){
				if(see[V1-1]==false)
					see[V1-1]=true;
				else
					important[V1-1]=true;
				if(V2!=0){
					E[V1-1].push_back(V2-1);
					E[V2-1].push_back(V1-1);
				}
				V2=V1;
			}
		}
		/*for(int i=0;i<n;i++){
			for(int j=0;j<E[i].size();j++){
				cout<<E[i][j]<<" ";
			}
			cout<<endl;
		}*/
		int min=MAX*1000;
		int min_index=-1;
		for(int i=0;i<n;i++){
			int min_temp=0;
			if(important[i]==true){
				queue <int> Q;
				int dis[MAX];
				int color[MAX]={0};
				color[i]=1;
				Q.push(i);
				dis[i]=0;
				while(!Q.empty()){
					int start=Q.front();
					Q.pop();
					for(int i=0;i<E[start].size();i++){
						if(color[E[start][i]]==0){
							color[E[start][i]]=1;
							Q.push(E[start][i]);
							dis[E[start][i]]=dis[start]+1;
							if(important[E[start][i]]==true)
								min_temp+=dis[E[start][i]];
						}
					}
					color[start]=2;
				}
				if(min_temp<min){
					min_index=i;
					min=min_temp;
				}
			}
		}
		cout<<"Krochanska is in: "<<min_index+1<<endl;
	}
}

