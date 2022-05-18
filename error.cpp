#include<bits/stdc++.h>
using namespace std;







int checkg(string s)
{
	int size=s.length();
	int m=0;
	 if (s[0] < 'A' || s[0] > 'Z')
	 {
	 	m=m+1;
	 }
	  if (s[size - 1] != '.'||s[size - 1] != '?'||s[size - 1] != '!')
        
        {
        	m=m+1;
		}
	int a=0;
	int b=0;	
	int it=1;
	
	for(int i=0;i<size;i++ )
	{
		if(s[i] == '.'||s[i] == '?'||s[i] == '!'||s[i] == ';'||s[i] == ',')
		{
			if(s[i+1]!=' ')
			{
				m=m+1;
			}
    	}		
	
	}
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
bool checkgb(int a)
{
	if(a>0) return false;
	
	return true;
}
int entercount(string s)
{
	int enter=0;
	int size=s.length();
	int i=0;
	while(i<size)
	{
	if(s[i]==10)
			{
			  enter++;
			  if(enter>3)
			  {
			  	cout<<"size limit excceded";
			  	break;
				  }	
			}
	else
	{
		  i+=1;
		
			}		
}
return enter;
}
int main()
{
	string s;
	getline(cin,s);
	int b=checkg(s);
	cout<<"the number of errors is: "<<b;
	bool a=checkgb(b);
	if(a) cout<<"true";
	else{
		cout<<"false";
	}
}
