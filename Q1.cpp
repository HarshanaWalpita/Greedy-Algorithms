#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct {
   int value;
   int count;
   float d;
} Item;

// Comparison function to sort object according to value/count ratio
bool compare(Item i1, Item i2) {
   return (i1.d > i2.d);
}

float knapsack(Item items[], int M, int W) {
   int i, j, pos;
   Item mx, temp;
   float totalValue = 0, totalcount = 0;
   for (i = 0; i < M; i++) {
      items[i].d = items[i].value / items[i].count;
   }
   
    //    sorting object on basis of ratio 
   sort(items, items+M, compare);
   for(i=0; i<M; i++) {
      if(totalcount + items[i].count<= W) {
         totalValue += items[i].value ;
         totalcount += items[i].count;
      } else {
         int wt = W-totalcount;
         totalValue += (wt * items[i].d);
         totalcount += wt;
         break;
      }
   }
   return totalValue;
}

int main() {
   int W;
   int N,M;
 //  cout<<"Input:"<<endl;
 //std::cout <<"No of bottles Sandun brougt: & No of barrels in the yard:";
  cin>>N>>M;
  Item items[M];
   //std::cout <<"volume of barrels in bottles"<<endl;
  for(int i=0; i<M; i++){
  cin >> items[i].count;
}
//std::cout <<"Price of each barrels"<<endl;
for(int i = 0; i< M; i++) {
      cin >> items[i].value;
  }
   
   float mxVal = knapsack(items, M, N);
   cout <<endl<< "Maximum value of wine Sandun gets:"<<endl<< mxVal;

}
