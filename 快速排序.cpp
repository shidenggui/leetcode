#include <iostream>
using namespace std;
int arrsort(int s[], int i, int j){
	int low = i, high = j;
	int k = s[low];
	while(low < high){
		while(low < high && s[high] >= k) --high;
		s[low] = s[high];
		while(low < high && s[low] <= k) ++low;
		s[high] = s[low];
	}
	s[low] = k;
	return low;
}

int qs(int s[], int i, int j){
	if(i < j){
		int piv = arrsort(s, i ,j);
		qs(s, i, piv - 1);
		qs(s, piv + 1, j);
	}
	
}

void quicksort(int s[], int n){
	qs(s, 0, n);
}

int main(int argc, char *argv[])
{
	int s[] = {2,5,8,65,48,78,45,12,56,22,45,33,10};
	int l = sizeof(s) / sizeof(int);
	quicksort(s, l);
	for(int i = 0; i < l; i++){
		cout<<s[i]<<"  ";
	}
	return 0;
}