#include<stdlib.h>
#include<limits.h>
int get_next_permutation(int *permutation, int n);
int tsp(int n, int graph[][n]){
       
       int comb[n-1];
       for(int i=0;i<n-1;i++){
                comb[i]=i+1;      
        }
        int mincost=INT_MAX;
        do{
                int cost=graph[0][comb[0]];
                cost=cost+graph[comb[n-2]][0];
                for(int i=0;i<n-2;i++){
                        cost=cost+graph[comb[i]][comb[i+1]];
                }
                if(cost<mincost)
                mincost=cost;
        }
        while(get_next_permutation(comb,n-1));
       return mincost;  
}

int* printPath(int n, int graph[][n]){
        int mincost=tsp(n,graph);
        int *a=(int *)malloc(sizeof(int)*n);
        a[0]=0;
        int p[n-1];
        for(int i=0;i<n;i++){
                p[i]=i+1;
         
        }
        do{
                int cost=graph[0][p[0]];
                cost=cost+graph[p[n-2]][0];
                for(int i=0;i<n-2;i++){
                        cost=cost+graph[p[i]][p[i+1]];
                }
                if(cost==mincost){
                        for(int j=0;j<n-1;j++){
                                a[j+1]=p[j];
                        }
                        break;
                }
               
        }
        while(get_next_permutation(p,n-1));
        return a;


}

int getCost(int n, int graph[][n], int *p){
        int c=graph[0][p[0]];
        c=c+graph[p[n-1]][0];
        for(int i=0;i<n-1;i++){
                c=c+graph[p[i]][p[i+1]];
       
        }
        return c;
}
