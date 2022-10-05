// https://www.learning.algozenith.com/problems/Auto-Suggestion-400

/*

Description

You are given a dictionary of N words (each word consists of lowercase characters) and Q query words. In each query, you will be given an integer K and a word S. We want to design a system that will suggest at most K words from the dictionary after each character of a query word is typed. Suggested words should have a common prefix with the query word. If there are more than K dictionary words with a common prefix return the K lexicographically minimum words. If there is no word with a common prefix print a blank line.
 


Input Format

The first line contains 3 space-separated integers N, MaxLen, Q- the number of words in the dictionary, the maximum length of a dictionary or query word, the number of queries.

The next N lines contain an integer denoting the length of the word and a string denoting the word in the dictionary.

The next Q lines contain an integer denoting the length of the word, a string denoting the query word, and an integer K.


Output Format

For each query, after every character print at most K lexicographically minimum space-separated dictionary words in a new line. Words should be printed in lexicographical order. If there is no word print a blank line.


Constraints

1 ≤ N ≤ 10000.

1 ≤ MaxLen ≤ 100.

1 ≤ Q ≤ 100.

1 ≤ |Length of dictionary or query word| ≤ 100.

Sum of K across all the queries ≤ 10000.


Sample Input 1

5 5 5

5 abcde

4 abcd

4 abcc

3 abc

1 a

5 abcde 2

3 xyz 100

2 ae 100

3 abc 5

4 abcc 2


Sample Output 1

a abc 
abc abcc 
abc abcc 
abcd abcde 
abcde 



a abc abcc abcd abcde 

a abc abcc abcd abcde 
abc abcc abcd abcde 
abc abcc abcd abcde 
a abc 
abc abcc 
abc abcc 
abcc 

*/

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int N=10000002;

struct node{
    node *child[26];
    int cnt;
    vector<string> v;
    node(){
        cnt=0;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};

void insert(string s, node *root){
    node *cur=root;
    for(int i=0;i<s.length();i++){
        if(cur->child[s[i]-'a']==NULL)
            cur->child[s[i]-'a']=new node;
        cur=cur->child[s[i]-'a'];
        cur->cnt++;
    }
    cur->v.push_back(s);
}

// void erase(int x, node *root){
//     node *cur=root;
//     for(int i=31;i>=0;i--){
//         int bit=(x>>i)&1;
//         cur=cur->child[bit];
//         cur->cnt--;
//     }
// }
void print(node *temp,int &left){
    // node *tempr=temp;
    if(!left || !temp) return;
    // if(temp->v.size()) left--,cout<<temp->v[0]<<" ";
    for(auto va:temp->v){
        cout<<va<<" ";
        left--;
        if(!left) return;
    }
    if(!left) return;
    for(int i=0;i<26;i++)
        print(temp->child[i],left);
}
void fmax(string ss,int k, node * root){
    node* temp = root;
    for(int i=0;i<ss.size();i++){
        if(temp==NULL){
            cout<<"\n";
            continue;
        }
        int y = ss[i]-'a';
        temp = temp->child[y];
        if(temp==NULL){
            cout<<"\n";
            continue;
        }
        int left = k;
        node* temp2 = temp;
        print(temp2,left);
        cout<<"\n";
    }
}
void solve(){
    int n,len,q; cin>>n>>len>>q;
    node *root = new node;
    for(int i=0;i<n;i++){
        int l; string s;
        cin>>l>>s;
        insert(s,root);
    }
    for(int i=0;i<q;i++){
        int l,k; string s;
        cin>>l>>s>>k;
        fmax(s,k,root);
    }
}

signed main()
{
    #define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t; while(t--)
    solve();
}
