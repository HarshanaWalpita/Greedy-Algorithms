#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

void sortingWeights(int weight[], int n);// declare funtions
void containersNumber(int weight[], int size);

int main(){
	int n;
	int *weight;// pointer
	
	cout<<"Enter number of weights (1<=number<=10^5) you have: "<<endl;
	cin>>n;//get size of array
	
	weight = new int[n];//dynamic weights array
	
	cout<<"Enter "<<n<<" number of weights (0<=weights<10^4) to the array:"<<endl;
	for(int i = 0; i < n; i++){
	cin>>weight[i];	//get inputs to array
	}
	
	sortingWeights(weight, n);//calling functions
	containersNumber(weight, n); 
 	
	return 0;
}

void sortingWeights(int weight[], int n){ //sorting the weights array using insertion sort 
    int i,j; 
	int curr; // current element
    for (i = 1; i < n; i++){  
        curr = weight[i];  
        j = i - 1; 
        while (j >= 0 && weight[j] > curr){  //move elements of weight array
            weight[j + 1] = weight[j];  
            j = j - 1;  
        }  
        weight[j + 1] = curr;  
    }  
}  
  
void containersNumber(int weight[], int size){  //count the number of containers
    int index = 0;
    int container = (size > 0) ? 1 : 0;
    for (int i = 0; i < size; i++) { 
        if (weight[i] > weight[index] + 4) {
            container++;
            index = i;
        }   
    }
	cout<<"Wanted containers number is: "<<container<<endl; //print count of containers
}  

