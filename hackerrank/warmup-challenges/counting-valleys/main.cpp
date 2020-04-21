#include <bits/stdc++.h>
// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
using namespace std;
#define SEA_LEVEL 0

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    bool enteredValley = false;
    int level = SEA_LEVEL;
    int counterValley = 0;
    for (int i = 0; i < s.length(); i++) {
        if (level == SEA_LEVEL) {
            if (s[i] == 'D' && !enteredValley) {
                enteredValley = true;
            } 
        } else if (level == SEA_LEVEL - 1) {
            if (s[i] == 'U' && enteredValley) {
                counterValley++;
                enteredValley = false;
            }
        }

        if (s[i] == 'U')
            level++;
        else    
            level--;
    }
    return counterValley;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
