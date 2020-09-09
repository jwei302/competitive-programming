struct Trie{
	bool leaf;
	Trie* child[26];
	Trie(){
		this->leaf = 0;
		for(int i = 0; i < 26; ++i){
			this->child[i] = nullptr;
		}
	}
};

void insert(Trie* root, string s){
	for(int i = 0; i < (int)s.length(); ++i){
		if(root->child[s[i]-'a'] == nullptr){
			root->child[s[i]-'a'] = new Trie();
		}
		root = root->child[s[i]-'a'];
	}
	root->leaf = 1;
}

bool search(Trie* root, string s){
	if(root==nullptr){
		return 0;
	}
	for(int i = 0; i < (int)s.length(); ++i){
		root = root->child[s[i]-'a'];
		if(root==nullptr){
			return 0;
		}
	}
	return root->leaf;
}
