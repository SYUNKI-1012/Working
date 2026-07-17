#include "Esa.h"
#include "Engine/Model.h"
#include "TestScene.h"
#include <vector>
#include "Engine/CsvReader.h"
#include "Ground.h"

namespace
{
	using std::vector;
	int model_t = -1;
}

Esa::Esa(GameObject* parent)
	:GameObject(parent, "Esa"), hModel_(-1), mapWidth_(-1), mapHeight_(-1)
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

void Esa::Initialize()
{
	model_t = Model::Load("Esa.fbx");
	hModel_ = Model::Load("Ground3.fbx");
}

void Esa::Update()
{
}

void Esa::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	for (int j = 11;j < 20; j++)
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
