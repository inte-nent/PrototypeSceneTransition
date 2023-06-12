/*
 *  このキー入力に関するソースコードは以下のサイトから取得した
 *  https://dixq.net/g/index.html [新・ゲームプログラミングの館]
 */

#include "DxLib.h"
#include "../../include/key_input_count.h"

int key_frame[256]; // キーが押されているフレーム数を格納する

int get_key_frame(int KEY_INPUT) {
    return key_frame[KEY_INPUT];
}

int gpUpdateKey() {
    char tmpKey[256]; // 現在のキーの入力状態を格納する
    GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
            key_frame[i]++;     // 加算
        }
        else {              // 押されていなければ
            key_frame[i] = 0;   // 0にする
        }
    }
    return 0;
}