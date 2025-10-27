#include "Input.h"
#include <cassert>
#define DIRECTINPIT_VERSION 0x0800
#include <dinput.h>
#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")
#include <wrl.h>
using namespace Microsoft::WRL;

void Input::Initialize(HINSTANCE hInstance, HWND hwnd)
{

	HRESULT result;

	IDirectInput8*directInput = nullptr;
	result = DirectInput8Create(
		hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(void**)&directInput,
		nullptr
	);
	assert(SUCCEEDED(result));


	//キーボードデバイスの生成
	IDirectInputDevice8* keyboard = nullptr;
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
}