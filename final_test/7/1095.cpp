#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Point
{
	int x, y;

	Point(int x, int y) : x(x), y(y) {}
	Point(const Point &p) : x(p.x), y(p.y) {}
	Point() : x(0), y(0) {}

	bool operator<(const Point &p) const
	{
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
};

Point a[10000];
int n;

set<Point> res;

void solve(int L, int R)
{
	if (L == R - 1)
	{
		// single point is okay
		res.insert(a[L]);
		return;
	}

	int mid = (L + R) / 2;

	solve(L, mid);
	solve(mid, R);

	set<int> Ys;

	for(int i = L; i < R; i++) Ys.insert(a[i].y);
	int x = a[mid].x;

	set<int>::iterator p = Ys.begin(), q = Ys.end();
	while(p != q)
	{
		int y = *p;
		p++;
		res.insert(Point(x, y));
	}
}

int main()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++) scanf("%d %d", &a[i].x, &a[i].y);

	sort(a, a + n);

	solve(0, n);

	printf("%d\n", res.size());

	set<Point>::iterator p = res.begin(), q = res.end();
	while(p != q)
	{
		Point t = *p;
		printf("%d %d\n", t.x, t.y);
		p++;
	}

	//for(int i = 0; i < 10000; i++) printf("%d %d\n", 100 + i, 100 + i);

	return 0;
}