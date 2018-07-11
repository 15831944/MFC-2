#include <Windows.h>


#include <tchar.h>
/**************************************************************
	main函数在WIN32 程序下是被封装的,要用 
	int WINAPI WinMain(
					HINSTANCE hInstance, 
					HINSTANCE hPrev, 
					LPSTR lpCmd, 
					int nCmdShow);
	做函数入口
*************************************************************/

/**************************************************************
part 1 第一个消息窗口

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个参数不填,就表示自己为主窗口
	MessageBox(NULL, _T("这是我的第一个Windows软件!"), _T("我不会告诉你:"), 0);
	return 0;
}
*************************************************************/

/**************************************************************
part 2 消息窗口测试

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//查找指定名的父窗口
	//HWND hwnd = FindWindow(NULL, _T("vpn.txt - 记事本"));

	//VS->工具->spy++->搜索->查找窗口
	//查找指定类的父窗体
	HWND hwnd = FindWindow(_T("Notepad"), NULL);

	//MessageBox第一个填写父类窗口,说明,MessageBox归父窗体管制
	//MessageBox(hwnd, _T("这是我的第一个Windows软件!"), _T("我不会告诉你:"), 0);

	//最后一个参数,是对对话框的选项
	//MessageBox(hwnd, _T("这是我的第一个Windows软件!"), _T("我不会告诉你:"), MB_CANCELTRYCONTINUE);

	//最后一个参数,是对对话框的选项 可以添加"确定"选项
	//								可以添加"确定" + 警告图标 选项
	//								组合选择用 | 运算进行累加
	//								高4位对图标进行管理, 低4位对选项进行管理
	//MessageBox(hwnd, _T("这是我的第一个Windows软件!"), _T("我不会告诉你:"), MB_ICONEXCLAMATION);
	MessageBox(hwnd, _T("这是我的第一个Windows软件!"), _T("我不会告诉你:"), MB_ICONEXCLAMATION | MB_ICONERROR);
	return 0;
}
*************************************************************/

/**************************************************************
part 3 MessageBox返回值的运用

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//MessageBox返回值的运用
	int nRet = MessageBox(NULL, _T("这是我的第一个Windows软件!"), _T("我不会告诉你:"), MB_YESNOCANCEL);

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
part 4 软件添加图标
	类视图->对应项目右键->添加资源->选择Icon->新建
	资源视图->找到Icon文件夹->删掉自带的图标->导入自己要的图标
*************************************************************/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{
	//第一个参数不填,就表示自己为主窗口
	MessageBox(NULL, _T("这是我的第一个Windows软件!"), _T("我不会告诉你:"), 0);
	return 0;
}
