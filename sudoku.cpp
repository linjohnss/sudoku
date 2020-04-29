#include"sudoku.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
Sudoku::Sudoku() {
    for(int i=0; i<sudokuSize; i++) {
        map[i] = 0;
        Ans=0;
    }
}
Sudoku::Sudoku(const int init_map[]) {
    for(int i=0; i<sudokuSize; i++)
        map[i] = init_map[i];
}

int Sudoku::getElement(int index) {
    return map[index];
}

void Sudoku::setElement(int index,int value) {
    map[index] = value;
}

void Sudoku::solve_set(int arr[]) {
    if(Ans>1)
        return;
    int map_Ans[81];
    int count[81];
    bool tag[81][9];
    int Max=1;
    int pos_Max;
    for(int i=0; i<81; i++) {
        count[i]=0;
        for(int j=0; j<9; j++)
            tag[i][j]=0;
        map_Ans[i]=arr[i];
    }
    int value;
    int location;
    int rows;
    int columns;
    for(int i=0; i<81; i++) {
        //count[i]=0;
        if(i==0) {
            found=0;
            //Max=1;
        }
        /*if(count[i] > Max) {
                cout<< Max <<" "<<pos_Max<<endl;
        		Max = count[i];
                pos_Max = i;
        		//cout<< Max <<" "<<pos_Max<<endl;
            }*/

        if(map_Ans[i]==0) {
            /*if(count[i] > Max){
            	Max = count[i];
            	pos_Max = i;
            }*/
            location;
            rows = i/9;
            columns = i%9;
            count[i]=0;
            for(int j=0; j<9; j++) {
                location=rows*9+j;
                if(map_Ans[location]!=0)
                    tag[i][map_Ans[location]-1]=1;
                location=columns+9*j;
                if(map_Ans[location]!=0)
                    tag[i][map_Ans[location]-1]=1;
                location=27*(rows/3) + 3*(columns/3) + 9*(j/3) + (j%3);
                if(map_Ans[location]!=0)
                    tag[i][map_Ans[location]-1]=1;
            }
            for(int j=0; j<9; j++) {
                if(tag[i][j]==1)
                    count[i]++;
                else
                    value=j+1;
            }
            if(count[i]==8) {
                map_Ans[i] = value;
                count[i]=0;
                i=-1;
            } else if(count[i]==9)
                return ;
            //else if(count[i] >Max){
            //	Max = count[i];
            //	pos_Max=i;}
        } else {
            found++;
        }
    }
    if(found==81) {
        Ans++;
        for(int i=0; i<81; i++)
            map[i]=map_Ans[i];
    } else {
        for(int i=0; i<sudokuSize; i++) {
            if(count[i] > Max) {
                Max = count[i];
                pos_Max = i;
            }
        }
        for(int i=0; i<9; i++) {
            if(tag[pos_Max][i]==0) {
                map_Ans[pos_Max]=i+1;
                solve_set(map_Ans);
            }
        }
        End = clock();
        time = double(End - Begin)/CLOCKS_PER_SEC;
    }
    return;
}

int Sudoku::solve() {
    Ans=0;
    Begin = clock();
    solve_set(map);
    cout << time <<endl;
    return Ans;
}


void Sudoku::swapNum(int x, int y) {
    for(int i=0; i<sudokuSize; i++) {
        if(map[i]==x)
            map[i]=y;
        else if(map[i]==y)
            map[i]=x;
    }
    return;

}
void Sudoku::swapRow(int x, int y) {
    int temp;
    if(x>y) {
        temp=x;
        x=y;
        y=temp;
    }
    for(int i=x*27; i<27*(x+1); i++) {
        temp=map[i];
        map[i]=map[i+27*y];
        map[i+27*y]=temp;
    }
    return;
}
void Sudoku::swapCol(int x, int y) {
    int temp;
    if(x>y) {
        temp=x;
        x=y;
        y=temp;
    }
    for(int i=3*x; i<=3*x+72; i+9) {
        temp=map[i];
        map[i]=map[i+3];
        map[i+3]=temp;
    }
    return;
}
void Sudoku::rotate(int x) {
    int temp[sudokuSize];
    x=x%4;
    for(int i=0; i<sudokuSize; i++)
        temp[i]=map[i];
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            if(x==1)
                map[i+9*j]=temp[i*9+8-j];
            else if(x==2)
                map[i+9*j]=temp[8-i+9*(8-j)];
            else if(x==3)
                map[i+9*j]=temp[j+9*(8-i)];
        }
    return;
}
void Sudoku::flip(int x) {
    int temp[sudokuSize];
    for(int i=0; i<sudokuSize; i++)
        temp[i]=map[i];
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++) {
            if(x==0)
                map[i+9*j]=temp[i+9*(8-j)];
            if(x==1)
                map[i+9*j]=temp[(8-i)+9*j];
        }
    return;
}
