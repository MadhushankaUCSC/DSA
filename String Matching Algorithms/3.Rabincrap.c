#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define k 256  //k is number of charactors in alphabet
int i,j,m,n;
char str1[]="960410";  //pattern
char *text;
int count;

void rabinkarp(int n,int m){
	
	FILE *fg=fopen("results.txt","a");
	
  int patHash=0; //hash value of nPattern
  int txtHash=0; //hash value of text
  int h=1;
  int prime=101;  //prime number
  
  
  //h value  pow(k,n-1)%q
  for(i=0;i <n-1;i++){
    h=(h*k) % prime;
  }
  //compute hash value of text and pattern
  for(i=0;i<n;i++){
   patHash=(k*patHash + str1[i]) % prime;
    txtHash=(k*txtHash + text[i]) % prime;
  }


  printf("\n\nTotal Number of matches:%d\n",count);  //print count of total matches
   fprintf(fg,"\n\n\tTotal Number of matches:%d\n\n",count);  //print count of total matches to the results.txt file
}


int  main(int argc, char const *argv[]) {
  int size=133978353;
  int cnt=0;
  text=malloc((size+1)*sizeof(char));   //dynamic memory allocation
  char ch;
  int w=0;
  FILE *fpoint=fopen("pi.txt","r");  //read pi text file
 
  while(ch!=EOF){
    ch=getc(fpoint);
    cnt++;
    	if(ch != ' ' && cnt > 568){
    		
    		if(ch==':') w++;
    		
    		else if(ch =='\n') w=0;
    		
    		else if(w==0){
    		  text[i]=ch;
    			i++;	
			}
  
}
  }
  
  fclose(fpoint);  //close file pointer
 // getch();
  
  m=strlen(text);  //get text length
  n=strlen(str1);  //get pattern length
  

   

   
  rabinkarp(n,m);  //call rabinKarp function
  
 
}
