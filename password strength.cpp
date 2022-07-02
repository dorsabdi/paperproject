#include<bits/stdc++.h>
using namespace std;

void password(string __password)
{
	int size=__password.length();
	int s=0;
	bool lower_case=false,Upper_case=false,digit=false,__char=false;
	
	
	
		
	
	for(int i=0;i<size;i++)
	{
		if(isalpha(__password[i]))
		{
		if(isupper(__password[i]))
			Upper_case=true;
			

		else if(islower(__password[i]))
			lower_case=true;
	   }
		
		else if(isdigit(__password[i]))
		     digit=true;
		     
		
		else if((int)__password[i]>=33 && (int)__password[i] <=47)
		   __char=true;
		else if((int)__password[i]==64)   
		   __char=true;
		   	 	
	}
	if(size>=8)
	{
		s++;
	}
	if(Upper_case)
		s++;
	if(lower_case)
	    s++;
	if(digit) 
	   s++;
	if(__char)
	  s++; 
	    
switch(s)
{	
	case(5):
	{
		cout<<(s*20)<<"%"<<endl;
		cout<<"Strong";
		break;
	}
	case(4):
	{
		cout<<(s*20)<<"%"<<endl;
		cout<<"good";
		break;
	}
	case(3):
	{
		cout<<(s*20)<<"%"<<endl;
		cout<<"good";
		break;
	}
	case(2):
	{
		cout<<(s*20)<<"%"<<endl;
		cout<<"medium";
		break;
	}
	
    case(1):
	{
		cout<<(s*20)<<"%"<<endl;
		cout<<"weak please choose another password";
		break;
	}
	default:
		{
			
		}
	
}
}
int main()
{
	string a;
	cin>>a;
	password(a);
}