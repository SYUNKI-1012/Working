#include "Esa.h"
#include "Engine/Model.h"

Esa::Esa(GameObject* parent)
{
}

void Esa::Initialize()
{
	hModel_ = Model::Load("Esa.fbx");
}

void Esa::Update()
{
}

void Esa::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}
