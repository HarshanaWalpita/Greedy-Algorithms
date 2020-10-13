#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char character;
	int frequency;
	struct node *leftnode;
	struct node *rightnode;
}newnode;

newnode *newheap[100];
int size=0;

void Insertion(newnode *value){
	size++;
	newheap[size]=value;
	int current = size;
	
	while(newheap[current/2]->frequency>value->frequency){
		newheap[current]=newheap[current/2];
		current/=2;
	}
	
	newheap[current]=value;
}

newnode *minimum(){
	newnode *minVal,*finalVal;
	int c, current;
	minVal=newheap[1];
	finalVal=newheap[size--];
	
	for(current=1; current*2 <= size; current=c){
		c=current*2;
		
		if(c != size && newheap[c+1]->frequency < newheap[c] -> frequency ){
                        c++;
        }
		
		if(finalVal->frequency > newheap[c]->frequency){
			newheap[current]=newheap[c];
		}
		else{
			break;
		}
	}
	
	newheap[current] = finalVal;
	
	return minVal;
}

void printTree(newnode *val, char *boolean){
	if(val->leftnode == NULL && val->rightnode ==NULL){
		printf(" Relevant code %s\n",boolean);
		return;
	}
	
	int a=strlen(boolean);
	char left[10],right[10];
	strcpy(left,boolean);
	strcpy(right,boolean);
	left[a]='0';
	left[a+1]='\0';
	right[a]='1';
	right[a+1]='\0';
	printTree(val->leftnode,left);
	printTree(val->rightnode,right);
}

int main(){
	newheap[0]=(newnode *)malloc(sizeof(newnode));
	newheap[0]->frequency=0;
	
	int m;
	
	printf("Input the number of students in the class:");
	scanf("%d",&m);
	
	printf("Input the scores of the students:");
	char character;
	int frequency,i,k=1,array[64],sum;
	
	for(i==0;i<m;i++){
		scanf("%c",&character);
		scanf("%d",&frequency);
		newnode * val = (newnode *) malloc(sizeof(newnode));
        val -> character = character;
        val -> frequency = frequency;
        val -> leftnode = val -> rightnode = NULL;
        Insertion(val);
	}
	
	if(m==1){
        printf("code 0\n");
        return 0;
    }
    
    for(i=0;i<m-1 ;i++){
        newnode * leftnode = minimum();
        newnode * rightnode = minimum();
        newnode * val = (newnode *) malloc(sizeof(newnode));
        val -> character = 0;
        val -> leftnode = leftnode;
        val -> rightnode = rightnode;
        val -> frequency = leftnode->frequency + rightnode -> frequency;
        Insertion(val);
    }
    
    
    newnode *valTree = minimum();
    char boolean[10];
    boolean[0] = '\0';
    printTree(valTree,boolean);
    
    printf("\nEnter the scores again ");
    
    for (i = 0; i < m; i++){
        
		scanf("%d", &array[i]);
		
    }
    
    
    for (i = 2 ; i <= m - 1; i++)
    {
        if(array[i-1] >= array[i] >= array[i+1]){
            array[i-1]=k+2;
            array[i]=k+1;
            array[i+1]=k;
		}
		else if(array[i-1] >= array[i] <= array[i+1]){
			array[i-1]=k+1;
            array[i]=k;
            array[i+1]=k+1;
		}
		else if(array[i-1] <= array[i] <= array[i+1]){
			array[i-1]=k;
            array[i]=k+1;
            array[i+1]=k+2;
		}
		else if(array[i-1] <= array[i] >= array[i+1]){
			array[i-1]=k;
            array[i]=k+1;
            array[i+1]=k;
		}
		else{
			array[i-1]=k;
            array[i]=k+1;
            array[i+1]=k+2;
		}
			
		k=1;
    }
    
    
    
    for (i = 0; i <= m - 1; i++){
    	
        printf("%d\n", array[i]);
        sum+=array[i];
        
    }
    
    printf("Total number of masks is : %d",sum-2);
    
}

