#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s){
	int center=s.size()/2;
	for(int i=0;i<center;i++)
		if(s[i]!=s[s.size()-1-i])
			return false;
	return true;
}
bool isMirrored(string s){
	if(s.size()==1)
		if(s[0]=='H'||s[0]=='I'||s[0]=='M'||s[0]=='O'||s[0]=='T'||s[0]=='W'||s[0]=='X'||s[0]=='Y'||s[0]=='V'||s[0]=='U'||s[0]=='1'||s[0]=='8')
			return true;
		else
			return false;
	int center=s.size()/2;
	for(int i=0;i<center;i++)
		if(s[i]=='A'&&s[s.size()-1-i]=='A');
		else if((s[i]=='E'&&s[s.size()-1-i]=='3')||(s[i]=='3'&&s[s.size()-1-i]=='E'));
		else if((s[i]=='J'&&s[s.size()-1-i]=='L')||(s[i]=='L'&&s[s.size()-1-i]=='J'));
		else if(s[i]=='H'&&s[s.size()-1-i]=='H');
		else if(s[i]=='I'&&s[s.size()-1-i]=='I');
		else if(s[i]=='M'&&s[s.size()-1-i]=='M');
		else if(s[i]=='O'&&s[s.size()-1-i]=='O');
		else if(s[i]=='T'&&s[s.size()-1-i]=='T');
		else if(s[i]=='W'&&s[s.size()-1-i]=='W');
		else if(s[i]=='X'&&s[s.size()-1-i]=='X');
		else if(s[i]=='Y'&&s[s.size()-1-i]=='Y');
		else if(s[i]=='V'&&s[s.size()-1-i]=='V');
		else if(s[i]=='U'&&s[s.size()-1-i]=='U');
		else if((s[i]=='S'&&s[s.size()-1-i]=='2')||(s[i]=='2'&&s[s.size()-1-i]=='S'));
		else if((s[i]=='Z'&&s[s.size()-1-i]=='5')||(s[i]=='5'&&s[s.size()-1-i]=='Z'));
		else if(s[i]=='1'&&s[s.size()-1-i]=='1');
		else if(s[i]=='8'&&s[s.size()-1-i]=='8');
		else 
			return false;
	return true;
}	


int main(){
	string s;
	while(cin>>s){
		bool p=isPalindrome(s);
		bool m=isMirrored(s);
		if(p&&m)
			cout<<s<<" -- is a mirrored palindrome."<<endl;
		else if(p&&!m)
			cout<<s<<" -- is a regular palindrome."<<endl;
		else if(!p&&m)
			cout<<s<<" -- is a mirrored string."<<endl;
		else
			cout<<s<<" -- is not a palindrome."<<endl;
		cout<<endl;
		}
}
