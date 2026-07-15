#pragma once
#include "Engine/GameObject.h"

class Ground; //前方宣言

class Esa :
    public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Esa(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;
private:
	int hModel_;
	Ground* ground_; //地面オブジェクトのポインタ
};

