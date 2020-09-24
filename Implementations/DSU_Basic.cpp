struct DSU{
	vector<int> parent;
	DSU(int N){
		parent.assign(N, 0);
		for(int i = 0; i < N; ++i)
			parent[i] = i;
	}
	int findSet(int i){
		return parent[i]==i?i:parent[i] = findSet(parent[i]);
	}
	bool isSameSet(int i, int j){
		return findSet(i)==findSet(j);
	}
	void unionFind(int i, int j){
		if(isSameSet(i, j))
			return;
		int x = findSet(i), y = findSet(j);
		parent[x] = y;
	}
}
