#include <bits/stdc++.h>
using namespace std;
/**
save all the point int point[] array
sort them in lexicographical order
call Closest_Pair(0,n-1)
where n is the size of point[] array
*/
typedef long long LL;
const int N = int(1e5) + 10;
const LL INF = 1LL << 60;

struct Point {
    LL x,y;
} point[N];
int n;
int tmpt[N];
bool cmpxy(const Point& a, const Point& b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}
bool cmpy(const int& a, const int& b) {
	return point[a].y < point[b].y;
}
LL dis2(int i, int j) {
	return (point[i].x - point[j].x) * (point[i].x - point[j].x)
			+ (point[i].y - point[j].y) * (point[i].y - point[j].y);
}
LL sqr(LL x) {
	return x * x;
}
LL Closest_Pair(int left, int right) {
	LL d = INF;
	if (left == right)
		return d;
	if (left + 1 == right)
		return dis2(left, right);
	int mid = (left + right) >> 1;
	LL d1 = Closest_Pair(left, mid);
	LL d2 = Closest_Pair(mid + 1, right);
	d = min(d1, d2);
	int i, j, k = 0;
	for (i = left; i <= right; i++) {
		if (sqr(point[mid].x - point[i].x) <= d)
			tmpt[k++] = i;
	}
	sort(tmpt, tmpt + k, cmpy);
	for (i = 0; i < k; i++) {
		for (j = i + 1; j < k && sqr(point[tmpt[j]].y - point[tmpt[i]].y) < d;
				j++) {
			LL d3 = dis2(tmpt[i], tmpt[j]);
			if (d > d3)
				d = d3;
		}
	}
	return d;
}

/*
4
200 100 -200 100
200 300 100 200
*/
