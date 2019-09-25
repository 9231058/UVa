#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void digit_parser(long number, vector<int>& vect);
bool palindrome_detect(const vector<int>& vect);
long reverse_as_int(const vector<int>& vect);

int main(int argc,char* argv[]){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		long number;
		cin >> number;
		long step = 0;
		while(true){
			vector<int> vect;
			vect.reserve(10);
			digit_parser(number, vect);
			if(palindrome_detect(vect)){
				cout << step << " " << number << endl;
				break;
			}
			else{
				step++;
				number += reverse_as_int(vect);
			}
		}
	}
}
void digit_parser(long number, vector<int>& vect){
	while(number != 0){
		vect.push_back(number % 10);
		number /= 10;
	}
}
bool palindrome_detect(const vector<int>& vect){
	int nSize = vect.size();
	int index = 0;
	for(int i = 0; i < nSize / 2; i++){
		if(vect[i] != vect[nSize - (i + 1)]){
			return false;
		}
	}
	return true;
}
long reverse_as_int(const vector<int>& vect){
	int nSize = vect.size();
	long number = 0;
	for(int i = 0; i < nSize; i++){
		number += vect[i] * pow(10,(nSize - (i + 1)));	
	}
	return number;
}
