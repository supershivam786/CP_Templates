/*
    Author      : SHIVAM SAHU
    Institution : IIT PATNA
    Country     : INDIA
*/
 
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
 
// PRAGMA reduces execution time a little
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
 
// The typedef is used to give data type a new name
// #define in C is a directive which is used to #define alias(shortcuts)
typedef long long ll;
typedef long double ld;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 
#define f(i,n)          for(int i=0;i<n;i++)
#define F(i,a,b)        for(int i=a;i<b;i++)
#define arrin(a,n)      for(int i=0;i<n;i++)cin>>a[i]
#define arrout(a,n)     for(int i=0;i<n;i++)cout<<a[i]<<" "
#define print2d(a,n,m)  for(int i=0;i<n;i++){for(int j=0;j<m;j++)cout<<a[i][j]<<" ";cout<<"\n";}
#define w(x)            int x; cin>>x; while(x--)
 
#define ff              first
#define ss              second
#define int             long long
#define double          long double
#define eb              emplace_back
#define pb              push_back
#define pf              push_front
#define popb            pop_back
#define popf            pop_front
#define mp              make_pair
#define rt              return
#define br              break
#define ct              continue
#define elif            else if
 
#define dbg             cout<<"\nhuehue\n"
#define sayy            cout<<"YES\n"
#define sayn            cout<<"NO\n"
#define debug(a)        cerr << #a << ": " << a << endl
 
 
#define pii             pair<int,int>  // ( p.first , p.second )
#define pss             pair<string,string>
 
#define mii             map<int,int> // ( insert(key,value), begin(), end(), size(), empty() )
#define mci             map<char, int>
#define msi             map<string, int>
#define mss             map<string, string>
#define umii            unordered_map<int,int>
// Itertating over a map m ==>> for( auto i : m ){ cout<<i.first<<" "<<i.second<<endl; }
 
#define vi              vector<int>  // ( size(), resize(), begin(), end(), empty() )
#define vb              vector<bool>
#define vii             vector<pair<int,int>>
#define vvi             vector<vector<int>>
 
#define si              set<int>  // stores in ascending order // ( insert(), size(), empty(), begin(), end() )
#define sid             set<int, greater<int> >  // stores in descending order
#define sii             set<pair<int,int>>
 
#define li              list <int> // ( pb(), pf(), popb(), popf(), reverse(), sort(), empty(), size(),
//  remove(), front(), back() insert() )
 
#define maxheap         priority_queue<int>  // by default, max heap ( push(), pop(), top(), empty(), size() )
#define minheap         priority_queue<int,vi,greater<int>>  // min heap ( push(), pop(), top(), empty(), size() )
 
 
#define setbits(x)      __builtin_popcountll(x) // return the count of set bits
#define startzeroes(x)  __builtin_clzll(x) //return the count the leading zeros of the integer(clz=count leading zeroâ��s)
#define endzeroes(x)    __builtin_ctzll(x) // used to count the trailing zeros of the given integer(ctz = count trailing zeros)
 
#define ps(x,y)         fixed<<setprecision(y)<<x  // (always prefer double) works with float and double..ps(x,y)=x with y digits after decimal
#define dma(a,n,type)   type *a=new type[n];  // dynamic memory allocation (Example : type*a = new int[n]; )
 
const int inf   = numeric_limits<int>::max();
const double pi = 3.1415926535898;
const int mod   = 1000000007;
const int lim   = 100005;
 
#define all(v)          v.begin(),v.end()
#define sum(v)          accumulate(v.begin(),v.end(),(ll)0)
#define asum(a,n)       accumulate(a,a+n,(ll)0)
#define rev(v)          reverse(v.begin(),v.end());
//  stoi() function - converts string to integer ( Example- int x = stoi(s) )
//  stoll() funtion - converts string to long long ( Example- long long x = stoll(s) )
//  to_string() function - converts integer to string ( Example- string s = to_string(x) )
 
 
 
// For Graph questions, globally initialised visited array, distance array and adjacency list with zeroes.
// ( of 10^5 )
// int vis[1000001], indeg[1000001], low[1000001];
vi v[1000001];
int indeg[1000001];
vi res;
 
 

 
 
// Returns whether topological sorting exists or not
bool toposort(int n) {
 
    // A min heap ( priority queue ) to ensure lexicographically smallest topological sorting
    minheap q;
 
    // Inseerting node with indegree zero in minheap
    F(i, 1, n + 1) {
        if (indeg[i] == 0)
            q.push(i);
    }
 
    while (!q.empty()) {
 
        int d = q.top();
        res.pb(d);
        q.pop();
 
        // removing the edges connected with the node
        for (auto child : v[d]) {
            indeg[child]--;
 
            if (indeg[child] == 0) {
                q.push(child);
            }
        }
    }
 
    // if proper topological sorting is done, then res.size() should be equal to n
    if (res.size() != n) {
        return false;
    }
 
    return true;
}
 
int32_t main()
{
 
    fio;
 
    int n, m, a, b;
    cin >> n >> m;
 
    while (m--){
        cin >> a >> b, v[a].pb(b), indeg[b]++;
    }
 
//   Checking whethere toposorting possible or not
    if (!toposort(n)) {
        cout << "Sandro fails.";
    }
    else
        // else printing the topo sorting
    {
        for (auto i : res)
            cout << i << " ";
    }
 
 
 
 
 
 
}
