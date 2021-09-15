










#include <bits/stdc++.h>
using namespace std;

size_t sz;
list< pair<int, int> > l;
unordered_map< int , list< pair<int, int> >::iterator> m;

LRUCache::LRUCache(int capacity) {
    sz = capacity;
}

int LRUCache::get(int key) {
    if(m.find(key) == m.end()) {
        return -1;
    }
    l.splice(l.begin(), l, m[key]);
    return m[key]->second;
}

void LRUCache::set(int key, int value) {
    if(m.find(key) != m.end()) {
        l.splice(l.begin(), l, m[key]);
        m[key]->second = value;
        return;
    }
    if(l.size() == sz) {
        auto d_key = l.back().first;
        l.pop_back();
        m.erase(d_key);
    }
    l.push_front({key,value});
    m[key] = l.begin();
}
