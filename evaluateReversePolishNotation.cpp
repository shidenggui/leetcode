#include <iostream.h>
#include <stack>
using namespace std;

int revpl(char a[][10], int n){
	stack<double> st;
	for(int i = 0; i < n; i++){
		double sum = 0;
		switch(*a[i]){
			case '+': 
				sum = st.top();
				st.pop();
				sum += st.top();
				st.pop();
				st.push(sum);
				break;
			case '-': 
				sum = st.top();
				st.pop();
				sum -= st.top();
				st.pop();
				st.push(-sum);
				break;
			case '*': 
				sum = st.top();
				st.pop();
				sum *= st.top();
				st.pop();
				st.push(sum);
				break;
			case '/': 
				sum = st.top();
				st.pop();
				sum /= st.top();
				st.pop();
				st.push(1/sum);
				break;	
			default: st.push(atoi(a[i]));	  
		}
		
	}
	cout<<"A£º"<<st.top();
}
int main(int argc, char *argv[])
{
	char a[][10] = {{"4"},{"13"},{"5"},{"/"},{"+"},};
	revpl(a, sizeof(a)/ sizeof(char[10]));
	return 0;
}