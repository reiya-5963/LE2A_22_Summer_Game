#include "OverScene.h"

OverScene::OverScene() {
}

OverScene::~OverScene() {}

void OverScene::Initialize() { 
	//
	BaseScene::Initialize();

	//
	scenedNo_ = OVER_S;

	//
	InitializeGlobalVariavles();

	if (input_->TriggerKey(DIK_1)) {
		scenedNo_ = TITLE_S;
	}
	if (input_->TriggerKey(DIK_2)) {
		scenedNo_ = GAME_S;
	}
	if (input_->TriggerKey(DIK_3)) {
		scenedNo_ = CLEAR_S;
	}


}

void OverScene::Update() {
	//
	ApplyGlobalVariavles();
}

void OverScene::Draw() { 
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画 
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	
	
	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion
#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion
#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void OverScene::ApplyGlobalVariavles() {}

void OverScene::InitializeGlobalVariavles() {}