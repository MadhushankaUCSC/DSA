#include<iostream>
#include<vector>
using namespace std;
//vector<vector<int> > vec;
vector<int> points;
vector<int> mask;
int main(){
	
	int n;
	int j=0;
	cin>>n;
	
	//vec.push_back(points);
	int curr,next;  
	int nom;  //number of masks
	while(j<n-1){
		curr =  points[j];
		next = points[j+1];
		
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
	j=n-1;     // begin of revers check
	while(j>0){
		curr =  points[j];
		next = points[j-1];
		
	
		j--;
	}
	nom=0;      // for calculate number of marks
	for(int i=0;i<n;i++){
		nom = mask[i] + nom;
	}
	cout<<nom;
	return 0;
}
