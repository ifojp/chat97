// RoomStc.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CRoomStc �E�B���h�E

class CRoomStc : public CStatic
{
// �R���X�g���N�V����
public:
	CRoomStc(int room);

// �A�g���r���[�g
public:
	int m_room;

// �I�y���[�V����
public:

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��𐶐����I�[�o�[���C�h���܂��B
	//{{AFX_VIRTUAL(CRoomStc)
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
public:
	virtual ~CRoomStc();

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
protected:
	//{{AFX_MSG(CRoomStc)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
