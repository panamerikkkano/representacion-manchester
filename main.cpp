#include <conio.h>
#include <iostream>
#include <winbgim.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

 void manchester(vector<bool> bites){
     // tamanio cuadro = 50x100;
    int a = 20; // ancho del bit [pixeles]
    int sx = 0, sy = 100;
    for (int i = 0; i < bites.size(); i++){
        cout << bites[i] << " ";
        if (bites[i] == 1){
            setcolor(4);
            line(sx,sy,sx + a/2 ,sy);
            line(sx + a/2,sy, sx + a/2, sy- a);
            line(sx + a/2, sy - a, sx + a, sy - a);
            sx = sx + a;
            outtextxy(sx- 12, sy+10, "1");
        }else{
            setcolor(3);
            line(sx, sy-a, sx+a/2, sy-a);
            line(sx+a/2, sy - a, sx+a/2, sy);
            line(sx+a/2, sy, sx+a, sy);
            sx = sx + a;
            outtextxy(sx- 12, sy+10, "0");
        }
        if (i+1 < bites.size() && bites[i] == bites[i+1]){ // si el siguiente bit es el mismo;
            setcolor(bites[i] == 1 ? 4 : 3);
            line(sx, sy ,sx, sy-a);
        }
    }
 }

int main(){

    int wx = 1920, wy = 200;
    initwindow(wx, wy); // trazando lineas para guiarme durante la graficacion;
    for (int i = 0; i<=wx; i = i + (20 * 8)){
        setcolor(8);
        line(i, 0, i, wy);

    }
    line(0,wy/2 + 50,wx,wy/2 + 50);
    int temp;

    vector<bool> bites;
    string nombre ;
    cout << "ingrese texto: ";cin >> nombre;
    for (int i = 0; i< nombre.size(); i++){
        vector <bool> current;
        temp = (int)nombre[i];
        for (int j=0;temp >0; j++){
            current.push_back(temp%2);
            //cout << temp%2 << " ";
            temp = temp / 2;
        }
        while(current.size() < 8){
            current.push_back(0);
        }
        reverse(current.begin(),current.end());
        bites.insert(bites.end(), current.begin(), current.end());
        current.clear();
    }
    // representacion de manchester
    manchester(bites);
    //manchester({1,0,1,1,0});
    // end
    cout << endl;
    getch();
    return 0;
}
