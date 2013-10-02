#include <bits/stdc++.h>

using namespace std;

const int MAX_LENGTH = 110;
string a, b, v;

typedef set<string> lcs_set;
int matrix[MAX_LENGTH][MAX_LENGTH];
lcs_set s_matrix[MAX_LENGTH][MAX_LENGTH];

string lcs(string a, string b) {
  int row = a.size() + 1;
  int column = b.size() + 1;

  int i, j;

  memset(matrix, 0, sizeof(matrix));
  for(i = 0; i < MAX_LENGTH ; ++i)
    s_matrix[0][i].insert("");
  for(i = 0; i < MAX_LENGTH ; ++i)
    s_matrix[i][0].insert("");

  for(i = 1; i < row; ++i)
  {
    for(j = 1; j < column; ++j)
    {
      if(a[i - 1] == b[j - 1])
      {
        matrix[i][j] = matrix[i -1][j - 1] + 1;
        for(lcs_set::iterator it = s_matrix[i - 1][j - 1].begin(); it != s_matrix[i - 1][j - 1].end(); ++it)
          s_matrix[i][j].insert(*it + a[i - 1]);
      }
      else
      {
        if(matrix[i][j - 1] > matrix[i - 1][j])
        {
          matrix[i][j] = matrix[i][j - 1];
          for(lcs_set::iterator it = s_matrix[i][j - 1].begin(); it != s_matrix[i][j - 1].end(); ++it)
            s_matrix[i][j].insert(*it);
        }
        else if(matrix[i][j - 1] == matrix[i - 1][j])
        {
          matrix[i][j] = matrix[i][j - 1];
          for(lcs_set::iterator it = s_matrix[i][j - 1].begin(); it != s_matrix[i][j - 1].end(); ++it)
            s_matrix[i][j].insert(*it);
          for(lcs_set::iterator it = s_matrix[i - 1][j].begin(); it != s_matrix[i - 1][j].end(); ++it)
            s_matrix[i][j].insert(*it);
        }
        else
        {
          matrix[i][j] = matrix[i - 1][j];
          for(lcs_set::iterator it = s_matrix[i - 1][j].begin(); it != s_matrix[i - 1][j].end(); ++it)
            s_matrix[i][j].insert(*it);
        }

      }
    }
  }
  int lcs_length = matrix[row - 1][column -1];

  int m, n;
  string ans = "";
  for(m = 1; m < row; ++m)
  {
    for(n = 1; n < column; ++n)
    {
      for(lcs_set::iterator it = s_matrix[m][n].begin(); it != s_matrix[m][n].end(); ++it)
        if (it->find(v) == string::npos && it->size() >= ans.size())
          ans =  *it;
    }
  }
  if (ans.size() == 0)
    ans = "0";

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> a >> b >> v;
  cout << lcs(a, b) << '\n';
  return 0;
}
