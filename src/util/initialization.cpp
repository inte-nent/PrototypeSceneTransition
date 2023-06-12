#include "DxLib.h"
#include "../../include/initialization.h"
#include "../../include/screen.h"

bool initialization() {
    //垂直同期をオフにする(FPSを環境によらず固定)
    SetWaitVSyncFlag(FALSE);

    // 画面表示を設定(TRUEでウィンドウ表示:FALSEでフルスクリーン表示)
    ChangeWindowMode(TRUE);

    // 画面モードの設定
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BIT_DEPTH);

    // スクリーン名の設定
    SetWindowText("Dynagon");

    // ＤＸライブラリの初期化
    if (DxLib_Init() < 0) {
        // エラーが発生したら直ちに終了
        return FALSE;
    }

    // 描画先を裏画面にする
    SetDrawScreen(DX_SCREEN_BACK);

    return TRUE;
}