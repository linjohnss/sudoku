#include <iostream>
using namespace std;
int main() {
    // finish your generate code...
    int arr[81]= {3,0,2,0,0,5,6,9,0
                  ,0,4,0,0,9,6,0,3,0
                  ,0,5,0,0,0,8,0,0,0
                  ,1,9,0,0,8,0,7,0,3
                  ,0,0,0,0,0,0,0,0,0
                  ,5,0,7,0,3,0,0,6,1
                  ,0,0,0,8,0,0,0,2,0
                  ,0,8,0,9,6,0,0,7,0
                  ,0,6,5,7,0,0,3,0,9
                 };
    for(int i=0; i<81; i++) {
        cout << arr[i];
        if(i%9==8)
            cout << endl;
        else
            cout << " ";
    }
    return 0;
}
