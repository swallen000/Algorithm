#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void dijkstra(int range,int speed,int src,int des,int v,int e,int **w){
	int dis[v];
	int parent[v];
	bool flag[v];
	for(int i=0;i<v;i++){
		dis[i]=1e6;
		flag[i]=false;
		parent[i]=-1;
	}
	dis[src]=0;
	parent[src]=0;
	for(int i=0;i<v;i++){
		int min_index=-1,min_dis=1e6;
		for(int j=0;j<v;j++){
			if(flag[j]==false && dis[j]<min_dis){
				min_index=j;
				min_dis=dis[j];
			}
		}
		//cout<<min_index<<"  here-<"<<endl;
		if(min_index==-1)
			break;
		flag[min_index]=true;
		for(int j=0;j<v;j++){
			if(flag[j]==false && dis[min_index]+w[min_index][j]<dis[j] && w[min_index][j]<range){
				dis[j]=dis[min_index]+w[min_index][j];
				parent[j]=min_index;
			}
		}
	}
	/*for(int i=0;i<v;i++)
		cout<<dis[i]<<" ";
	cout<<endl;
	for(int i=0;i<v;i++)
		cout<<parent[i]<<" ";*/
	vector<int> vec;
	vector<int>::reverse_iterator it;
	for(int i=des;i!=src;i=parent[i]){
		vec.push_back(i);
	}
	cout<<"Route: "<<src<<" ";
	for(it=vec.rbegin();it!=vec.rend();it++)
		cout<<*it<<" ";
	cout<<endl;
	cout<<"Total distance: "<<dis[des]<<endl;
	cout<<"Estimation time:"<<((float)dis[des]/speed)<<endl;
}

int main(){
	int v,e,src,des,range,speed;
	cin>>v>>e;
	int **w=new int *[v];
	for(int i=0;i<v;i++){
		w[i]=new int[v];
		for(int j=0;j<v;j++){
			if(i==j)
				w[i][j]=0;
			else
				w[i][j]=1e6;
		}
	}
	for(int i=0;i<e;i++){
		int a,b,dis;
		cin>>a>>b>>dis;
		w[a][b]=dis;
		w[b][a]=dis;
	}
	/*for(int i=0;i<v;i++){
		for(int j=0;j<v;j++)
			cout<<w[i][j]<<" ";
		cout<<endl;
	}*/
	cin>>range>>speed;
	cin>>src>>des;
	dijkstra(range,speed,src,des,v,e,w);
	for(int i=0;i<v;i++)
		delete [] w[i];
	delete [] w;
	return 0;
}