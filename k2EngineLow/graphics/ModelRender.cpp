#include "k2EngineLowPreCompile.h"
#include "graphics/ModelRender.h"
#include "graphics/RenderingEngine.h"
using namespace nsK2EngineLow;

namespace nsK2EngineLow {
	ModelRender::ModelRender()
	{
		
	}
	ModelRender::~ModelRender()
	{
		
	}
    

	void ModelRender::Init(const char* filePath,
		AnimationClip* animationClips,
		int numAnimationClips,
		EnModelUpAxis enModelUpAxis,
		bool isShadowReciever,
		int maxInstance,
		bool isFrontCullingOnDrawShadowMap)
	{
		// インスタンシング描画用のデータを初期化。
		


		// スケルトンを初期化。
		InitSkeleton(filePath);

		//モデルの初期化データを変数に保持できるようにする
		ModelInitData modelInitData;

		//モデルデータのtkmのファイルパスはこの引数が勝手に決めている
		//あとはそれを入れるだけ
		modelInitData.m_tkmFilePath = filePath;

		//モデルを描画するために必要なシェーダー
		modelInitData.m_fxFilePath = "Assets/shader/model.fx";

		// アニメーションを初期化。
		
		// アニメーション済み頂点バッファの計算処理を初期化。
		
		// GBuffer描画用のモデルを初期化。
		
		// ZPrepass描画用のモデルを初期化。
		
		// シャドウマップ描画用のモデルを初期化。
		
		// 幾何学データを初期化。
		
		// 各種ワールド行列を更新する。
		

		//tkmのデータが入ったモデルを初期化する(引数はモデルの初期化データ)
		m_model.Init(modelInitData);
	}

	
	void ModelRender::InitSkeleton(const char* filePath)
	{
		//スケルトンのデータを読み込み。
		std::string skeletonFilePath = filePath;
		int pos = (int)skeletonFilePath.find(".tkm");
		skeletonFilePath.replace(pos, 4, ".tks");
		m_skeleton.Init(skeletonFilePath.c_str());
	}

	
	void ModelRender::Update()
	{
		//ワールド行列の更新をすることによって
		//モデルの場所、回転、大きさがその状態で映される
		m_model.UpdateWorldMatrix(m_position, m_rotation, m_scale);

		if (m_skeleton.IsInited()) {
			m_skeleton.Update(m_zprepassModel.GetWorldMatrix());
		}

		//スケルトン(モデルの骨)を更新する
		//引数はモデルのワールド座標を参考にする
		//これで、モデルの骨が適切な場所へ更新される
		m_skeleton.Update(m_model.GetWorldMatrix());

		//アニメーションを進める。
		m_animation.Progress(g_gameTime->GetFrameDeltaTime() * m_animationSpeed);

	}
	void ModelRender::Draw(RenderContext& rc)
	{
		//描画オブジェクトを追加
		g_renderingEngine->AddRenderObject(this);

		//モデルの描画をする
		m_model.Draw(rc);
		
	}

	
}