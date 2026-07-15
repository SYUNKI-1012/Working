#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "TestScene.h"
#include <vector>
#include "Engine/CsvReader.h"


namespace
{
	using std::vector;
	int model_t = -1;
	//vector< vector<int>> mapData =
	//{
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, }, //0 (外壁)
	//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, }, //1 (左下がゴール)
	//	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, }, //2
	//	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, }, //3
	//	{1, 0, 1, 0, 0, 0, 0, 0, 0, 1, }, //4
	//	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1, }, //5
	//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, }, //6
	//	{1, 0, 1, 1, 1, 0, 0, 0, 0, 1, }, //7
	//	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, },//8 （右下がゴール）
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, } //9行目 (外壁)
	//};
}

Ground::Ground(GameObject* parent)
	:GameObject(parent, "Ground"), hModel_(-1), mapWidth_(-1), mapHeight_(-1)
{
	CsvReader csvData;
	csvData.Load("map.csv");
	mapWidth_ = csvData.GetWidth();
	mapHeight_ = csvData.GetHeight();
	//mapData_を初期化 mapHeith_個のvector<int>の配列を作る
	mapData_ = vector<vector<int>>(mapHeight_, vector<int>(mapWidth_, 0));
	for (int x = 0; x < mapWidth_; x++)
	{
		for (int y = 0; y < mapHeight_; y++)
		{
			mapData_[y][x] = csvData.GetValue(x, y); 
		}
	}
}

void Ground::Initialize()
{
	hModel_ = Model::Load("Ground3.fbx");
	model_t = Model::Load("Brock.fbx");

}

void Ground::Update()
{
}

void Ground::Draw()
{
	//Model::SetTransform(hModel_, transform_);
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	for (int j = 0;j < 10; j++)
	{
		for (int i = 0;i < 10;i++)
		{
			if (mapData_[j][i] == 1)
			{
				Transform tr;
				tr.position_ = { -9.0f + i * 2.0f, 0.0f, 9.0f - j * 2.0f };
				Model::SetTransform(model_t, tr);
				Model::Draw(model_t);
			}
		}
	}
}

void Ground::Release()
{
}
