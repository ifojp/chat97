// Send.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CSend �E�B���h�E

#ifdef CHAT97_USERICHEDIT
class CSend : public CRichEditCtrl
#else
class CSend : public CEdit
#endif
{
// �R���X�g���N�V����
public:
	void CopyClip(CString&str);
	CSend();

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CSend)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	COLORREF SetBackgroundColor(BOOL bSysColor,COLORREF cr);
	virtual ~CSend();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CSend)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
