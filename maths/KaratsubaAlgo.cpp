#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

const ll BASE = 10000;
const int WIDTH = 4;
const int CUTOFF = 32;

void trim(vll &a) {
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

vll fromString(const string &s) {
    vll a;

    for (int i = (int)s.size(); i > 0; i -= WIDTH) {
        int start = max(0, i - WIDTH);
        int len = i - start;
        a.push_back(stoll(s.substr(start, len)));
    }

    trim(a);
    return a;
}

string toString(vll a) {
    trim(a);

    string res = std::to_string(a.back());

    for (int i = (int)a.size() - 2; i >= 0; --i) {
        string block = std::to_string(a[i]);
        res += string(WIDTH - block.size(), '0') + block;
    }

    return res;
}

vll add(const vll &a, const vll &b) {
    vll res(max(a.size(), b.size()) + 1);

    ll carry = 0;

    for (size_t i = 0; i < res.size(); i++) {
        ll cur = carry;

        if (i < a.size()) cur += a[i];
        if (i < b.size()) cur += b[i];

        res[i] = cur % BASE;
        carry = cur / BASE;
    }

    trim(res);
    return res;
}

vll subtract(const vll &a, const vll &b) {
    vll res = a;

    ll borrow = 0;

    for (size_t i = 0; i < res.size(); i++) {
        ll cur = res[i] - borrow - (i < b.size() ? b[i] : 0);

        if (cur < 0) {
            cur += BASE;
            borrow = 1;
        } else {
            borrow = 0;
        }

        res[i] = cur;
    }

    trim(res);
    return res;
}

vll shiftLeft(const vll &a, size_t k) {
    if (a.size() == 1 && a[0] == 0)
        return a;

    vll res(k, 0);
    res.insert(res.end(), a.begin(), a.end());
    return res;
}

vll naiveMultiply(const vll &a, const vll &b) {
    vll res(a.size() + b.size());

    for (size_t i = 0; i < a.size(); i++) {
        ll carry = 0;

        for (size_t j = 0; j < b.size() || carry; j++) {
            long long cur =
                res[i + j] +
                carry +
                (j < b.size() ? a[i] * b[j] : 0);

            res[i + j] = cur % BASE;
            carry = cur / BASE;
        }
    }

    trim(res);
    return res;
}

vll karatsuba(vll a, vll b) {
    trim(a);
    trim(b);

    size_t n = max(a.size(), b.size());

    if (n <= CUTOFF)
        return naiveMultiply(a, b);

    a.resize(n, 0);
    b.resize(n, 0);

    size_t m = n / 2;

    vll a0(a.begin(), a.begin() + m);
    vll a1(a.begin() + m, a.end());

    vll b0(b.begin(), b.begin() + m);
    vll b1(b.begin() + m, b.end());

    vll z0 = karatsuba(a0, b0);
    vll z2 = karatsuba(a1, b1);

    vll aSum = add(a0, a1);
    vll bSum = add(b0, b1);

    vll z1 = karatsuba(aSum, bSum);
    z1 = subtract(z1, z0);
    z1 = subtract(z1, z2);

    vll result = add(
        add(
            shiftLeft(z2, 2 * m),
            shiftLeft(z1, m)
        ),
        z0
    );

    trim(result);
    return result;
}

string multiplyBig(const string &x, const string &y) {
    if (x == "0" || y == "0")
        return "0";

    vll a = fromString(x);
    vll b = fromString(y);

    return toString(karatsuba(a, b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    cout << multiplyBig(a, b) << '\n';
}