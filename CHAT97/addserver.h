#if !defined(AFX_ADDSERVER_H__9C481414_59AB_11D1_9B6C_0040051AF39C__INCLUDED_)
#define AFX_ADDSERVER_H__9C481414_59AB_11D1_9B6C_0040051AF39C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// AddServer.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CAddServer �_�C�A���O

class CAddServer : public CDialog
{
// �R���X�g���N�V����
public:
	void SetData(CString name,CString host,UINT port);
	CAddServer(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CAddServer)
	enum { IDD = IDD_ADDSERVER };
	CString	m_address;
	CString	m_name;
	UINT	m_port;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CAddServer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CAddServer)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_ADDSERVER_H__9C481414_59AB_11D1_9B6C_0040051AF39C__INCLUDED_)
