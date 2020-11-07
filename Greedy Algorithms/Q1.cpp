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

//function of greedyknapsack 
//return double value
double greedyknapsack(vector<int>price,vector<int>volume,int N){
	
	int numOfElements = volume.size(); 	//number of elements (it also can calculate price.size() )
	int k;
	int Maximum_value=0;   //variable for store the maximum value wine sandun takes 
	
		/*create a Multimap container call value_density to store 
	ratio and indexes */
	multimap<double, int> value_density;
	 
	 
	//for loop for insert value_density casted value of price[k]/volume[k] and the corresponding indexs
	for(k=0;k<numOfElements;k++){
		value_density.insert(make_pair((double)price[k]/volume[k],k));
	}
	
	//create a reverse iterator call itr for multimap
	multimap<double,int>::reverse_iterator itr;
	
	//traverse the multimap reverse order  
	for(itr=value_density.rbegin();itr!=value_density.rend();itr++){
		
			/* Fraction of volume  of i'th item 
		 that can be store in the knapsack */
		double fraction=(double)N / volume[itr->second]; 
		
		/* if remaining_volume of knapsack is greater 
		 than the volume of i'th barrel */
		if(N>=0 && N>=volume[itr->second]){
			
				/* increase Maximum_value by i'th barrel
			 price value*/
			Maximum_value =	Maximum_value + price[itr->second];
			
				/* decrement knapsack volume to get 
			 new remaining_volume */ 
			N =N- volume[itr->second]; 
		}
		
			/* remaining_volume of knapsack is less than 
		volume of i'th barrel */
		else if (N < volume[itr->second]) { 
			Maximum_value =	Maximum_value + (fraction * price[itr->second]);  //update 	Maximum_value
			break; 
		}
	}
}
