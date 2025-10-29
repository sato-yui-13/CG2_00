#include "Input.h"
#include <cassert>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")



void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{

	HRESULT result;


	//前回のキー入力保存
	memcpy(keyPre, key, sizeof(key));


	//IDirectInputDevice8 keyboard;

	
	result = DirectInput8Create(
		hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&directInput,
		nullptr
	);
	assert(SUCCEEDED(result));


	//キーボードデバイスの生成

	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	//入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));


	//排制御レベルのセット
	result = keyboard->SetCooperativeLevel(
		hwnd,
		DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY
	);

}





void Input::Update()
{


	//キーボード情報の取得開始
	keyboard->Acquire();

	//全キーの入力情報を取得する
	BYTE key[256] = {};
	keyboard->GetDeviceState(sizeof(key), key);


}

bool Input::PushKey(BYTE keyNumber)
{

	//指定きーを押していればtrueを返す
	if (key [keyNumber] ) {
		return true;
	};


	return false;
}

bool Input::TriggerKey(BYTE keyNumber)
	{

	if (key[keyNumber]) {
		return true;
	};
		return false;
	}
