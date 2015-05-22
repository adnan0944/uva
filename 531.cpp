#include<bits/stdc++.h>


using namespace std;

string A[110], B[110];
int LCS[110][110];
int pre[110][110];

int main()
{

    while (1) {

        int N = 1, M = 1;
        while (cin >> A[N] && A[N] != "#") ++N;
        while (cin >> B[M] && B[M] != "#") ++M;

        if (N == 1) return 0;

        //making LCS table

        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                if (A[i] == B[j]) {
                    LCS[i][j] = LCS[i-1][j-1] + 1;
                    pre[i][j] = 0;  // 0 is  right
                }
                else {
                    if (LCS[i-1][j] > LCS[i][j-1]) {
                        LCS[i][j] = LCS[i-1][j];
                        pre[i][j] = 1; // 1 is up
                    }
                    else {
                        LCS[i][j] = LCS[i][j-1];
                        pre[i][j] = 2; // 2 is left
                    }
                }
            }
        }
        vector<string> Ans;
        int i = N - 1, j = M - 1;
        while (i && j) {
            if (pre[i][j] == 0) {
                Ans.push_back(A[i]);
                i--, j--;
            }
            else if (pre[i][j] == 1)
                i--;
            else
                j--;
        }
        if (!Ans.empty()) {
            cout <<Ans[Ans.size()-1];
            for ( int i =Ans.size()-2 ;i>=0; i--)
                cout << ' ' << Ans[i];
        }
        cout << endl;
    }
}
