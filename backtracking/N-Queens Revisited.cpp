// https://www.learning.algozenith.com/problems/N-Queens-Revisited-137

/*

Description

An S-Queen is a chess piece that combines the power of a knight and a queen. 
Find the number of ways to place N S-Queens on N x N chessboard.



Input Format

The input contains only single integer N denoting the side of the chessboard. 


Output Format

Print the number of ways to place N S-Queens on the N x N chessboard.


Constraints

2 ≤ N ≤ 14


Sample Input 1

3

Sample Output 1

0

Sample Input 2

10

Sample Output 2

4

*/


#include<stdio.h>
#include<bits/stdc++.h>
#include<stdbool.h>
using namespace std;

int N,cnt=0;

void solution(int x,vector<int> &prev);

bool isSafe(int row,int col,int prevr,int prevc)
{   
    if(prevc==col)
        return false;
    if(abs(prevr-row)==abs(prevc-col))
        return false;
    if(((abs(prevr-row)==2) && (abs(prevc-col)==1)) || ((abs(prevr-row)==1) && (abs(prevc-col)==2)))
        return false;

    return true;
}

int solve()
{
    cin>>N;

    vector<int> prev;

    solution(0,prev);

    cout<<cnt<<endl;
}

void solution(int row,vector<int> &prev)
{
    if(row==N)
    {
        cnt++;
        return;
    }
    for(int i=0;i<N;i++)
    {   bool canKeep=true;
        for(int j=0;j<prev.size();j++)
        {
            if(!isSafe(row,i,j,prev[j]))
            { canKeep=false;
            }
        }   

            if(canKeep)
            {

                prev.emplace_back(i);
                solution(row+1,prev);
                prev.pop_back();
            }
    }


}


int main()
{
    solve();
}
