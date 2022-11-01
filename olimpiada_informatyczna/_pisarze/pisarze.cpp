#include <stdio.h>

constexpr long long M = 1e9 + 7;
int hash313(char * s) {
    constexpr long long p = 313;
    long long ans = 0, c;
    while(c = *(s++))
        ans = (ans * p + c) % M;
    return (int) ans;
}

int main(int argc, char*[] argv) {
    if(argc != 2) { printf("Bad arguments."); return 1; }
    FILE * fptr = fopen(argv[1], "r");
    if(FILE == NULL) { printf("Bad file."); return 1; }

    

    return 0;
}