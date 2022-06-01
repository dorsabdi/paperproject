#include<bits/stdc++.h>
using namespace std;
int entercount(string s)
{
	int enter=0;
	int size=s.length();
	int i=0;
while(i<size)
{
	if(s[i]=='\n')enter++;
				
}
return enter;
}