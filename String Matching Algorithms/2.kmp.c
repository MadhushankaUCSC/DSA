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
//Knuth-Morris-Pratt(KMP) string matching function
int KMP(int n,int m){
	
	 	FILE *fk=fopen("results.txt","a");
	 	
   compLps(str1,n,lps);   //call compLps function
   	i=0;
  	j=0;
  while(i<m-n+1){
  	if(text[i]==str1[j]){  //match tezt characters with pattern characters
  		i++;
  		j++;
	  }else {
	  	if(j!=0){
	  		j=lps[j-1];
		  }else{
		  	i++;
		  }
	}
		 if(j==n){
		 	count++;
		 	fprintf(fk,"%d, ",i-j);
		 	printf("%d, ",i-j);  //print text index which match with pattern
		 	j=lps[j-1];
		 } 
	  
  }	
printf("\n\nTotal Number of matches:%d\n",count);  //print number of matches were present
fprintf(fk,"\n\n\tTotal Number of matches:%d\n\n",count);  //write matching count to the results.txt
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
 
 


