#if !defined(AFX_SRVSOCKET_H__ECADFD73_3748_11D1_9B33_0040051AF39C__INCLUDED_)
#define AFX_SRVSOCKET_H__ECADFD73_3748_11D1_9B33_0040051AF39C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// SrvSocket.h : �w�b�_�[ �t�@�C��
//



/////////////////////////////////////////////////////////////////////////////
// CSrvSocket �R�}���h �^�[�Q�b�g

class CSrvSocket : public CSocket
{
// �A�g���r���[�g
public:

// �I�y���[�V����
public:
	CSrvSocket();
	virtual ~CSrvSocket();

// �I�[�o�[���C�h
public:
	CWnd* m_pWnd;
	CPtrList m_client;
	BOOL Connect(CWnd*pWnd,CString host,int port);
	BOOL Init(int port);
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂�
	//{{AFX_VIRTUAL(CSrvSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	//}}AFX_VIRTUAL

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CSrvSocket)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
	//}}AFX_MSG

// �C���v�������e�[�V����
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_SRVSOCKET_H__ECADFD73_3748_11D1_9B33_0040051AF39C__INCLUDED_)
