// ConnectDlg.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CConnectDlg �_�C�A���O

class CConnectDlg : public CDialog
{
// �R���X�g���N�V����
public:
	CConnectDlg(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^
	CString m_host;
	int m_port;
	CString m_handle;
	CString m_profile;
	CString m_mail;
	CString m_homepage;
	CString m_room;
	int getCGI();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CConnectDlg)
	enum { IDD = IDD_CONNECT };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CConnectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CConnectDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditserver();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
