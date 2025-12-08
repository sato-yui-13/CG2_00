#pragma once
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>
#include "WinApp.h"
class DirectXCommon
{

public:
	//初期化
	void Initialize(WinApp* winApp);
	//描画開始
	void PreDraw();
	//描画終了
	void PostDraw();

	//デバイス初期化
	void DeviceInitialize();
	//コマンド初期化
	void CommandInitialize();

	//スワップチェイン
	void SwapInitialize();
	
	//バッファの生成
	void BufferInitialize();

	//デスクリプタヒープ
	void DescriptorHeapInitialize();

private:
	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device>device;
	//DXGIファクトリ
	Microsoft::WRL::ComPtr<ID3D12Device>dxgiFactory;

	WinApp* winApp = nullptr;

	//デスクリプタヒープを生成する
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>CreateDescriptorHeap();
};

