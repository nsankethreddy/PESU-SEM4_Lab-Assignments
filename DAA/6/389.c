#include "graphSearch.h"
#include<stdbool.h>
#include<stdlib.h>

// Given an unweighted and undirected graph, 
// check if it is a tree topology or not
// Return true/false
bool isTree(int n, const int graph[][n]){
	int* stack = (int*)calloc(n, sizeof(int));
	int* visited = (int*)calloc(n, sizeof(int));
	int top = -1;
	stack[++top] = 0;
	while(top != -1){
		int node = stack[top--];
		visited[node] = 1;
		for(int i=0;i<n;++i){
			if(graph[node][i] && !visited[i])
				stack[++top] = i;
			else if(graph[node][i] && visited[i] && i != node)
				return false; 
		}
	}
	return true;
}

// In FrogLand, Pepe the Frog wants to build a food delivery app after being inspired by Swiggy.
// Frogs in FrogLand are not very friendly and don't allow frogs to jump from 
// HouseX to HouseY if they are enemies. Each house in FrogLand has a safeSequence 
// that mentions which houses are safe to jump onto, from the current house.
// No two frogs can cover the same house. Houses are numbered from 0 to n-1.
// Your task is to help Pepe find how many delivery frogs are required for his swamp,
// and to find the maximum number of houses any delivery agent has to visit.
// Note: Frogs can start at any house initially.
// Return a structure Result, with its members assigned.
Result pepesAnswers(int n, const int safeSeq[][n]){
	int* stack = (int*)calloc(n, sizeof(int));
	int top = -1;
	int* visited = (int*)calloc(n, sizeof(int));
	int numVisited = 0;
	int highestCount = 0;
	int numberOfFrogs = 0;
	while(numVisited < n){
		int firstUnvisitedHouse;
		for(int i=0; i<n; ++i){
			if(!visited[i]){
				firstUnvisitedHouse = i;
				visited[i] = 1;
				++numberOfFrogs;
				break;				
			}
		}
		stack[++top] = firstUnvisitedHouse;
		int count = 0;
		while(top != -1){
			++numVisited;
			++count;
			int node = stack[top--];
			visited[node] = 1;
			for(int i=0;i<n;++i){
				if(safeSeq[node][i] && !visited[i]){
					stack[++top] = i;
					visited[i] = 1;
				}
			}
		}
		if(count > highestCount)
			highestCount = count;
	}
	Result temp;
	temp.numDeliveryFrogs = numberOfFrogs;
	temp.maxHouses = highestCount;
	return temp;
}

// The swamp has now grown in population, and hence there are more frog houses.
// A delivery frog can only jump over 'k' houses at a time. 
// ie. A frog can jump from HouseX to HouseY only if abs(X-Y) <= k
// Hence modify your above solutions to account for this.
Result pepesAnswersWithK(int n, const int safeSeq[][n], int k){
	Result temp;
	temp.numDeliveryFrogs = 3;
	temp.maxHouses = 2;
}

