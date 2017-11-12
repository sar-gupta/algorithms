#include<bits/stdc++.h>
using namespace std;

int findTiles (int top_r, int top_c, int def_r, int def_c, int size) {
    if(size == 2) {
        return 1;
    }

    int num_tiles = 0;
    int half_size = size/2;

    if (def_r <= top_r + half_size && def_c <= top_c + half_size) {
        num_tiles = 1 + findTiles(top_r, top_c, def_r, def_c, half_size) + 
                        findTiles(top_r, top_c + half_size + 1, top_r + half_size, top_c + half_size + 1, half_size) + 
                        findTiles(top_r + half_size + 1, top_c, top_r + half_size + 1, top_c + half_size, half_size) + 
                        findTiles(top_r + half_size + 1, top_c + half_size + 1, top_r + half_size + 1, top_c + half_size + 1, half_size);
    }
    else if (def_r <= top_r + half_size && def_c > top_c + half_size) {
        num_tiles = 1 + findTiles(top_r, top_c, top_r + half_size, top_c + half_size, half_size) + 
                        findTiles(top_r, top_c + half_size + 1, def_r, def_c, half_size) + 
                        findTiles(top_r + half_size + 1, top_c, top_r + half_size + 1, top_c + half_size, half_size) + 
                        findTiles(top_r + half_size + 1, top_c + half_size + 1, top_r + half_size + 1, top_c + half_size + 1, half_size);
    }
    else if (def_r > top_r + half_size && def_c <= top_c + half_size) {
        num_tiles = 1 + findTiles(top_r, top_c, top_r + half_size, top_c + half_size, half_size) + 
                        findTiles(top_r, top_c + half_size + 1, top_r + half_size, top_c + half_size + 1, half_size) + 
                        findTiles(top_r + half_size + 1, top_c, def_r, def_c, half_size) + 
                        findTiles(top_r + half_size + 1, top_c + half_size + 1, top_r + half_size + 1, top_c + half_size + 1, half_size);
    }
    else if (def_r > top_r + half_size && def_c > top_c + half_size) {
        num_tiles = 1 + findTiles(top_r, top_c, top_r + half_size, top_c + half_size, half_size) + 
                        findTiles(top_r, top_c + half_size + 1, top_r + half_size, top_c + half_size + 1, half_size) + 
                        findTiles(top_r + half_size + 1, top_c, top_r + half_size + 1, top_c + half_size, half_size) + 
                        findTiles(top_r + half_size + 1, top_c + half_size + 1, def_r, def_c, half_size);
    }

    return num_tiles;

}

int main() {
    cout<<findTiles (0,0,2,0,4);
}