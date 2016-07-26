//
// Created by Henry on 16/7/10.
//
#include <algorithm>
#include <cstdio>

#define NUM 50010
#define L_son(a) (a << 1)
#define R_son(a) (a << 1 | 1)
#define MID(a, b) ((a + b) >> 1)

using namespace std;

int cover[NUM << 2], l_sum[NUM << 2], r_sum[NUM << 2], m_sum[NUM << 2];

void Push_Up(int rt, int m) {
  l_sum[rt] = l_sum[L_son(rt)];
  r_sum[rt] = r_sum[R_son(rt)];
  if (l_sum[rt] == m - (m >> 1))
    l_sum[rt] += l_sum[R_son(rt)];
  if (r_sum[rt] == m >> 1)
    r_sum[rt] += r_sum[L_son(rt)];
  //若满,合并区间
  m_sum[rt] = max(m_sum[L_son(rt)],
                  max(l_sum[R_son(rt)] + r_sum[L_son(rt)], m_sum[R_son(rt)]));
}
void Push_Down(int rt, int m) {
  if (cover[rt] != -1) {
    // cover=1进去,=0离去
    cover[L_son(rt)] = cover[R_son(rt)] = cover[rt];
    l_sum[R_son(rt)] = r_sum[R_son(rt)] = m_sum[R_son(rt)] =
        cover[rt] ? 0 : m >> 1;
    l_sum[L_son(rt)] = r_sum[L_son(rt)] = m_sum[L_son(rt)] =
        cover[rt] ? 0 : m - (m >> 1);
    cover[rt] = -1;
  }
}

void build(int l, int r, int rt) {
  m_sum[rt] = r_sum[rt] = l_sum[rt] = r - l + 1;
  cover[rt] = -1;
  if (l == r) {
    return;
  }

  int mid = MID(l, r);
  build(l, mid, L_son(rt));
  build(mid + 1, r, R_son(rt));
}

int query(int w, int l, int r, int rt) {
  if (l == r)
    return l;
  Push_Down(rt, r - l + 1);

  int m = MID(l, r);

  if (m_sum[L_son(rt)] >= w) { //左边剩的空间足够,查左树
    return query(w, l, m, L_son(rt));
  } else if (r_sum[L_son(rt)] + l_sum[R_son(rt)] >= w) {
    return m - r_sum[L_son(rt)] + 1; //左边靠右空间和右边靠左空间
  } else {
    return query(w, m + 1, r, R_son(rt));
  }
}

void update(int L, int R, int c, int left, int right, int rt) {
  if (L <= left && right <= R) {
    m_sum[rt] = l_sum[rt] = r_sum[rt] =
        c ? 0 : right - left + 1; // 1就进入,0就离去
    cover[rt] = c;
    return;
  }

  Push_Down(rt, right - left + 1);
  int m = MID(left, right);
  if (L <= m)
    update(L, R, c, left, m, L_son(rt));
  if (R > m)
    update(L, R, c, m + 1, right, R_son(rt));
  Push_Up(rt, right - left + 1);
}
int main() {
  int n, m;
  int op, a, b;
  scanf("%d%d", &n, &m);
  build(1, n, 1);
  while (m--) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &a);

      if (m_sum[1] < a) {
        puts("0");
      } else {
        int p = query(a, 1, n, 1);
        printf("%d\n", p);
        update(p, p + a - 1, 1, 1, n, 1);
      }
    } else {

      scanf("%d %d", &a, &b);
      update(a, b + a - 1, 0, 1, n, 1);
    }
  }
}
