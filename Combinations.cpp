#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class bigInt{
	private:
		vector <int> N;
	public:
		friend bigInt operator +(bigInt A,bigInt B){
			vector <int> C;
			if(A.size()==1&&A[0]==0){
				return B;
			}
			else if(B.size()==0&&B[0]==0){
				return A;
			}
			if(A.size()>=B.size()){
				int div=0;
				for(int i=0;i<B.size();i++){
					C.push_back((A[i]+B[i]+div)%10);
					div=((A[i]+B[i]+div)/10);
				}
				for(int i=B.size();i<A.size();i++){
					C.push_back((A[i]+div)%10);
					div=((A[i]+div)/10);
				}
				if(div!=0)
					C.push_back(div);
			}
			else{
				int div=0;
				for(int i=0;i<A.size();i++){
					C.push_back((A[i]+B[i]+div)%10);
					div=((A[i]+B[i]+div)/10);
				}
				for(int i=A.size();i<B.size();i++){
					C.push_back((B[i]+div)%10);
					div=((B[i]+div)/10);
				}
				if(div!=0)
					C.push_back(div);
			}
			return bigInt(C);
		}
		bigInt(string S){
			for(int i=S.size()-1;i>=0;i--){
				N.push_back((static_cast <int> (S[i]))-48);
			}
		}
		bigInt(vector <int> V){
			for(int i=0;i<V.size();i++){
				N.push_back(V[i]);
			}
		}
		bigInt(){
			N.push_back(0);
		}
		bigInt(int n){
			while(n!=0){
				N.push_back(n%10);
				n=n/10;
			}
		}
		void show(){
			for(int i=N.size()-1;i>=0;i--){
				cout<<N[i];
			}
			cout<<endl;
		}
	 	friend ostream &operator <<(ostream &output,bigInt T){
			for(int i=T.size()-1;i>=0;i--){
				output<<T[i];
			}
			return output;
		}
		int size(){
			return N.size();
		}
		int &operator [](int n){
			return N[n];
		}
		bigInt operator =(bigInt T){
			N.erase(N.begin(),N.end());
			for(int i=0;i<T.size();i++){
				N.push_back(T[i]);
			}
			return *this;
		}
		bigInt operator =(int n){
			bigInt temp(n);
			*this=temp;
			return temp;
		}
		bigInt operator +=(bigInt T){
			*this=*this+T;
			return *this;
		}
};

const int MAX=1000;
bigInt Cb[MAX];

int main(){
	while(true){
		int n,k;
		cin>>n>>k;
		if(n==0&&k==0)
			break;
		for(int i=1;i<n+1;i++){
			bigInt temp1=1;
			for(int j=0;j<=k;j++){
				if(j==0){
					Cb[j]=1;
					continue;
				}
				if(j==i){
					Cb[j]=1;
					break;
				}
				bigInt temp2=Cb[j];
				Cb[j]=Cb[j]+temp1;
				temp1=temp2;
			}
		}
		cout<<n<<" things taken "<<k<<" at a time is "<<Cb[k]<<" exactly."<<endl;
	}
}
