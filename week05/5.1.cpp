#include <iostream>
#include <stack>

int main(){
	std::stack<int> s;
	int n, index=0; std::cin>>n;
	int popped[n];
	for(int i=0; i<n; i++)
		std::cin>>popped[i];
	for(int i=1; i<=n; i++){
		s.push(i);
		while(!s.empty() && popped[index] == s.top()){
			s.pop();
			index++;
		}
	}
	if(!s.empty())
		std::cout<<"no";
	else
		std::cout<<"yes";
	return 0;
}
