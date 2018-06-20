#include<iostream>
#include<cstring>
using namespace std;

int countPalindromeSubstrings(char s[]) {

	int left=0,right=0,mid,count=0,start=0,end=0,flag=1,i=0,n,mid1,mid2;
    n = strlen(s);

	while(s[i]!='\0'){
		count++;
		mid = i;
		left = mid-1;
		right = mid+1;
		flag=1;
		while(left>=0 && right<n && flag!=0){
			start=left;
			end=right;
			flag=1;
			while(start<=end){
		   	 	if(s[start]!=s[end]){
					flag=0;
				}
				start++;
				end--;
		   	}
			if(flag==1){
				count++;
			}
			left--;
			right++;
		}
		 i++;
		}

		flag=1;
		i=0;
		while(s[i]!='\0'){
			mid1 = i;
			mid2 = i+1;

			if(s[mid1]==s[mid2]){
				count++;
				left = mid1-1;
				right = mid2+1;
				flag=1;
				while(left>=0 && right<n && flag!=0){
					start=left;
					end=right;
					flag=1;
					while(start<=end){
				   	 	if(s[start]!=s[end]){
							flag=0;
						}
						start++;
						end--;
				   	}
					if(flag==1){
						count++;
					}
					left--;
					right++;
				}
			}
			i++;
		 }
		 return count;
}

int main(){
	char arr[]={"abaabaaba"};
	cout<<countPalindromeSubstrings(arr);
}
