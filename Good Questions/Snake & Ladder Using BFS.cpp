#include <bits/stdc++.h>
using namespace std;

#define endl                    '\n'
#define rep()                   for(LL i = 0 ; i < n ; i++)
#define f(i,s,n)                for(LL i = s ; i < n ; i++)
#define fe(i,s,n)               for(LL i = s ; i <= n ; i++)
#define rfe(i,s,n)              for(LL i = s ; i >= n ; i--)
#define auto(it,m)              for(auto &it:m)
#define f2(it,v)                for(it = v.begin(); it != v.end(); ++it)
#define fori(it, x)             for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define ip(n,a)                 LL n;cin>>n;LL a[n];rep(){cin>>a[i];}
#define op(n,a)                 f(i,0,n){cout<<a[i]<<" ";}cout<<endl;
#define i2p(n,k,a)              LL n,k;cin>>n>>k;LL a[n];rep{cin>>a[i];}
#define TCs(x)                  LL x; cin>>x; while(x--)
#define TC(x)                   LL x=1; while(x--)
#define mp                      make_pair
#define pb                      push_back
#define ff                      first
#define ss                      second
#define all(v)                  v.begin(), v.end()
#define mem(a,x)                memset(a,x,sizeof(a))
#define Max(x,y,z)              max(x,max(y,z))
#define Min(x,y,z)              min(x,min(y,z))
#define fastIO                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ps(x)                   std::cout << std::fixed; std::cout << std::setprecision(x);
#define clz(a)                  __builtin_clz(a) // count leading zeroes (geeksforgeeks.org/builtin-functions-gcc-compiler/)
#define ctz(a)                  __builtin_ctz(a) // count trailing zeroes
#define popc(a)                 __builtin_popcount(a) // count set bits (for ints only diff for ll)
#define GCD(A,B)                __gcd(A,B)
#define d1(x)                   cout<<#x<<": "<<x<<endl
#define d2(x, y)                cout<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define d3(x, y, z)             cout<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define d4(a, b, c, d)          cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define d5(a, b, c, d, e)       cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define d6(a, b, c, d, e, f)    cout<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
#define c1(a);                  LL a;cin>>a;
#define c2(a,b);                LL a,b;cin>>a>>b;
#define c3(a,b,c);              LL a,b,c;cin>>a>>b>>c;
#define c4(a,b,c,d);            LL a,b,c,d;cin>>a>>b>>c>>d;
#define c5(a,b,c,d,e);          LL a,b,c,d,e;cin>>a>>b>>c>>d>>e;
#define c6(a,b,c,d,e,f);        LL a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f;
#define c(a,n);                 LL a[n];f(i,0,n){cin>>a[i];}
#define ce(a,n);                LL a[n+1];fe(i,1,n){cin>>a[i];}

//Typedefs:-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
typedef string                  S;
typedef long long               LL;
typedef long double             LD;
typedef unsigned long long      ULL;
typedef vector<long long>       VL;
typedef vector<VL>              VVL;
typedef vector<string>          VS;
typedef vector<char>            VC;
typedef pair<LL,LL>             PLL;
typedef pair<string,LL>         PSL;
typedef pair<LL,string>         PLS;
typedef pair<char,LL>           PCL;
typedef pair<LL,char>           PLC;
typedef pair<string,string>     PSS;
typedef pair<char,char>         PCC;
typedef vector<PLL>             VPLL;
typedef vector<PSL>             VPSL;
typedef vector<PLS>             VPLS;
typedef vector<PCL>             VPCL;
typedef vector<PLC>             VPLC;
typedef vector<PSS>             VPSS;
typedef vector<PCC>             VPCC;
typedef map<LL,LL>              MLL;
typedef map<string,LL>          MSL;
typedef map<char,LL>            MCL;
typedef map<char,char>          MCC;
typedef set<LL>                 SL;
typedef set<string>             SS;
typedef set<char>               SC;

int power(LL x,LL y)
{
    if (y == 0)
    return 1;
    LL p = power(x, y/2);
    p = (p * p);

    return (y%2 == 0)? p : (x * p);
}           
const long long N=(long long)(1e5+1);
const long long N2=(long long)(1e6+1);
const long long MOD=(long long)(1e9+7);
const long long INF=(long long)(2e18);

map<LL,VL> m;
void bfs(LL parent[],LL level[],LL start){
	level[start]=0;
	queue<LL> q;
	q.push(start);
	while(!q.empty()){
		LL x=q.front();
		q.pop();
		for(LL it:m[x]){
			if(level[it]==-1){
				level[it]=level[x]+1;
				parent[it]=x;
				q.push(it);
			}
		}
	}
}
void print(LL parent[], LL destination)
{
    if (parent[destination] == -1) {
        cout<<destination<<" -> ";
    } 
    else {
        print(parent, parent[destination]);
        cout<<destination<<" -> ";
    }
}
void solve()
{
	LL n;
	cin>>n;
	MLL m2;
	LL p,q;
	cin>>p;
	while(p--){
		LL x,y;
		cin>>x>>y;
		m2[x]=y;
	}
	cin>>q;
	while(q--){
		LL x,y;
		cin>>x>>y;
		m2[y]=x;
	}
	fe(i,0,n-1){
		LL x=i+1;
		LL y=min(n,i+6);
		fe(j,x,y){
			if(m2[j]>0){
				m[i].pb(m2[j]);
			}
			else{
				m[i].pb(j);
			}
			
		}
	}
	for(auto &it:m){
		VL v=it.ss;
		sort(all(v));
		//cout<<it.ff<<" : ";
		//for(auto &i:v){
		//	cout<<i<<" ";
		//}
		//cout<<endl;
	}
	LL s=0;
	LL parent[n+1],level[n+1];
	fe(i,0,n){
		parent[i]=-1;
		level[i]=-1;
	}
	bfs(parent,level,s);
	cout<<level[n]<<endl;
	print(parent,n);
}
/*
Test1
100
11
8 11
15 36
20 23
29 34
42 64
54 75
70 73
59 61
80 82
84 95
90 93
13
1 25
6 32
10 55
28 51
35 57
5 60
18 76
43 81
46 88
52 86
65 94
68 92
26 99

Test 2
36
5	//Ladders
2 15
5 7
9 27
18 29
25 35
5	//Snakes
4 17
6 20
30 32
12 34
16 24
*/
int main()
{
        fastIO
        TC(t){solve();}
        return 0;
}
