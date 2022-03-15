#include <bits/stdc++.h>
#include <unordered_set>                
/*
Hash Table is a data structure which organizes data using hash functions in order to support quick insertion and search.

There are two different kinds of hash tables: hash set and hash map.

The hash set is one of the implementations of a set data structure to store no repeated values.
The hash map is one of the implementations of a map data structure to store (key, value) pairs.

Maps- Maps (also known as Dictionaries) are data structures stores a collection of key-value pairs. Each key is unique and allows for quick access to values. A real life example of a map could be storing the grades for students in a class (student name is key, grade is value).

When we insert a new key hash function decides in which bucket that key will be stored and while searching that same hash function is used to find that bucket
eg:- key     Hash function(y=x%5)   bucket(0 1 2 3 4 5)
     0                                0
     1987                             2
     24                               4
     2                                2
Search - if we will search 1987 then it will map it using same hash function and search it in 2 buncket
if we search 23 then it will search it in bucket 3 and if its empty then 23 is not in hash table

*/

int main() {
    // 1. initialize a hash set
    unordered_set<int> hashset;   
    // 2. insert a new key
    hashset.insert(3);
    hashset.insert(2);
    hashset.insert(1);
    // 3. delete a key
    hashset.erase(2);
    // 4. check if the key is in the hash set
    if (hashset.count(2) <= 0) {
        cout << "Key 2 is not in the hash set." << endl;
    }
    // 5. get the size of the hash set
    cout << "The size of hash set is: " << hashset.size() << endl; 
    // 6. iterate the hash set
    for (auto it = hashset.begin(); it != hashset.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << "are in the hash set." << endl;
    // 7. clear the hash set
    hashset.clear();
    // 8. check if the hash set is empty
    if (hashset.empty()) {
        cout << "hash set is empty now!" << endl;
    }
    return 0;
}