// HashTable.h

#pragma once

#include <string>
#include <vector>

class HashTableItem {
public:
    std::string key;
    int position;

    HashTableItem(const std::string& k, int pos);
};

class HashTable {
private:
    std::vector<std::vector<HashTableItem>> table;
    int TABLE_SIZE; 

    int hash(const std::string& key);

public:
    HashTable();
    void insert(const std::string& key, int position);
    int find(const std::string& key);
    void remove(const std::string& key); 
};
