#pragma once
#include<Windows.h>
#include<wrl.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>


class Input
{
public:
	//初期化
	void Initialize(HINSTANCE hInstance,HWND hwnd);

	//更新
	void Update();


	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;


	bool PushKey(BYTE keyNumber);
	bool TriggerKey(BYTE keyNumber);

private:


	BYTE key[256] = {};

//前回の全キー
	BYTE keyPre[256] = {};


	//キーボードのデバイス
	ComPtr<IDirectInputDevice8> keyboard;

	ComPtr<IDirectInput8> directInput;



	




	// directInput
	// keyboardDevice
	// 
	//


};

