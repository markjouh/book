/* A hash table with a better constant than unordered_map, using gnu pbds.
 * The optional custom hash function provides better resistance to hacks
 * on Codeforces (shouldn't be a concern for USACO, thankfully).
 */

#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<class K, class V> using hash_table = __gnu_pbds::gp_hash_table<K, V, custom_hash>;
