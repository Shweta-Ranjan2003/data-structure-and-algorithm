#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
Given N and K, where N is the sequence of numbers from 1 to N([1,2,3….. N]) 
find the Kth permutation sequence.
for n = 3 , k=3:
"123"
"132"
"213"
"231"
"312"
"321"
Output:- 213

one naive approch would be generating all the permutations and then
sorting it and returning k-1th permutation
*/

/*
*****OPTIMAL APPROACH******
Since this is a permutation we can assume that there are four positions 
that need to be filled using the four numbers of the sequence. First, 
we need to decide which number is to be placed at the first index. 
Once the number at the first index is decided we have three more positions 
and three more numbers.  Now the problem is shorter. We can repeat the 
technique that was used previously until all the positions are filled.

Step 1:-
Lets say N=4 and k=17 . hence the number sequence is {1,2,3,4}.
First we know if we make permutation in sorted manner than among 4 position
first position we be filled in order like 1,2,3,4 . 
Total 4! = 24 permutation will be maded in which
The 0th – 5th permutation will start with 1 
The 6th – 11th permutation will start with 2
The 12th – 17th permutation will start with 3 
The 18th – 23rd permutation will start with 4.

every block contains 6 permutation(i.e 4!/4=6 which is nothing but 3!=6) so in order to get 17th permutation which is basically 
16th permutation in 0-based indexing - we need to find in which block 16th permutation resides.
16/6=2nd block - so 2nd block contains 16th 
Now first value is fixed in permutation that is 3 
Still 3 positions are left {1,2,4};
now from 2nd block we want which sequence? -> 16%6=4th sequence so k=4;


Step 2:-
 Three elements {1,2,4} where K = 4 .
 one position is fixed, the remaining two numbers of each block can form 2! = 2  sequences. In sorted order : 
 The 0th – 1st sequence starts with 1 
The 2nd – 3rd sequence starts with 2 
The 4th – 5th sequence starts with 4
Now we need 4th sequence 4/2=2 -> again are required sequence is in 2nd block
Now 2nd position is also fixed - 3 , 4 
but which sequence of 2nd block -> 4%2=0 it means 0th sequence of 2nd block
k=0;

Step 3:-
Two elements {1 ,2} and K = 0. The remaining number can form only one 1! = 1 sequence. In sorted form –
The  0th sequence starts with 1 
The  1st sequence. starts with 2
The 0th permutation will lie in the (0/1) = 0th block and our answer is the 0%1 = 0th sequence from the 0th block. Therefore 1 occupies the 3rd position and K = 0.
3 4 1


Step 4:-
the only block has 2 in the first position and no remaining number is present.
3 4 1 2
*/

string getPermutation(int n, int k){
    int fact=1;
    vector<int> numbers;
    for(int i=1;i<n;i++){
      fact=fact*i;
      numbers.push_back(i);
    }
    numbers.push_back(n);
    k=k-1;
    string ans="";
    while(true){
     ans= ans + to_string(numbers[k/fact]);
     numbers.erase(numbers.begin()+k/fact);
     if(numbers.size()==0) break;
     k=k%fact;
     fact=fact/numbers.size();
    }
    return ans;
}
int main()
{ 
 cout<<getPermutation(4,17);
 return 0;
}