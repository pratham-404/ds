#include <bits/stdc++.h>

#define ll long long int

using namespace std;

vector<vector<int>> generate(int n)
{
    
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> vec = generate(n);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
