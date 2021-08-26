#include <stdio.h>
#define FIN "rmq.in"
#define FOUT "rmq.out"

const int nmax = 100100;
const int log = 18;

int sparse[log][nmax],
    lg[nmax];

inline int min(int a, int b){
    if(a < b) {
      return a;
    } else {
      return b;
    }
}

int main(int argc, char const *argv[]) {

    int n, m, i, x, y, step, cnt, sol;

    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; ++i) {

        scanf("%d", &sparse[0][i]);
    }

    lg[1] = 0;

    for(i = 2; i <= n; ++i) lg[i] = lg[i/2] + 1;


    for(step = 1, cnt = 1; cnt <= n; ++step, cnt <<= 1) {

        for(i = 1; i <= n; ++i) {

           sparse[ step ][ i ] = min(sparse[step-1][i], sparse[step-1][i + cnt]);

        }

    }

    /*display Spase Table
    for(i = 0; i <= n; ++i) {

       for(j = 0; j <= n; ++j) {

           cout<<sparse[i][j]<<" ";
       }
       cout<<"\n";
    }
    */

    while(m--) {

         scanf("%d %d", &x, &y);

         sol = min( sparse[ lg[y - x + 1] ][ x ], sparse[ lg[y - x + 1] ][ y - (1<<lg[y - x + 1]) + 1] );

         printf("%d\n", sol);
    }

  return 0;
}
