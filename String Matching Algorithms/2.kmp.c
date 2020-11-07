#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,n,i,j;
char str1[]="960410";   //pattern
char *text;      //charactor pointer
int s;
int lps[6];   //integer arra for store longest prefix and suffix of the pattern
int count;
 //compute longest prefix and suffix
int compLps(char str1[],int n,int lps[]){

	int len=0;
	int i=1;
	lps[0]=0;
	while(i<n){
		if(str1[i] == str1[len]){
			lps[i]=len+1;
			len++;
			i++;
		}else{
			if(len!=0){
			len=lps[len-1];	
			}else{
				lps[i]=0;
				i++;
			}
		}
	}

}

//main function
int main(){
	int size=1339783531;
	text=malloc((size+1)*sizeof(char));   //dynamic memory allocation
	char ch;
	int w=0;
	int cnt=0;    //it helps to skip first 21 lines
	FILE *fpoint=fopen("pi.txt","r");   //open file in read mode get into a fpoint

	while(ch!=EOF){
		ch=getc(fpoint); 
		cnt++;
		if(ch != ' ' && cnt > 568){
		
		if(ch == ':') w++;
		
		else if(ch == '\n') w=0;
		
		else if(w==0){
			text[i]=ch;      //assign caractors to the array
			i++;
		}
	
	}
	}

 }
 
 


