#include <windows.h>
#include "DxLib.h"
#include "../include/screen.h"
#include "../include/initialization.h"
#include "../include/fps.h"
#include "../include/scene.h"
#include "../include/key_input_count.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    Fps fps;
    int opening_sound_hundle;
    
    // 初期化と設定
    if (initialization() != TRUE) {
        return -1;
    }

    // 起動直後の隙間時間
    Sleep(500);

    // サークル名表示
    opening_sound_hundle = LoadSoundMem("resources/opening_sound.wav");
    if (opening_sound_hundle == -1) {
        return -1;
    }
    DrawString((SCREEN_WIDTH / 2) - 85 , SCREEN_HEIGHT / 2, "Made by EAST CASTLE", GetColor(255, 255, 255));
    ScreenFlip();

    // 音の再生
    PlaySoundMem(opening_sound_hundle, DX_PLAYTYPE_NORMAL);
    // 音のハンドル削除
    DeleteSoundMem(opening_sound_hundle);

    ClearDrawScreen();
    ScreenFlip();

    // 隙間時間
    Sleep(1300);

    // 裏画面を表画面へ表示，メッセージ処理，裏画面消去，全てが正常の場合のみループする
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
        fps.Update();	//更新
        fps.Draw();		//描画

        // Scene管理
        scene();

        fps.Wait();		//待機
    }

    // ＤＸライブラリの後始末
    DxLib_End();

    // ソフトの終了
    return 0;
}