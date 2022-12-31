#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
ll ksm (ll a, ll b, ll p)
{
	ll res = 1;
	for (; b; b >>= 1, a = a * a, a %= p) if (b & 1) res *= a;
	return res;
}

int main ()
{
	
	return 0;
}
