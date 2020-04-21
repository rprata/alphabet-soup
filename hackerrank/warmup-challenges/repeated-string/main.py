#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
    long as = 0;
    as = std::count(s.begin(), s.end(), 'a');
    if (as == s.length())   return n;
    else {
        as = (long) ((n / s.length()) * as);
        long remaining = std::count(s.begin(), 
                            s.begin() + (n % s.length()), 'a');
        as += remaining;
    }
    return as;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
