#include <bits/stdc++.h>
using namespace std;

void matching(string t, string p){
    int n = t.size();
    int m = p.size();

    cout << "Matched at:\n";
    for(int s = 0; s <= n - m; s++){
        if(t.substr(s, m) == p){
            cout << s << " ";
        }
    }
}

int main(){
    string text, pattern;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    matching(text, pattern);

    return 0;
}