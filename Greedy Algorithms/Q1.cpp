#include<iostream>
#include<conio.h>
#include<vector>
#include<map>

using namespace std; 
//declaration of greedyknapsack function
double greedyknapsack(vector<int>,vector<int>,int);

int main(){
	
	int N,M;
	
	cin>>N;		//get user input for no of bottles sandun brought
	
	cin>>M;   	//get user input for no of barrels in the yard  
	int val;
	
	//create a vector for store barrel price and volume of barrel in bottles 
	vector<int> price(M), volume(M); 

	 //for loop for fill the vector
     //get  volume of  barrels 1 by 1 as user input
	for(int i=0;i<M;i++){
		cin>>val;
		volume.push_back(val);
	}
	//for loop for fill the vector
     //get price  of  barrels 1 by 1 as user input
	for(int i=0;i<M;i++){
		cin>>val;
		price.push_back(val);       	
	}
		// call the function of greedyknapsack and print output
		/*to the function pass, price of barrel(price) ,
		 volume of barrel(volume) and 
		 no of bottles sandun brought(N)*/
	cout <<greedyknapsack(price,volume,N); 
}


