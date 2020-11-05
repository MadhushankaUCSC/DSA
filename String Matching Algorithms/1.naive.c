#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,n,i,j;
char str1[]="960410";   //pattern
char *text;      //charactor pointer
int count;
//naive string matching function
int naive(int n,int m){
	
	FILE *fp=fopen("results.txt","a");
	 for(i=0;i<m-n+1;i++)
  {
    for(j=0;j<n;j++)
    {
     if(text[i+j] != str1[j])
       break;
    }
    if(j == n)
    {
    	count++;
    	fprintf(fp,"%d ,",i);
      printf("%d ,",i);  //print matched text index with tha pattern 
    }
   
  }
  
 printf("\n\nTotal Number of matches:%d\n",count);   //print number of matches were present
 fprintf(fp,"\n\n\tTotal Number of matches:%d\n\n",count);   //write matching count to the results.txt
  return 0;
   
}


//main function
int main(){
	int size=1339783531;
	text=malloc((size+1)*sizeof(char));   //dynamic memory allocation
	char ch;
	int cnt=0;  //count it helps to skip first 21 lines
	int w=0;
	FILE *fpoint=fopen("pi.txt","r");   //open file in read mode get into a fpoint

	while(ch!=EOF){
		ch=getc(fpoint); 
		cnt++;    //get character count for skip first 21 lines  
			if(ch != ' ' && cnt > 568){  //ignore ' ' 
				if(ch == ':') w++;
				
				else if(ch == '\n') w=0;
				
				else if(w==0){
						text[i]=ch;      //assign caractors to the array
		                i++;
				}   
		 
		 
	}
	}
fclose(fpoint);
 
}
