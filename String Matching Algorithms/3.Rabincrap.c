#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define k 256  //k is number of charactors in alphabet
int i,j,m,n;
char str1[]="960410";  //pattern
char *text;
int count;




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
  

