#include <bits/stdc++.h>
#include "dfa.hpp"
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

int main(int argc, char *argv[]) {
    int k = atoi(argv[1]);

    stack<tuple<int,int,int> > S;
    map<tuple<int,int,int>, int> id;
    int start = id[{0,0,0}] = 0;
    S.push({0,0,0});

    int end = -1;
    vector<tuple<int,int,int> > es;
    while (!S.empty()) {
        auto [cur1, cur2, cur3] = S.top();
        S.pop();

        if (cur1 == (1<<k)-1 && (cur2>>1) == (1<<(k-1))-1 && cur3 == (1<<(k-1))-1) {
            end = id[{cur1,cur2,cur3}];
        }

        for (int i = 0; i < k; i++) {
            int nxt1 = cur1 | (1<<i),
                nxt2 = cur2,
                nxt3 = cur3;

            if (i > 0 && (cur1 & (1<<(i-1)))) {
                nxt2 |= 1<<i;
            }

            if (i+1 < k && (cur1 & (1<<(i+1)))) {
                nxt3 |= 1<<i;
            }

            tuple<int,int,int> nxt = {nxt1,nxt2,nxt3};
            if (id.find(nxt) == id.end()) {
                id.insert({ nxt, id.size() });
                S.push(nxt);
            }

            es.push_back({ id[{cur1,cur2,cur3}], i, id[nxt] });
        }
    }

    assert(end != -1);

    int actual_start = id.size();
    es.push_back({ actual_start, 0, start });

    dfa d(id.size()+1, actual_start);
    d.add_term(end);
    for (auto [u,l,v] : es) {
        d.add_trans(u,l,v);
    }

    output_dfa(cout, d);

    return 0;
}

