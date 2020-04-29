#include <cstdlib>
#include <iostream>
#include "sudoku.h"
#include <time.h>
int Ans=0;
int found;
int map[81];
clock_t Begin,End;
using namespace std;
void solve_set(int arr[]) {
    if(Ans>1)
        return;
    int map_Ans[81];
    int count[81]= {0};
    bool tag[81][9]= {0};
    int Max=1;
    int pos_Max;
    for(int i=0; i<81; i++) {
        map_Ans[i]=arr[i];
    }
    int value;
    int location;
    int rows;
    int columns;
    for(int i=0; i<81; i++) {
        if(i==0)
            found=0;
        if(map_Ans[i]==0) {
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
            //  Max = count[i];
            //  pos_Max=i;}
        } else {
            found++;
        }
    }
    if(found==81) {
        Ans++;
        for(int i=0; i<81; i++)
            map[i]=map_Ans[i];
    } else {
        for(int i=0; i<81; i++) {
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
        //End = clock();
        //time = double(End - Begin)/CLOCKS_PER_SEC;
    }
    return;
}

int main() {
    // Begin = clock();
    // double time;
    //Sudoku ques;
    //int map[81];
    //int num;
    for(int i=0; i<81; i++) {
        cin >> map[i];//read in map
        //ques.setElement(i,num);
    }
    //num=ques.solve();
    solve_set(map);
    if(Ans==1) {
        cout << Ans << endl;
        for(int i=0; i<81; i++) {
            //cout << ques.getElement(i);
            cout << map[i];
            if(i%9 == 8)
                cout<<endl;
            else //if(i%9!=8)
                cout << " ";
        }
    } else
        cout << Ans << endl;
    //End = clock();
    //time=double(End-Begin)/CLOCKS_PER_SEC;
    //cout << time <<endl;
    return 0;
}

