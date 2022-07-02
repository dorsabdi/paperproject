#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <ctime>
#include <regex>
#include <chrono>  // chrono::system_clock
#include <ctime>   // localtime
#include <format>
#include <iomanip>
#include <iostream>
#include <iostream>
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <regex>.
#include <json/json.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <streambuf>
using namespace std;
#pragma warning(disable : 4996) 

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
	void setpapername(string papername) {
		this->papername = papername;
	}
	string getpapername() {
		return this->papername;
	}
	void settextbody(string textbody) {
		this->textbody = textbody;
	}
	string gettextbody() {
		return this->textbody;
	}
	void setdate(string date) {
		this->date = date;
	}
	string getdate() {
		return this->date;
	}
	void setuniaccid(int uniaccid) {
		this->uniaccid = uniaccid;
	}
	int getuniaccid() {
		return this->uniaccid;
	}
	void setunipaperid() {
		this->unipaperid = papercount;
		papercount += 1;
	}
	int getunipaperid() {
		return this->unipaperid;
	}
	void submitrefrencec(int id) {
		refrencecs.push_back(id);
	}
	vector<int> getrefrencecs() {
		return this->refrencecs;
	}
	void setevaluation(bool value) {
		this->evaluation = value;
	}
	bool getevaluation() {
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
	int passwordstrength;
	vector<Paper> accountpaperslist;

public:
	void setusername(string username) {
		this->username = username;
	}

	void setpasswordstrength() {
		int size = this->password.length();
		int s = 0;
		bool lower_case = false, Upper_case = false, digit = false, __char = false;


		for (int i = 0; i < size; i++)
		{
			if (isalpha(this->password[i]))
			{
				if (isupper(this->password[i]))
					Upper_case = true;

				else if (islower(this->password[i]))
					lower_case = true;
			}
			else if (isdigit(this->password[i]))
				digit = true;

			else if ((int)this->password[i] >= 33 && (int)this->password[i] <= 47)
				__char = true;
			else if ((int)this->password[i] == 64)
				__char = true;

		}
		if (size >= 8)
		{
			s++;
		}
		if (Upper_case)
			s++;
		if (lower_case)
			s++;
		if (digit)
			s++;
		if (__char)
			s++;
		switch (s)
		{
		case(5):
		{
			cout << (s * 20) << "%" << endl;
			cout << "Strong";
			break;
		}
		case(4):
		{
			cout << (s * 20) << "%" << endl;
			cout << "good";
			break;
		}
		case(3):
		{
			cout << (s * 20) << "%" << endl;
			cout << "good";
			break;
		}
		case(2):
		{
			cout << (s * 20) << "%" << endl;
			cout << "medium";
			break;
		}

		case(1):
		{
			cout << (s * 20) << "%" << endl;
			cout << "weak please choose another password";
			break;
		}
		default:
		{

		}
		}
	}

	string getusername() {
		return this->username;
	}
	void setpassword(string password) {
		this->password = password;
	}
	string getpassword() {
		return this->password;
	}
	void setuniid() {
		this->uniid = accountcount;
		accountcount++;
	}
	int getuniid() {
		return this->uniid;
	}
	void addsubmitedpaper(Paper paper) {
		accountpaperslist.push_back(paper);
	}
	vector<Paper> getaccountpaperslist() {
		return this->accountpaperslist;
	}
};

// initializing . 
int Paper::papercount = 0;
int Account::accountcount = 0;

/*


	  */


size_t writefunc(void* ptr, size_t size, size_t nmemb, std::string* s)
{
	s->append(static_cast<char*>(ptr), size * nmemb);
	return size * nmemb;
}

vector<string> decode(string text)
{
	vector<string> results;
	Json::Value root;
	Json::Reader reader;
	bool parsingSuccessful = reader.parse(text, root);
	if (!parsingSuccessful)
	{
		cout << "Error parsing the string" << endl;
	}

	const Json::Value mynames = root["matches"];

	for (int index = 0; index < mynames.size(); ++index)
	{
		Json::StreamWriterBuilder builder;
		builder["indentation"] = ""; // If you want whitespace-less output
		const std::string output = Json::writeString(builder, mynames);


		results.push_back(output);
	}
	return results;
}

string setdatetostring() {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string str(buffer);

	return str;
}

int connecttoapi(string str) {

		string s = "text=";
		s.append(str);
		s.append("&language=en-US");

		std::regex space("[[:space:]]");
		s = std::regex_replace(s, space, "%20");

		CURL* hnd = curl_easy_init();
		string result;
		curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(hnd, CURLOPT_URL, "https://dnaber-languagetool.p.rapidapi.com/v2/check");
		curl_easy_setopt(hnd, CURLOPT_WRITEFUNCTION, writefunc);
		curl_easy_setopt(hnd, CURLOPT_WRITEDATA, &result);

		struct curl_slist* headers = NULL;
		headers = curl_slist_append(headers, "content-type: application/x-www-form-urlencoded");
		headers = curl_slist_append(headers, "X-RapidAPI-Host: dnaber-languagetool.p.rapidapi.com");
		headers = curl_slist_append(headers, "X-RapidAPI-Key: 8f39d0880bmshc99b348f0bc4baep1ed18fjsn06d485f1dbd6");

		curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
		string stri = "text=";

		char* writable = new char[s.size() + 1];
		std::copy(s.begin(), s.end(), writable);
		writable[s.size()] = '\0'; // don't forget the terminating 0

		curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, writable);

		CURLcode ret = curl_easy_perform(hnd);

		curl_easy_cleanup(hnd);

		int counts = decode(result).size();

		delete[] writable;

		return counts;
	}

// for similarity.
float LevenshteinDistanceCalculate(const string& st1, const string& st2) {

	if (st1.size() > st2.size()) {
		return LevenshteinDistanceCalculate(st2, st1);
	}

	const int min_size = st1.size();
	const int max_size = st2.size();
	vector<int> levdis(min_size + 1);

	for (int i = 0; i <= min_size; i++) {
		levdis[i] = i;
	}

	for (int j = 1; j < max_size; j++) {
		int previous_diagonal = levdis[0];
		int previous_diagonal_save;
		++levdis[0];

		for (int i = 1; i <= min_size; i++) {
			previous_diagonal_save = levdis[i];
			if (st1[i - 1] == st2[j - 1]) {
				levdis[i] = previous_diagonal;
			}
			else {
				levdis[i] = min(min(levdis[i - 1], levdis[i]), previous_diagonal) + 1;
			}
			previous_diagonal = previous_diagonal_save;
		}
	}

	return (1 - (float)(levdis[min_size] - 1) / (float)(max(st1.size(), st2.size()))) * 100;
}

	std::vector<std::string> toknized(string s, regex token)
	{
		sregex_token_iterator iterator{ s.begin(),s.end(),token,-1};
		vector<std::string> token_{ iterator,{} };
		return token_;
	}

	// () 
	int chechparantez(string s) {
		char left = ')';
		char right = '(';

		vector<char> arr;

		int balance = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == right) {
				arr.push_back(s[i]);
				balance++;
			}if (s[i] == left) {
				arr.pop_back();
				balance--;
			}
		}
		return balance;
	}


	// check errors
	int chech(string s) {
		int error = 0;
		if (isupper(s[0]) == false) {
			error++;
		}
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == ',') {
				if (isalpha(s[i - 1]) == false) {
					error++;
				}
				int j = i + 1;
				if (j < s.length()) {
					if (s[j] != ' ') {
						error++;
					}
				}
			}
			if (s[i] == '.' || s[i] == '!' || s[i] == ' ? ') {
				// here not so sure.
				if (isalpha(s[i - 1]) == false) {
					error++;
				}
				int j = i + 1;
				if (j < s.length()) {
					if (s[j] != ' ') {
						error++;
					}
					if (isupper(s[j + 1]) == false) {
						error++;
					}
				}
			}
		}
		return error;
	}

	int chechdouble(string s) {
		char left = '"';
		char right = '"';

		vector<char> arr;

		int balance = 0;

		for (int i = 0; i < s.length(); i++) {
			if (s[i] == right) {
				arr.push_back(s[i]);
				balance++;
			}if (s[i] == left) {
				arr.pop_back();
				balance--;
			}
		}
		return balance;
	}

	int entercount(string s)
	{
		int enter = 0;
		int size = s.length();
		for (int i = 0; i < size; i++) {
			if (s[i] == 10) {
				enter++;
			}
		}
		return enter;
	}

	bool papervalidity(Paper paper, vector<Paper> paperList, regex token) {
		bool valuesimilarity = true;
		bool valuenumberofwords = false;
		bool valuenumberofwordsoftitle = false;
		vector<std::string> tokenized = toknized(paper.gettextbody(), token);
		vector<string> titletokenized = toknized(paper.getpapername() , token);
	
		if (100 < tokenized.size() && tokenized.size() < 5000) {
			valuenumberofwords = true;
		}

		if (titletokenized.size() <= 12) {
			valuenumberofwordsoftitle = true;
		}

		for (auto it = begin(paperList); it != end(paperList); ++it) {
			float similarity = LevenshteinDistanceCalculate(it->gettextbody(), paper.gettextbody());
			if (similarity > 50) {
				int refrenceisfound = 0;
				std::vector<int>::iterator itref;
				std::vector<int> papercev = paper.getrefrencecs();
				for (auto itref = papercev.begin(); itref != papercev.end(); ++itref) {
					if (*itref == it->getunipaperid()) {
						refrenceisfound++;
						break;
					}
				}
			if (refrenceisfound == 0) {
				valuesimilarity = false;
				break;
			}
		}
	}

	if (valuesimilarity && valuenumberofwords && valuenumberofwordsoftitle == true && entercount(paper.gettextbody()) >= 2) {
		return true;
	}
	else {
		return false;
	}
	}

int main(int argc, char** argv) {

	vector<Paper> paperList;
	vector<Account> accountList;
	bool programvalue = true;
	regex token("[(?. ,:;\"!)]");

	while (programvalue) {
		string S, T;
		int i = 0;
		cout << "welcome type something: "<<endl;
		getline(cin, S);

		if (S == "createnewacc") {
			Account newAcc;
			string username;
			string password;
			cout << "give us username: " << endl;
			getline(cin, username);
			cout << "give us password: " << endl;
			getline(cin, password);
			newAcc.setpassword(password);
			cout << " let us validate your password sir." << endl;
			newAcc.setpasswordstrength();
			cout << endl;
			newAcc.setusername(username);
			newAcc.setuniid();
			accountList.push_back(newAcc);
		}

		else if (S == "signtoacc") {

			string username;
			string password;
			cout << "give us username: " << endl;
			getline(cin, username);
			cout << "give us password: " << endl;
			getline(cin, password);
			bool accountvalue = false;
			std::vector<Account>::iterator it;
			for (it = accountList.begin(); it != accountList.end(); ++it) {
				if ((it)->getusername() == username && (it)->getpassword() == password) {
					accountvalue = true;
					cout << "the acc is found" << ". welcome " << it->getusername() << endl;
					break;
				}
			}

			if (accountvalue == false) {
				cout << "account was not find" << endl;
			}

			while (accountvalue) {
				string V;
				getline(cin, V);

				if (V == "submitpaper") {
					Paper newPaper;
					string text;
					string name;
					int numberofrefrences;

					//getdate
					newPaper.setdate(setdatetostring());

					//newPaper.setdate(return_current_time_and_date);
					//  C:\\Users\\taha\\Documents\\testcase(100).txt for example
					cout << "give us the title :" << endl;
					getline(cin, name);
					cout << "give us the text address :" << endl;
					getline(cin, text);

					std::ifstream t(text);
					std::string strtextbody((std::istreambuf_iterator<char>(t)),
					std::istreambuf_iterator<char>());

					newPaper.setpapername(name);
					newPaper.settextbody(strtextbody);

					cout << "how many refrence does your paper have? " << endl;
					cin >> numberofrefrences;

					
					for (int i = 0; i < numberofrefrences; i++) {
						cout << " submit refrence ids here :"<<endl;
							int refrenceid;
							cin >> refrenceid;
							cout << endl;
							newPaper.submitrefrencec(refrenceid);
						}

					//evaluattion functions here;
					// something like this here
					//newPaper.setevaluation(false);


					bool papervalidityvalue = papervalidity(newPaper, paperList, token);
					// set valuation
					newPaper.setevaluation(papervalidityvalue);
					// set the account id
					newPaper.setuniaccid(it->getuniid());
					// set the paper   id
					newPaper.setunipaperid();
					// submit paper to account paper .
					it->addsubmitedpaper(newPaper);
					int count = connecttoapi(strtextbody);
					if (papervalidityvalue == true && count == 0) {
						cout << "the account is succsefuly submited " << endl;
						paperList.push_back(newPaper);
					}
					else {
						cout << "the validaion of this paper was false" << endl;
					}
				}

				else if (V == "listofaccpapers") {
					std::vector<Paper>::iterator itpaper;
					std::vector<Paper> papercev = it->getaccountpaperslist();
					for (itpaper = papercev.begin(); itpaper != papercev.end(); ++itpaper) {
						cout << "the paper title : " << itpaper->getpapername() << " . its validation is " <<  itpaper->getevaluation()  << " the id is :" << itpaper->getunipaperid() << endl;
					}

				}

				else if (V == "exitacc") {
					accountvalue = false;
				}

			}
		}

		else if (S == "listofvalidpapers") {
		std::vector<Paper>::iterator itpaper;
		std::vector<Paper> papercev = paperList;
		for (itpaper = papercev.begin(); itpaper != papercev.end(); ++itpaper) {
			cout << "the paper title : " << itpaper->getpapername() << " -> its validation is " << itpaper->getevaluation() << " the id is : " << itpaper->getunipaperid() << endl;
		 }
		}

		else if (S == "exit") {
			programvalue = false;
		}
	}

	return 0;
}
