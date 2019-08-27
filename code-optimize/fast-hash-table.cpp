#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<int, int> table;//very fast alternate of unorder map , work well on codemarshal


const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<key, int, chash> table;



struct chash
{
  size_t operator()(const pair<int,int>&x)const
  {
    return hash<long>()(((long)x.first)^(((long)x.second)<<32));
  }
};
unordered_map<pair<int,int>,int,chash>vs;
unordered_set<pair<int,int>,chash>dr;
