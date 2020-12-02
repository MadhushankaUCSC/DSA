#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<limits.h>

#define k 256  //k is number of charactors in alphabet
int i,j,m,n;
char str1[]="960410";  //pattern
char *text;
int count;
int badCharacter[k];

//function to get maximum from two numbers
int maximum(int a,int b){
	if(a>b){
		return a;
	} else{
		return b;
	}
}

//function for bad character heuristic
void badCharHeu(int n){
	for(i=0;i<k;i++){
		badCharacter[i] = -1; //all occurrences as -1
	}
	for(i=0;i<n;i++){
		badCharacter[(int) str1[i]]=i;   //true value of last occurrence
	}
}

//function of boyer moore algorithm
int boyerMoore(int n,int m){
	
	FILE *fg=fopen("results.txt","a");  //creat a file pointer for append file
	
	badCharHeu(n);      //call the badCharHeu function
	int s=0;   //shift of pattern with text
while(s<=(m-n)){
	int j=n-1;
	
/*  reducing  j of pattern while 
		characters of pattern and text are 
		matching  */
	while(j >= 0 && str1[j]==text[s+j]){
	j--;
	}
	  

	if(j<0){
		
		count++;
		printf("%d ,",s);
		fprintf(fg,"%d ,",s);  //print matched index of text 
		s += (s+n<m)? n-badCharacter[text[s+n]] : 1;
	}
	else{
		s += maximum(1, j- badCharacter[text[s+j]]);
	}
}

	printf("\n\nTotal Number of matches:%d\n",count);  //print number of matches were present
   fprintf(fg,"\n\n\tTotal Number of matches:%d\n\n",count);  //write matching count to the results.txt
}




//main function
int  main() {
  int size=133978353;
  int cnt=0;   //it helps to skip first 21 lines
  int w=0;
  text=malloc((size+1)*sizeof(char));   //dynamic memory allocation
  
  char ch;
  
  FILE *fpoint=fopen("pi.txt","r");  //read pi text file
  
  while(ch!=EOF){
    ch=getc(fpoint);
    cnt++;
    
    	if(ch != ' ' && cnt > 568){
    		
    		if(ch == ':') w++;
    		
			else if(ch == '\n') w=0;
    		
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
   
  FILE *fp=fopen("results.txt","a");
 
  printf("\n\t**********Searching Pattern From Pi**********");   
  printf("\n\nPattern (DOB):9 6 0 4 1 0");						//print pattern 
   fprintf(fp,"\n\t**********Searching Pattern From Pi**********");
  fprintf(fp,"\n\nPattern (DOB):9 6 0 4 1 0");    //print pattern  to the results.txt file
  
  printf("\n\n------Boyer-Moore String Matching------");
  fprintf(fp,"\n\n\n------Boyer-Moore String Matching------");
 
  printf("\n\nPattern found at index: ");
  fprintf(fp,"\n\n\tPattern found at index: ");
  
  boyerMoore(n,m);  //call boyer moore function
   
  fclose(fp);
  return 0;
}
