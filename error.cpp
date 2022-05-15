#include<bits/stdc++.h>
using namespace std;


std::vector<std::string> toknized(string s,regex token)
{
	sregex_token_iterator iterator{s.begin(),s.end(),token,-1};
	vector<std::string> token_{iterator,{}};
	return token_;
}
int checkg(char s[])
{
	int size=strlen(s);
	int m=0;
	 if (s[0] < 'A' || s[0] > 'Z')
	 {
	 	m=m+1;
	 }
	  if (s[size - 1] != '.')
        
        {
        	m=m+1;
		}
	int a=0;
	int b=0;	
	int it=1;
	while(s[it])
	{
		 if (s[it] >= 'A' && s[it] <= 'Z')
            a = 0;
         else if (s[it] == ' ')
            a = 1; 
		else if (s[it] >= 'a' && s[it] <= 'z')
            a = 2;
		else if (s[it] == '.')
            a = 3;	
		if (b == a && b != 2)
            m=m+1;
 
        if (b == 2 && a == 0)
            m=m+1;
        if (a == 3 && b != 1)
            if (s[it + 1] == '\0')
			{
				m=m+0;
				} 
		
		it++;
		a=b;		   
 		 
		}
	return m;		
        
}
int main()
{
	string s;
	getline(cin,s);
	int size=s.length();
	char m[size];
	strcpy(m,s.c_str());
	int b=checkg(m);
	cout<<"the number of errors is: "<<b;
}
