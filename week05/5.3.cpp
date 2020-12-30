#include <iostream>
#include <stack>
int main(){
	int stackmax, n, qs;
	std::cin>>stackmax>>n>>qs;
	int popped[n];
	for(int j=0; j<qs; j++){
		std::stack<int> s;
		int index = 0, usedstack = 0;
		for(int i=0; i<n; i++)
			std::cin>>popped[i];
		for(int i=1; i<=n; i++){
			s.push(i);
			if(s.size() > usedstack) usedstack = s.size();
			while(!s.empty() && popped[index] == s.top()){
				s.pop();
				index++;
			}
		}
		if(s.empty() && usedstack <= stackmax)
			std::cout<<"YES"<<std::endl;
		else
			std::cout<<"NO"<<std::endl;
	}
	return 0;
}
