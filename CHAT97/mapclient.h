// MapClient.h : MAPCLIENT �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#define CHAT97_USERICHEDIT

#define DEFAULT_PORT	8000
#define DEFAULT_WORLD	0
#define DEFAULT_NAME	"RUBY�T�[�o"
#define DEFAULT_HOST	"chat97.oosama.net"

#define GETCGI_HOST		"www.oosama.net"
#define GETCGI_PATH		"/server.txt"
#define GETCGI_PORT		80
#define NOW_VERSION     "20020710"
#define BOSSSTRING		"#4�{�X�����܂����`"
#define HISTORYMAX		20
#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��

/////////////////////////////////////////////////////////////////////////////
// CMapClientApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� MapClient.cpp �t�@�C�����Q�Ƃ��Ă��������B
//
#include "util.h"
#include "user.h"
#include "ChatSock.h"
#include "Send.h"
#include "sethandle.h"
#include "Member.h"
#include "BossString.h"
#include "editserver.h"
#include "addserver.h"

class CMapClientApp : public CWinApp
{
public:
	CMapClientApp();
	void CutESC(CString &str);
	BOOL m_isDebug;
	BOOL m_isAuto;
	BOOL m_isSysOp;
	CString m_host;
	int	m_port;
	int	m_world;

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CMapClientApp)
	public:
	virtual BOOL InitInstance();
	virtual int Run();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CMapClientApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

