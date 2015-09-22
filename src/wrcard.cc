#include <node.h>
#include <v8.h>
#include <iostream>
#include <windows.h>
#include <exception>
#include <stdlib.h>
#include <string>

using namespace std;
using namespace v8;

static char *TO_CHAR(Handle<Value> val) {
	String::Utf8Value utf8(val->ToString());

	int len = utf8.length() + 1;
	char *str = (char *)calloc(sizeof(char), len);
	strncpy(str, *utf8, len);

	return str;
}

static WCHAR* UTF8toWCHAR(const char* inputString /** UTF-8 string. */)
{
	int outputSize;
	WCHAR* outputString;

	outputSize = MultiByteToWideChar(CP_UTF8, 0, inputString, -1, NULL, 0);

	if (outputSize == 0)
		return NULL;

	outputString = (WCHAR*)malloc(outputSize * sizeof(WCHAR));

	if (outputString == NULL) {
		SetLastError(ERROR_OUTOFMEMORY);
		return NULL;
	}

	if (MultiByteToWideChar(CP_UTF8, 0, inputString, -1, outputString, outputSize) != outputSize)
	{
		free(outputString);
		return NULL;
	}

	return outputString;
}

void Getcardid(const v8::FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	WCHAR* unicodeFilename = UTF8toWCHAR("RFV2007NETHOTEL.dll");

	static HMODULE module = LoadLibraryW(unicodeFilename);
	if (module){
		using pInit = char*(__stdcall *)(char* nCom);
		pInit procAddress = reinterpret_cast<pInit>(::GetProcAddress(module, "Getcardid"));

		if (procAddress)
		{
			char* result = reinterpret_cast<pInit>(procAddress)(TO_CHAR(args[0]));
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, result));
		}
		else
		{
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, "0"));
		}
	}
	else{
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "加载dll失败，检查文件是否存在或者路径是否正确"));
	}
}


void Woff_Card(const v8::FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	WCHAR* unicodeFilename = UTF8toWCHAR("RFV2007NETHOTEL.dll");

	static HMODULE module = LoadLibraryW(unicodeFilename);
	if (module){
		using pInit = int(__stdcall *)();
		pInit procAddress = reinterpret_cast<pInit>(::GetProcAddress(module, "Woff_Card"));
		if (procAddress)
		{
			int result = reinterpret_cast<pInit>(procAddress)();
			char* str = new char[0];
			sprintf(str, "%d", result);
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, str));
		}
		else
		{
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, "0"));
		}
	}
	else{
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "加载dll失败，检查文件是否存在或者路径是否正确"));
	}
}

void r_Card(const v8::FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	WCHAR* unicodeFilename = UTF8toWCHAR("RFV2007NETHOTEL.dll");

	static HMODULE module = LoadLibraryW(unicodeFilename);
	if (module){
		using pInit = char*(__stdcall *)(int i_display);
		pInit procAddress = reinterpret_cast<pInit>(::GetProcAddress(module, "R_Card"));
		if (procAddress)
		{
			char* result = reinterpret_cast<pInit>(procAddress)(1);
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, result));
		}
		else
		{
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, "0"));
		}
	}
	else{
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "加载dll失败，检查文件是否存在或者路径是否正确"));
	}
}

void w_Card(const v8::FunctionCallbackInfo<Value>& args) {
	Isolate* isolate = Isolate::GetCurrent();
	HandleScope scope(isolate);

	WCHAR* unicodeFilename = UTF8toWCHAR("RFV2007NETHOTEL.dll");

	static HMODULE module = LoadLibraryW(unicodeFilename);
	if (module){
		char* ptrnRoom = TO_CHAR(args[0]);
		char* ptrWstartdate = TO_CHAR(args[1]);
		char* ptrWenddate = TO_CHAR(args[2]);
		char* ptrVioce = TO_CHAR(args[3]);
		char* ptrObt = TO_CHAR(args[4]);
		char* ptrOp = TO_CHAR(args[5]);
		char* ptrnCode = TO_CHAR(args[6]);
		char* ptrjLift = TO_CHAR(args[7]);

		using pInit = int(__stdcall *)(char* nRoom, char* Wstartdate, char* Wenddate, char* Vioce, char* Obt, char* Op, char* nCode, char* jLift);
		pInit procAddress = reinterpret_cast<pInit>(::GetProcAddress(module, "W_Card"));
		if (procAddress)
		{
			int result = reinterpret_cast<pInit>(procAddress)(ptrnRoom, ptrWstartdate, ptrWenddate, ptrVioce, ptrObt, ptrOp, ptrnCode, ptrjLift);
			char* str = new char[0];
			sprintf(str, "%d", result);
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, str));
		}
		else
		{
			args.GetReturnValue().Set(String::NewFromUtf8(isolate, "0"));
		}
	}
	else{
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "加载dll失败，检查文件是否存在或者路径是否正确"));
	}
}

void InitAll(Handle<Object> exports) {
	Isolate* isolate = Isolate::GetCurrent();
	exports->Set(String::NewFromUtf8(isolate, "Getcardid"),
		FunctionTemplate::New(isolate, Getcardid)->GetFunction());

	exports->Set(String::NewFromUtf8(isolate, "Woff_Card"),
		FunctionTemplate::New(isolate, Woff_Card)->GetFunction());

	exports->Set(String::NewFromUtf8(isolate, "r_Card"),
		FunctionTemplate::New(isolate, r_Card)->GetFunction());

	exports->Set(String::NewFromUtf8(isolate, "w_Card"),
		FunctionTemplate::New(isolate, w_Card)->GetFunction());
}

NODE_MODULE(wrcard, InitAll)