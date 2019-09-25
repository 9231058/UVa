#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int y,k;
	while(cin>>k){
		int num=0;
		for(y=k+1;y<=2*k;y++)
			if((k*y)%(y-k)==0)
				num++;
		printf("%d\n",num);
		for(y=k+1;y<=2*k;y++)
			if((k*y)%(y-k)==0)
				printf("1/%d = 1/%d + 1/%d\n",k,(k*y)/(y-k),y);
	}
}
