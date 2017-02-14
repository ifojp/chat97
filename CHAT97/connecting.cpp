// Connecting.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MapClient.h"
#include "Connecting.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CConnecting �_�C�A���O


CConnecting::CConnecting(CWnd*pParent,CChatSocket*sock,CString&host,int port)
	: CDialog(CConnecting::IDD, pParent)
{
	m_pParent=pParent;

	m_pSocket=sock;
	m_host=host;
	m_port=port;
	m_timer=0;
	//{{AFX_DATA_INIT(CConnecting)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CConnecting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConnecting)
                // ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CConnecting, CDialog)
	//{{AFX_MSG_MAP(CConnecting)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConnecting ���b�Z�[�W �n���h��

void CConnecting::OnOK() 
{
}

void CConnecting::OnCancel() 
{
	if (m_timer!=0)
		KillTimer(m_timer);
	
	CDialog::OnCancel();
}

BOOL CConnecting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_pSocket->Connect(m_pParent,m_host,m_port);
	CDialog::OnOK();
//	m_timer=SetTimer(1,100,NULL);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CConnecting::OnTimer(UINT nIDEvent) 
{
	KillTimer(m_timer);
	m_timer=0;
	m_pSocket->Connect(m_pParent,m_host,m_port);
	CDialog::OnOK();
}
