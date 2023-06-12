#include "DxLib.h"
#include "../../include/initialization.h"
#include "../../include/screen.h"

bool initialization() {
    //�����������I�t�ɂ���(FPS�����ɂ�炸�Œ�)
    SetWaitVSyncFlag(FALSE);

    // ��ʕ\����ݒ�(TRUE�ŃE�B���h�E�\��:FALSE�Ńt���X�N���[���\��)
    ChangeWindowMode(TRUE);

    // ��ʃ��[�h�̐ݒ�
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_BIT_DEPTH);

    // �X�N���[�����̐ݒ�
    SetWindowText("Dynagon");

    // �c�w���C�u�����̏�����
    if (DxLib_Init() < 0) {
        // �G���[�����������璼���ɏI��
        return FALSE;
    }

    // �`���𗠉�ʂɂ���
    SetDrawScreen(DX_SCREEN_BACK);

    return TRUE;
}