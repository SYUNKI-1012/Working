#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "TestScene.h"

Ground::Ground(GameObject* parent)
	:GameObject(parent), hSilly(-1)
{

}

void Ground::Initialize()
{
	hSilly = Model::Load("Ground2.fbx");
	Model::SetAnimFrame(hSilly, 0, 29, 1.0);

}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hSilly, transform_);
	Model::Draw(hSilly);
}

void Ground::Release()
{
}
