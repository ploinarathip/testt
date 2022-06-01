#include <iostream>
#include <vector>
#include <cstring>
#include <bits/stdc++.h>
#include <queue>

using namespace std;

int count_color(vector<int> &v,int step){
    int ans = 1;
    for(int i=0;i<step;i++){
        if(v[i] > ans) ans = v[i];
    }
    return ans;
}

bool check(vector<int> &v,vector<vector<int>> &adj,int step,int col){
    for(int i=0;i<adj[step].size();i++){
        if(v[adj[step][i]] == col)return false;
    }
    return true;
}

void gen_color(vector<int> &v,int step,int n,int &minCol,vector<vector<int>> &adj){
    if(step == n){
        if(count_color(v,step)< minCol)minCol = count_color(v,step);
    }else{
        for(int i=1;i<=n;i++){
            if(i >= minCol) return;
            if(check(v,adj,step,i)){
                v[step] = i;
                gen_color(v,step+1,n,minCol,adj);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,e;
    cin >> n >> e;
    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> color(n);
    int minCol = n;
    gen_color(color,0,n,minCol,adj);
    cout << minCol;
}
