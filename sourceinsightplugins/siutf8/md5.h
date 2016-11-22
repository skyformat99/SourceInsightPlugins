/********************************************************************
*  ģ����: MD5�㷨ģ��
*  ժҪ:
********************************************************************/

#ifndef __MD5_H__
#define __MD5_H__


#ifndef uint8
	#define uint8  unsigned char
#endif

#ifndef uint32
	#define uint32 unsigned long int
#endif

typedef struct
{
	uint32 total[2];
	uint32 state[4];
	uint8 buffer[64];
}md5_context;


#ifdef  __cplusplus
extern "C" {
#endif


/**************************
����	:������������MD5��
����	:buf��Ҫ�����������
		:len��Ҫ������������ĳ���
���	:md5sum�����ɵ�MD5�룬�̶�16bytes
����	:��
ע�����ֺ��ն˲�ͬ��������
*/
void Md5Sum(unsigned char *buf, int len, unsigned char md5sum[16]);


#ifdef  __cplusplus
}
#endif


#endif

