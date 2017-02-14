// SetHandle.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MapClient.h"
#include "SetHandle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetHandle �_�C�A���O


CSetHandle::CSetHandle(CWnd* pParent /*=NULL*/)
	: CDialog(CSetHandle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetHandle)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CSetHandle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetHandle)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetHandle, CDialog)
	//{{AFX_MSG_MAP(CSetHandle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetHandle ���b�Z�[�W �n���h��

void CSetHandle::OnOK() 
{
	GetDlgItem(IDC_HANDLE)->GetWindowText(m_handle);
	GetDlgItem(IDC_MAIL)->GetWindowText(m_mail);
	GetDlgItem(IDC_HOMEPAGE)->GetWindowText(m_homepage);
	GetDlgItem(IDC_PROFILE)->GetWindowText(m_profile);
	
	CDialog::OnOK();
}

BOOL CSetHandle::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	GetDlgItem(IDC_HANDLE)->SetWindowText(m_handle);
	GetDlgItem(IDC_MAIL)->SetWindowText(m_mail);
	GetDlgItem(IDC_HOMEPAGE)->SetWindowText(m_homepage);
	GetDlgItem(IDC_PROFILE)->SetWindowText(m_profile);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
