node<int> *top = solver.list_nodes[0].front_node;
    vector<int> edge2index(N,0);
    int count = 0;
    while(top->next_pointer){
        int index = (*top).value;
        edge2index[index] = count;
        count++;
        *top = *top->next_pointer;
        
    }
    int index = (*top).value;
    edge2index[index] = count;
    rep(i,N){
        cout << edge2index[i] << endl;
    }
    vector<ll> ans(N+1,0);
    UnionFind solver1(N);
    rep(i,N-1){
        int rx = solver1.root(p[i]);
        int ry = solver1.root(q[i]); 
        ll rx_size = solver1.connection_size[rx];
        ll ry_size = solver1.connection_size[ry];
        int index_rx = edge2index[rx];
        int index_ry = edge2index[ry];
        // cout << index_rx <<" " <<  rx_size<< endl;
        // cout << index_ry <<" " <<  ry_size<< endl;
        ans[index_rx] += rx_size*inv(rx_size+ry_size) % mod;
        ans[index_rx + rx_size] -= rx_size*inv(rx_size+ry_size) % mod;
        ans[index_ry] += ry_size*inv(rx_size+ry_size) % mod;
        ans[index_ry + ry_size] -= ry_size*inv(rx_size+ry_size) % mod;
        solver1.unite(p[i],q[i]);
    }
    rep(i,N){
        ans [i+1] += ans[i];
        ans[i+1] %= mod;
        if (ans[i+1] < 0) ans[i+1] += mod;
    }
    rep(i,N){
        cout << ans[i] << " ";
    }
    