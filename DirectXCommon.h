#pragma once
#include "StringUtility.h"
#include "WinApp.h"
#include <array>
#include <cstdint>
#include <Windows.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <wrl.h>


#include "externals/imgui/imgui.h"
#include "externals/imgui/imgui_impl_dx12.h"
#include "externals/imgui/imgui_impl_win32.h"


struct Vector4
{
	float x;
	float y;
	float z;
	float w;
};

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

	//レンダーターゲットビュー
	void RTV_Initialize();

	//深度ステンシルビュー
	void DSV_Initialize();

	//フェンス
	void FenceInitialize();

	//ビューポート矩形の初期化
	void ViewportRectangleInitialize();

	//シザリング矩形
	void ScissoringRectangleInitialize();

	//DXCコンパイラの生成
	void DXC_Initialize();

	//ImGui
	void ImGuiInitialize();



	//デスクリプタヒープを生成する
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>CreateDescriptorHeap(D3D12_DESCRIPTOR_HEAP_TYPE heapType, UINT numDescriptors, bool shaderVisible);

	//指定番号のCPUデスクリプタハンドルを取得する
	static D3D12_CPU_DESCRIPTOR_HANDLE GetGPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);

	//指定番号のGPUデスクリプタハンドルを取得する
	static D3D12_GPU_DESCRIPTOR_HANDLE GetCPUDescriptorHandle(const Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>& descriptorHeap, uint32_t descriptorSize, uint32_t index);

	//SRVの指定番号のCPUデスクリプタハンドル取得する
	D3D12_CPU_DESCRIPTOR_HANDLE GetSRVCPUDescripptorHandle(uint32_t index);

	//SRVの指定番号のGPUデスクリプタハンドルを取得する
	D3D12_GPU_DESCRIPTOR_HANDLE GetSRVGPUDescriptorHandle(uint32_t index);

	ID3D12Resource* CreateDepthStencilTextureResource(int32_t width, int32_t height);

	//DXGIファクトリ
	//Microsoft::WRL::ComPtr<ID3D12Device>dxgiFactory;

	//sスワップチェ―ンリソース
	std::array<Microsoft::WRL::ComPtr<ID3D12Resource>, 2>swapChainResources;


private:
	HRESULT hr;

	//DirectX12デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> device;

	Microsoft::WRL::ComPtr<IDXGIFactory7> dxgiFactory;

	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> srvDescriptorHeap = nullptr;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>dsvDescriptorHeap = nullptr;
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap>rtvDescriptorHeap = nullptr;

	D3D12_CPU_DESCRIPTOR_HANDLE rtvStartHandle;

	D3D12_SHADER_RESOURCE_VIEW_DESC srvDesc{};
	D3D12_RENDER_TARGET_VIEW_DESC rtvDesc = {};
	D3D12_RENDER_TARGET_VIEW_DESC dsvDesc{};

	//フェンス
	ID3D12Fence* fence;

	D3D12_RESOURCE_BARRIER barrier{};

	IDXGISwapChain4* swapChain;
	DXGI_SWAP_CHAIN_DESC1 swapChainDesc{};

	//マテリアル用のリソースを作る。今回はcolor1つ分のサイズを用意する
	//ID3D12Resource* materialResource = nullptr;

	//ID3D12Resource* textureResources = nullptr;

	///ID3D12Resource* wvpResource = nullptr;


	D3D12_VIEWPORT viewport{};

	D3D12_RECT scissorRect{};

	//頂点バッファビューを作成する
	D3D12_VERTEX_BUFFER_VIEW vertexBufferViewSprite{};

	D3D12_GRAPHICS_PIPELINE_STATE_DESC graphicsPipelineStateDesc{};

	D3D12_DEPTH_STENCIL_DESC depthStencilDesc{};

	UINT backBufferIndex;

	//RTVを2つ作るのでディスクリプタを２つ用意
	D3D12_CPU_DESCRIPTOR_HANDLE rtvHandles[2];

	ID3D12Resource* depthStencilResource;

	//ID3D12Fence* fence = nullptr;


	HANDLE fenceEvent;

	uint64_t fenceValue = 0;
	
	//デバックレイヤー
	ID3D12Debug1* debugController = nullptr;
	//アダプターの選別
	IDXGIAdapter4* useAdapter = nullptr;

	WinApp* winApp = nullptr;

	uint32_t rtvDescriptorSize = 0;
	uint32_t srvDescriptorSize = 0;
	uint32_t dsvDescriptorSize = 0;

	ID3D12CommandQueue* commandQueue = nullptr;
	//コマンドアロケータ
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> commandAllocator;
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>commandList;

	

	D3D12_COMMAND_QUEUE_DESC commandQueueDesc{};

};

