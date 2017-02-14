// Chat97ServerDlg.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "Chat97Server.h"
#include "Chat97ServerDlg.h"

#define WM_NOTIFYICON		(WM_USER+100)

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChat97ServerDlg �_�C�A���O

CChat97ServerDlg::CChat97ServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChat97ServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChat97ServerDlg)
		// ����: ���̈ʒu�� ClassWizard �ɂ���ă����o�̏��������ǉ�����܂��B
	//}}AFX_DATA_INIT
	// ����: LoadIcon �� Win32 �� DestroyIcon �̃T�u�V�[�P���X��v�����܂���B
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	g_clientno=0;
}

void CChat97ServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChat97ServerDlg)
		// ����: ���̏ꏊ�ɂ� ClassWizard �ɂ���� DDX �� DDV �̌Ăяo�����ǉ�����܂��B
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChat97ServerDlg, CDialog)
	//{{AFX_MSG_MAP(CChat97ServerDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ROOMGO, OnRoomgo)
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(IDM_GETIPADDRESS, OnGetipaddress)
	ON_COMMAND(IDM_SENDMESSAGE, OnSendmessage)
	ON_WM_SYSCOMMAND()
	ON_WM_INITMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChat97ServerDlg ���b�Z�[�W �n���h��

BOOL CChat97ServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (FALSE==m_server.Init(((CChat97ServerApp*)AfxGetApp())->m_port,this))
	{	AfxMessageBox("chat97�T�[�o�����ɗ����オ���Ă�݂����ł�");
		EndDialog(IDCANCEL);
		return FALSE;
	}

	// ���̃_�C�A���O�p�̃A�C�R����ݒ肵�܂��B�t���[�����[�N�̓A�v���P�[�V�����̃��C��
	// �E�B���h�E���_�C�A���O�łȂ����͎����I�ɐݒ肵�܂���B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R����ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R����ݒ�

	SetTray(NIM_ADD,NULL,"22");
	SetInfo(FALSE);
	ShowWindow(SW_HIDE);
	CString room1=AfxGetApp()->GetProfileString("CHAT97Server","Room1","�����");
	GetDlgItem(IDC_ROOM1)->SetWindowText(room1);
	if (room1.GetLength())
	{	hotspot[0]=room1;
	}
	m_rmenu.LoadMenu(IDR_RMENU);
	CString s;
	s.Format("chat97�I %d��",NOWVERSION);
	SetWindowText(s);

  /* �V�X�e�����j���[���擾���܂� */
	CMenu*pMenu = GetSystemMenu(FALSE);
    /* ���j���[����u�ړ��v���폜���܂� */
    pMenu->RemoveMenu(SC_CLOSE, FALSE);	
	return TRUE;  // TRUE ��Ԃ��ƃR���g���[���ɐݒ肵���t�H�[�J�X�͎����܂���B
}

// �����_�C�A���O�{�b�N�X�ɍŏ����{�^����ǉ�����Ȃ�΁A�A�C�R����`�悷��
// �R�[�h���ȉ��ɋL�q����K�v������܂��BMFC �A�v���P�[�V������ document/view
// ���f�����g���Ă���̂ŁA���̏����̓t���[�����[�N�ɂ�莩���I�ɏ�������܂��B

void CChat97ServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// �N���C�A���g�̋�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R����`�悵�܂��B
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// �V�X�e���́A���[�U�[���ŏ����E�B���h�E���h���b�O���Ă���ԁA
// �J�[�\����\�����邽�߂ɂ������Ăяo���܂��B
HCURSOR CChat97ServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChat97ServerDlg::OnClose(int clientno)
{
	int world;
	CString send;

	if (clientno==-1)
	{
		while (user.getCount()>0)
		{	CChatSocket*p=(CChatSocket*)user.getData(0);
			delete p;
			user.del(p);
		}
		return;
	}
	
	CListBox*pList=(CListBox*)GetDlgItem(IDC_MEMBER);
	for (int i=0;i<user.getCount();i++)
	{	CChatSocket*p=(CChatSocket*)user.getData(i);
		if (p->clientno==clientno)
		{
			world=p->world;
			send.Format("LOGOUT\nclientno: %d\nroom: %d\n\n\n",p->clientno,p->x);
			user.del(p);
			delete p;
			//���X�g�{�b�N�X����̍폜
			for (int j=0;j<pList->GetCount();j++){
				if (clientno==(int)pList->GetItemData(i))
				{	pList->DeleteString(i);
					break;
				}
			}
			break;
		}
	}
	for (i=0;i<user.getCount();i++)
	{	CChatSocket*p=(CChatSocket*)user.getData(i);
		if (world==p->world)
		{
			p->SendMessage(send);
		}
	}
	SetInfo(TRUE);
}

void CChat97ServerDlg::SetInfo(BOOL isListRefresh)
{
	CString count;
	int c=0;
	CListBox*pList=(CListBox*)GetDlgItem(IDC_MEMBER);
	if (isListRefresh)
		pList->ResetContent();
	for (int i=0;i<user.getCount();i++)
	{	CChatSocket*p=(CChatSocket*)user.getData(i);
		if (! p->isSendOK)
			continue;
		c++;
		if (isListRefresh)
		{	CString s=p->handle;
			CString s2="�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@";
			s+=s2.Left((50-s.GetLength())&0xffffe);
			int no=pList->AddString(s);
			pList->SetItemData(no,p->clientno);
		}
	}
	int icon[10]={
		IDI_ICON0,IDI_ICON1,IDI_ICON2,IDI_ICON3,IDI_ICON4,
		IDI_ICON5,IDI_ICON6,IDI_ICON7,IDI_ICON8,IDI_ICON9,
	};
	count.Format("%d�l�̃��[�U�����܂�",c);
TRACE(count);
	CWnd*pWnd=GetDlgItem(IDC_COUNT);
	pWnd->SetWindowText(count);
	SetTray(NIM_MODIFY,AfxGetApp()->LoadIcon(icon[c%10]),count);
}

void CChat97ServerDlg::OnAccept()
{
	CChatSocket*s=new CChatSocket;
	if (!s)
		return;
	s->clientno=g_clientno++;
	s->user=&user;
	s->hotspot=hotspot;
	s->m_pWnd=this;
	if (FALSE==m_server.Accept(*s))
	{
		int iErrorCode = s->GetLastError();
		if (iErrorCode != WSAEWOULDBLOCK)
		{
			delete s;
			return;
		}
	}
	user.add(s);
}

void CChat97ServerDlg::PostNcDestroy() 
{
	delete this;
}

void CChat97ServerDlg::OnNotifyIcon(WPARAM wParam,LPARAM lParam)
{
	TRACE("w:%04X l:%08lX\n",wParam,lParam);
	if (lParam==WM_LBUTTONDOWN)
	{
		ShowWindow(SW_SHOW);
		ShowWindow(SW_RESTORE);
	}
	else if (lParam==WM_RBUTTONDOWN)
	{
		POINT point;
		::GetCursorPos(&point);
		m_rmenu.GetSubMenu(0)->TrackPopupMenu(
			TPM_RIGHTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON,
			point.x,point.y,this);
	}
}

void CChat97ServerDlg::SetTray(int cmd,HICON hIcon, CString str)
{
	nd.cbSize=sizeof(NOTIFYICONDATA);
	nd.hWnd=m_hWnd;
	nd.uID=1001;
	nd.uFlags=NIF_MESSAGE|NIF_ICON|NIF_TIP;
	nd.uCallbackMessage=WM_NOTIFYICON;
	if (hIcon==NULL)
		nd.hIcon=AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	else
		nd.hIcon=hIcon;
	strcpy(nd.szTip,str);
	Shell_NotifyIcon(cmd,&nd);
}

BOOL CChat97ServerDlg::PreTranslateMessage(MSG* pMsg) 
{
	if ((pMsg->message==WM_KEYDOWN)&&
		(pMsg->wParam==VK_ESCAPE))
	{	ShowWindow(SW_HIDE);
		return TRUE;
	}
	if ((pMsg->message==WM_KEYDOWN)&&
		(pMsg->wParam==VK_RETURN))
	{
		OnRoomgo();
		return TRUE;
	}
	if (pMsg->message==WM_NOTIFYICON)
	{	//TRACE("fsdfdasafsd\n");
	}

	return CDialog::PreTranslateMessage(pMsg);
}

void CChat97ServerDlg::OnCancel() 
{
	OnClose(-1);

	SetTray(NIM_DELETE,NULL,"22");
	
	DestroyWindow();
}

void CChat97ServerDlg::OnRoomgo() 
{
	CString room1;
	GetDlgItem(IDC_ROOM1)->GetWindowText(room1);
	if (room1.GetLength())
	{	AfxGetApp()->WriteProfileString("CHAT97Server","Room1",room1);
		hotspot[0]=room1;
	}
}

void CChat97ServerDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	if (nType==SIZE_MINIMIZED)
		ShowWindow(SW_HIDE);
}

void CChat97ServerDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CRect rect;
	CPoint c;
	CListBox*pList=(CListBox*)GetDlgItem(IDC_MEMBER);
	pList->GetWindowRect(&rect);
	if ((rect.left>point.x)||
		(rect.right<point.x)||
		(rect.top>point.y)||
		(rect.bottom<point.y))
		return;

	c.x=point.x-rect.left;
	c.y=point.y-rect.top;
	for (int i=0;i<pList->GetCount();i++)
	{	pList->GetItemRect(i,&rect);
		if ((rect.left<=c.x)&&
			(rect.right>=c.x)&&
			(rect.top<=c.y)&&
			(rect.bottom>=c.y))
		{	break;
		}
	}
	if (i>=pList->GetCount())
		return;

	int clientno=pList->GetItemData(i);
	CChatSocket*p=NULL;
	for (i=0;i<user.getCount();i++)
	{	p=(CChatSocket*)user.getData(i);
		if (clientno==p->clientno)
			break;
		p=NULL;
	}
	if (p==NULL)
		return;

	pClient=p;
	ScreenToClient(&point);
	point.y-=14;

	ClientToScreen(&point);

	m_rmenu.GetSubMenu(1)->TrackPopupMenu(
		TPM_CENTERALIGN|TPM_LEFTBUTTON,
		point.x,point.y,this);
}

void CChat97ServerDlg::OnGetipaddress()
{
	if (pClient==NULL)
		return;
	CString s;
	UINT port;
	pClient->GetPeerName(s,port);
	MessageBox(s);
}

void CChat97ServerDlg::OnSendmessage()
{
	if (pClient==NULL)
		return;
	CSendMes dlg(pClient->handle,pClient->clientno,pClient->x);
	if (IDOK==dlg.DoModal())
	{
		CString send;
		send="CHAT\n";
		send+="handle: �V�X�e��\n";
		send+="room: 0\n";
		send+="clientno: -1\n";
		send+="target_clientno: 1\n\n";

		send+=dlg.mes+"\n\n";
		pClient->SendMessage(send);
	}
}


LRESULT CChat97ServerDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	if (message==WM_NOTIFYICON)
	{	OnNotifyIcon(wParam,lParam);
	}
	
	return CDialog::WindowProc(message, wParam, lParam);
}

void CChat97ServerDlg::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
//	CDialog::OnOK();
}

void CChat97ServerDlg::OnSysCommand(UINT nID, LPARAM lParam) 
{
	if (nID==SC_CLOSE)
		return;
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	
	CDialog::OnSysCommand(nID, lParam);
}

void CChat97ServerDlg::OnInitMenu(CMenu* pMenu) 
{
	CDialog::OnInitMenu(pMenu);
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	
}
