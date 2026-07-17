#include "Food.h"
#include "Engine/Model.h"


Food::Food(GameObject* parent)
	:GameObject(nullptr, "Food"), type_(FOODTYPE_NORMAL), hModel_(-1), score_(0)
{ 
}

Food::~Food()
{
}

void Food::Initialize()
{
	transform_.scale_ = { 0.3f, 0.3f, 0.3f };
	if (type_ == FoodType::FOODTYPE_NORMAL)
	{
		hModel_ = Model::Load("Esa.fbx");
		score_ = 1;
	}
	else if (type_ == FoodType::FOODTYPE_POWER)
	{
		hModel_ = Model::Load("");
		score_ = 5;
	}
}

void Food::Update()
{
	if (type_ == FoodType::FOODTYPE_POWER)
	{
		transform_.rotate_.y += 12;
	}
}

void Food::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Food::Release()
{
}

void Food::SetFoodType(FoodType type)
{
	type_ = type;
	if (type_ == FoodType::FOODTYPE_NORMAL)
	{
		hModel_ = Model::Load("Esa.fbx");
		score_ = 1;
	}
	else if (type_ == FoodType::FOODTYPE_POWER)
	{
		hModel_ = Model::Load("");
		score_ = 5;
	}
}

void Food::OnCollision(GameObject* pTarget)
{
}
