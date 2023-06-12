#include "DxLib.h"
#include "../../include/scene.h"
#include "../../include/key_input_count.h"

int game() {
	DrawString(300, 200, "GAME SCENE NOW.", GetColor(255, 255, 255));

	// キーフレームを参照して60fpsの連続入力になることを防いでいる
	if (get_key_frame(KEY_INPUT_ESCAPE) == 1) {
		return MENU_SCENE;
	}

	return GAME_SCENE;
}

int menu() {
	DrawString(300, 200, "MENU SCENE NOW.", GetColor(255, 255, 255));

	if (get_key_frame(KEY_INPUT_RETURN) == 1) {
		return GAME_SCENE;
	}

	if (get_key_frame(KEY_INPUT_ESCAPE) == 1) {
		return TITLE_SCENE;
	}

	return MENU_SCENE;
}

int title() {
	DrawString(300, 200, "TITLE SCENE NOW.", GetColor(255, 255, 255));
	
	if (get_key_frame(KEY_INPUT_RETURN) == 1) {
		return GAME_SCENE;
	}
	
	if (get_key_frame(KEY_INPUT_ESCAPE) == 1) {
		return MENU_SCENE;
	}

	return TITLE_SCENE;
}

// シーンの遷移を管理
void scene() {
	// 初期シーンはタイトル
	static int scene_check = TITLE_SCENE;
	scene_check = scene_map.at(scene_check)();
}