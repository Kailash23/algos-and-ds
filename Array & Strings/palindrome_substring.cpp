#include<iostream>
#include<cstring>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int checkPalindrome(char s[]){
	int count=0,end ,start=0;
	int n = strlen(s);
	end = n-1;
	char t[n];

	int ind=0;
	for(int k=0;s[k]!='\0';k++){
		t[ind++]=s[k];
	}
	t[ind]='\0';

	 while(start<=end){
	 	swap(s[start],s[end]);
	 	start++;
	 	end--;
	 }
	 cout<<"s: "<<s<<endl;
	 cout<<"t: "<<t<<endl;
	if(strcmp(s, t) == 0){
      	return 1;
	} else {
		return 0;
	}
}

int countPalindromeSubstrings(char s[]) {
		int i=0, j=0;
		int n = strlen(s);
		int count=0;
		while(i<n){
			j=i;
			while(j<n){
				char temps[j-i+1];
				cout<<j-i+1<<endl;
				int ind=0;
				for(int k=i;k<=j;k++){
					temps[ind++]=s[k];
				}
				temps[ind]='\0';
				count+=checkPalindrome(temps);
				j++;
			}
			i++;
		}
		cout<<count<<endl;
}

int main(){
	char arr[]={"abaabaaabbcac"};
	countPalindromeSubstrings(arr);
}
