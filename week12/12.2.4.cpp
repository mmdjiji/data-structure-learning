#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> counter;

bool solve(std::string &str){
	counter[str]++;
	str.erase();
	return true;
}
bool printmax(){
	std::map<std::string, int>::iterator maximum = counter.begin();
	for(std::map<std::string, int>::iterator it = maximum; it != counter.end(); it++)
		if(it->second > maximum->second)
			maximum = it;
	std::cout << maximum->second << ":" << maximum->first << std::endl;
	counter.erase(maximum);
	return true;
}
int main(){
	std::string buffer, word;
	bool flag = false;
	while(std::cin>>buffer){
		for(int i=0; i<buffer.length(); i++){
			if(buffer[i] == '#' && (flag = true)) break;
			if(word.length() >= 15){
				solve(word);
				break;
			}
			if(buffer[i] >= 'A' && buffer[i] <= 'Z'){
				word += buffer[i] + 32;
			}else if(buffer[i] >= 'a' && buffer[i] <= 'z' || buffer[i]>='0' && buffer[i]<='9' || buffer[i] == '_'){
				word += buffer[i];
			}else if(word.length() > 0){
				solve(word);
				continue;
			}
		}
		if(word.length() > 0)
			solve(word);
		if(flag) break;
	}
	std::cout << counter.size() << std::endl;
	for(int i=0, ecx=counter.size()/10; i<ecx; i++)
		printmax();
	return 0;
}
