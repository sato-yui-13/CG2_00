#pragma once
#include<Windows.h>
#include<wrl.h>
#define DIRECTINPIT_VERSION 0x0800
#include <dinput.h>


class Input
{
public:
	//初期化
	void Initialize(HINSTANCE hInstance,HWND hwnd);

	//更新
	void Update();


	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;


private:
	//キーボードのデバイス
	IDirectInputDevice8 keyboard;

	// directInput
	// keyboardDevice
	// 
	//


};

