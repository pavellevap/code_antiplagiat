#include <bits/stdc++.h>

#define TASKNAME ""
#define pb push_back
#define mp make_paer
#define MAXN int(1e3)
#define INF int(1e9)
#define sz(A) (int) (A).size()
#define pi 3,1415926
#define DB(x) cerr << #x << " = " << x << "\n";
#define DB2(a, b) cerr << #a << " = " << a << " " << #b << " = " << b << "\n"

  /*#ifdef WIN32
    printf("%I64d\n",ans);
  #else
    printf("%lld\n",ans);
  #endif */


using namespace std;
int l, n, ans = INF;
set<string> strings;
string str;

            
int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> l;
  cin >> str;
  for(int mask = 0; mask < (1 << (sz(str))); mask++){
    vector<int> num;
    set<string> tmp;
    for(int j = (sz(str) - 1); j >= 0; j--){
      if( ((mask >> j )  & 1) == 1)
        num.pb(j);
     // cout << ((mask >> j )  & 1);
    }
  //  cout << "\n";
    bool flag = true;
    int last = 0;
    sort(num.begin(), num.end());
    for(int j = 0; j < sz(num); j++){
      int cur = num[j];
      string temp_str;
      temp_str.clear();
      for(int i = last; i <= cur; i++)
        temp_str.pb(str[i]);
    //  DB(temp_str);
      if(sz(temp_str) > l)
        flag = false;
      tmp.insert(temp_str);
      last = num[j] + 1;
    }
    string temp_str;

    for(int i = last; i  < sz(str); i++)
        temp_str.pb(str[i]);
    if(sz(temp_str) > l)
        flag = false;
    tmp.insert(temp_str);

    if(sz(tmp) < ans && flag){
      strings.clear();
      for(set<string> ::iterator it = tmp.begin(); it != tmp.end(); it++)
        strings.insert(*it);
      ans = sz(tmp);
      
    }

  }
  cout << ans << "\n";
  for(set<string> ::iterator it = strings.begin(); it != strings.end(); it++)
    cout << *it << "\n";
  return 0;
}