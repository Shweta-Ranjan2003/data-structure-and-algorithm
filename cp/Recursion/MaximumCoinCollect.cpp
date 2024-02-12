#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
Maximize the coin collected by two people(boy,girl) in a park if one starts from 0,0 and
dest is m-1,n-1 , boy-right,bottom and girl - up,right
and other starts from m-1,0 and dest is 0,n-1
condition is they can only overlap one point and coin of that point will be collected by none
return maximum coin collected by both

At the intersection cell
If Boy enters from top he is only allowed to exit from bottom because ig he doesn't then
girl will not be able to enter left and exit from bottom as she is only allowed to move up and right

same if boys enters from left he should only leave from right so that girl and enter from bottom
and exit from up

so we will pre compute dp from destionation as a source to intersection cell as dest
we will compute four dp to get answer
for eg
if intersection cell is (i,j)
option 1= dp2[i,j-1]+dp3[i,j+1]+dp1[i-1,j]+dp4[i+1,j]
where dp2,dp3 is for girl entering from left and leaving from right
and boy entering from top and exit from bottom
we will distribute matrix into 4 sub matrix for it

option 2= boy left to right and girl bottom to up

eg - 
1 2 1 4 6
6 8 7 -2 3
4 3 2 1 6
11 10 8 5 4
12 15 6 3 7
*/


int main()
{ 
 
 return 0;
}