#ifndef SCENE_H_
#define SCENE_H_

#include <unordered_map>
#include <string>

#define  GAME_SCENE	0
#define  MENU_SCENE	1
#define TITLE_SCENE	2

int game();
int menu();
int title();

const std::unordered_map<int, int(*)()> scene_map = {
	{GAME_SCENE, game},
	{MENU_SCENE, menu},
	{TITLE_SCENE, title}
};

void scene();

#endif // !SCENE_H_
