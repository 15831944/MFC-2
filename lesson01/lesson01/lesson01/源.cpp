#include <Windows.h>


#include <tchar.h>
/**************************************************************
	main������WIN32 �������Ǳ���װ��,Ҫ�� 
	int WINAPI WinMain(
					HINSTANCE hInstance, 
					HINSTANCE hPrev, 
					LPSTR lpCmd, 
					int nCmdShow);
	���������
*************************************************************/

/**************************************************************
part 1 ��һ����Ϣ����

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//��һ����������,�ͱ�ʾ�Լ�Ϊ������
	MessageBox(NULL, _T("�����ҵĵ�һ��Windows���!"), _T("�Ҳ��������:"), 0);
	return 0;
}
*************************************************************/

/**************************************************************
part 2 ��Ϣ���ڲ���

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//����ָ�����ĸ�����
	//HWND hwnd = FindWindow(NULL, _T("vpn.txt - ���±�"));

	//VS->����->spy++->����->���Ҵ���
	//����ָ����ĸ�����
	HWND hwnd = FindWindow(_T("Notepad"), NULL);

	//MessageBox��һ����д���ര��,˵��,MessageBox�鸸�������
	//MessageBox(hwnd, _T("�����ҵĵ�һ��Windows���!"), _T("�Ҳ��������:"), 0);

	//���һ������,�ǶԶԻ����ѡ��
	//MessageBox(hwnd, _T("�����ҵĵ�һ��Windows���!"), _T("�Ҳ��������:"), MB_CANCELTRYCONTINUE);

	//���һ������,�ǶԶԻ����ѡ�� �������"ȷ��"ѡ��
	//								�������"ȷ��" + ����ͼ�� ѡ��
	//								���ѡ���� | ��������ۼ�
	//								��4λ��ͼ����й���, ��4λ��ѡ����й���
	//MessageBox(hwnd, _T("�����ҵĵ�һ��Windows���!"), _T("�Ҳ��������:"), MB_ICONEXCLAMATION);
	MessageBox(hwnd, _T("�����ҵĵ�һ��Windows���!"), _T("�Ҳ��������:"), MB_ICONEXCLAMATION | MB_ICONERROR);
	return 0;
}
*************************************************************/

/**************************************************************
part 3 MessageBox����ֵ������

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//MessageBox����ֵ������
	int nRet = MessageBox(NULL, _T("�����ҵĵ�һ��Windows���!"), _T("�Ҳ��������:"), MB_YESNOCANCEL);

	switch (nRet)
	{
	case IDYES:
		MessageBox(NULL, _T("you click is YES!"), _T("Prompt Message"), 0);
		break;
	case IDNO:
		MessageBox(NULL, _T("you click is NO!"), _T("Prompt Message"), 0);
		break;
	case IDCANCEL:
		MessageBox(NULL, _T("you click is CANCEL!"), _T("Prompt Message"), 0);
		break;
	}
	return 0;
}
*************************************************************/

/**************************************************************
part 4 ������ͼ��
	����ͼ->��Ӧ��Ŀ�Ҽ�->�����Դ->ѡ��Icon->�½�
	��Դ��ͼ->�ҵ�Icon�ļ���->ɾ���Դ���ͼ��->�����Լ�Ҫ��ͼ��
*************************************************************/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//��һ����������,�ͱ�ʾ�Լ�Ϊ������
	MessageBox(NULL, _T("�����ҵĵ�һ��Windows���!"), _T("�Ҳ��������:"), 0);
	return 0;
}
