// Tower of Hannoi Puzzle
// 3 Towers and N disks of diff size which can slide on any tower
// Puzzle starts with disks sorted in ascending order of size from
// top to bottom. Move the disk from tower A to tower C
#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int disks,char from_rod, char to_rod, char aux_rod){
    if(disks == 1){
        // Shift the last disk from A to C
        cout<<"Move the disk 1 from "<<from_rod<<" to "<<to_rod<<endl;
        return;
    }
    towerOfHanoi(disks-1,from_rod,aux_rod,to_rod); // shift n-1 disks from A to B
    cout<<"Move the disk "<<disks<<" from "<<from_rod<<" to "<<to_rod<<endl;
    towerOfHanoi(disks-1,aux_rod,to_rod,from_rod); // shift n-1 disks from A to C
}

int main(){
    int n = 3; // number of disks
    towerOfHanoi(n,'A','C','B');
    return 0;
}