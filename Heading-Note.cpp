#include <bits/stdc++.h>
using namespace std;
                            /* DEFINE AREA */

 /* Definition */                                           /* Meaning */

#define faster()                                ios_base::sync_with_stdio(false);cin.tie(0)
#define ll                                      long long
#define llu                                     unsigned long long
#define fl                                      float
#define db                                      double
#define str                                     string
#define ch										char
#define loop(i,a,b)                             for(ll i = a; i < b; ++i)
#define rev_loop(i,a,b)                         for(ll i = a; i > b; --i)
#define loop_dis(i,a,b,distance)                for(ll i = a; i < b; i += distance) 
#define all(a)                                  a.begin(), a.end()
#define vll                                     vector<ll>
#define vi                                      vector<int>
#define vs                                      vector<str>
#define vc                                      vector<ch>
#define vvll                                    vector<vector<ll> >
#define vvi                                     vector<vector<int> >
#define vpll                                    vector<pair<ll,ll> >
#define vpii                                    vector<pair<int,int> >
#define vpls                                    vector<pair<ll,str> >
#define vplc                                    vector<pair<ll,ch> >
#define sll                                     set<ll>
#define sc                                      set<ch>
#define sstr                                    set<str>
#define svll                                    set<vector<ll> >
#define svi                                     set<vector<int> >
#define msll                                    multiset<ll>
#define mssc                                    multiset<ch>
#define msstr                                   multiset<str>
#define usll                                    unordered_set<ll>
#define usc                                     unordered_set<ch>
#define usstr                                   unordered_set<str>
#define umsll                                   unordered_multiset<ll>
#define umsc                                    unordered_multiset<ch>
#define umsstr                                  unordered_multiset<str>
#define mllll									map<ll,ll>
#define mllstr 									map<ll,str>
#define mstrll									map<str,ll>
#define mcll									map<ch,ll>
#define mllc									map<ll,ch>
#define mcstr									map<ch,str>
#define mstrc									map<str,ch>
#define umllll									unordered_map<ll,ll>
#define umllstr									unordered_map<ll,str>
#define umstrll									unordered_map<str,ll>
#define umcll									unordered_map<ch,ll>
#define umllc									unordered_map<ll,ch>
#define umcstr									unordered_map<ch,str>
#define umstrc									unordered_map<str,ch>
#define qll 									queue<ll>
#define qstr									queue<str>
#define qc										queue<ch>
#define emp										empty
#define pu										push
#define pb                                      push_back
#define pob                                     pop_back
#define rev                                     reverse
#define rs                                      resize
#define ins                                     insert
#define era                                     erase
#define cl										clear
#define mp                                      make_pair
#define fr										front
#define f                                       first
#define s                                       second
#define bs                                      binary_search
#define lb										lower_bound
#define ub										upper_bound
#define Test()                                  ll t; cin >> t; while (t--)
const ll mod_val =                              1e9 + 7;

                            /* INLINE FUNCTIONS */

        //  Code  //                                                                                   //   Note  //

inline void swap_xor(ll &a, ll &b){
    a^=b;                                                                                   
    b^=a;                                                                                   /* ANOTHER WAY FOR SWAP 2 VALUES */
    a^=b;
}

inline void split_string(str a, vs &res){
    stringstream ss;
    ss<<a;
    str temp;
    while(ss>>temp){                                                                        /* SPLITING WORDS IN SENTENCE HAS WHITE SPACES BETWEEN THEM */
        res.pb(temp);
        temp="";
    }
}

inline ll random(ll a, ll b){
    return (a+(ll)(rand()*(b-a+1.0)/(1.0+RAND_MAX)));                                       /* GENERATING RANDOM VALUE, USING FOR MILLER-RABIN PRIME TEST */
}

inline bool miller_prime(ll n){
    if(n<2 || (!(n%2)&&n>2)) return false;
    bool check=true;
    db output_value;                                                                       
    ll input_value=log2(n-1);                                                               /* FOR CHECKING WHETHER PRIME OR NOT PRIME WITH NUMBERS FROM 0 TO 100 */
    while(input_value>0){
        output_value=(n-1)/pow(2,input_value);
        if((ll)output_value==output_value && (ll)output_value%2) break;
        --input_value;
    }                                                                                       
    ll ans=0;
    loop(i,1,4){
        ll random_value=random(2,n-2);
        ans=(ll)pow(random_value,output_value)%n;
        if(ans!=1 && ans!=n-1){
            check=false;
            break;	
        }
    }
    if(check) return true;
    ans=(ans*ans)%n;
    if(ans==1 || ans==n-1) return true;
    return false;
}

inline bool check_prime(ll n){
    if(n<2 || (!(n%2)&&n>2)) return false;
    loop_dis(i,3,sqrt(n)+1,2){                                                              /* FOR CHECKING WHETHER PRIME OR NOT PRIME WITH ALL NUMBERS */                                                        
        if(!(n%i)) return false;                                                        
    }                                                                                       /* TIME COMPLEXITY: O(SQRT(N)) */
    return true;
}

inline void build_Era_sieve(vll &sieve,ll size){
    sieve[0]=sieve[1]=0;            
    sieve[2]=1;                                                                                     
    loop(i,2,sqrt(size)+1){                                                                 /* FOR CHECKING WHETHER PRIME OR NOT PRIME WITH ALL NUMBERS */
        if(sieve[i]) loop_dis(j,i*i,size,i)                                                 
            sieve[j]=0;                                                                     /* TIME COMPLEXITY: O(LOG(N)) */
    }
}

inline ll expo(ll n, ll m){
    if(m==1) return n;                                                                      /* ANOTHER WAY FOR EVALUATING POW(N,M) */
    if(!(m%2)) return expo(n,m/2) * expo(n,m/2);                                            
    return expo(n,m/2) * expo(n,m/2) * n;                                                   /* TIME COMPLEXITY: O(LOG(N)) */
}
                                /* INT MAIN */
int main(){
    faster();
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    Test(){
    }
}