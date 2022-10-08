// https://www.learning.algozenith.com/problems/Intersection-and-Union-of-Two-Rectangles-AZ101-314

/*

Description

You are given two rectangles with their lower-left and upper-right coordinates. You have to find the area of the intersection and union of the rectangles. Both rectangles are axis-aligned.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains four space-separated integers X1, Y1, X2, Y2 - coordinates of the first rectangle. 

The second line of each test case contains four space-separated integers X3, Y3, X4, Y4 - coordinates of the second rectangle. 


Output Format

For each test case, print the area of intersection and union of the rectangles.


Constraints

1≤ T ≤ 105
-103≤ Xi, Yi ≤ 103
It is guaranteed that X1 ≤ X2, Y1 ≤ Y2, X3 ≤ X4, and Y3 ≤ Y4.


Sample Input 1

3
0 0 2 2
1 1 3 4
0 0 3 3
1 1 2 3
1 2 3 4
0 0 1 1

Sample Output 1

1 9
2 9
0 5

Note

If the image is not visible please check this docs link - https://docs.google.com/document/d/126mU5E-f2FhaByhQ8xE3jeI7JrpCOwyT2Pnp1pAvAu0/

For the first test case,


For the second test case,


For the third test case,



*/


#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x1,x2,y1,y2;
    int x3,y3,x4,y4;
    
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    
    int a1 = max(x1,x3) , b1 = max(y1,y3);
    int a2 = min(x2,x4) , b2 = min(y2,y4);
    
    int ans = 0;
    if(a1 <= a2 && b1 <= b2){
        ans = (a2-a1)*(b2-b1);
    }
    int area1 = (x2-x1)*(y2-y1);
    int area2 = (x4-x3)*(y4-y3);
    
	cout<<ans<<" "<<area1 + area2 - ans<<endl;
}

signed main(){
    int t;
    cin>>t;
    
    while(t--) solve();
    
    return 0;
}
