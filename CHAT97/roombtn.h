// RoomBtn.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CRoomBtn �E�B���h�E

class CRoomBtn : public CButton
{
// �R���X�g���N�V����
public:
	CRoomBtn(int room);

// �A�g���r���[�g
public:

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CRoomBtn)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CRoomBtn();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	int m_room;
	//{{AFX_MSG(CRoomBtn)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
