#include <iostream>

using namespace std;

int quick_find_1d_pick(int a[],int left,int right,int size){
    int mid=(left+right)/2;
    if((mid==0&&a[mid]>=a[mid+1])||(mid==size-1&&a[mid]>=a[mid-1]))
        return mid;
    else if(mid!=0&&mid!=size-1){
        if(a[mid]>=a[mid-1]&&a[mid]>=a[mid+1])
            return mid;
        else if(a[mid]<a[mid-1])
            return quick_find_1d_pick(a,left,mid-1,size);
        else
            return quick_find_1d_pick(a,mid+1,right,size);
    }
    else if(mid==0)
        return quick_find_1d_pick(a,1,right,size);
    else if(mid==size-1)
        return quick_find_1d_pick(a,left,size-1,size);
    else
        return -1;
}

int main()
{
    int size,pos;
    cin>>size;
    while(!cin.eof()){
        int a[size];
        for(int i=0;i<size;i++)
            cin>>a[i];
        pos=quick_find_1d_pick(a,0,size-1,size);
        if(pos!=-1)
            cout<<a[pos]<<endl;
        else
            cout<<"not found"<<endl;
        cin>>size;
    }
    return 0;
}
