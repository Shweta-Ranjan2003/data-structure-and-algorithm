#include <iostream>
using namespace std;
/*
Recursion is function calling itself 
* It has one or multiple base cases and one or multiple recursive calls.
* If one function calls itself with one parameter passed with reference and other parameter passed by value then after 
that new function returns to the root function then the value which was passed by value it will remain same as it was 
at the time of new function call . But the parameter which was passed by refernce if its value is changed then the 
new changed value will be there in root function also.
* Function call in recursion is like traversing a tree from root to all branches by various recursive function calls 
then after it reaches the base case then return value is passed to root of the tree back.
*/


/*
*********NATURAL NUMBER SUM***************
1. Break it into smaller problem like if n=4 then the sum will be 4+3+2+1 which 
is nothing but 4+ function call to(n-1), and the base condition would be when we reach 0 we return 0;

int getSum(int n){
    if(n==0) return 0;
    return n+getSum(n-1);
}
*/

/*
*********PALINDROME CHECK*********
2.If a string is palindrome then it reverse should be same as the original string. So breaking it down means 
some work we will do and rest work will be done by breaked downed recursion call like we will check wheather 
the first and last element are same or not and then call the recursion to check the rest of the string.

bool isPalindrome(string &str,int start,ind end){
    if(start>=end) return true;
    return (str[start]==str[end]) && isPalindrome(str,start+1,end-1);
}

here two pointer will first check if 0 index and last index is equal or not and then leave rest of the work
to smaller recursion call while passing left over string by start++ and end--.

or

bool isPalindrome(string &str , int i , int n){
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]) return false;
    return isPalindrome(str,i+1,n);
}

*/


/*
*********REVERSE AN ARRAY*********
3. Breaking it down is simple - swap 0th and last index then call recursion function to swap first and last second index
and so on until the index crosses or reaches the mid element.
void reverse(int arr[], int n , int i){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    return reverse(arr,n,i+1);
}
*/


/*
*******SUM OF DIGITS USING RECURSION**********
4.Again breaking down it if we want sum of 243 then we will do some work like n%10=3 and then then pass left
over number n/10=24 to the recursion call and at last return the addition of all.

int sum(int n){
    if(n==0) return 0;
    return (n%10) + sum(n/10);
}
*/

/*
**********CHECK IF ARRAY IS SORTED OR NOT*********
5. Check any two index wheather the first two or last two are sorted or not then pass remaining array to 
recursion call to check if its sorted or not.

bool isSorted(int ind , int n , int arr[]){
    if(ind==n-1) return true;

    if(arr[ind]<=arr[ind+1] && isSorted(ind+1 , n, arr)) return true;
    return false;
}
*/

/*
*********FIRST OCCURRENCE IN ARRAY**********
6. Check the first index at every call wheather if it is the required no. or not . If its not then call the smaller 
recursion function to check for next index by breaking down the array into a smaller array 

int firstOcc(int arr[] , int n , int key){
    if(n==0) return -1;
    if(arr[0]==key) return 0;

    int subIndex= firstOcc(arr+1 , n-1 , key);  //now array next index will become 0th index for next call
    if(subIndex!=-1) return subIndex+1;
    return -1;
}
*/

/*
*********LAST OCCURRENCE IN ARRAY*********
7. First break the array into the smallest array where the base case will be until the array becomes of 0 size
after reaching the end start searching from the back and whenever you get the key element stop searching after ward and
return the index by adding 1 at each step.

int lastOcc(int arr[], int n , int key){
    if(n==0) return -1;
    int subIndex= lastOcc(arr+1 , n-1 , key);
    if(subIndex==-1){
        if(arr[0]==key) return 0;
        else return -1;
    }
    else return subIndex+1;

}
*/
int main()
{ 
 
 return 0;
}