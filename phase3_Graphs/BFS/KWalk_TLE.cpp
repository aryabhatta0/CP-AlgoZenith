#include <bits/stdc++.h>
using namespace std;

// bhai how is it different from solution
// what's wrong? why TLE?

const int INF = 1e9;
vector<vector<int>> knight_moves = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

bool isValid(int x, int y, int N){
    return x>=1 && x<=N && y>=1 && y<=N;
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{
	// Complete the function
    if (Sx == Fx && Sy == Fy) return 0;
    
    vector<vector<int>> board(N+1, vector<int>(N+1, INF));
    // INF means unvisited - will serve as vis array as well

    queue<pair<int, int>> q;
    q.push({Sx, Sy});
    board[Sx][Sy]=0;    // updating vis means it has been pushed in queue once

    while(!q.empty()){
        pair<int, int> top = q.front();
        q.pop();

        if(board[Fx][Fy]!=INF) return board[Fx][Fy];

        for(auto it: knight_moves){
            int x = top.first + it[0];
            int y = top.second + it[1];

            if(isValid(x, y, N) && board[x][y] == INF){
                // is it guaranteed that the dist will always be minimized and we don't have to check? YES. since level-wise exploration.
                board[x][y] = board[top.first][top.second] + 1;
                q.push({x, y});
                if(x==Fx && y==Fy) return board[Fx][Fy];
            }
        }
        // if(board[Fx][Fy]!=INF) return board[Fx][Fy];
    }

    // cout << "Board: \n";
    // for(int i=1; i<=N; i++){
    //     for(int j=1; j<=N; j++) {
    //         if(board[i][j]==INF) cout << "INF\t";
    //         else cout << board[i][j] << "\t";
    //     }
    //     cout << "\n";
    // }

    // couldn't find Fx Fy?
    return -1;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
}
