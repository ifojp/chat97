// SendMes.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CSendMes �_�C�A���O

class CSendMes : public CDialog
{
// �R���X�g���N�V����
public:
	CString mes;
	CSendMes(CString&handle,int clientno,int room);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CSendMes)
	enum { IDD = IDD_SENDMESSAGE };
		// ����: ClassWizard �͂��̈ʒu�Ƀf�[�^ �����o��ǉ����܂��B
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CSendMes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	CString m_handle;
	int m_clientno;
	int m_room;
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSendMes)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnColor0();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};