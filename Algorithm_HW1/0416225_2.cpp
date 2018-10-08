#include <iostream>

using namespace std;

int size;

int quick_find_2d_peak(int a[],int i,int j,int x,int y){
    int mid1=(i+j)/2;
    int mid2=(x+y)/2;
    int l,r,c=0;
    for(int k=x;k<=y;k++){
        if(a[mid1+k*(size+2)]>c){
            c=a[mid1+k*(size+2)];
            l=mid1;
            r=k;
        }
    }
    for(int k=i;k<=j;k++){
        if(a[k+mid2*(size+2)]>c){
            c=a[k+mid2*(size+2)];
            l=k;
            r=mid2;
        }
    }
    if(c>=a[l+r*(size+2)-1]&&c>=a[l+r*(size+2)+1]&&c>=a[l+(r-1)*(size+2)]&&c>=a[l+(r+1)*(size+2)])
        return c;
    else if(c<a[l+r*(size+2)+1]){
        if(r<mid2)
            return quick_find_2d_peak(a,mid1+1,j,x,mid2-1);
        else
            return quick_find_2d_peak(a,mid1+1,j,mid2+1,y);
    }
    else if(c<a[l+r*(size+2)-1]){
        if(r<mid2)
            return quick_find_2d_peak(a,i,mid1-1,x,mid2-1);
        else
            return quick_find_2d_peak(a,i,mid1-1,mid2+1,y);
    }
    else if(c<a[l+(r-1)*(size+2)]){
        if(l<mid1)
            return quick_find_2d_peak(a,i,mid1-1,x,mid2-1);
        else
            return quick_find_2d_peak(a,mid1+1,j,x,mid2-1);
    }
    else{
        if(l<mid1)
            return quick_find_2d_peak(a,i,mid1-1,mid2+1,y);
        else
            return quick_find_2d_peak(a,mid1+1,j,mid2+1,y);
    }
}

int main()
{
    cin>>size;
    while(!cin.eof()){
        int a[size+2][size+2];
        for(int i=0;i<=size+1;i++){
            for(int j=0;j<=size+1;j++)
                a[i][j]=0;
        }
        for(int i=1;i<=size;i++){
            for(int j=1;j<=size;j++)
                cin>>a[i][j];
        }
        cout<<quick_find_2d_peak(a[0],1,size,1,size)<<endl;
        cin>>size;
    }
    return 0;
}
