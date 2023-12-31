#pragma once
#include "BaseCharacter.h"
#include <optional>

#include "input/Input.h"

#include "PlayerBullet.h"

#include "Sprite.h"

//class GameScene;

/// <summary>
/// プレイヤー
/// </summary>
class Player : public BaseCharacter {
public: // サブクラス
	/// <summary>
	/// モデルの配列番号
	/// </summary>
	enum modelIndex {
		Body,	// 体
		Head,	// 頭
		L_Arm,	// 左腕
		R_Arm,	// 右腕
		Wepon	// 
	};

public: // メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();
	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// 初期化処理 
	/// </summary>
	/// <param name="models">モデルデータ</param>
	void Initialize(const std::vector<Model*>& models) override;

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update() override;

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="viewProjection">ViewProjection</param>
	void Draw(const ViewProjection& viewProjection) override;

	/// <summary>
	/// もし当たっていた場合の処理
	/// </summary>
	void OnCollision(float damage) override;

	/// <summary>
	/// グローバル変数の取得
	/// </summary>
	void ApplyGlobalVariavles() override;

	/// <summary>
	///
	/// </summary>
	void InitializeGlobalVariavles() override;

	/// <summary>
	/// 浮遊ギミック更新
	/// </summary>
	void UpdateFloatingGimmick() override;

	/// <summary>
	/// 腕ふりギミック更新
	/// </summary>
	void UpdateArmGimmick() override;

	/// <summary>
	/// 攻撃を食らったときの動き
	/// </summary>
	void DamageGimmick() override;


	/// <summary>
	/// 各部位のモデルの初期化処理
	/// </summary>
	void ModelInitialize(); 

	/// <summary>
	/// 通常状態の更新処理
	/// </summary>
	void RootUpdate();

	/// <summary>
	/// 攻撃の更新処理
	/// </summary>
	void Attack();

	/// <summary>
	/// 2D,3Dレティクルの更新処理
	/// </summary>
	void ReticleUpdate();

	/// <summary>
	/// 弾が有効かどうか
	/// </summary>
	void BulletIsDead();

	/// <summary>
	/// 2dのUI関係の描画処理
	/// </summary>
	void DrawUI();

	/// <summary>
	/// ViewProjectionの設定
	/// </summary>
	/// <param name="viewProjection">ViewProjection</param>
	void SetViewProjection(const ViewProjection* viewProjection);

	/// <summary>
	/// 弾のモデル設定
	/// </summary>
	/// <param name="bulletModels"></param>
	void SetBulletModel(const std::vector<Model*>& bulletModels) { bulletModels_ = bulletModels; }

	/// <summary>
	/// レティクルの設定
	/// </summary>
	/// <param name="texture"></param>
	void SetReticle(uint32_t texture) { texReticle_ = texture; }

	/// <summary>
	/// 体力の設定
	/// </summary>
	/// <param name="texture"></param>
	void SetHeart(
		uint32_t hp_root, 
		uint32_t hp_gauge_root,
		uint32_t hp_out,
		uint32_t hp_gauge_out);

	void SetDamageEffect(uint32_t tex) { damageEffectTex_ = tex; }

	/// <summary>
	///
	/// </summary>
	/// <returns></returns>
	const std::list<PlayerBullet*>& GetBullets() { return bullets_; }

	void SetIsFps(bool isFps) { isFps_ = isFps; }

	float GetHP() { return hp_; }

	float GetSetHP() { return setHp_; }

private: // メンバ変数
	// 入力関係
	Input* input_ = nullptr;

	// 追従カメラ用のビュープロジェクション
	const ViewProjection* viewProjection_ = nullptr;

	// モデルの数
	const int kModelNo = 5;
	// 弾
	PlayerBullet* bullet_ = nullptr;
	std::list<PlayerBullet*> bullets_;

	// 弾のモデル
	std::vector<Model*> bulletModels_;
	


	// 3dレティクルのワールド変換データ
	WorldTransform worldTransform_3dReticle_;

	// 2dレティクルのスプライト
	std::unique_ptr<Sprite> sprite_2dReticle_ = nullptr;
	// レティクルのテクスチャ
	uint32_t texReticle_ = 0u;

	// 体力表示のスプライト
	std::unique_ptr<Sprite> hp_bar[2];
	std::unique_ptr<Sprite> hp_gauge_[2];

	Vector2 hp_pos_{};
	Vector2 hp_gauge_pos_{};

	Vector2 hp_size_{};

	uint32_t hp_tex_[2];
	uint32_t hp_gauge_tex_[2];
	bool isDenger_ = false;

	uint32_t damageSEHandle_ = 0u;
	uint32_t fire_SEHandle_ = 0u;
	std::unique_ptr<Sprite> damageEffect_;
	uint32_t damageEffectTex_ = 0u;
	float damageEffectAlpha_ = 0.0f;
	float damageEffectAlpha_offset_ = 0.01f;

	// 体力のスプライト
	//std::unique_ptr<Sprite> p_heart_ = nullptr;
	// 体力のテクスチャ
	//uint32_t heartTex_ = 0u;


	// 弾のタイマー
	int timer_ = 1;

	//
	bool isFps_ = true;

	// 弾を撃てるかどうか
	bool isAttack_ = false;

	// ジャンプできるかどうか
	bool isJump_ = false;

	bool isClear_ = false;

private: // 外部から書き換え可能な値
	// 各部位のワールド変換データ
	WorldTransform worldTransform_parts_[5];

};
