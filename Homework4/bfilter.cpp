#include <vector>
#include "bfilter.h"

// not used 
class SillyHashFun : public HashFun {
    unsigned int operator()(const std::string& key) {
        // Here's my silly hash function that always returns 0.
        // You should make some good hash functions and not use this one.
        // This is just an example of how to inherit the HashFun class.
        // just an ex
        return 0;
    }
};

// 
class GoodHashFun_0 : public HashFun {
    unsigned int operator()(const std::string& key) {
        // You've seen my silly hash function above.
        // Your good hash function should go here!
        unsigned int asciiSum = 0;
        for (int i = 0; i < key.length(); i++){
            asciiSum = asciiSum + key[i]; // here the hash is calculating the sum of ascii values in input string
        }
        return asciiSum; 
    }
};

// ...
// You can make as many hash functions as you want!
// ...

class threethree_HashFun : public HashFun  {
    unsigned int operator()(const std::string& key){
        int hash = 0;
        for (int i = 0; i < key.length(); i++) // creates the hash from the ascii character indexed times that 31 to the i power
            hash += key[i] * pow(31, i);  // 31 is good since it is an odd and prime number told in discussion to reduce collisions & online said to be preffered since tis representationin biary
        return hash;
    }
};

void BloomFilter::add_hash_funs() {
    // You will need to implement this function, it is responsible
    // for adding your custom hash functions to your bloom filter.

    // Here's an example where I add two hash functions.
    // You will need to add at least one hash function.
    threethree_HashFun *h1 = new threethree_HashFun(); // modified to my hash
    GoodHashFun_0 *h2 = new GoodHashFun_0();
    this->hash_funs.push_back(h1);
    this->hash_funs.push_back(h2);
}

void BloomFilter::insert(const std::string& key) {
    // You will need to implement this function, it is responsible
    // for inserting key into the bloom filter.

    // Here's how you can call your hash functions that you added in add_hash_funs()
    // unsigned int first_hash_result = this->call_hash(0, key);
    // std::cout << "Hash of '" << key << "' is '" << first_hash_result << "' using the first hash function." << std::endl;
    // unsigned int second_hash_result = this->call_hash(1, key);
    // std::cout << "Hash of '" << key << "' is '" << second_hash_result << "' using the second hash function." << std::endl;

    // You'll need to use the results of the hash function to update this->filter
    // Here's an example
    for (int i = 0; i < hash_funs.size(); i++){ // makes the hashvalue of of the functions and sets the respective bits to 1
        (this->filter)[this -> call_hash(i,key) % 330] = 1;
    }
}

bool BloomFilter::member(const std::string& key) {
    // This function should report true if key is potentially in the bloom filter.
    // It should only return false if you know for sure that key is not in the bloom filter.

    //
    // your code here ...
    int count = 0; 
    for(int i = 0; i < hash_funs.size(); i++){  
        if((this->filter)[this->call_hash(i, key) % 330] == 1) 
            count++;
        if (count == hash_funs.size()) // once it has gone through, there is a check to see if the number of 1 bits is same as expected
            return true; //if so it is a possible yes
    }

    return false; // the case that not all the expected bits are 1 then it is false 
}
