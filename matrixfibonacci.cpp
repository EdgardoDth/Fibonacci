#include <iostream>
#include <vector>

typedef unsigned long long ll;

std::vector<std::vector<ll> >
    dot(std::vector<std::vector<ll> >,
        std::vector<std::vector<ll> >);

std::vector<std::vector<ll> >
    ebs(std::vector<std::vector<ll> >, int);

int main() {
    std::vector<std::vector<ll> > a {{1, 1},
                                        {1, 0}};


    int pos = 0;
    std::cout << "Enter the fibonacci position: ";
    std::cin >> pos;
    std::vector<std::vector<ll> > c = ebs(a, pos);
    std::cout << c[1][1] << '\n';

    return 0;
}

std::vector<std::vector<ll> >
    ebs(std::vector<std::vector<ll> > bas, int exp) {
    std::vector<std::vector<ll> > t(bas);

    while(exp > 0) {
        if(exp % 2) {
            t = dot(t, bas);
        }
        bas = dot(bas, bas);
        exp /=2;
    }

    return t;
}

std::vector<std::vector<ll> >
    dot(std::vector<std::vector<ll> > a,
        std::vector<std::vector<ll> > b) {

    int r1 = a.size();
    int c1 = a[0].size();
    int r2 = b.size();

    std::vector<std::vector<ll> > result;
    result.resize(c1, std::vector<ll>(r2, 0));

    if(c1 == r2) {
        for(int i = 0; i < r1; i++)
            for(int j = 0; j < c1; j++)
                for (int k = 0; k < c1; k++)
                    result[i][j] += a[i][k] * b[k][j];
    }
    return result;
}
