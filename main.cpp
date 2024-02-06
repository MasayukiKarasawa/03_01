#include <Novice.h>
#include"GameManager.h"
const char kWindowTitle[] = "LE2D_07_カラサワ_マサユキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	GameManager* gameManager = new GameManager();

	//ゲームループ
	gameManager->Run();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
