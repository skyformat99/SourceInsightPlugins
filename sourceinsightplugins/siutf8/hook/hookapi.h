#ifndef __HOOKAPI__H__
#define __HOOKAPI__H__

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

//ָ��API����HOOK��������һ������ԭ�����Ĵ�������ַ��
void* HookFunction(char* ModuleName,char* FunctionName,void* pNewFunction);

//�ָ���HOOK�ĺ���������ҪHookFunction�������صĴ�������ַ��Ϊ������
BOOL UnHookFunction(char* ModuleName,char* FunctionName,void* pProxyFunction);

//���ĳ�������Ƿ�HOOK
BOOL IsFuncHooked(char* ModuleName,char* FunctionName);

#ifdef __cplusplus
}
#endif

#endif
