#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

const int MAX = 1000 + 10;

int main(int argc,char* argv[]){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		int D[MAX][MAX];
		memset(&D,sizeof(D),0);
	 	int size = str.size();
		for(int i = size - 1; i >= 0; i--){
			for(int j = 0; j < size; j++){
				if(i < j){
					int temp = (str[i] == str[j]) ? 0 : 1;
					//cout << D[i+1][j-1] + temp << " " << D[i+1][j] + 1 << " " << D[i][j-1] + 1 << endl; 
					D[i][j] = min(D[i+1][j-1] + temp, min(D[i+1][j] + 1, D[i][j-1] + 1));
				}
				//cout << "D[" << i << "][" << j << "] : " << D[i][j] << endl;
			}
		}
		cout << "Case " << i + 1 << ": " << D[0][size - 1] << endl;
	}
}
