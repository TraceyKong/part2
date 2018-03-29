#include <iostream>
#include <string>

std::string removeLeadingSpaces(std::string line){ 
	for (int i = 0; i < line.size(); i++){
		if (!isspace(line[i])){
			std::string result = line.substr(i);
			return result;
		}
	}
}

std::string unindent(){
	std::string result;
	std::string line;
	while (getline(std::cin, line)){
		result += removeLeadingSpaces(line) + "\n";
	}
	return result;
}

int countChar(std::string line, char c){
	int count = 0;
	for (int i = 0; i < line.size(); i++){
		if (line[i] == c){
			count += 1;
		}
	}
	return count;
}

std::string indent(){
	int openBlock = 0;
	int closeBlock = 0;
	int tabs = 0;
	std::string result;
	std::string line;
	while (getline(std::cin, line)){
		line = removeLeadingSpaces(line);
		openBlock += countChar(line, '{');
		closeBlock += countChar(line, '}');
		tabs = (openBlock - closeBlock);
		result += line + "\n";
		for (int i = 0; i < tabs; i++){
			result += "	";
		}
	}
	return result;
}
