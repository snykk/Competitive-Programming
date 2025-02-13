#include <iostream>

using namespace std;

typedef long long ll;

ll generate_next(ll a, ll P, ll Q, ll MOD) {
    return (a * P + Q) % MOD;
}

int main() {
    ll N, S, P, Q;
    cin >> N >> S >> P >> Q;

    const ll MOD = (1LL << 31);
    ll a0 = S % MOD;

    ll tortoise = a0, hare = generate_next(a0, P, Q, MOD);
    ll power = 1, cycle_length = 0;

    // Find the Cycle Using Brent's Algorithm
    while (tortoise != hare) {
        if (power == cycle_length) {
            tortoise = hare;
            power *= 2;
            cycle_length = 0;
        }
        hare = generate_next(hare, P, Q, MOD);
        cycle_length++;
        if (cycle_length >= N) {  // Early exit if we reach N unique numbers
            cout << N << endl;
            return 0;
        }
    }

    // Find Start of Cycle
    tortoise = a0;
    hare = a0;
    for (int i = 0; i < cycle_length; i++) {
        hare = generate_next(hare, P, Q, MOD);
    }

    ll mu = 0; // Position where cycle starts
    while (tortoise != hare) {
        tortoise = generate_next(tortoise, P, Q, MOD);
        hare = generate_next(hare, P, Q, MOD);
        mu++;
    }

    // Compute the Result
    ll result = min(N, mu + cycle_length);
    cout << result << endl;
    return 0;
}
