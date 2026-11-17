// Drumsticks — maximum number of packs the band leader can buy with v tomans.
//
// A pack with `a` sticks can be split "without a fight" if:
//   - each of the k drummers gets x sticks, the leader gets x + 1 sticks,
//   - and x >= 1 (nobody is left empty-handed).
// Total sticks in the pack: k * x + (x + 1) = (k + 1) * x + 1.
// So a pack is valid exactly when:
//     a >= k + 2            (smallest valid pack: x = 1)
//     (a - 1) % (k + 1) == 0   (a - 1 must be a multiple of k + 1)
//
// Then the problem becomes: among the valid packs, buy as many as possible with budget v.
// Greedy: sort the prices and buy the cheapest packs first until the money runs out.
//
// Complexity: O(n log n). Memory: O(n).

#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;  // prices sum up to ~ 1e5 * 1e9 = 1e14, which overflows int

// Returns true if a pack with `sticks` sticks can be split without a fight among
// k drummers and one leader.
bool canSplitFairly(ll sticks, ll k) {
    bool bigEnough = sticks >= k + 2;
    bool divisible = (sticks - 1) % (k + 1) == 0;
    return bigEnough && divisible;
}

// Keeps only the prices of the packs that can be split fairly.
vector<ll> validPackPrices(const vector<ll> &sticks, const vector<ll> &prices, ll k) {
    vector<ll> validPrices;
    for (size_t i = 0; i < sticks.size(); i++) {
        if (canSplitFairly(sticks[i], k)) {
            validPrices.push_back(prices[i]);
        }
    }
    return validPrices;
}

// Buys the cheapest packs first; returns how many packs fit in the budget.
int maxPacksWithin(vector<ll> &prices, ll budget) {
    sort(prices.begin(), prices.end());

    int packsBought = 0;
    ll spent = 0;

    for (size_t i = 0; i < prices.size(); i++) {
        if (spent + prices[i] > budget) {
            break;  // all remaining packs are at least as expensive
        }
        spent += prices[i];
        packsBought++;
    }
    return packsBought;
}

vector<ll> readNumbers(int n) {
    vector<ll> numbers(n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &numbers[i]);
    }
    return numbers;
}

int main() {
    ll k, budget;
    int n;
    scanf("%lld %lld %d", &k, &budget, &n);

    vector<ll> sticks = readNumbers(n);  // a[i]: number of sticks in pack i
    vector<ll> prices = readNumbers(n);  // c[i]: price of pack i

    vector<ll> validPrices = validPackPrices(sticks, prices, k);
    printf("%d\n", maxPacksWithin(validPrices, budget));

    return 0;
}
