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
    
    // �������Ɛݒ�
    if (initialization() != TRUE) {
        return -1;
    }

    // �N������̌��Ԏ���
    Sleep(500);

    // �T�[�N�����\��
    opening_sound_hundle = LoadSoundMem("resources/opening_sound.wav");
    if (opening_sound_hundle == -1) {
        return -1;
    }
    DrawString((SCREEN_WIDTH / 2) - 85 , SCREEN_HEIGHT / 2, "Made by EAST CASTLE", GetColor(255, 255, 255));
    ScreenFlip();

    // ���̍Đ�
    PlaySoundMem(opening_sound_hundle, DX_PLAYTYPE_NORMAL);
    // ���̃n���h���폜
    DeleteSoundMem(opening_sound_hundle);

    ClearDrawScreen();
    ScreenFlip();

    // ���Ԏ���
    Sleep(1300);

    // ����ʂ�\��ʂ֕\���C���b�Z�[�W�����C����ʏ����C�S�Ă�����̏ꍇ�̂݃��[�v����
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
        fps.Update();	//�X�V
        fps.Draw();		//�`��

        // Scene�Ǘ�
        scene();

        fps.Wait();		//�ҋ@
    }

    // �c�w���C�u�����̌�n��
    DxLib_End();

    // �\�t�g�̏I��
    return 0;
}