#include<cstring>
#include<iostream>
#include<limits.h>
using namespace std;

void findLargestUniqueSubstring(char input[], char output[]){
	int n = strlen(input);
	int visited[256]={0};
	int beg=0;
	int i,start=0,end =0,cur_len=0,max_len=0,flag=1;
	i=start;
	while(i<n){
		if(flag==0){
			i=start;
		}
		cout<<"i: "<<i<<endl;
		if(visited[input[i]]==0){
			cout<<input[i]<<" unique:"<<endl;
			visited[input[i]]=1;
			cur_len++;
			flag=1;
		} else {
			cout<<input[i]<<" dublicate:"<<endl;
			if(cur_len>max_len){
				max_len=cur_len;
				beg=start;
			}
			start++;
			flag=0;
			memset(visited,0,sizeof(visited));
			cur_len=0;
		}
		cout<<endl;
		++i;
	}
	int s=0;
	for(int k=beg;k<beg+max_len;k++){
		output[s++]= input[k];
	}
	output[s]='\0';
	cout<<output;

}

int main(){
	char input[]= "abcdefghasbedgfhjiknsdmn";
	int n = strlen(input);
	char output[n];
	findLargestUniqueSubstring(input,output);
}
