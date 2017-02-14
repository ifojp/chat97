// HelpDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MapClient.h"
#include "HelpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg �_�C�A���O


CHelpDlg::CHelpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHelpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHelpDlg)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CHelpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHelpDlg)
                // ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHelpDlg, CDialog)
	//{{AFX_MSG_MAP(CHelpDlg)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_SEECHAT97HP, OnSeechat97hp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHelpDlg ���b�Z�[�W �n���h��

void CHelpDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	OnCancel();
}

void CHelpDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	OnCancel();
}

void CHelpDlg::OnRButtonDown(UINT nFlags, CPoint point) 
{
	OnCancel();
}

BOOL CHelpDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CString v(NOW_VERSION);
	v=v.Left(4)+"/"+v.Mid(4,2)+"/"+v.Mid(6)+"��";
	GetDlgItem(IDC_VERSION)->SetWindowText(v);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CHelpDlg::OnSeechat97hp() 
{
	CString s="[InternetShortcut]\nURL=http://www.oosama.com/chat";
	CFile fp;
	fp.Open("tmp.URL",CFile::modeCreate|CFile::modeReadWrite);
	fp.Write(s,s.GetLength());
	fp.Close();

	ShellExecute(m_hWnd,"open","tmp.URL",NULL,NULL,SW_SHOW);
}
