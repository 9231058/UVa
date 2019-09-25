#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000 * 1000 + 10;

int main(int argc,char* argv[]){
	int D[MAX];
	D[0] = 0;
	D[1] = 1;
	for(int i = 2; i <= 10000; i++){
		int min_D = MAX; 
		for(int j = 1; j * j <= i; j++){
			min_D = min(min_D, D[i - j * j] + 1);
		}
		D[i] = min_D;
	}
	int T;
	cin >> T;
	for(int i = 0; i < T; i++){
		int N;
		cin >> N;
		cout << D[N] << endl;
	}
}
