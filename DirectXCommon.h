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

	//初期化
	void DeviceInitialize();

private:
	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device>device;
	//DXGIファクトリ
	Microsoft::WRL::ComPtr<ID3D12Device>dxgiFactory;

	WinApp* winApp = nullptr;


};

