#include <iostream>
#include <string>

using namespace std;
//didn't use using namespace before

string removeLeadingSpaces(string line){ 
	for (int i = 0; i < line.size(); i++){
		if (!isspace(line[i])){
			string result = line.substr(i);
			return result;
		}
	}
}

string unindent(){
	string result;
	string line;
	while (getline(cin, line)){
		result += removeLeadingSpaces(line) + "\n";
	}
	return result;
}

int countChar(string line, char c){
	int count = 0;
	for (int i = 0; i < line.size(); i++){
		if (line[i] == c){
			count += 1;
		}
	}
	return count;
}

string indent(){
	int tabs = 0;
	string result;
	string line;
	bool noCB = false;
	while (getline(cin, line)){
		line = removeLeadingSpaces(line);
		tabs -= countChar(line, '}');
		for (int i = 0; i < tabs; i++){
			result += "	";
		}
		result += line + "\n";
		tabs += countChar(line, '{');
		if(noCB){
			noCB=!noCB;
			tabs -=1;
		}
		if(line.find("if")== string::npos && countChar(line,'{')==0){
			cout << "found if" << endl;
			tabs+=1;
			noCB = !noCB;
		}
	}
	return result;
}