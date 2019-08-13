#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (auto i=(a); i<(b); ++i)
#define iter(it,c) for (auto it = (c).begin(); it != (c).end(); ++it)
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
const int INF = 2147483647;

#define MAXN 400

#define MOD_OVER(t) if (t >= mod) t -= mod;
#define MOD_UNDER(t) if (t < 0) t += mod;

int mem[2][MAXN+1][MAXN+1][MAXN+1];
int nck[MAXN+1][MAXN+1];

void usage(int argc, char *argv[]) {
    fprintf(stderr, "usage: %s mod\n", argv[0]);
}

int main(int argc, char *argv[]) {

    if (argc != 2) {
        usage(argc, argv);
        return 1;
    }

    int mod = atoi(argv[1]);

    if (mod < 2 || mod > 1000000000) {
        fprintf(stderr, "error: mod must be in range [2,1000000000]\n");
        usage(argc, argv);
        return 1;
    }

    for (int i = 2; i*i <= mod; i++) {
        if (mod % i == 0) {
            fprintf(stderr, "error: mod must be prime\n");
            usage(argc, argv);
            return 1;
        }
    }

    nck[0][0] = 1 % mod;

    for (int run = 0; run <= MAXN; run++) {
        for (int n = 1; n <= MAXN; n++) {
            nck[n][0] = nck[n][n] = 1 % mod;
            for (int k = 1; k < n; k++) {
                nck[n][k] = nck[n-1][k] + nck[n-1][k-1];
                MOD_OVER(nck[n][k]);
            }

            for (int c = 1; c <= n; c++) {
                for (int d = 1; d <= n; d++) {
                    int res = 0;

                    if (run != 0 && c <= d) {
                        if (n == d && c == 1 && run == 1) {
                            res++;
                            MOD_OVER(res);
                        }

                        if (c == d) {
                            res += mem[~run&1][n-1][c-1][n-1];
                            MOD_OVER(res);
                            res -= mem[~run&1][n-1][0][n-1];
                            MOD_UNDER(res);
                            res -= mem[~run&1][n-1][c-1][c-1];
                            MOD_UNDER(res);
                            res += mem[~run&1][n-1][0][c-1];
                            MOD_OVER(res);
                        } else {
                            for (int k = 0; k <= min(n-3, d-c-1); k++) {
                                int cur = 0;
                                cur += mem[~run&1][n-2-k][d-2-k][n-2-k];
                                MOD_OVER(cur);
                                cur -= mem[~run&1][n-2-k][0][n-2-k];
                                MOD_UNDER(cur);
                                cur -= mem[~run&1][n-2-k][d-2-k][c-1];
                                MOD_UNDER(cur);
                                cur += mem[~run&1][n-2-k][0][c-1];
                                MOD_OVER(cur);

                                res += (long long)nck[d-c-1][k] * cur % mod;
                                MOD_OVER(res);
                            }
                        }
                    }

                    res += mem[run&1][n][c-1][d];
                    MOD_OVER(res);
                    res += mem[run&1][n][c][d-1];
                    MOD_OVER(res);
                    res -= mem[run&1][n][c-1][d-1];
                    MOD_UNDER(res);

                    mem[run&1][n][c][d] = res;
                }
            }

            int res = mem[run&1][n][n][n];
            res -= mem[run&1][n][0][n];
            MOD_UNDER(res);
            res -= mem[run&1][n][n][0];
            MOD_UNDER(res);
            res += mem[run&1][n][0][0];
            MOD_OVER(res);

            cout << res << " ";
        }
        cout << endl;
    }

    return 0;
}

