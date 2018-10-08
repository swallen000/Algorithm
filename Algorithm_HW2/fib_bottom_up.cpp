#include <iostream>
#include <cstdio>

using namespace std;

int fib_bottom_up(int,unsigned long long int *);

int main(){
	int num=7;
	unsigned long long int *fib;	
	FILE* fd = fopen("output.txt", "w");
	fib=new unsigned long long int [num+1];
	for(int i=0;i<=num;i++){
		if(i==1||i==2)
			fib[i]=1;
		else
			fib[i]=0;
	}
	fprintf(fd,"%d", fib_bottom_up(num,&fib[0]) );
	delete [] fib;
	return 0;
}

int fib_bottom_up(int num,unsigned long long int *temp){
	for(int i=3;i<=num;i++){
		temp[i]=temp[i-1]+temp[i-2];
	}
	return temp[num];
} 