#include <iostream>
using namespace std;

int TSort(int s[], int n, int k){
	int i = 0, j = n - 1;
	int mid = n / 2;
	while((s[mid] != k) && (i < j)){
		if(s[mid] < k){
			i = mid + 1;
		}else{
			j = mid - 1;
		}
		if(i <= j){
			mid = (i + j + 1) / 2;
			cout<<"i: "<<i<<" j: "<<j<<" mid: "<<mid<<endl;
		}else{
			break;
		}
		
	}
	if(k == s[mid]){
		return mid;
	}else{
		return -1;
	}
}

int main(int argc, char *argv[])
{
	int s[]={1,3,6,8,9,14,17,22,23,45,46,47,81,82};
	cout<<TSort(s, sizeof(s) / sizeof(int), 83);
	return 0;
}