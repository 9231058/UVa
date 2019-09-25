#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class team{
	public:
		int b;	//total points earned
		int c; 	//games played
		int d; 	//wins
		int e; 	//ties
		int f; 	//losses
		int g; 	//goal difference
		int h; 	//goals scored
		int i; 	//goals against
		string p; //team name
		friend ostream &operator <<(ostream &output,const team &T){
			output<<T.p<<" "<<T.b<<"p, "<<T.c<<"g ("<<T.d<<"-"<<T.e<<"-"<<T.f<<"), "<<T.g<<"gd ("<<T.h<<"-"<<T.i<<")";
		}
		void update(int scored,int against){
			this->c++;
			this->h+=scored;
			this->i+=against;
			this->g+=(scored-against);
			if(scored>against){
				this->d++;
				this->b+=3;
			}
			else if(scored<against){
				this->f++;
			}
			else{
				this->e++;
				this->b+=1;
			}
		}
		team(){
			b=c=d=e=f=g=h=i=0;
		}
};

const int MAX1=100;
const int MAX2=3000;
team A[MAX2][MAX1];
string S[MAX2];
int num[MAX2];

void update(string T,int g1,int g2,int n,int index){
	for(int i=0;i<n;i++){
		if(A[index][i].p==T){
			A[index][i].update(g1,g2);
			break;
		}
	}
}
int compare_function(const void *a,const void *b){
	team *A=(team *)a;
	team *B=(team *)b;
	if(A->b!=B->b)
		return B->b-A->b;
	else if(A->d!=B->d)
		return B->d-A->b;
	else if(A->g!=B->g)
		return B->g-A->g;
	else if(A->h!=B->h)
		return B->h-A->h;
	else if(A->c!=B->c)
		return A->c-B->c;
	else
		return (A->p).compare(B->p);
}

int main(){
	int N;
	cin>>N;
	cin.get();
	for(int index=0;index<N;index++){
		getline(cin,S[index]);
		int n;
		cin>>n;
		num[index]=n;
		cin.get();
		for(int i=0;i<n;i++){
			getline(cin,A[index][i].p);
		}
		int m;
		cin>>m;
		cin.get();
		for(int i=0;i<m;i++){
			string s;
			string t1="",t2="";
			getline(cin,s);
			int j=0;
			while(s[j]!='#'){
				t1+=s[j];
				j++;
			}
			j++;
			int g1=s[j]-'a';
			j+=2;
			int g2=s[j]-'a';
			j+=2;
			while(s.size()!=j){
				t2+=s[j];
				j++;
			}
			update(t1,g1,g2,n,index);
			update(t2,g2,g1,n,index);
		}
		qsort(A[index],n,sizeof(team),compare_function);
	}
	for(int index=0;index<N;index++){
		cout<<S[index]<<endl;
		for(int i=0;i<num[index];i++){
			cout<<i+1<<") "<<A[index][i]<<endl;
		}
		cout<<endl;
	}
	cout<<endl;
}
