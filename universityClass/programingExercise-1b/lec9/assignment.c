/*
以下のようなフラクタル模様を作成する
lev = 0:
    #
lev = 1:
    ###
    #.#
    ###
lev = 2:
    #########
    #.##.##.#
    #########
    ###...###
    #.#...#.#
    ###...###
    #########
    #.##.##.#
    #########
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char** createPattern(int lev, int cnt, char** pattern) {
    int size = pow(3, cnt);
    char** newPattern = (char**)malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        newPattern[i] = (char*)malloc(size * sizeof(char));
    }

    // 全体を3*3に区切って、左上から右方向に詰めていく
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            for (int row = 0; row < pow(3, cnt - 1); row++) {
                for (int col = 0; col < pow(3, cnt - 1); col++) {
                    int BASE_X_INDEX = x * pow(3, cnt - 1);
                    int BASE_Y_INDEX = y * pow(3, cnt - 1);
                    // 3*3に分けた要素の内、中央に位置するもの
                    if (x == 1 && y == 1) {
                        newPattern[row + BASE_X_INDEX][col + BASE_Y_INDEX] = '.';
                    } 
                    // 3*3に分けた要素の内、中央以外の箇所それぞれに1レベル前の全体をコピーする
                    else {
                        // レベル0のときのベースケース
                        if (pattern == NULL) {
                            newPattern[row + BASE_X_INDEX][col + BASE_Y_INDEX] = '#';
                        } else {
                            newPattern[row + BASE_X_INDEX][col + BASE_Y_INDEX] = pattern[row][col];
                        }
                    }
                }   
            }
        }   
    }
    if (lev == cnt) {
        return newPattern;
    }
    return createPattern(lev, cnt + 1, newPattern);
}

int main(void) {
    int lev;
    char** pattern;
    scanf("%d", &lev);

    pattern = createPattern(lev, 0, NULL);
    
    for (int row = 0; row < pow(3, lev); row++) {
        for (int col = 0; col < pow(3, lev); col++) {
            printf("%c", pattern[row][col]);
        }
        puts("\n");
    }

    return 0;
}
