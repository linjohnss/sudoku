#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/
#include <iostream>
using namespace std;
class Sudoku {
  public:
    Sudoku();
    Sudoku(const int init_map[]);
    void setMap(const int set_map[]);
    int getElement(int index);
    void isCorrect(int pos);
    static const int sudokuSize = 81;
    // generate
    static Sudoku generate();

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    void solve_set(int arr[]);
    int solve();
    void sol();
    void setElement(int index,int value);


  private:
    void checkUnity(int arr[],int pos);
    int map[sudokuSize];//question
    //int map_Ans[sudokuSize];//answer
    //int map_out[sudokuSize];
    //int count[sudokuSize];
    int found;
    int Ans;
    //int a;
    //int b;
    clock_t Begin,End;
    double time;
    //bool tag[sudokuSize][9];
};

#endif // SUDOKU_H
