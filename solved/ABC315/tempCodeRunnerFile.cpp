o itr = graph.begin();
    // while (itr != graph.end()){
    //     auto key = (*itr).first;
    //     dis[key] = INF;
    //     itr++;
    // }    
    
    // priority_queue<pair<ld,T>,vector<pair<ld,T>>,greater<pair<ld,T>>> que;
    // dis[start] = 0;
    // que.push(make_pair(dis[start],start));
    // while(!que.empty()){
    //     auto p = que.top();
    //     int d = p.first;
    //     T u = p.second;
    //     if (d > dis[u]) continue;
    //     for (auto e: graph[u]){
    //         T v = e.v;
    //         if (dis[v] > dis[u] + e.cost){
    //             dis[v] = dis[u] + e.cost;
    //             que.push(make_pair(dis[v],v));
    //         }
    //     }
    // }