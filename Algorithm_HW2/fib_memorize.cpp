#include <iostream>
#include <cstdio>

using namespace std;

int fib_memorize(int,unsigned long long int *);

int main(){
	int num=7;
	unsigned long long int *fib;
	//while(!cin.eof()){
	FILE* fd = fopen("output.txt", "w");
	fib=new unsigned long long int [num+1];
	for(int i=0;i<=num;i++){
		if(i==1||i==2)
			fib[i]=1;
		else
			fib[i]=0;			
	}
	fprintf(fd,"%d", fib_memorize(num,&fib[0]) );	
	//	cout<<fib_memorize(num,&fib[0])<<endl;
	//}	
	delete [] fib;
	return 0;
}

int fib_memorize(int num,unsigned long long int *temp){
	if(temp[num]==0){
		temp[num]=fib_memorize(num-1,&temp[0]) + fib_memorize(num-2,&temp[0]);
		return temp[num];
	}
	else
		return temp[num];
}