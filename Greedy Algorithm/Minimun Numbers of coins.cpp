vector<int> coins={1000,500,100,50,20,10,5,2,1};
int findMinimumCoins(int amount) 
{
    int count=0;
    for(int i=0;i<coins.size(); i++){
        while(amount-coins[i]>=0){
            amount-=coins[i];
            count++;
        }
    }
    return count;
}


// ---------------------------------------

int minCoins(int coins[], int M, int V) 
	{ 
	    int table[V+1];
	    table[0]=0;
	    for(int i=1; i<=V; i++){
	        table[i]=INT_MAX;
	    }
	    
	    for(int i=1; i<=V; i++){
	        for(int j=0;j<M; j++){
	            if(coins[j]<=i){
	                int sub_res=table[i-coins[j]];
	                if(sub_res!=INT_MAX && 1+sub_res<table[i])
    	                table[i]=1+sub_res;
	            }
	        }
	    }
	    return (table[V]==INT_MAX)?-1:table[V];
	} 