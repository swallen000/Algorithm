#include <iostream>
#include <cstdio>

using namespace std;

int fib_recursive(int);

int main(){
	int num=7;
	//while(!cin.eof()){
	FILE* fd = fopen("output.txt", "w");
	fprintf(fd,"%d", fib_recursive(num));	
	//}
	return 0;
}

int fib_recursive(int num){
	if(num==1)
		return 1;
	else if(num==2)
		return 1;
	else 
		return fib_recursive(num-1)+fib_recursive(num-2);
}