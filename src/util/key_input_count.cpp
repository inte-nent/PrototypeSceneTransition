/*
 *  ���̃L�[���͂Ɋւ���\�[�X�R�[�h�͈ȉ��̃T�C�g����擾����
 *  https://dixq.net/g/index.html [�V�E�Q�[���v���O���~���O�̊�]
 */

#include "DxLib.h"
#include "../../include/key_input_count.h"

int key_frame[256]; // �L�[��������Ă���t���[�������i�[����

int get_key_frame(int KEY_INPUT) {
    return key_frame[KEY_INPUT];
}

int gpUpdateKey() {
    char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            key_frame[i]++;     // ���Z
        }
        else {              // ������Ă��Ȃ����
            key_frame[i] = 0;   // 0�ɂ���
        }
    }
    return 0;
}