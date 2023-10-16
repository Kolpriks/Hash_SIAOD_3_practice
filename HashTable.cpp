// HashTable.cpp

#include "HashTable.h"

HashTableItem::HashTableItem(const std::string& k, int pos) : key(k), position(pos) {}

HashTable::HashTable() {
    TABLE_SIZE = 1000;
    table.resize(TABLE_SIZE);
}

int HashTable::hash(const std::string& key) {
    unsigned int sum = 0;
    for (char c : key) {
        sum += static_cast<int>(c);
    }
    return sum % TABLE_SIZE;
}



void HashTable::insert(const std::string& key, int position) {
    int index = hash(key);
    table[index].emplace_back(key, position);
}

int HashTable::find(const std::string& key) {
    int index = hash(key);
    for (const HashTableItem& item : table[index]) {
        if (item.key == key) {
            return item.position;
        }
    }
    return -1; 
}

void HashTable::remove(const std::string& key) {
    int index = hash(key);
    auto& bucket = table[index];

    for (auto it = bucket.begin(); it != bucket.end(); ++it) {
        if (it->key == key) {
            bucket.erase(it);
            return; 
        }
    }
}