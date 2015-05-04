//Alex Tran
//861168759
//4/27/15
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void coPrimePreHelper(int k, int m, int n){
    cout << m << " " << n << endl;
    if(k >= 2*m - n + m){
        coPrimePreHelper(k, 2*m - n, m);
    }
    if(k >= 2*m + n + m){
        coPrimePreHelper(k, 2*m + n, m);
    }
    if(k >= 2*n + m + n){
        coPrimePreHelper(k, 2*n + m, n);
    }
}

void coPrimePostHelper(int k, int m, int n){
    if(k >= 2*m - n + m){
        coPrimePostHelper(k, 2*m - n, m);
    }
    if(k >= 2*m + n + m){
        coPrimePostHelper(k, 2*m + n, m);
    }
    if(k >= 2*n + m + n){
        coPrimePostHelper(k, 2*n + m, n);
    }
    cout << m << " " << n << endl;
}

void printQueue(priority_queue<pair<int, int> > pq){
    vector<pair<int,int> > reverse;
    while(!pq.empty()){
        reverse.push_back(pq.top());
        pq.pop();
    }
    for(int i = reverse.size() - 1; i >= 0; i--){
        cout << reverse.at(i).first << " " << reverse.at(i).second << endl;
    }
}

void coPrimeOrderHelper(int k, priority_queue<pair<int,int> > &a, pair<int,int> x){
    a.push(x);
    if(k >= 2*x.first - x.second + x.first){
        coPrimeOrderHelper(k, a, make_pair(2*x.first - x.second, x.first));
    }
    if(k >= 2*x.first + x.second + x.first){
        coPrimeOrderHelper(k, a, make_pair(2*x.first + x.second, x.first));
    }
    if(k >= 2*x.second + x.first + x.second){
        coPrimeOrderHelper(k, a, make_pair(2*x.second + x.first, x.second));
    }
}

void coPrimePre(int k){
    coPrimePreHelper(k, 2, 1);
    coPrimePreHelper(k, 3, 1);
}

void coPrimePost(int k){
    coPrimePostHelper(k, 2, 1);
    coPrimePostHelper(k, 3, 1);
}

void coPrimeOrder(int k){
    priority_queue<pair<int,int> > x;
    coPrimeOrderHelper(k, x, make_pair(2,1));
    coPrimeOrderHelper(k, x, make_pair(3,1));
    printQueue(x);
}