#if !defined(AFX_EDITSERVER_H__9C481413_59AB_11D1_9B6C_0040051AF39C__INCLUDED_)
#define AFX_EDITSERVER_H__9C481413_59AB_11D1_9B6C_0040051AF39C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditServer.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CEditServer �_�C�A���O

class CEditServer : public CDialog
{
// �R���X�g���N�V����
public:
	void UpdateList();
	int m_port[16];
	CString m_host[16];
	CString m_name[16];
	int m_count;
	CEditServer(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CEditServer)
	enum { IDD = IDD_EDITSERVER };
	CListBox	m_list;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CEditServer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CEditServer)
	afx_msg void OnSvadd();
	afx_msg void OnSvdel();
	afx_msg void OnSvdown();
	afx_msg void OnSvup();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnGetcgi();
	afx_msg void OnEditchange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_EDITSERVER_H__9C481413_59AB_11D1_9B6C_0040051AF39C__INCLUDED_)
