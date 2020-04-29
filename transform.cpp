#include <iostream>
#include <cstdlib>
#include "sudoku.h"
using namespace std;
int main() {
    Sudoku ques;
    int num;
    for(int i=0; i<Sudoku::sudokuSize; i++) {
        cin >> num;
        ques.setElement(i,num);
    }
    /*for(int i=0;i<81;i++)
    {
        cout << ques.getElement(i) << " ";
        if(i%9 == 8 && i!=80)
            cout << endl;
    }*/
    int type=-1;
    int x,y;
    while(type!=0) {
        cin >> num;
        //cout << num<<endl;
        type=num;
        if(type==1) {
            cin >> x >> y;
            ques.swapNum(x,y);
        } else if(type==2) {
            cin >> x >> y;
            ques.swapRow(x,y);
        } else if(type==3) {
            cin >> x >> y;
            ques.swapCol(x,y);
        } else if(type==4) {
            cin >> x;
            ques.rotate(x);
        } else if(type==5) {
            cin >> x;
            ques.flip(x);
        }

    }
    for(int i=0; i<81; i++) {
        cout << ques.getElement(i);
        if(i%9 == 8)
            cout << endl;
        else
            cout << " " ;
    }

    return 0;
}
