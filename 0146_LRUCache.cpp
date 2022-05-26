struct Node{
	int key, val;
	Node *prev, *next;
	Node(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
	unordered_map<int, Node*> hmap;
	Node *head, *tail;
	int capacity;
public:
    LRUCache(int _capacity): capacity(_capacity) {
		head = new Node(-1, -1), tail = new Node(-1, -1);
		head->next = tail;
		tail->prev = head;
    }
    
    int get(int key) {
		if(hmap.count(key) == 0) return -1;
		// 如果 key 存在，先通过哈希表定位，再移到头部
		Node *p = hmap[key];
		remove(p);
		addToHead(p);
		return p->val;
    }
    
    void put(int key, int value) {
		if(hmap.count(key) != 0) {
			Node *p = hmap[key];
			//更新hash
			p->val = value;
			//更新链表
			remove(p);
			addToHead(p);
		} else {
			Node *p = new Node(key, value);
			hmap[key] = p;
			addToHead(p);
			//缓存已满
			if(hmap.size() > capacity) {
				Node *p = tail->prev;
				remove(p);
				hmap.erase(p->key);
				delete(p); // 防止内存泄漏
			}
		}
    }
	
	void remove(Node *p) {
		p->prev->next = p->next;
		p->next->prev = p->prev;
	}
	
	void addToHead(Node *p) {
		p->prev = head;
		p->next = head->next;
		head->next->prev = p;
		head->next = p;
		
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */