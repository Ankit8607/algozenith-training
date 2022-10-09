// https://www.learning.algozenith.com/problems/Running-Mean,-Median-and-Mode-AZ101-366

/*

Description

You have an empty array and can perform the following operations on it:

insert x - add integer x to the array
remove x - remove integer x from the array. It's guaranteed the element present in it.
getMean - find the mean of elements currently presents in the array.
getMedian - find the median of elements currently present in the array,  if the count of the numbers is even, take the average of the two middle elements.
getMode - find the mode of elements currently present in the array, if there is more than one potential element, assume that the mode is the smaller of all.
If the array is empty at the point a query is asked about a metric(mean, median, mode), print -1.

If any of the answers for the query is a fraction, let's say, P / Q in reduced form, the return the number (P*Q-1) Modulo 1000000007.


Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.
The first line of each test case contains one integer Q - the number of queries. 
Each of the next Q lines contains a string S and integer X or just a string S - description of the query.


Output Format

For each test case, print the answer for the queries.


Constraints

1 ≤ T ≤ 105
1 ≤ Q ≤ 105
1 ≤ x ≤ 109
It is guaranteed that the sum of Q over all test cases does not exceed 105.


Sample Input 1

1
12
insert 4
insert 3
insert 5
getMean
getMedian
getMode
insert 4
remove 3
insert 5
getMean
getMedian
getMode

Sample Output 1

4
4
3
500000008
500000008
4

Note

Array becomes: [4]
Array becomes [3, 4]
Array becomes [3, 4, 5]
Mean = (3+4+5) / 3 = 4
Median = 4 (middle element)
Mode = 3 (since it is smallest in value)
Array becomes [3, 4, 4, 5]
Array becomes [4, 4, 5]
Array becomes [4, 4, 5, 5]
Mean = (4+4+5+5)/4 = 4.5 (=500000008 in mod domain)
Median = (4+5)/2 = 4.5 (average of the two middle elements)
Mode = 4 (since it is smallest in value)

*/


#include<bits/stdc++.h>
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD = 1000000007;

int power(int a, int p){
    if(p == 0) return 1;
    if(p == 1) return a;
    int ret = power(a, p/2);
    ret = (ret*ret)%MOD;
    if(p%2 == 1) ret = (ret*a)%MOD;
    return ret;
}

int fractionAnswer(int a, int b){
    int inverse = power(b%MOD, MOD - 2);
    return (a%MOD * inverse)%MOD;
}

struct meanStruct {
    int sum = 0;
    int count = 0;
    void insert(int val){
        sum += val;
        count ++;
    }
    void remove(int val){
        sum -= val;
        count--;
    }
    int getMean(){
        if(count==0) return -1;
        if(sum%count!=0) return fractionAnswer(sum, count);
        return sum/count;
    }
};

struct modeStruct {
    map<int, int> mp;
    set<pair<int, int>> st;

    void insert(int val){
        if(mp.find(val)!=mp.end()){
            auto it = st.find({mp[val], val});
            mp[val]++;
            st.erase(it);
            st.insert({mp[val], val});
        }
        else{
            mp[val] = 1;
            st.insert({1, val});
        }
    }

    void remove(int val){
        auto it = st.find({mp[val], val});
        st.erase(it);
        mp[val]--;
        if(mp[val] == 0) mp.erase(val);
        else{
            st.insert({mp[val], val});
        }
    }

    int getMode(){
        if(mp.size()==0) return -1;
        auto it = st.end();
        it--;
        int freq = it->first;
        it = st.lower_bound({freq, 0});
        return it->second;
    }
};

struct medianStruct{
    multiset<int> m1, m2;
     
    void rebalance(){
        if(m1.size() > m2.size() + 1){
            auto it = m1.end();
            it--;
            m2.insert(*it);            
            m1.erase(it);
        }
        else if(m2.size() > m1.size()){
            auto it = m2.begin();
            m1.insert(*it);
            m2.erase(it);
        }

    } 

    void insert(int val){
        if(!m1.empty() && val<=(*m1.rbegin())){
            m1.insert(val);
        }
        else{
            m2.insert(val);
        }
        rebalance();
    }

    void remove(int val){
        if(!m1.empty() && (m1.count(val) > 0)){
            auto it = m1.find(val);
            m1.erase(it);
        }
        else if(!m2.empty() && (m2.count(val) > 0)){
            auto it = m2.find(val);
            m2.erase(it);
        }
        rebalance();
    }

    int getMedian(){
        if(m1.size()+m2.size()==0) return -1;
        if(m1.size() > m2.size()){
            auto it = m1.end();
            it--;
            return *it;
        }
        else{
            auto it1 = m1.end();
            auto it2 = m2.begin();
            it1--;
            return fractionAnswer((*it1) + (*it2), 2);
        }
    }
};

void solve(){
    int q; cin >> q;
    medianStruct median;
    modeStruct mode;
    meanStruct mean;
    while(q--){
        string s; cin >> s;
        if(s == "insert"){
            int val; cin >> val;
            mean.insert(val);
            median.insert(val);
            mode.insert(val);
        }
        else if(s == "remove"){
            int val; cin >> val;
            mean.remove(val);
            median.remove(val);
            mode.remove(val);
        }
        else if(s == "getMean"){
            cout << mean.getMean() << "\n";
        }
        else if(s == "getMedian"){
            cout << median.getMedian() << "\n";
        }
        else {
            cout << mode.getMode() << "\n";
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int _t; cin >> _t; while(_t--)
    solve();
    return 0;
}
