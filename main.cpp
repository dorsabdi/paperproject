#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <ctime>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class Paper {
	private:
		string papername;
		string textbody;
		string date;
		// id of the acc which submits the paper
		int uniaccid;
		// id of the paper
		int unipaperid;	
		// array of refrences in which id's of diffrent papers are stored in
		vector<int> refrencecs;
		bool evaluation;
		static int papercount;
	public:
		void setpapername(string papername){
			this->papername = papername;
		}	
		string getpapername(){
			return this->papername;
		}
		void settextbody(string textbody){
			this->textbody = textbody;
		}	
		string gettextbody(){
			return this->textbody;
		}
		void setdate(string date){
			this->date = date;
		}	
		string getdate(){
			return this->date;
		}
		void setuniaccid(int uniaccid){
			this->uniaccid = uniaccid;
		}	
		int getuniaccid(){
			return this->uniaccid;
		}		
		void setunipaperid(){
			this->unipaperid = papercount;
			papercount += 1;
		}	
		int getunipaperid(){
			return this->unipaperid;
		}
		void submitrefrencec(int id){
			refrencecs.push_back(id);
		}
		vector<int> getrefrencecs(){
			return this->refrencecs;
		}
		void setevaluation(bool value){
			this->evaluation = value;
		}							
		bool getevaluation(){
			return this->evaluation;
		}					
};

// account class
class Account {
	
	private:
		string username;
		string password;
		int uniid;
		static int accountcount;
		vector<Paper> accountpaperslist;

	public:
		void setusername(string username){
			this->username = username;
		}	
		string getusername(){
			return this->username;
		}
		void setpassword(){
			this->password = password;
		}
		string getpassword(){
			return this->password;
		}
		void setuniid(){
			this->uniid = accountcount;
			accountcount++;			
		}
		int getuniid(){
			return this->uniid;
		}
		void addsubmitedpaper(Paper paper){
			accountpaperslist.push_back(paper);
		}
		vector<Paper> getaccountpaperslist(){
			return this->accountpaperslist;
		}
};

int Paper::papercount = 0;
int Account::accountcount = 0;

/* 

	
	  */
	  
	  

int main(int argc, char** argv) {
	
	vector<Paper> paperList;
	vector<Account> accountList;
	bool programvalue = true;

	while(programvalue){
		string S,T;
		string arrstr[3];
		int i = 0;
		getline(cin , S);
		stringstream X(S);	
		while (getline(X, T, ' ')){          		
			arrstr[i] = T;
			i++;
		}
		
		if(arrstr[0] == "createnewacc"){
			Account newAcc;
			string username;
			string password;
			username = arrstr[1];
			password = arrstr[2];
			newAcc.setuniid();
			accountList.push_back(newAcc);
		}
		
		else if(arrstr[0] == "signtoacc"){
			
			string username;
			string password;
			username = arrstr[1];
			password = arrstr[2];
			bool accountvalue = false;		
			std::vector<Account>::iterator it;	
			for(it = accountList.begin(); it != accountList.end(); ++it){
				if((it)->getusername() == username && (it)->getpassword() == password){
					accountvalue = true;
					break;
				}
			}
			
			if(accountvalue == false){
				cout<<"account was not find"<<endl;
			}
			
			while(accountvalue){
				string V;
				getline(cin , V);
				
				if(V == "submitpaper"){
					Paper newPaper;
					string text;
					string name;
					int numberofrefrences;
				  	
				  	//getdate
					time_t rawtime;
	  				struct tm * timeinfo;
	  				char buffer[80];
	  				time (&rawtime);
	  				timeinfo = localtime(&rawtime);	
	  				strftime(buffer,sizeof(buffer),"%d-%m-%Y %H:%M:%S",timeinfo);
	  				std::string strdate(buffer);		
					newPaper.setdate(strdate);
					
					getline(cin ,name);
					getline(cin , text);
					
					newPaper.setpapername(name);
					newPaper.settextbody(text);
					
					cin>>numberofrefrences;
					cout<<endl;
					
					for(int i = 0 ; i < numberofrefrences ; i++ ){
						int refrenceid;
						cin>>refrenceid;
						cout<<endl;
						newPaper.submitrefrencec(refrenceid);
					}
					
					//evaluattion functions here;
					// something like this here
					//newPaper.setevaluation(false);
					
					it->addsubmitedpaper(newPaper);
					paperList.push_back(newPaper);
				}	
				
				else if(V == "listofaccpapers"){
						std::vector<Paper>::iterator itpaper;	
						for(itpaper = it->getaccountpaperslist().begin(); itpaper != it->getaccountpaperslist().end(); ++itpaper){
							cout<<itpaper->getpapername()<<endl;
						}			
										
				}
				 
				else if(V == "exitacc"){
					accountvalue = false;
				}
						
		   	 }
		  }	
		  else if(arrstr[0] == "exit"){
		  	programvalue = false;
		  }
	 }
	
	return 0;
}
