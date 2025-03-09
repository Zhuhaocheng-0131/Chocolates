#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<"    A      M    M    I  N    N    OOO     A      CCCCC   \n";
	cout<<"   A A    M  MM  M      N N  N   O   O   A A    C        \n"; 
	cout<<"  AAAAA   M      M   I  N  N N   O   O  AAAAA   C        \n";
	cout<<" A     A  M      M   I  N    N    OOO  A     A   CCCCC   \n\n"; 
	cout<<"HELLO! I'm Aminoac AI!\n";
	cout<<"What's your name?";
	string s,n;
	cin>>n;
	cout<<"Hello "<<n<<"!!\nPlease ask me some question!\n#使用\"t:\"可以翻译\n";
	cin>>s;
	while(s!="0"){
		map<char,int>m;
		for(auto x:s){
			m[x]++;
		}
		if(s=="**")cout<<"牛肉干\n";
		else if(m.count('^')||m.count('$')||m.count('%')||m.count('&')||m.count('@')||m.count('#')||m.count('*'))cout<<"系统提示：请文明用语\n";
		else if(s=="250"||s=="2b"||s=="sb")cout<<"is you!!:) \n";
		else if(s=="aminoac"||s=="Aminoac")cout<<"is me. ^_^\n";
		else if(s=="1+1="|s=="1+1=?")cout<<"3\n";
		else if(s[0]=='t'&&s[1]==':'){
			string t=s.substr(2,s.size()-2);
			if(t=="sb"||t=="250"||t=="2b")cout<<n<<endl;
			else{
				cout<<"I cannot do it...... :(\nPlease go to see my teacher,'www.doubao.com'.\n";
			}		
		}
		else{
			cout<<"I cannot do it...... :(\nPlease go to see my teacher,'www.doubao.com'.\n";
		}
		cin>>s;
	}
	cout<<"Good bye!! I'm Aminoac AI!";
    return 0;  
}
