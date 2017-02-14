// Chat97Server.h : CHAT97SERVER �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#define NOWVERSION	990919
#define CLIENTVERSION	971108
#define PORT		8000

#define  CMD_ELSE			0
#define  CMD_GETRANGEXY		1
#define  CMD_GETALLXY		2
#define  CMD_LOGIN			3
#define  CMD_LOGOUT			4
#define  CMD_ROOM			5
#define  CMD_MOVE			6
#define  CMD_SETHOTSPOT		7
#define  CMD_GETALLHOTSPOT	8
#define  CMD_KILL			9
#define  CMD_GETIPADDRESS	10
#define  CMD_SETVERSION		11
#define  CMD_CHAT			12
#define  CMD_SETHANDLE		13
#define  CMD_HTTP			99
#define  CMD_USER			999

#define  SEQ_NAME			1
#define  SEQ_HEAD			2
#define  SEQ_BODY			3




#if !defined(AFX_CHAT97SERVER_H__2A66FFC5_38A1_11D1_9B33_0040051AF39C__INCLUDED_)
#define AFX_CHAT97SERVER_H__2A66FFC5_38A1_11D1_9B33_0040051AF39C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��
#include "util.h"
#include "user.h"
#include "chatsock.h"
#include "sendmes.h"

/////////////////////////////////////////////////////////////////////////////
// CChat97ServerApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� Chat97Server.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CChat97ServerApp : public CWinApp
{
public:
	CChat97ServerApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CChat97ServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
	int m_port;

	//{{AFX_MSG(CChat97ServerApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_CHAT97SERVER_H__2A66FFC5_38A1_11D1_9B33_0040051AF39C__INCLUDED_)
