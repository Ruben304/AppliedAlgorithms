#ifndef _BF
#define _BF

#include <vector>
#include <string>
#include <bitset>
#include <assert.h>

// (a)

class HashFun {
    public:
    virtual unsigned int operator()(const std::string&) =0;
};

class BloomFilter {
    private:
    std::vector<HashFun*> hash_funs;
    std::bitset<330> filter;
    public:
    BloomFilter() {
        this->add_hash_funs();
        assert(this->hash_funs.size() > 0);
    };
    ~BloomFilter() {
        for (auto it=this->hash_funs.begin(); it != this->hash_funs.end(); ++it) delete *it;
    }
    void add_hash_funs();
    unsigned int call_hash(int k, const std::string& key) { assert(k < this->hash_funs.size()); return (*((this->hash_funs)[k]))(key); }
    void insert(const std::string&);
    bool member(const std::string&);
};

#endif
