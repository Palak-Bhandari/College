#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_CHARS = 256;
void badCharHeuristic(string pat, int badchar[MAX_CHARS], int size)
{
    int len = pat.size();
    memset(badchar, -1, size);
    for (int i = 0; i < len; i++)
        badchar[(int) pat[i]] = i;
}
void preprocessGoodSuffix(string pat, int shift[], int f[])
{
    int m = pat.size();
    int i = m, j = m + 1;
    f[i] = j;
    while (i > 0) {
        while (j <= m && pat[i - 1] != pat[j - 1]) {
            if (shift[j] == 0)
                shift[j] = j - i;
            j = f[j];
        }
        i--;
        j--;
        f[i] = j;
    }
    j = f[0];
    for (int i = 0; i <= m; i++) {
        if (shift[i] == 0)
            shift[i] = j;
        if (i == j)
            j = f[j];
    }
}

void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();
    int badchar[MAX_CHARS];
    int size = sizeof(badchar)/sizeof(badchar[0]);
    badCharHeuristic(pat, badchar, size);

    int shift[m + 1];
    int f[m + 1];

    memset(shift, 0, sizeof(shift));
    memset(f, 0, sizeof(f));

    preprocessGoodSuffix(pat, shift, f);

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern occurs at shift = " << s << endl;
            s += shift[0];
        }
        else {
            int bcShift = j - badchar[txt[s + j]];
            int gsShift = shift[j + 1];
            s += max(bcShift, gsShift);
        }
    }
}

int main()
{
    string txt = "aaabaabab";
    string pat = "aab";
    search(txt, pat);
    return 0;
}
