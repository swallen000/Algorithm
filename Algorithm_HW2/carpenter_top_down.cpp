#include <iostream>
#include <cstdio>
#define unknown 1e6

using namespace std;

int carpenter_top_down(int *,int **,int,int);

int main(){
	int n,l;
	int *wood,**cost;
	FILE* fd = fopen("output.txt", "w");
	//while(!cin.eof()){
	l=10;
	n=3;
	wood=new int[n+2];
	wood[1]=2;
	wood[2]=4;
	wood[3]=7;
	wood[0]=0;
	wood[n+1]=l;
	cost=new int*[n+1];
	for(int i=0;i<n+1;i++){
		cost[i]=new int[n+2];
		for(int j=0;j<n+2;j++)
			cost[i][j]=0;
	}
	carpenter_top_down(wood,cost,0,n+1);
	fprintf(fd,"%d", cost[0][n+1]);
	delete [] wood;
	for(int i=0;i<n+1;i++)
		delete [] cost[i];
	delete [] cost;
	//}
	return 0;
}

int carpenter_top_down(int *wood,int **cost,int start,int end){
	if(end<start+2)
		return 0;
	else{
		cost[start][end]=unknown;
		for(int i=start+1;i<end;i++){
			int temp=carpenter_top_down(wood,cost,start,i)+carpenter_top_down(wood,cost,i,end)
				+wood[end]-wood[start];
			cost[start][end]=(temp<cost[start][end])?temp:cost[start][end];
		}
		return cost[start][end];
	}
}