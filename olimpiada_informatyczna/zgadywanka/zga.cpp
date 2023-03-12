#include "zga.h"
#include <iostream>

const int N = 9;
double numbers[N + 2];
int good[N + 2];

void inicjalizuj() { }

void nowa_rozgrywka() {
    for(int i = 1; i <= N; ++i) good[i] = 0;
    numbers[0] = 0.;
    numbers[N+1] = 1.;
    good[0] = 1;
    good[N+1] = 1;
}

int kolejna_liczba(double x) {
    int i = N+1, j = 0;
    while(1) {
        if(good[j])
            if(x < numbers[j]) break;
        j++;
    }
    while(1) {
        if(good[i])
            if(x > numbers[i]) break;
        i--;
    }

    if(j - i <= 1) return 1;
    //std::cout << i << " " << j << "\n";
    int itr = i + 1 + (int) (x * (numbers[j] - numbers[i]) * (j - i - 1));
    numbers[itr] = x;
    good[itr] = 1;
    //for(int i = 0; i <= N+1; ++i) {
    //    std::cout << numbers[i] << " ";
    //}std::cout << "\n";
    return itr;
}