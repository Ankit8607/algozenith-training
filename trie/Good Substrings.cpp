// https://www.learning.algozenith.com/problems/Good-Substrings-395

/*

Description

You are given a string S consisting of lowercase characters. Some of the characters are good and the rest are bad. A substring S[l..r] is a string SlSl+1…Sr. A substring S[l..r] is good if among the letters SlSl+1…Sr there are at most K bad ones. You have to find the number of distinct good substrings of the given string S. Two substrings S[l..r] and S[p..q] is distinct if their content is different S[l…r]≠S[p..q].


Input Format

The first line contains a string S. 1 ≤ |S| ≤ 3000.

The second line contains a binary string of length 26. ‘0’ means ith character is bad and ‘1’ means ith character is good.

The third line contains an integer K, 1 ≤ K ≤ |S|.

 


Output Format

For each test case print the number of distinct substrings having at most K bad characters.


Sample Input 1

algozenith
10010100000010100100101100
2

Sample Output 1

24

Sample Input 2

acehqnrtuwaealwbqufdmizce
10000110100000010011101101
16

Sample Output 2

316

Sample Input 3

yqahbyyoxltryqdmvenemaqnbakglgqolxnaifnqtoclnnqiab
11000001000110100111100001
41

Sample Output 3

1243

Note

Substrings with utmost 2 bad characters are allowed.

In the given character set , bad characters are :- a,d,f,m,o,w,x,r,u

Substrings with 0 bad characters - a,o = 2 

Substrings with 1 bad characters - al,go,oz,z,e,n,i,t,h,l,g = 11

Substrings with 2 bad characters - algo,alg,lgo,goz,oze,lg,ze,en,ni,it,th = 11

Total count of substrings = 2+11+11=24


 
 
 */


# include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using lli =  int long long;
using ii = pair<lli,lli>;
//#define ld long double;
#define F first
#define S second

const int tot = 1e6+5;
const lli mod = 1e9+7;

string s,a;
int k,n;
lli ans=0;


struct node{
    node *child[26];
    int cnt;
    //vector<string> wend;
    node(){
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        cnt=0;
    }
};

struct trie{
    node *root;
    trie(){
        root = new node();
    }

};


trie *root_main;
node *root1;

//insert the substrings to the nodes
void insert(string s,int start){
      node *cur = root1;
      for(int i=start;i<n;i++){

          int x = s[i]-'a';
          if(cur->child[x]==NULL){
              cur->child[x]=new node();
          }

          cur =cur->child[x];
          cur->cnt = (a[x]=='0');
      }
  }



void good_search(node *cur,int k){

  for(int i=0;i<26;i++){
    if(cur->child[i]!=NULL){
      if(k-(a[i]=='0')>=0){
        ans++;        
        good_search(cur->child[i],k-(a[i]=='0'));
      }
    }
  }
}

int main(){
  
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    
    IOS
    
    cin >> s >> a;
    cin >> k;

    root_main = new trie();
    root1 = root_main->root;

    n = s.length();

    for(int i=0;i<n;i++){
      insert(s,i);
    }

    //search for nodes with count <=k
    good_search(root1,k);

    cout << ans << "\n";
    
    return 0;
}
