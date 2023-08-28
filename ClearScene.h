#pragma once

#include "BaseScene.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

#include <memory>

class ClearScene : public BaseScene {
public: // メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	ClearScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~ClearScene();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// グローバル変数の取得
	/// </summary>
	void ApplyGlobalVariavles();

	/// <summary>
	///
	/// </summary>
	void InitializeGlobalVariavles();

private: // メンバ変数
};