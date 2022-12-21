#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int new_a[n], pos[n];
    int shifts[n];
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            pos[a[j]-1] = j;
        }
        int shift = pos[i] + 1;
        if (i == shift - 1)
            shifts[i] = 0;
        else
            shifts[i] = shift;
        // cout << shift << ": ";
        for (int j = 0; j <= i; j++) {
            int new_pos = -1;
            if (pos[a[j]-1] < shift)
                new_pos = (i + 1) - shift + pos[a[j]-1];
            else
                new_pos = pos[a[j]-1] - shift;
            new_a[new_pos] = a[j];
            // cout << new_pos << " ";
        }
        // for (int x : new_a)
        //     cout << x << " ";
        // cout << "\n";
        memcpy(a, new_a, sizeof(a));
    }
    bool ok = true;
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i+1])
            ok = false;
    if (ok) {
        for (int x : shifts)
            cout << x << " ";
    } else
        cout << -1;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
        test_case();
}
