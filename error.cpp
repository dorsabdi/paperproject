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
	 if(s[size-2]==' '||s[size-2] == '.'||s[size-2] == '?'||s[size-2] == '!'||s[size-2] == ';'||s[size-2] == ',')
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
	int q=0;
	
	for(int i=1;i<size-2;i++ )
	{
		if(s[i] == '.'||s[i] == '?'||s[i] == '!'||s[i] == ';'||s[i] == ',')
		{
			if(s[i-1]==' ')
			{
				m=m+1;
			}
			if(s[i+1]!=' ')
			{
				m=m+1;
			}

			for(int q=2;i+q<size-2;q++)
			{
			if(s[i+q]=='.'||s[i+q] == '?'||s[i+q] == '!'||s[i+q] == ';'||s[i+q]== ','||s[i+q]<'A'||s[i+q]>'Z')
			{
				q++;
			}
			else
			{
				i=size-2-q;
			}
	    	}
    	}
    	if(q!=0)
    	{
    		m=m+1;
		}
				
	
	}

	
	return m-1;		
        
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
