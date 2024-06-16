rity_queue<pair<int,int>> que;
    que.push(make_pair(1,roots[0]));
    vector<int> ans(n,0);
    ans[roots[0]] = 1;
    while(!que.empty()){
        pair<int,int> p = que.top();
        que.pop();
        int u = p.second;
        for (int v:graph[u]){
            if (a[v] > a[u]  & ans[v] < ans[u] + 1){
                que.push(make_pair(ans[u] + 1, v));
                ans[v] = ans[u] + 1;
            }
        }
    }