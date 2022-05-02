#include<bits/stdc++.h>
using namespace std;


std::vector<std::string> toknized(string s,regex token)
{
	sregex_token_iterator iterator{s.begin(),s.end(),token,-1};
	vector<std::string> token_{iterator,{}};
	return token_;
}
int main()
{
	string s;
	cin>>s;
	std::regex token ("[(?.!)]");
	vector<std::string> tokenized=toknized(s,token);
	for(string token_:tokenized)
	{
		std::cout<<token_<<endl;
	}
}
