vector<int> A(N);
    vector<int> B(N);
    vector2d graph(N,vector<int>());
    for (int i=0;i<N;i++){
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        graph[A[i]].push_back(i);
        graph[B[i]].push_back(i);
    }