#include <DxLib.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE);				// ウィンドウモードに切り替え
	if (DxLib_Init()) return -1;		// DxLibの初期化

	SetFontSize(100);

	SetDrawScreen(DX_SCREEN_BACK);		// 書き込み先をバックバッファに変更
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		DrawString(0, 0, "hello", 0x80ff80);
		
		ScreenFlip();					// バックバッファをフロントバッファにコピー
		ClearDrawScreen();				// バックバッファをクリア
	}

	DxLib_End();						// DxLibの終了処理
	return 0;
}
