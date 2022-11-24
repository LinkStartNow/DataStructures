#include <bits/stdc++.h>

#define run(i, a, b) for(int i = a; i <= b; i ++)
#define len(a) sizeof(a) / sizeof(a[0])
#define shows(a) show(1, len(a) - 1)
#define N 1000007
#define m(l, r) m = l + r >> 1

using namespace std;

int a[N] = { 0, 1, 5, 2, 5, 6, 6, 4 }, t[N];

/* 交换 */
void swap(int *a, int *b);

/* 展示数组 */
void show(int l, int r);

/* 归并排序 */
void merge_sort(int l, int r);

/* 堆排序 */
void heap_sort(int l, int r);

/* 快速排序 */
void fast_sort(int l, int r);

int main()
{
	int n;
	scanf("%d", &n);
	run(i, 1, n) scanf("%d", &a[i]);
	fast_sort(1, n);
	run(i, 1, n) printf("%d%c", a[i], " \n"[i == n]);
}

void show(int l, int r)
{
	run(i, l, r) printf("%d ", a[i]);
	puts("");
}

void merge_sort(int l, int r)
{
	if (r - l + 1 <= 1) return;
	int m(l, r);
	merge_sort(l, m), merge_sort(m + 1, r);
	int p = l, q = m + 1, w = l;
	while (w <= r)
	{
		if ((a[p] > a[q] || p > m) && q <= r)  t[w++] = a[q++];
		else t[w++] = a[p++];
	}
	run(i, l, r) a[i] = t[i];
}

void heap_sort(int l, int r)
{
	run(i, l + 1, r)
	{
		int p = i;
		while (p > l && a[p] > a[p >> 1] && p >> 1 >= l) swap(&a[p], &a[p >> 1]), p >>= 1; // 此行非常的妙
	}
	while (r > l)
	{
		int p = l;
		swap(&a[l], &a[r--]);
		while (p < r)
		{
			int ll = p << 1, rr = p << 1 | 1;
			if (ll > r) break;
			if (rr > r)
				if (a[p] < a[ll]) swap(&a[p], &a[ll]), p = ll;
				else break;
			else
			{
				if (a[p] >= max(a[ll], a[rr])) break;
				if (a[ll] > a[rr]) swap(&a[p], &a[ll]), p = ll;
				else swap(&a[p], &a[rr]), p = rr;
			}
		}
	}
}

void fast_sort(int l, int r)
{
	if (l >= r) return;
	int x = a[l + r >> 1], p = l, q = r;
	while (p <= q)
	{
		while (a[p] < x) p++;
		while (a[q] > x) q--;
		if(p <= q) swap(&a[p++], &a[q--]);
	}
	fast_sort(l, q), fast_sort(p, r);
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
