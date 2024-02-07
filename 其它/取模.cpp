
#include<bits/stdc++.h>
#define endl '\n' 
using namespace std;
typedef long long LL;

template<class T>
constexpr T power(T a, LL b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
template<int P>
struct MInt {
    int x;
    constexpr MInt(LL x = 0) : x(norm(x % P)) {}
    constexpr int norm(int x) const {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr int val() const {
        return x;
    }
    constexpr MInt operator-() const {
        return MInt(P - x);
    }
    constexpr MInt inv() const {
        // assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr MInt &operator*=(const MInt &rhs) {
        x = LL(x) * rhs.x % P;
        return *this;
    }
    constexpr MInt &operator+=(const MInt &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(const MInt &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(const MInt &rhs) {
        return *this *= rhs.inv();
    }
    constexpr friend MInt operator*(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    constexpr friend MInt operator+(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    constexpr friend MInt operator-(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    constexpr friend MInt operator/(const MInt &lhs, const MInt &rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    constexpr friend std::istream &operator>>(std::istream &is, MInt &a) {
        LL v;
        is >> v;
        a = MInt(v);
        return is;
    }
    constexpr friend std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    constexpr friend bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    constexpr friend bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
const int P = 998244353;
using Z = MInt<P>;
int n,k;
const int N=110,K=1e5+10;
Z a[N],sg[K];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	return 0;
} 