#include<iostream>  
#include<set>  
#define MAX 500  
using namespace std;  
void ans(int, int);  
set<int> cnt[MAX+1];  
int g[MAX+1][MAX+1] = {0};  
int cost[MAX+1];  
bool used[MAX+1];  
int N, M;  
int answer = -1;  
  
int main() {  
      
    int i;  
    int a, b, p;  
    cin >> N;  
    for (i = 1;i <= N;i++) cin >> cost[i];  
    cin >> M;  
    for (i = 1;i <= M;i++) {  
        cin >> a >> b >> p;  
        if (g[a][b] == 0 || g[a][b] > p) {  
            g[a][b] = p;  
            g[b][a] = p;  
        }  
        cnt[a].insert(b);  
        cnt[b].insert(a);  
    }  
    ans(1, 0);  
    cout << answer;  
    return 0;  
}  
  
void ans(int n, int total) {  
    if (n == N) {  
        if (answer == -1 || total < answer) {  
            answer = total;  
        }  
    } else {  
        set<int>::iterator it;  
        int num;  
        it = cnt[n].begin();  
        for (;it != cnt[n].end();it++) {  
            num = *it;  
            if (used[num]) continue;  
            used[num] = true;  
            ans(num, total+g[n][num]+cost[num]);  
            used[num] = false;  
        }  
    }  
}
