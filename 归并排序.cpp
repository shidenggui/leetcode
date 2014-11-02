#include <iostream>
using namespace std;

void mergearr(int s[], int f, int m, int l){
	int i = f, j = m;
	int *t = new int[l - f + 1];
	int p = 0;
	while(i < m && j < l){
		if(s[i] < s[j]){
			t[p++] = s[i++];
		}else{
			t[p++] = s[j++];
		}
	}
	
	for(int i = 0; i < (l - f); i++){
		cout<<t[i]<<" ";
	}
	
	while(i < m){
		t[p++] = s[i++];
	}
	while(j < l){
		t[p++] = s[j++];
	}
	for(int i = f; i < l; i++){
		s[i] = t[i];
	}
	for(int i = 0; i < (l - f); i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	delete [] t;
} 

void mergesort(int s[], int f, int l){
	if(f < l){
		int mid = (f + l) / 2;
		mergesort(s, f, mid);
		mergesort(s, mid, l);
		mergearr(s, f, mid, l);
	}
}

int main(int argc, char *argv[])
{
	int s[] = {2,5,8,65,48,78,45,12,56,22,45,33,10};
	int l = sizeof(s) / sizeof(int);
	//mergesort(s, 0, l);
	mergearr(s, 0, 5, l);
	for(int i = 0; i < l; i++){
		cout<<s[i]<<"  ";
	}
	return 0;
}