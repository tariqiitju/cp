gp Tree;
// Now Tree can probably be used for fenwick, indices can be long long
// S is an offset to handle negative value
// If values can be >= -1e9, S=1e9+1
// maxfen is the MAXN in fenwick, this case it was 2e9+2;
// Note that it was okay to declare gp in integer as the values were
// still in the range of int.
void add(long long p, int v) {
    for (p += S; p < maxfen; p += p & -p)
        Tree[p] += v;
}
int sum(int p) {
    int ans = 0;
    for (p += S; p; p ^= p & -p)
        ans += Tree[p];
    return ans;
}
Similar alternative  :
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht;
