#include <iostream.h>
using namespace std;
char * revstr(string &s){
	const char *ph = s.c_str();
	const char *ptr = ph;
	char *tmp = new char[strlen(ph) + 1];
	char *tpt = tmp + strlen(ph);
	*tpt-- = '\0';
	while( *ptr != '\0' ){
		while( *ptr != '\0' && *ptr++ != ' ');
		const char *revp = ptr;
		if(*ptr == '\0'){
			revp++;
		}
		revp -= 2;
		while(revp != (ph - 1) && !isspace(*revp)){
			*tpt-- = *revp--;
		}
		if(tpt != tmp){
			*tpt-- = ' ';
		}	
	}
	cout<<"strlen(tmp):"<<strlen(tmp)<<endl; 
	cout<<"strlen(ph):"<<strlen(ph)<<endl;
	cout<<"strlen(tpt):"<<strlen(tpt)<<endl;
	return tmp;
}
int main(int argc, char *argv[])
{
	string s = "blue sky ou   ";
	cout<<revstr(s);
	return 0;
}