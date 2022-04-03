#include <bits/stdc++.h> 
using namespace std;

#define ll long long
#define rep(i, a, b) for(ll i=a; i<b; i++)
#define mod 1000000007

ll solve(){
    ll bucket_count = 0;
    ll global_depth;
    ll bucket_capacity;
    cin>>global_depth>>bucket_capacity;

    map<ll, vector<ll>*> directory;
    map<vector<ll>*, ll> local_depth;
    map<ll, vector<ll>*> buckets;

    ll x = pow(2,global_depth);

    rep(i, 0, x){
        vector<ll>*w;
        w = new vector<ll>();
        buckets[bucket_count++] = w;
        directory[i] = w;
        local_depth[directory[i]] = global_depth;
        
    }    

    while(1){
        // cout<<"yo";
        ll input;
        cin>>input;

        if(input == 2){
            ll val;
            cin>>val;
            // cout<<"hi";
            // cout<<val<<" "<<val%x<<endl;
            while(1){
                // cout<<'?'<<endl;
                if(directory[val%x]->size() == bucket_capacity){
                    if(local_depth[directory[val%x]] < global_depth){
                        ll old_depth = local_depth[directory[val%x]];
                        ll new_depth = old_depth+1;
                        local_depth[directory[val%x]]++;

                        vector<ll>*w;
                        w = new vector<ll>();
                        buckets[bucket_count++] = w;

                        ll old = val%(ll)pow(2,old_depth);
                        ll nw = val%(ll)pow(2,old_depth) + pow(2,old_depth);

                        directory[nw] = w;

                        rep(i, 0, directory[old]->size()){
                            ll element = directory[old]->at(i);
                            if(element % (ll)pow(2,new_depth) == element % (ll)pow(2,old_depth)){
                                
                            }
                            else{
                                directory[old]->erase(directory[old]->begin() + i);
                                i--;
                                directory[nw]->push_back(element);
                            }
                        }

                    }
                    else{
                        ll old = val%x;
                        global_depth++;
                        x *= 2;
                        rep(i, x/2, x){
                            directory[i] = directory[i-x/2];
                        }
                        vector<ll>*w;
                        w = new vector<ll>();
                        buckets[bucket_count++] = w;

                        directory[old + x/2] = w;
                        ll nw = old + x/2;

                        local_depth[directory[old]]++;
                        local_depth[directory[nw]] = local_depth[directory[old]];

                        rep(i, 0, directory[old]->size()){
                            ll element = directory[old]->at(i);
                            if(element % x == element % (x/2)){
                                
                            }
                            else{
                                directory[old]->erase(directory[old]->begin() + i);
                                i--;
                                directory[nw]->push_back(element);
                            }
                        }
                    }
                }

                else{
                    (*directory[val%x]).push_back(val);
                    break;
                }
            }
        }

        else if(input == 3){
            ll y;
            cin>>y;
            bool b = false;

            rep(i, 0, directory[y%x]->size()){
                if(directory[y%x]->at(i) == y){
                    b = true;
                }
            }

            if(!b){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }

        else if(input == 4){
            ll y;
            cin>>y;
            
            rep(i, 0, directory[y%x]->size()){
                if(directory[y%x]->at(i) == y){
                    directory[y%x]->erase(directory[y%x]->begin() + i);
                }
            }
        }

        else if(input == 5){
            for(auto a:buckets){
                cout<<a.second->size()<<" "<<local_depth[a.second];
                cout<<endl;
            }
        }

        if(input == 6){
            break;
        }
    }

    

    return 0;
    }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
