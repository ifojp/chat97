#if !defined(AFX_BOSSSTRING_H__C87EBE81_35F1_11D1_9B31_0040051AF39C__INCLUDED_)
#define AFX_BOSSSTRING_H__C87EBE81_35F1_11D1_9B31_0040051AF39C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// BossString.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// BossString �_�C�A���O

class BossString : public CDialog
{
// �R���X�g���N�V����
public:
	CString m_bossstring;
	BossString(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(BossString)
	enum { IDD = IDD_BOSSSTRING };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(BossString)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(BossString)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_BOSSSTRING_H__C87EBE81_35F1_11D1_9B31_0040051AF39C__INCLUDED_)
