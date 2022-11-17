#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>

using namespace std;

typedef unsigned long long u64;
typedef unsigned int u32;

u32 jerry(string str) {
    constexpr u64 M = 4'294'967'291;
    constexpr u32 p = 29;
    u64 ans = 0;
    unsigned char c;
    u32 itr = 0;
    while(c = str[itr++]) {
        if(c == ' ') break;
        c = (c & 223) - 64;
        if(c - 1 > 25) continue;
        ans = (ans * p + c) % M;
    }
    //itr--;
    return ans;
}

vector<string> split(string str, string c) {
    vector<string> ans;
    u32 i = 0, j;
    while(1) {
        j = str.find(c, i);
        if(j == (u32)string::npos) break;
        ans.push_back(str.substr(i, j-i));
        i = j + c.length();
    }
    ans.push_back(str.substr(i, str.length()-i));
    return ans;
}

map<u32, u32> book2map(string book) {
    vector<string> words = split(book, " ");
    vector<u32> hash;
    for(string itr : words) {
        hash.push_back(jerry(itr));
    }
    //sort(hash.begin(), hash.end());
    map<u32, u32> freq;
    for(u32 itr : hash) {
        if(freq.count(itr)) freq[itr]++;
        else freq[itr] = 1;
    }
    for(auto [h, A] : freq) {
        freq[h] = ((u64)A * 1'000'000'000ULL) / freq.size();
    }
    return freq;
}

string file2str(string fname) {
    std::fstream f (fname, std::fstream::in);
    return f.read();
}

int main() {

    cout << file2str("pis_dlazaw/Mickiewicz.txt");

    string book;
    getline(cin, book);
    fstream f;

    return 0;
}