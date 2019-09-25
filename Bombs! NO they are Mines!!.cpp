#include <iostream>
#include <queue>

using namespace std;

struct point{
	int x;
	int y;
};

const int MAX=1000+10;
bool A[MAX][MAX];

int main(){
	while(true){
		int R,C;
		cin>>R>>C;
		int Color[MAX][MAX]={{0}};
		int D[MAX][MAX]={{0}};
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				A[i][j]=false;
		if(R==0&&C==0)
			break;
		int MR;
		cin>>MR;
		for(int i=0;i<MR;i++){
			int tempR,MC,tempC;
			cin>>tempR>>MC;
			for(int j=0;j<MC;j++){
				cin>>tempC;
				A[tempR][tempC]=true;
			}
		}
		point start;
		cin>>start.x>>start.y;
		point end;
		cin>>end.x>>end.y;
		D[start.x][start.y]=0;
		Color[start.x][start.y]=1;
		queue <point> Q;
		Q.push(start);
		while(!Q.empty()){
			point temp=Q.front();
			int X=temp.x;
			int Y=temp.y;
			if(X>0&&Y<C&&X>-1&&Y>-1&&Color[X-1][Y]==0&&A[X-1][Y]==false){
				D[X-1][Y]=D[X][Y]+1;
				temp.x=X-1;
				temp.y=Y;
				Color[X-1][Y]=1;
				Q.push(temp);
			}
			if(X<R-1&&Y<C&&X>-1&&Y>-1&&Color[X+1][Y]==0&&A[X+1][Y]==false){
				D[X+1][Y]=D[X][Y]+1;
				temp.x=X+1;
				temp.y=Y;
				Color[X+1][Y]=1;
				Q.push(temp);
			}
			if(Y>0&&X<R&&X>-1&&Y>-1&&Color[X][Y-1]==0&&A[X][Y-1]==false){
				D[X][Y-1]=D[X][Y]+1;
				temp.x=X;
				temp.y=Y-1;
				Color[X][Y-1]=1;
				Q.push(temp);
			}
			if(Y<C-1&&X<R&&X>-1&&Y>-1&&Color[X][Y+1]==0&&A[X][Y+1]==false){
				D[X][Y+1]=D[X][Y]+1;
				temp.x=X;
				temp.y=Y+1;
				Color[X][Y+1]=1;
				Q.push(temp);
			}
			if(D[end.x][end.y]!=0)
				break;
			Color[X][Y]=2;
			Q.pop();
		}
		cout<<D[end.x][end.y]<<endl;
	}
}
/*1000 1000
0
0 0
999 999
0 0*/

