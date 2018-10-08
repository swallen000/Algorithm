#include <iostream>
#include <queue>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

void setcode(string,const int,const int);
void dfs(int,int,string);

struct node{
    int l,r;
    int freq;
    int leaf;
    int pos;
    unsigned char c;
};

struct cmp{
    bool operator()(node &a,node &b){
        if(a.freq!=b.freq)
            return a.freq>b.freq;
        return a.leaf>b.leaf;
    }
};

node tree[1024];
node ini[1024];
unsigned char acode[256][512];

void huffmancode_tree(){
    string input;
    int ascii[256]={};
    int i,size;
    cin>>noskipws;
    getline(cin, input);
    for(i=0;i<input.size();i++)
        ascii[input[i]]++;
    priority_queue<node,vector<node>,cmp> pq;
    for(i=0,size=0;i<256;i++){
        if(ascii[i]!=0){
            size++;
            /*ini[size].l=0;      //null
            ini[size].r=0;      //null*/
            ini[size].pos=size;
            ini[size].leaf=1;
            ini[size].freq=ascii[i];
            ini[size].c=i;
            pq.push((node)ini[size]);
        }
    }
    for(i=1;i<=size;i++){
        tree[i]=ini[i];
    }
    node a,b;
    while(pq.size()>1){
        a=pq.top(); pq.pop();
        b=pq.top(); pq.pop();
        size++;
        ini[size].pos=size;
        ini[size].l=a.pos;
        ini[size].r=b.pos;
        ini[size].leaf=a.leaf+b.leaf;
        ini[size].freq=a.freq+b.freq;
        tree[size]=ini[size];
        pq.push((node)ini[size]);
    }
    for(i=1;i<=size;i++){
        cout<<tree[i].l<<" "<<tree[i].r<<"  "<<tree[i].freq<<"  "<<tree[i].c<<endl<<endl;
    }
    setcode(input,size,input.size());
}

void setcode(string s,const int size,const int length){
    string code;
    queue<int> que;
    dfs(size,0,code);
    for(int i=0;i<length;i++){
        for(int j=0;acode[s[i]][j];j++){
            cout<<acode[s[i]][j]-48;
            que.push(acode[s[i]][j]-48);
        }
        cout<<endl;
    }
    cout<<endl;
    int temp,temp2;
    temp2=size;
    while(que.size()>0){
        temp=que.front();
        que.pop();
        if(temp==0){
            temp=tree[temp2].l;
            if(tree[temp].l==0 && tree[temp].r==0){
                cout<<tree[temp].c;
                temp2=size;
            }
            else
                temp2=temp;
        }
        else if(temp==1){
            temp=tree[temp2].r;
            if(tree[temp].l==0 && tree[temp].r==0){
                cout<<tree[temp].c;
                temp2=size;
            }
            else
                temp2=temp;
        }
    }
    cout<<endl;
}


void dfs(int pos, int start,string code){
    if(tree[pos].l!=0&&tree[pos].r!=0){
        code+="0";
        dfs(tree[pos].l,start+1,code);
        code.erase(code.begin()+start);
        code+="1";
        dfs(tree[pos].r,start+1,code);
    }
    /*else if(tree[pos].l!=0&&tree[pos].r==0){
        code+="0";
        dfs(tree[pos].l,start+1,code);
    }
    else if(tree[pos].l==0&&tree[pos].r!=0){
        code+="1";
        dfs(tree[pos].r,start+1,code);
    }*/
    else{
        //code[start]="\0";
        for(int i=0;i<start;i++)
            acode[tree[pos].c][i]=code[i];
        return;
    }
}

int main(){
    /*char s;
    scanf("%s",&s);
    printf("%d ",s);*/
    huffmancode_tree();
    return 0;
}
