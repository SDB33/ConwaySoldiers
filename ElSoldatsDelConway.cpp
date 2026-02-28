#include <iostream>
#include <vector>

using namespace std;

// falta que el tamaño de la matriz sea variable
//  falta bajar el o(n)

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



buit FarlandsWell(ent liniaVermella) {
    vector<vector<ent>> m(120, vector<ent>(5, 0));
    m[0][2] = 1;
    bool aDaltBrut = cert;

    mentre (aDaltBrut) {
        aDaltBrut = fals;
        per (ent i = 0; i<m.mida(); i++) {
            si (m[i][2]==1) {
                aDaltBrut = cert;
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
            mostraMatriu(m); 
        }
    }   
    mostraMatriu(m); 
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