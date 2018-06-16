#include <DxLib.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE);				// �E�B���h�E���[�h�ɐ؂�ւ�
	if (DxLib_Init()) return -1;		// DxLib�̏�����

	SetFontSize(100);

	SetDrawScreen(DX_SCREEN_BACK);		// �������ݐ���o�b�N�o�b�t�@�ɕύX
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		DrawString(0, 0, "hello", 0x80ff80);
		
		ScreenFlip();					// �o�b�N�o�b�t�@���t�����g�o�b�t�@�ɃR�s�[
		ClearDrawScreen();				// �o�b�N�o�b�t�@���N���A
	}

	DxLib_End();						// DxLib�̏I������
	return 0;
}
