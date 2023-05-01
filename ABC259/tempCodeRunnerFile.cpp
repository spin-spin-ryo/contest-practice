int N;cin >> N;
    vector<int> d(N);
    for (int i=0;i<N;i++) cin >> d[i];
    int u,v,w;
    vector<tuple<int,int,int> > edge(N-1);
    for (int i=0;i<N-1;i++){
        cin >> u >> v >> w;
        edge[i] = make_tuple(w,