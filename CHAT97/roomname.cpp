// RoomName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MapClient.h"
#include "RoomName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoomName �_�C�A���O


CRoomName::CRoomName(int room)
	: CDialog(CRoomName::IDD, NULL)
{
	m_room=room;
	//{{AFX_DATA_INIT(CRoomName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void CRoomName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRoomName)
                // ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRoomName, CDialog)
	//{{AFX_MSG_MAP(CRoomName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomName ���b�Z�[�W �n���h��

BOOL CRoomName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CString s;
	CString a="�P�Q�R�S�T�U�V�W�X10";
	a=a.Mid(m_room*2,2);
	s.Format("%s�����ɖ��O��t���܂�",a);
	GetDlgItem(IDC_SENDTITLE)->SetWindowText(s);
	
	return FALSE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void CRoomName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
	GetDlgItem(IDC_ROOMNAME)->GetWindowText(mes);
	CDialog::OnOK();
}
