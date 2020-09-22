#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
#define INF 987654321
#define pii pair<int, int>
#define piipii pair<pair<int, int>, pair<int, int> >
using namespace std;

int N, M, fuel;
int x, y;
int sx, sy, dx, dy;
int dist[21][21][21][21], field[21][21];
int deltaX[4] = {-1, 0, 1, 0}, deltaY[4] = {0, 1, 0, -1};

bool cmp(piipii _lhs, piipii _rhs) {
  pii lhs = _lhs.first;
  pii rhs = _rhs.first;
  if (dist[x][y][lhs.first][lhs.second] != dist[x][y][rhs.first][rhs.second]) {
    return dist[x][y][lhs.first][lhs.second] > dist[x][y][rhs.first][rhs.second];
  }
  else {
    return lhs.first != rhs.first ? lhs.first > rhs.first : lhs.second > rhs.second;
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &fuel);
  
  for (int si=1; si<=N; si++) {
    for (int sj=1; sj<=N; sj++) {
      for (int di=1; di<=N; di++) {
        for (int dj=1; dj<=N; dj++) {
          dist[si][sj][di][dj] = INF;
        }
      }
    }
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      scanf("%d", &field[i][j]);
      if (field[i][j] == 0) {
        dist[i][j][i][j] = 0;

        for (int d=0; d<4; d++) {
          int ni = i + deltaX[d];
          int nj = j + deltaY[d];

          if (ni <= 0 || nj <= 0 || ni > N || nj > N) {
            continue;
          }

          dist[i][j][ni][nj] = 1;
        }
      }
    }
  }

  for (int ki=1; ki<=N; ki++) {
    for (int kj=1; kj<=N; kj++) {
      for (int si=1; si<=N; si++) {
        for (int sj=1; sj<=N; sj++) {
          for (int di=1; di<=N; di++) {
            for (int dj=1; dj<=N; dj++) {
              dist[si][sj][di][dj] = min(dist[si][sj][di][dj], dist[si][sj][ki][kj]+dist[ki][kj][di][dj]);
            }
          }
        }
      }
    }
  }

  scanf("%d %d", &x, &y);
  vector<piipii > customer;
  for (int i=0; i<M; i++) {
    scanf("%d %d %d %d", &sx, &sy, &dx, &dy);

    customer.push_back(make_pair(make_pair(sx, sy), make_pair(dx, dy)));
  }

  while (!customer.empty()) {
    sort(customer.begin(), customer.end(), cmp);

    piipii nextCustomer = customer.back();
    sx = nextCustomer.first.first;
    sy = nextCustomer.first.second;
    dx = nextCustomer.second.first;
    dy = nextCustomer.second.second;
    customer.pop_back();

    if (dist[x][y][sx][sy] + dist[sx][sy][dx][dy] > fuel) {
      fuel = -1;
      break;
    }

    fuel = fuel - dist[x][y][sx][sy] + dist[sx][sy][dx][dy];
    x = dx;
    y = dy;
  }

  printf("%d\n", fuel);
}