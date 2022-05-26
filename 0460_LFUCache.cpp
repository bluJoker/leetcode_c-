struct Node {
    int key, val;
	int cnt, time;
	Node(int _key, int _val): key(_key), val(_val), cnt(1), time(1) {}
	bool operator<(const Node& w) {
		if(cnt == w.cnt) return time < w.time;
		else return cnt < w.cnt;
	}
};

class LFUCache {
private:
    //unordered_map<int, Node> umap;
	//set<Node> tset;
	map<int, Node> M;
	int capacity;
public:
    LFUCache(int _capacity): capacity(_capacity) {
		
    }
    
    int get(int key) {
        //if(umap.count(key) == 0) return -1;
		//Node p = tset.
		if(!M.count(key)) return -1;
		Node p = M[key];
		M.erase(key);
		p.cnt++;
		p.time++;
		M[key] = p;
		return p.val;
    }
    
    void put(int key, int value) {
        if(M.count(key) == 0) {
			M[key] = Node(key, value);
			if(M.size() > capacity)
			    M.erase(M.begin()->key);
		} else {
			Node p = M[key];
		    M.erase(key);
		    p.cnt++;
		    p.time++;
		    M[key] = p;
		}
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */