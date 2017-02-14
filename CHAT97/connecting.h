// Connecting.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CConnecting �_�C�A���O

class CConnecting : public CDialog
{
// �R���X�g���N�V����
public:
	CConnecting(CWnd*pParent,CChatSocket*sock,CString&host,int port);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CConnecting)
	enum { IDD = IDD_CONNECTING };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CConnecting)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	CString m_host;
	int m_port;
	CChatSocket *m_pSocket;
	UINT m_timer;
	CWnd*m_pParent;

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CConnecting)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
