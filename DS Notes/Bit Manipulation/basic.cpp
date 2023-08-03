#include <iostream>
#include <string>
using namespace std;
/*
Binary number are expressed in the base-2 numeral system.
1101 - 1.2^3 + 1.2^2 + 0.2^1 + 1.2^0 = 13

negative no. are mostly stored in the form of two's complement i.e
8 = 1000
-8 = 0111 + 1 (1's complement +1) = 1000
here leading 1 represent negative no.
2's complement of x = 2^32 - x (here 32 is no. of bit)
x=3  0011
     1100
       +1
     ----
     1101  -> -13 (2^4 - 3 = 13)
     ----


Bitwise operator -
      AND & , OR | , XOR ^ , NOT ~ (flips all the bit)
0 0 -  0       0      0        
1 0 -  0       1      1
0 1 -  0       1      1
1 1 -  1       1      0

unsigned integer range - 0 to 2^32 -1
signed integer range  -  -2^31 to 2^31 -1

We do not use sign bit ( eg -3 = 1000...11) and 1's complement for negative number representation because then we will have two representation of 0

Shift operator :-
Right shift operaton (>>):- shifts number to the right and adds zero in the front.
each shift by one represents an integer division by 2. so right shift to k - integer division by 2^k

Left shift operaton (<<):- shifts number to the left and adds zero in the end.
each shift by one represents an integer multiplication by 2. so left shift to k - integer multiplication by 2^k


*/
bool LastBit(int n){
    if((n&1)!=0) return true;
    return false;
}
bool KthBit(int n , int k){
    //If k=3 then left shift 1 by k-1 times that is 2 = 100 then and with n
    // basically and with the no. 2^k-1 -> 2^3-1 = 4 = 100;

    /*Naive approach
    for(int i=0;i<k-1;i++){
        x=x*2; 
        //or
        n=n/2;
    }
    if((n&x)!=0) return true;
    else return false;
    OR
    if((n&1)!=0) return true;
    else return false;
    */

   int x=(1<<(k-1));
   if((n&x)!=0) return true;
   return false;

   /*
   int x=(n>>(k-1));
   if((x&1)!=0)return true;
   return false;
   */
}

void SetithBit(int &n , int k){
    n= n|(1<<(k-1));
    /*
    1011 - n=11 , k=3
    0100
    ----
    1111 - 15
    ----
    */
}
void FlipithBit(int &n , int k){
    n= n^(1<<(k-1));
    /*
    1111 - n=15 , k=3
    0100
    ----
    1011 - 11
    ----
    */
}
void ClearithBit(int &n , int k){
    n= n&~(1<<(k-1));
    /*
    1001 - n=9 , k=2
                  0010 - n=2
    1101 - ~2
    ----
    1001 - 9
    ----
    */
}

//Brian Kernighan's algorithm
int countSetBits(int n){
    int count =0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;

    /*
    n&(n-1) - In n-1, in place of all trailing zeroes of n it has 1 and in place of last 1 it has zero
    so by doing and of n&(n-1) we clear the rightmost set bit of n
    00110100 - n=52
    00110011 - n=51
    --------
    00110000
    */
}
//Lookup Table soln O(1)
int tbl[256];
void initialize(){
    tbl[0]=0;
    for(int i=1;i<256;i++){
        tbl[i]=tbl[i&(i-1)]+1;
    }
}
int countSet(int n){
    return tbl[n&255]+tbl[(n>>8)&255]+tbl[(n>>16)&255]+tbl[(n>>24)];
}

bool isPowerofTwo(int n){
    return n&&!(n&(n-1));
    //if n ==0 return false and if there are more than one set bit in n then n is not a power of two
}

//XOR Properties
// x^0 = x
// x^y = y^x
// x^x=0
// x^x^x^x=0 (even times) , x^x^x=x(odd times)

//x&~(x-1) return a number which has only 1 bit set and the set bit corresponds to last set bit of x;

//Power Set
/*s="abc" , n=3   
2^3=8 0to7
000 0 =""  (0&0,1,2==0)
001 1 = "a" (1&(1<<0)!=0) a , (1&(1<<1)==0) , (1&(1<<2)==0)
010 2 = "b" (2&(1<<1)!=0) b , (2&(1<<0,2)==0) 
011 3 = "ab" (3&(1<<0)!=0) a , (3&(1<<1)!=0) b , (3&(1<<2)==0) 
100 4 = "c"  (4&(1<<0)==0)  , (4&(1<<1)==0) , (4&(1<<2)!=0) c
101 5 = "ac" (5&(1<<0)!=0) a , (5&(1<<1)==0) , (5&(1<<2)!=0) c 
110 6 = "bc" (6&(1<<0)==0)  , (6&(1<<1)!=0) b , (6&(1<<2)!=0) c
111 7 = "abc" (7&(1<<0)!=0) a , (7&(1<<1)!=0) b , (7&(1<<2)!=0) c
*/

void print(string s){
    int n=s.length();
    int size=(1<<n); //2^n
    for(int i=0;i<size;i++){
        for(int j=0;j<n;j++){
            if((i&(1<<j))!=0) cout<<s[j];
        }
        cout<<endl;
    }
}

// ADDITIONAL TRICKS
// n&(n+1) clears all trailing ones( 1's that are after zero) : 00110111 -> 00110000
// n|(n+1) sets the last cleared bit: 00110101 -> 00110111
// n& -n extracts the last set bit : 00110100 -> 00000100

void ConverttoBinary(int n){
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
}
int main()
{ 
    //initialize();
 //cout<<countSet(255);
 //string s="abc";
 //print(s);
 ConverttoBinary(255);
 return 0;
}