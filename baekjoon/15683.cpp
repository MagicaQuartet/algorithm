#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

int coverOneDirection(vector<vector<int> >& room, int x, int y, int direction, int delta) {
  int ret = 0;
  if (direction == 0) {            // up
    for(int i=x-1; i>=0; i--) {
      if (room[i][y] == -1) {
        break;
      }
      else if (room[i][y] == 0) {
        ret++;
        room[i][y] += delta;
      }
      else if (room[i][y] < 10) {
        room[i][y] += delta;
      }
      else {
        continue;
      }
    }
  }
  else if (direction == 1) {      // right
    for(int j=y+1; j<room[0].size(); j++) {
      if (room[x][j] == -1) {
        break;
      }
      else if (room[x][j] == 0) {
        ret++;
        room[x][j] += delta;
      }
      else if (room[x][j] < 10) {
        room[x][j] += delta;
      }
      else {
        continue;
      }
    }
  }
  else if (direction == 2) {       // down
    for(int i=x+1; i<room.size(); i++) {
      if (room[i][y] == -1) {
        break;
      }
      else if (room[i][y] == 0) {
        ret++;
        room[i][y] += delta;
      }
      else if (room[i][y] < 10) {
        room[i][y] += delta;
      }
      else {
        continue;
      }
    }
  }
  else {
    for(int j=y-1; j>=0; j--) {    // left
      if (room[x][j] == -1) {
        break;
      }
      else if (room[x][j] == 0) {
        ret++;
        room[x][j] += delta;
      }
      else if (room[x][j] < 10) {
        room[x][j] += delta;
      }
      else {
        continue;
      }
    }
  }
  
  return ret;
}

int cover(vector<pair<int, pair<int, int> > >& cctv, vector<vector<int> >& room, int cnt) {
  if (cctv.empty()) {
    return cnt;
  }
  
  int ret = 64;
  int coveredArea;
  
  pair<int, pair<int, int> > tv = cctv.back();
  pair<int, int> coord = tv.second;
  cctv.pop_back();
  
  if (tv.first == 10) {
    coveredArea = coverOneDirection(room, coord.first, coord.second, 0, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 0, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 1, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 2, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 3, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 3, -1);
  }
  else if (tv.first == 20) {
    coveredArea = coverOneDirection(room, coord.first, coord.second, 0, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 2, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 0, -1);
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 1, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 3, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    coverOneDirection(room, coord.first, coord.second, 3, -1);
  }
  else if (tv.first == 30) {
    coveredArea = coverOneDirection(room, coord.first, coord.second, 0, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 1, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 0, -1);
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 1, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 2, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 2, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 3, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    coverOneDirection(room, coord.first, coord.second, 3, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 3, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 0, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 3, -1);
    coverOneDirection(room, coord.first, coord.second, 0, -1);
  }
  else if (tv.first == 40) {
    coveredArea = coverOneDirection(room, coord.first, coord.second, 0, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 1, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 2, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 0, -1);
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 3, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 1, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 2, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 3, -1);
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 3, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 0, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 2, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 3, -1);
    coverOneDirection(room, coord.first, coord.second, 0, -1);
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    
    coveredArea = coverOneDirection(room, coord.first, coord.second, 3, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 1, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 0, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 3, -1);
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    coverOneDirection(room, coord.first, coord.second, 0, -1);
  }
  else {
    coveredArea = coverOneDirection(room, coord.first, coord.second, 0, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 1, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 2, 1);
    coveredArea += coverOneDirection(room, coord.first, coord.second, 3, 1);
    ret = min(ret, cover(cctv, room, cnt - coveredArea));
    coverOneDirection(room, coord.first, coord.second, 0, -1);
    coverOneDirection(room, coord.first, coord.second, 1, -1);
    coverOneDirection(room, coord.first, coord.second, 2, -1);
    coverOneDirection(room, coord.first, coord.second, 3, -1);
  }
  cctv.push_back(tv);
  
  return ret;
}

int main() {
  int N, M, cnt;
  scanf("%d %d", &N, &M);
  vector<vector<int>> room (N, vector<int>());
  vector<pair<int, pair<int, int> > > cctv;
  
  cnt = N*M;
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      int block;
      scanf("%d", &block);
      if (block != 0) {
        cnt--;

        if (block < 6) {
          block *= 10;
          cctv.push_back(make_pair(block, make_pair(i, j)));
        }
        else {
          block = -1;
        }
      }
      room[i].push_back(block);
    }
  }

  printf("%d\n", cover(cctv, room, cnt));
}

/* 먼저 CCTV로 확인 가능한 영역을 방향별로 체크할 수 있는 함수를 만든다. 이를 이용해 각 CCTV마다 가능한 경우의 수를 모두 구하고 그 중 사각지대가 가장 작은 경우를 고른다 */