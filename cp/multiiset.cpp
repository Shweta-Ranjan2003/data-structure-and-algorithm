#include <iostream>
#include <set>
using namespace std;

int main()
{ 
 multiset<int>ms;
 ms.insert(10);
 ms.insert(20);
 ms.insert(30);
 ms.insert(30);
 ms.insert(40);
 ms.insert(50);
 ms.insert(50);

 multiset<int>::iterator it;
 it=ms.lower_bound(32);
 cout<<*it<<endl; //40 if not got matched value then returns next bigger value
 it=ms.upper_bound(40);
 cout<<*it<<endl; //50
 it=ms.end();
 cout<<*it; //7 
 return 0;
}

//binary search will happend when you know the range and its monotonic graph (not increase then decrease then increase)
//set - takes log n time because it uses self balancing binary tree- red black , avl so your search insert takes log n
//unordered set- takes O(1) on average because it uses hash function to store data but in worst case if there are many value store on same hash functioned index
// then it will take O(n)

//same for map and unordered map