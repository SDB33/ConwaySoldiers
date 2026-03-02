#include <iostream>
#include <vector>

using namespace std;

// --- Macros catalanes ---
#define principal main
#define buit void
#define retorna return
#define mida size
#define mentre while
#define per for
#define si if
#define altrament else
#define cert true
#define fals false 
#define ent int 

buit mostraMatriu(const vector<vector<ent>>& m);
buit FarlandsWell(ent liniaVermella);

ent principal() {
    FarlandsWell(4);
    retorna 0;
}

/*
L'algoritme opera sobre una matriu de mida m x 5, on m ∈ N i m > 0.
Es defineix una 'línia vermella' (L) com un llindar on L ∈ N i 0 < L < m.
L'estat inicial és un '1' a la posició central (fila 0, columna 2).

Lògica de propagació:

A partir de la fila L es prioritza el desplaçament lateral per tal d'alliberar la columna central.
En qualsevol altre cas, la propagació continua cap avall.

Punts de col·lapse:

Si només deixem que els "1" s'apartin cap a un costat, ens trobem amb el següent bucle infinit:
X X 1 0 0 
1 1 X 0 0  

0 0 1 0 0  |  0 0 0 0 0  |  0 0 0 0 0
1 1 0 0 0  |  1 1 1 0 0  |  1 1 1 0 0
0 0 0 0 0  |  0 0 1 0 0  |  1 1 0 0 0
0 0 0 0 0  |  0 0 0 0 0  |  0 0 0 0 0

Si deixem que els "1" s'apartin cap a banda i banda, ens trobem amb el següent bucle infinit:
1 1 1 1 1 
1 1 X 1 1 
1 1 X 1 1
1 1 X X X

1 1 1 1 1  |  1 1 0 1 1  |  1 1 0 1 1
1 1 0 1 1  |  1 1 1 1 1  |  1 1 1 1 1
1 1 0 1 1  |  1 1 1 1 1  |  1 1 0 1 1
1 1 0 0 0  |  1 1 0 0 0  |  1 1 0 1 1
0 0 0 0 0  |  0 0 0 0 0  |  1 1 0 0 0
*/
buit FarlandsWell(ent liniaVermella) {
    vector<vector<ent>> m(20, vector<ent>(5, 0));
    m[0][2] = 1;
    bool aDaltBrut = cert;

    mentre (aDaltBrut) {
        aDaltBrut = fals;
        per (ent i = 0; i<m.mida(); i++) {
            si (m[i][2]==1) {
                //aDaltBrut = cert;
                si (i<liniaVermella) {aDaltBrut = cert;}
                // Si estem per sota la línia vermella, intentem moure el "1" cap als costats.
                si (i>=liniaVermella) {
                    si      (m[i][1]==0) {m[i][2] = 0; m[i][1] = 1; m[i][0] = 1;} 
                    altrament si (m[i][3]==0) {m[i][2] = 0; m[i][3] = 1; m[i][4] = 1;}
                }
                // Intentem moure el "1" cap avall.
                si (m[i][2]==1) {
                    si (i+2<m.mida() && m[i+1][2]+m[i+2][2]==0) {m[i][2] = 0; m[i+1][2] = 1;m[i+2][2] = 1;}
                }
            } 
        }
        mostraMatriu(m);
    }   
}

buit mostraMatriu(const vector<vector<ent>>& m) {
    cout << "-----------------" << endl;

    per (ent i = 0; i < m.mida(); i++) {
        per (ent j = 0; j < m[i].mida(); j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}