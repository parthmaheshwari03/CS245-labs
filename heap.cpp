#include<bits/stdc++.h>
using namespace std;

int page_size;

map<int,vector<pair<int,int>>> book;//address,-1,key==page_no.
map<int,int> p_size_used;

void search(int pk)
{
    int f = 0;
    for(auto it : book)
    {
        int c = 0;
        for(auto x : it.second)
        {++c;
            if(x.second==pk)
            {
                cout<<it.first<<" "<<c-5<<"\n";
                f=1;
                break;
            }
        }
    }
    if(!f)
    {
        cout<<-1<<" "<<-1<<endl;
    }
}

void status()
{
    cout<<book.size()<<" ";
    for(auto it : book)
    {
        cout<<it.second[2].first<<" ";
    }
    cout<<endl;
}

void insert(int size, int pk)
{
    int cnt = 0;
    if(book.size()==0)
    {
     //  map<int,vector<pair<int,int>>> temp;
       
       book[cnt].push_back({0,-1});
       book[cnt].push_back({cnt+1,-1});
       book[cnt].push_back({1,-1});
       book[cnt].push_back({book[cnt].size()+1,-1});
       book[cnt].push_back({size,pk});
       p_size_used[cnt]=16+size+4;
       //book.push_back(book);
    }
    
    else
    {
        cnt=-1;
        for(auto x : p_size_used)//page in which inserted
        {
            if(page_size-x.second >= size+4)
            {
                cnt=x.first;
                break;
            }
        }
        if(cnt==-1)
        {
            cnt = p_size_used.size();
           // map<int,vector<pair<int,int>>> temp;
       
           book[cnt].push_back({cnt-1,-1});
           book[cnt].push_back({cnt+1,-1});
           book[cnt].push_back({1,-1});
           book[cnt].push_back({book[cnt].size()+1,-1});
       
           book[cnt].push_back({size,pk});
           p_size_used[cnt]=16+size+4;
          // book.push_back(temp);
    
        }
        else
        {
            
            book[cnt].push_back({size,pk});
            p_size_used[cnt]+=size+4;
            book[cnt][2].first++;
            book[cnt][3].first++;
        }
    }
}

int main()
{
    cin>>page_size;
    while(1)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int s,p;
            cin>>s>>p;
            insert(s,p);
        }
        else if(op==2)
        {
            status();
        }
        else if(op==3) 
        {
            int k;
            cin>>k;
            search(k);
        }
        else break;
    }
    return 0;
}