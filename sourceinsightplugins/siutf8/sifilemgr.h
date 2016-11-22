#ifndef __SIFILEMGR__H__
#define __SIFILEMGR__H__


//�ļ��ṹ
typedef struct SiFileInfo
{
	unsigned long hash;
	int u8flag;
	unsigned char orgmd5[16];
	char orgfile[256];
	char gbkfile[256];
};


//��ӵ�����
void SiFile_Add(unsigned long hash,int u8flag,unsigned char md5[16],char* orgfile,char* gbkfile);


//ɾ����ʱ�ļ�
void SiFile_Unlink(void);

//�������в����ļ�
struct SiFileInfo* FindSiFileFromLink(unsigned long hash);


#endif
