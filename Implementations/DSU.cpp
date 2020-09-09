struct DSU{
	vector<int> parent, rank, setSize;
	int numSets;
	DSU(int N){
		parent.assign(N, 0);
		for(int i = 0; i < N; ++i){
			parent[i] = i;
		}
		rank.assign(N, 0);
		setSize.assign(N, 1);
		numSets = N;
	}
	int find(int i){
		return parent[i] == i ? i : parent[i] = find(parent[i]);
	}
	bool same(int i, int j){
		return find(i)==find(j);
	}
	int count(int i){
		return numSets;
	}
	int size(int i){
		return setSize[find(i)];
	}
	void unionSet(int i, int j){
		if(same(i, j)){
			return;
		}
		int x = find(i), y = find(j);
		if(rank[x]>rank[y]){
			swap(x, y);
		}
		parent[x] = y;
		if(rank[x] == rank[y]){
			++rank[y];
		}
		setSize[y] += setSize[x];
		--numSets;
	}
};
