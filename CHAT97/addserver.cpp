// AddServer.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "MapClient.h"
#include "AddServer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAddServer �_�C�A���O


CAddServer::CAddServer(CWnd* pParent /*=NULL*/)
	: CDialog(CAddServer::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddServer)
	m_address = _T("");
	m_name = _T("");
	m_port = 0;
	//}}AFX_DATA_INIT
}


void CAddServer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddServer)
	DDX_Text(pDX, IDC_SVADDRESS, m_address);
	DDV_MaxChars(pDX, m_address, 40);
	DDX_Text(pDX, IDC_SVNAME, m_name);
	DDV_MaxChars(pDX, m_name, 64);
	DDX_Text(pDX, IDC_SVPORT, m_port);
	DDV_MinMaxUInt(pDX, m_port, 20, 65535);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddServer, CDialog)
	//{{AFX_MSG_MAP(CAddServer)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddServer ���b�Z�[�W �n���h��

void CAddServer::SetData(CString name, CString host, UINT port)
{
	m_address=host;
	m_name=name;
	m_port=port;
}
