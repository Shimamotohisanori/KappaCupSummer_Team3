#pragma once
#include "MyRenderer.h"
#include "graphics/IRenderer.h"

#include "graphics/ComputeAnimationVertexBuffer.h"

namespace nsK2EngineLow {
	

	/// </summary>
	class ModelRender : public IRenderer
	{
	public:
		ModelRender();
		~ModelRender();
		/// <summary>
		/// 初期化。通常はこの関数で初期化してください。
		/// </summary>
		/// <param name="filePath">ファイルパス。</param>
		/// <param name="animationClips">アニメーションクリップ。</param>
		/// <param name="numAnimationClips">アニメーションクリップの数。</param>
		/// <param name="enModelUpAxis">モデルの上方向。</param>
		/// <param name="isShadowReciever">シャドウレシーバーフラグtrueなら影が落ちる。</param>
		/// <param name="maxInstance">
		/// インスタンスの最大数。この引数を１より大きくするとインスタンシング描画が行われます。
		/// インスタンシング描画を行う際は描画したいインスタンスの数分だけ、UpdateInstancingDraw()を呼び出す必要があります。
		/// インスタンシング描画の詳細はSmaple_XXを参照してください。
		/// </param>
		/// <param name="isFrontCullingOnDrawShadowMap">
		/// シャドウマップを描画する際にフロントカリングを行う？
		/// フロントカリングを行うとシャドウアクネが軽減できます。
		/// しかし、板ポリのような閉じていないモデルをフロントカリングで描画すると、
		/// シャドウマップに描画されなくなってしまうため、その場合はこのフラグをfalseにしてください。
		/// 例)地面など。
		/// </param>
		void Init(
			const char* filePath,
			AnimationClip* animationClips = nullptr,
			int numAnimationClips = 0,
			EnModelUpAxis enModelUpAxis = enModelUpAxisZ,
			bool isShadowReciever = true,
			int maxInstance = 1,
			bool isFrontCullingOnDrawShadowMap = false);
		/// <summary>
		/// 半透明描画を行うオブジェクトを初期化
		/// </summary>
		/// <param name="filePath">ファイルパス。</param>
		/// <param name="animationClips">アニメーションクリップ。</param>
		/// <param name="numAnimationClips">アニメーションクリップの数。</param>
		/// <param name="enModelUpAxis">モデルの上方向。</param>
		/// <param name="isShadowReciever">trueなら影が落ちる。</param>
		/// <param name="maxInstance">
		/// インスタンスの最大数。この引数を１より大きくするとインスタンシング描画が行われます。
		/// インスタンシング描画を行う際は描画したいインスタンスの数分だけ、UpdateInstancingDraw()を呼び出す必要があります。
		/// インスタンシング描画の詳細はSmaple_XXを参照してください。
		/// </param>	
		/// <param name="isFrontCullingOnDrawShadowMap">
		/// シャドウマップを描画する際にフロントカリングを行う？
		/// フロントカリングを行うとシャドウアクネが軽減できます。
		/// しかし、板ポリのような閉じていないモデルをフロントカリングで描画すると、
		/// シャドウマップに描画されなくなってしまうため、その場合はこのフラグをfalseにしてください。
		/// 例)地面など。
		/// </param>
		


		/// <summary>
		/// 特殊なシェーディングを行いたい場合の初期化処理。
		/// </summary>
		/// <param name="initData">モデルデータ。</param>
		void InitForwardRendering(ModelInitData& initData);
		/// <summary>
		/// 更新処理。
		/// </summary>*/
		void Update();
		/// <summary>
		/// インスタンシングデータの更新。
		/// </summary>
		/// <param name="instanceNo">インスタンス番号</param>
		/// <param name="pos">座標</param>
		/// <param name="rot">回転</param>
		/// <param name="scale">拡大率</param>
		//////////////void UpdateInstancingData(int instanceNo, const Vector3& pos, const Quaternion& rot, const Vector3& scale);
		/// <summary>
		/// 描画処理。
		/// </summary>
		void Draw(RenderContext& rc);

		/// <summary>
		/// アニメーション再生。
		/// </summary>
		/// <param name="animNo">アニメーションクリップの番号。</param>
		/// <param name="interpolateTime">補完時間(単位：秒。)</param>
	



	//	/// <summary>
	//	/// アニメーションの再生中？
	//	/// </summary>
	


	//	/// <summary>
	//	/// モデルを取得。
	//	/// </summary>
	//	/// <returns>モデル</returns>
	



	//	/// <summary>
	//	/// 座標、回転、拡大を全て設定。
	//	/// </summary>
	//	/// <remark>
	//	/// インスタンシング描画が有効の場合は、この設定は無視されます。
	//	/// </remark>
	//	/// <param name="pos">座標。</param>
	//	/// <param name="rotation">回転。</param>
	//	/// <param name="scale">拡大。</param>
	


	//	/// <summary>
	//	/// 座標を設定。
	//	/// </summary>
	//	/// <remark>
	//	/// インスタンシング描画が有効の場合は、この設定は無視されます。
	//	/// </remark>
	//	/// <param name="pos">座標。</param>
	


	//	/// <summary>
	//	/// 座標を設定。
	//	/// </summary>
	//	/// <param name="x">x座標</param>
	//	/// <param name="y">y座標</param>
	//	/// <param name="z">z座標</param>
	


	//	/// <summary>
	//	/// 回転を設定。
	//	/// </summary>
	//	/// <remark>
	//	/// インスタンシング描画が有効の場合は、この設定は無視されます。
	//	/// </remark>
	//	/// <param name="rotation">回転。</param>
	


	//	/// <summary>
	//	/// 拡大率を設定。
	//	/// </summary>
	//	/// <remark>
	//	/// インスタンシング描画が有効の場合は、この設定は無視されます。
	//	/// </remark>
	//	/// <param name="scale">拡大率。</param>
	


	//	/// <summary>
	//	/// シャドウキャスターのフラグを設定する
	//	/// </summary>
	


	//	/// <summary>
	//	/// アニメーション再生の速度を設定する。
	//	/// </summary>
	//	/// <param name="animationSpeed">数値の分だけ倍にする。</param>
	


	//	/// <summary>
	//	/// ボーンの名前からボーン番号を検索。
	//	/// </summary>
	//	/// <param name="boneName">ボーンの名前</param>
	//	/// <returns>ボーン番号。見つからなかった場合は-1が返ってきます。</returns>
	


	//	/// <summary>
	//	/// ボーン番号からボーンを取得。
	//	/// </summary>
	//	/// <param name="boneNo">ボーン番号</param>
	//	/// <returns>ボーン</returns>
	



	//	/// <summary>
	//	/// シャドウキャスター？
	//	/// </summary>
	//	/// <returns></returns>
	


	//	/// <summary>
	//	/// インスタン数を取得。
	//	/// </summary>
	//	/// <returns></returns>
	


	//	/// <summary>
	//	/// インスタンシング描画を行う？
	//	/// </summary>
	//	/// <returns></returns>
	


	//	/// <summary>
	//	/// ワールド行列を取得。
	//	/// </summary>
	//	/// <param name="instanceId">
	//	/// インスタンスID。
	//	/// この引数はインスタンシング描画が向こうの場合は無視されます。
	//	/// </param>
	//	/// <returns></returns>
	


	//	/// <summary>
	//	/// インスタンスを除去。
	//	/// </summary>
	//	/// <remark>
	//	/// インスタンス描画を利用している際に、そのインスタンスをシーンから除去したい場合に利用してください。
	//	/// </remark>
	//	/// <param name="instanceNo">インスタンス番号</param>
	//	void RemoveInstance(int instanceNo);
	//	/// <summary>
	//	/// レイトレワールドに登録するかのフラグを設定する
	//	/// 頻繁に生成するモデル（弾など）をInitする前に引数falseで実行してください。
	//	/// </summary>
	


	
	//	/// <summary>
	//	/// スケルトンの初期化。
	//	/// </summary>
	//	/// <param name="filePath">ファイルパス。</param>
		void InitSkeleton(const char* filePath);
	//	/// <summary>
	//	/// アニメーションの初期化。
	//	/// </summary>
	//	/// <param name="animationClips">アニメーションクリップ。</param>
	//	/// <param name="numAnimationClips">アニメーションクリップの数。</param>
	//	/// <param name="enModelUpAxis">モデルの上向き。</param>
	


	//	/// <summary>
	//	/// 頂点計算パスから呼び出される処理。
	//	/// </summary>
	//	/// <param name="rc"></param>
	


	//	/// <summary>
	//	/// シャドウマップへの描画パスから呼ばれる処理。
	//	/// </summary>
	//	/// <param name="rc">レンダリングコンテキスト</param>
	//	/// <param name="ligNo">ライト番号</param>
	//	/// <param name="shadowMapNo">シャドウマップ番号</param>
	//	/// <param name="lvpMatrix">ライトビュープロジェクション行列</param>
	


	//	/// <summary>
	//	/// ZPrepassから呼ばれる処理。
	//	/// </summary>
	//	/// <param name="rc"></param>
	


	//	/// <summary>
	//	/// G-Buffer描画パスから呼ばれる処理。
	//	/// </summary>
	


	//	/// <summary>
	//	/// フォワードレンダーパスから呼ばれる処理。
	//	/// </summary>
	


	//	/// <summary>
	//	/// 半透明オブジェクト描画パスから呼ばれる処理。
	//	/// </summary>
	//	/// <param name="rc"></param>
	


	//	/// <summary>
	//	/// 各種モデルのワールド行列を更新する。
	//	/// </summary>
	


	
	//	/// <summary>
	//	/// レンダリングエンジンで発生したイベントを受け取ったときに呼ばれる処理。
	//	/// </summary>
	//	/// <param name="enEvent"></param>
	


	//	/// <summary>
	//	/// シャドウマップ描画用のモデルを初期化。
	//	/// </summary>
	//	/// <param name="renderingEngine">レンダリングエンジン</param>
	//	/// <param name="tkmFilePath">tkmファイルパス</param>
	//	/// <param name="modelUpAxis">モデルの上軸</param>
	


	//	/// <summary>
	//	/// ZPrepass描画用のモデルを初期化。
	//	/// </summary>
	//	/// <param name="renderingEngine"></param>
	//	/// <param name="tkmFilePath"></param>
	



	//	/// <summary>
	//	/// インスタンシング描画用の初期化処理を実行。
	//	/// </summary>
	//	/// <param name="maxInstance">最大インスタンス数</param>
	


	//	/// <summary>
	//	/// アニメーション済み頂点バッファの計算処理を初期化。
	//	/// </summary>
	//	/// <param name="tkmFilePath">tkmファイルのファイルパス</param>
	//	/// <param name="enModelUpAxis">モデルの上軸</param>
	


	//	/// <summary>
	//	/// GBuffer描画用のモデルを初期化。
	//	/// </summary>
	//	/// <param name="renderingEngine">レンダリングエンジン</param>
	//	/// <param name="tkmFilePath">tkmファイルパス</param>
	


	//	/// <summary>
	//	/// 半透明オブジェクト描画パスで使用されるモデルを初期化。
	//	/// </summary>
	//	/// <param name="renderingEngine"></param>
	//	/// <param name="tkmFilePath"></param>
	//	/// <param name="enModelUpAxis"></param>
	//	/// <param name="isShadowReciever"></param>
	


	//	/// <summary>
	//	/// 各種モデルの頂点シェーダーのエントリーポイントを設定。
	//	/// </summary>
	


	//	/// <summary>
	//	/// モデルを内包するバウンディングボリュームを初期化。
	//	/// </summary>
	//	/// <remark>
	//	/// AABBを構築します。
	//	/// </remark>
	


	//	/// <summary>
	//	/// 幾何学情報を初期化
	//	/// </summary>
	//	/// <param name="maxInstance">インスタンス数</param>
	


	public:
		static const int NUM_SHADOW_LIGHT = 1;
	private:
		AnimationClip* m_animationClips = nullptr;			// アニメーションクリップ。
		int							m_numAnimationClips = 0;			// アニメーションクリップの数。
		Vector3 					m_position = Vector3::Zero;			// 座標。
		Quaternion	 				m_rotation = Quaternion::Identity;	// 回転。
		Vector3						m_scale = Vector3::One;				// 拡大率。
		EnModelUpAxis				m_enFbxUpAxis = enModelUpAxisZ;		// FBXの上方向。
		Animation					m_animation;						// アニメーション。
		ComputeAnimationVertexBuffer m_computeAnimationVertexBuffer;	// アニメーション済み頂点バッファの計算処理。
		Model						m_model;							// モデル
		Model* m_addRaytracingWorldModel = nullptr;// レイトレワールドに登録したモデル。				
		Model						m_zprepassModel;					// ZPrepassで描画されるモデル
		Model						m_forwardRenderModel;				// フォワードレンダリングの描画パスで描画されるモデル
		Model						m_translucentModel;					// 半透明モデル。
		Model						m_renderToGBufferModel;				// RenderToGBufferで描画されるモデル
		Model						m_shadowModels[MAX_DIRECTIONAL_LIGHT][NUM_SHADOW_MAP];	// シャドウマップに描画するモデル
		ConstantBuffer				m_drawShadowMapCameraParamCB[MAX_DIRECTIONAL_LIGHT][NUM_SHADOW_MAP];		// シャドウマップ作成時に必要なカメラパラメータ用の定数バッファ。
		bool						m_isUpdateAnimation = true;			// アニメーションを更新する？
		Skeleton					m_skeleton;							// 骨。
		bool						m_isShadowCaster = true;			// シャドウキャスターフラグ
		float						m_animationSpeed = 1.0f;
		int							m_numInstance = 0;					// インスタンスの数。
		int							m_maxInstance = 1;					// 最大インスタンス数。
		bool						m_isEnableInstancingDraw = false;	// インスタンシング描画が有効？
		bool						m_isRaytracingWorld = true;			//レイトレワールドに登録する？
		std::unique_ptr<Matrix[]>	m_worldMatrixArray;					// ワールド行列の配列。
		StructuredBuffer			m_worldMatrixArraySB;				// ワールド行列の配列のストラクチャードバッファ。
							// ジオメトリ情報。
		std::unique_ptr<int[]>		m_instanceNoToWorldMatrixArrayIndexTable;	// インスタンス番号からワールド行列の配列のインデックスに変換するテーブル。


	};
}
