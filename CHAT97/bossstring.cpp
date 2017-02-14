// BossString.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MapClient.h"
#include "BossString.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BossString �_�C�A���O
BossString::BossString(CWnd* pParent /*=NULL*/)
	: CDialog(BossString::IDD, pParent)
{
	//{{AFX_DATA_INIT(BossString)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}

void BossString::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BossString)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(BossString, CDialog)
	//{{AFX_MSG_MAP(BossString)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BossString ���b�Z�[�W �n���h��

BOOL BossString::OnInitDialog()
{
	CDialog::OnInitDialog();
	GetDlgItem(IDC_BOSSSTRING)->SetWindowText(m_bossstring);
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
}

void BossString::OnOK() 
{
	CWinApp*pApp=AfxGetApp();
	GetDlgItem(IDC_BOSSSTRING)->GetWindowText(m_bossstring);
	pApp->WriteProfileString("CHAT97","BossString",m_bossstring);
	CDialog::OnOK();
}
