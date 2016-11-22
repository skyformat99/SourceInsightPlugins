#include "sihandlemgr.h"
#include "utils.h"
#include <string.h>




//�������
typedef struct SiHandleLink
{
	struct SiHandleInfo handleinfo;
	struct SiHandleLink* next;
};

static struct SiHandleLink* si_handle_link = NULL;

//����һ��SiHandleLink�ṹ
static struct SiHandleLink* SiHandle_Create(HANDLE handle,int u8flag,char* orgfile,char* gbkfile)
{
	struct SiHandleLink* tmp = (struct SiHandleLink*)malloc(sizeof(struct SiHandleLink));
	memset(tmp,0,sizeof(struct SiHandleLink));
	tmp->handleinfo.handle = handle;
	tmp->handleinfo.u8flag = u8flag;
	strcpy(tmp->handleinfo.orgfile,orgfile);
	strcpy(tmp->handleinfo.gbkfile,gbkfile);
	return tmp;
}

static void SiHandle_Destory(struct SiHandleLink* node)
{
	free(node);
}

//��ӵ�����
void SiHandle_Add(HANDLE handle,int u8flag,char* orgfile,char* gbkfile)
{
	if(handle == INVALID_HANDLE_VALUE)
	{
		return;
	}
	struct SiHandleLink* file = SiHandle_Create(handle,u8flag,orgfile,gbkfile);
	struct SiHandleLink* tmp = si_handle_link;
	
	if(tmp == NULL)
	{
		si_handle_link = file;
		return;
	}
	
	while(tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = file;
	
	return;
}


//������ɾ��
void SiHandle_Del(HANDLE handle)
{
	struct SiHandleLink* cur = si_handle_link;
	struct SiHandleLink* prev = NULL;
	
	while(cur)
	{
		if(cur->handleinfo.handle == handle)
		{
			if(cur == si_handle_link)
			{
				si_handle_link = si_handle_link->next;
			}
			else 
			{
				prev->next = cur->next;
			}
			SiHandle_Destory(cur);
			return;
		}
		
		prev = cur;
		cur = cur->next;
	}	
	return;
}

//����
void SiHandle_Debug(void)
{
	struct SiHandleLink* cur = si_handle_link;
	int size = 0;
	if(cur == NULL)
	{
		OutputDebugString("SiHandleLink size=0");
		return;
	}
	while(cur)
	{
		size++;
		cur = cur->next;
	}
	OutputDebugStringEx("SiHandleLink size=%d",size);
}

//�������в��Ҿ��
struct SiHandleInfo* FindSiHandleFromLink(HANDLE handle)
{
	struct SiHandleLink* cur = si_handle_link;
	
	while(cur)
	{
		if(cur->handleinfo.handle == handle)
			return &cur->handleinfo;
			
		cur = cur->next;
	}	
	
	return NULL;
}
