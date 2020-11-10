#include<iostream>
#include<vector>

using namespace std;


int main(){
	
	int n;
	int j=0;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int val;
		cin>>val;
		points.push_back(val);
		mask.push_back(j);
	}
	//vec.push_back(points);
	
	

		
		if(curr>next){
			if(mask[j]==0){
				//nom=1;  vec.insert(vec.begin() + i, 7); 
				mask.insert(mask.begin()+j,2);			//mask[j]=2;
				mask.insert(mask.begin()+(j+1),2);		//mask[j+1]=1;
			}
			else{
				mask.insert(mask.begin()+(j+1),1);       //mask[j+1]=1;
			}	
		}	
		if(curr<next){
			if(mask[j]==0){
				mask.insert(mask.begin()+j,1);				//mask[j]=1;
				mask.insert(mask.begin()+(j+1),2);			//mask[j+1]=2;
			}
			else{
				nom = mask[j];
				mask.insert(mask.begin()+(j+1),nom+1);		//mask[j+1]=mask[j]+1;
			}
		}
		else{    //curr=next
			if(mask[j]==0){
				mask.insert(mask.begin()+j,1);		
				mask.insert(mask.begin()+(j+1),1);											
															
			}
			else{
				mask.insert(mask.begin()+(j+1),1);				//mask[j+1]=1;
			}
		}
		
		j++;	
	}

