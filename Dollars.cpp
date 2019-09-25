#include <stdio.h>

const int MAX=1000*100;
long long D[MAX+1];
int C[11]={100*100,50*100,20*100,10*100,5*100,200,100,50,20,10,5};

int main(){
	while(true){
		int number1,number2;
		scanf("%d.%d",&number1,&number2);
		if(number1==0&&number2==0)
			break;
		int n=100*number1+number2;
		for(int i=1;i<=n;i++)
			D[i]=0;
		D[0]=1;
		for(int i=0;i<11;i++){
			int c=C[i];
			for(int j=c;j<=n;j++){
				D[j]+=D[j-c];
			}
		}
		printf("%3d.%02d%17lld\n",number1,number2,D[n]);
	}
}
