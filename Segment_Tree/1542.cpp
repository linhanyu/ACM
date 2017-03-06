#include <algorithm>
#include <cstdio>
#include <memory>

#define L_son(a) (a << 1)
#define R_son(a) (a << 1 | 1)
#define NUM 2222
#define MID(a, b) ((a + b) >> 1)

using namespace std;

struct Seg {
  double l, r, h;
  int s;
  Seg() {}
  Seg(double a, double b, double c, int d) : l(a), r(b), h(c), s(d) {}
  bool operator < (const Seg &sg) const { return h < sg.h; }
} ss[NUM];

double X[NUM];
int cnt[NUM << 2];
double sum[NUM << 2];

void Push_Up(int l, int r, int rt) {
  if (cnt[rt]) {
    sum[rt] = X[r + 1] - X[l];
  } else if (l == r) {
    sum[rt] = 0;
  } else {
    sum[rt] = sum[L_son(rt)] + sum[R_son(rt)];
  }
}

void update(int L_bound, int R_bound, int c, int l, int r, int rt) {
  if (L_bound <= l && r <= R_bound) {
    cnt[rt] += c;
    Push_Up(l, r, rt);
    return;
  }

  int m = MID(l, r);
  if (L_bound <= m) {
    /* code */
    update(L_bound, R_bound, c, l, m, L_son(rt));
  }
  if (R_bound > m) {
    /* code */
    update(L_bound, R_bound, c, m + 1, r, R_son(rt));
  }
  Push_Up(l, r, rt);
}

template <class T> int Binary_Search(T key, T A[], int left, int right) {
  while (left <= right) {
    int mid = MID(left, right);
    if (key < A[mid]) {
      right = mid - 1;
    } else if (key > A[mid]) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main(int argc, char const *argv[]) {
  int n, count = 1;
  while (scanf("%d", &n) != EOF && n) {
    int m = 0;
    printf("Test case #%d\n", count++);
    while (n--) {
      double a, b, c, d;
      scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
      X[m] = a;
      ss[m++] = Seg(a, c, b, 1);
      X[m] = c;
      ss[m++] = Seg(a, c, d, -1);
    }

    sort(X, X + m);
    sort(ss, ss + m);
    int k = 1;

    for (int i = 1; i < m; i++) {
      if (X[i] != X[i - 1]) {
        X[k++] = X[i];
      }
    }
    //去除重复坐标
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    double ret = 0;

    for (int i = 0; i < m - 1; i++) {
      /* code */
      int l = Binary_Search(ss[i].l, X, 0, k - 1);
      int r = Binary_Search(ss[i].r, X, 0, k - 1) - 1;
      if (l <= r) {
        update(l, r, ss[i].s, 0, k - 1, 1);
      }
      ret += sum[1] * (ss[i + 1].h - ss[i].h);
    }

    printf("Total explored area: %.2lf\n\n", ret);
  }

  return 0;
}
