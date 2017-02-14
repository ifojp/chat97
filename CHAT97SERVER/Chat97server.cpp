// Chat97Server.cpp : �A�v���P�[�V�����p�N���X�̒�`���s���܂��B
//

#include "stdafx.h"
#include "Chat97Server.h"
#include "Chat97ServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChat97ServerApp

BEGIN_MESSAGE_MAP(CChat97ServerApp, CWinApp)
	//{{AFX_MSG_MAP(CChat97ServerApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChat97ServerApp �N���X�̍\�z

CChat97ServerApp::CChat97ServerApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}

/////////////////////////////////////////////////////////////////////////////
// �B��� CChat97ServerApp �I�u�W�F�N�g

CChat97ServerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CChat97ServerApp �N���X�̏�����

BOOL CChat97ServerApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// �W���I�ȏ���������
	// ���������̋@�\���g�p�����A���s�t�@�C���̃T�C�Y��������������
	//  ��Έȉ��̓���̏��������[�`���̒�����s�K�v�Ȃ��̂��폜����
	//  ���������B

#ifdef _AFXDLL
	Enable3dControls();			// ���L DLL ���� MFC ���g���ꍇ�͂������R�[�����Ă��������B
#else
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N����ꍇ�͂������R�[�����Ă��������B
#endif
	if (__argc > 1)
	{	m_port=atoi(__argv[1]);
	}else
	{	m_port=PORT;
	}

	CChat97ServerDlg* dlg=new CChat97ServerDlg;
	m_pMainWnd = dlg;
	dlg->Create(IDD_CHAT97SERVER_DIALOG);

	return TRUE;
}

