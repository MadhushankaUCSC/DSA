#include <stdio.h>
#include <string.h>
#include<stdlib.h>

#define k 256  //k is number of charactors in alphabet
int i,j,m,n;
char str1[]="960410";  //pattern



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

  for(i=0;i<=m-n;i++){
    if(patHash == txtHash){
      for(j=0;j<n;j++){
        if(text[i+j] != str1[j])
        break;
      }

      if(j==n){
      	 printf("%d ,",i);  //print index of text match with the pattern
      fprintf(fg,"%d, ",i);
      count++;
	  }
      
     
    }

    if(i<m-n){
      txtHash= (k * (txtHash - text[i]*h) + text[i+n]) % prime;


      if(txtHash<0)
      txtHash=(txtHash+prime);
    }
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
  
   FILE *fp=fopen("results.txt","a");
   
  printf("\n\t**********Searching Pattern From Pi**********");		
   printf("\n\nPattern (DOB):9 6 0 4 1 0");						//print pattern
    fprintf(fp,"\n\t**********Searching Pattern From Pi**********");
   fprintf(fp,"\n\nPattern (DOB):9 6 0 4 1 0");		//print pattern to the results.txt file
   
  printf("\n\n------Rabin Karp String Matching------");
   fprintf(fp,"\n\n\n------Rabin Karp String Matching------");
   
  printf("\n\nPattern found at index: ");
   fprintf(fp,"\n\n\tPattern found at index: ");
   
  rabinkarp(n,m);  //call rabinKarp function
  
   fclose(fp);
  return 0;
}
