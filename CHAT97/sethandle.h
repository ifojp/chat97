#if !defined(AFX_SETHANDLE_H__96E2F7E1_3454_11D1_9B2E_0040051AF39C__INCLUDED_)
#define AFX_SETHANDLE_H__96E2F7E1_3454_11D1_9B2E_0040051AF39C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SetHandle.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CSetHandle �_�C�A���O

class CSetHandle : public CDialog
{
// �R���X�g���N�V����
public:
	CString m_homepage;
	CString m_mail;
	CString m_profile;
	CString m_handle;
	CSetHandle(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSetHandle)
	enum { IDD = IDD_SETHANDLE };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CSetHandle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSetHandle)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SETHANDLE_H__96E2F7E1_3454_11D1_9B2E_0040051AF39C__INCLUDED_)
