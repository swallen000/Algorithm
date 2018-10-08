#include <iostream>
#include <cstdio>
#define unknown 1e6

using namespace std;

int carpenter_bottom_up(int *,int **,int);

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
	fprintf(fd,"%d", carpenter_bottom_up(wood,cost,n+1) );
	delete [] wood;
	for(int i=0;i<n+1;i++)
		delete [] cost[i];
	delete [] cost;
	//}
	return 0;
}
int carpenter_bottom_up(int *wood,int **cost,int num){
	for(int i=2;i<=num;i++){
		for(int j=0;j<=num-i;j++){
			cost[j][j+i]=unknown;
			for(int temp=j+1;temp<j+i;temp++)
				cost[j][j+i]=((cost[j][temp]+cost[temp][j+i]+wood[j+i]-wood[j])<(cost[j][j+i]))?
					cost[j][temp]+cost[temp][j+i]+wood[j+i]-wood[j]:cost[j][j+i];
		}
	}
	return cost[0][num];
}