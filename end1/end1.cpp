//*****************************************************************************
//@ProjectName      hao's Lazie remote controller
//@Description      Graduation design
//@Author           haoMax
//@Date             2018/03/16
//*****************************************************************************
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <cstdio>
#include <WinSock2.h>
#include <iostream>
#include<Windows.h>
#include<sstream>
#include<winuser.h >
using namespace std;
#define BUFFER_SIZE 10240
#define HOST "127.0.0.1"
#define PORT 18000
#define  MOV 5
#define HEADER "\
HTTP/1.1 200 OK\r\n\
Content-Type: text/html; charset=UTF-8\r\n\
Server: ZYhttp_v1.0.1\r\n\
Content-Length: %d\r\n\r\n%s\
"

#define HTML1 "<html lang=\"zh-cn\"><meta charset=\"utf-8\"/><body id=\"start\" style=\"text-align:center\"><head><title>hao's Lazie remote controller</title></head><meta content=\"width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no\" name=\"viewport\" /><meta name=\"apple-mobile-web-app-capable\" content=\"yes\" /><meta name=\"viewport\" content=\"width=device-width,initial-scale=1\"><style>.dropbtn {    background-color: #4CAF50;    color: white;    padding: 16px;    font-size: 16px;    border: none;    cursor: pointer;}.dropdown {    position: relative;    display: inline-block;}.dropdown-content {    display: none;    position: absolute;    background-color: #f9f9f9;    min-width: 260px;    box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);}.index_body {    overflow-y: hidden;    height: 100%;    position: fixed;  }.dropdown-content a {    color: black;    padding: 12px 16px;    text-decoration: none;    display: block;}.dropdown-content a:hover {background-color: #f1f1f1}.dropdown:hover .dropdown-content {    display: block;}.dropdown:hover .dropbtn {    background-color: #3e8e41;}</style><div class=\"box\" style=\" text-align:center;font-size:15px\" >Server:<input id=\"url2\" type=\"text\" name=\"url\" value=\""
#define HTML2 "\" style=\" width:70%;height:45px;font-size:25px\" /><br/><br/><table style=\"margin:0 auto; \" width=\"90%\" height=\"400px\" ><tr><td id=\"leftClick\"style=\" background: SlateGray;\"></td><td id=\"rightClick\"style=\" background: SlateGray;\"></td></tr><tr><td id=\"touchBoard\" colspan=\"3\" align=\"center\" id=\"myElement\"style=\" background: silver;width:80%;height: 300px;font: 30px/300px Helvetica, Arial, sans-serif;margin:0 auto;\"></td></tr></table><input id=\"url3\" type=\"text\" name=\"url\" style=\"                                          width:40%;height:45px;font-size:25px\" />&nbsp<span class=\"btn10\" style=\"display: inline-block;border:2px solid #ccc;text-align:center;width:40%;line-height:45px;font-size:25px\" >Send</span><input id=\"speed\" type=\"text\" name=\"url\" value=\"20\" style=\"                                      width:20%;height:45px;font-size:25px\" /><span class=\"btn6\" style=\"display: inline-block;border:2px solid #ccc;text-align:center;width:20%;line-height:45px;font-size:25px\" >KeyOn</span>&nbsp<span class=\"hide\"flag=\"off\" style=\"display: inline-block;border:2px solid #ccc;text-align:center;width:20%;line-height:45px;font-size:25px\" >Hide</span><span class=\"shutdown\" style=\"display: inline-block;border:2px solid #ccc;text-align:center;width:20%;line-height:45px;font-size:25px\" >shutD</span><input id=\"flag\" type=\"text\" value=\"off\" style=\"display:none\" name=\"url\" /><input id=\"pptflag\" type=\"text\" value=\"off\" style=\"display:none\" name=\"url\" /><span id=\"altTab\"class=\"altTab\" style=\"display: inline-block;border:2px solid #ccc;text-align:center;width:20%;line-height:45px;font-size:25px\" >ATab</span>&nbsp<span id=\"esc\" class=\"esc\"flag=\"off\" style=\"display: inline-block;border:2px solid #ccc;text-align:center;width:20%;line-height:45px;font-size:25px\" >Esc</span><span id=\"off\" class=\"off\" style=\"display: inline-block;border:2px solid #ccc;text-align:center;width:20%;line-height:45px;font-size:25px\" >Off</span>   	<script src=\"http://libs.baidu.com/jquery/2.0.0/jquery.min.js \"></script><script src=\"https://cdn.staticfile.org/hammer.js/2.0.8/hammer.min.js\"></script><script type=\"text/javascript\">$(\".ppt\").on(\"click\",function(){		if($(\" #pptflag \").val()==\"off\"){				 $(\".ppt\").text(\"pptOff\");  				 $(\" #pptflag\").val(\"on\");				 }else{				 $(\".ppt\").text(\"pptOn\");  				 $(\" #pptflag \").val(\"off\");				 }					 })</script><script type=\"text/javascript\"> $(\"#speed\").change(function(){  var Url =\"http://\" + $(\"#url2\").val() + \"/spe?x=\"+$(\"#speed\").val() ;				$.get(Url);});</script><script type=\"text/javascript\">			$(\".shutdown\").on(\"click\",function(){			   				if(confirm('Are you sure shutdown your computer?')){                      	var Url =\"http://\" + $(\"#url2\").val() + \"/shu\" ;				$.get(Url);             }			})		</script><script>   var hammertime = new Hammer(document.getElementById(\"touchBoard\"));        hammertime.on(\"pan\", function (e) {			 var Url =\"http://\" + $(\"#url2\").val() + \"/touch?x=\" + e.deltaX+\"&y=\"+e.deltaY ;				$.get(Url);        });</script><script type=\"text/javascript\">			$(\".hide\").on(\"click\",function(){							 if($(\".hide \").attr(\"flag\")==\"off\")				 {				 $(\".hide \").attr(\"flag\",\"on\");				 $(\".hide\").text(\"Show\");				 var Url =\"http://\" + $(\"#url2\").val() + \"/hid\" ;				$.get(Url);				 }else{				 $(\".hide \").attr(\"flag\",\"off\");				 $(\".hide\").text(\"Hide\");				 var Url =\"http://\" + $(\"#url2\").val() + \"/sho\" ;				 $.get(Url);				 }				})		</script>		<script type=\"text/javascript\">			$(\".btn10\").on(\"click\",function(){				var Url =\"http://\" + $(\"#url2\").val() + \"/fas/\" + $(\"#url3\").val();				$.get(Url);                document.getElementById(\"url3\").value=\"\";			})		</script>       		<script type=\"text/javascript\">			$(\"#off\").on(\"click\",function(){							var Url =\"http://\" + $(\"#url2\").val() + \"/xof\" ;				$.get(Url);			})		</script>		<script type=\"text/javascript\">			$(\".btn\").on(\"click\",function(){ 			if($(\" #flag \").val()==\"off\"){				var Url = \"http://\" + $(\"#url2\").val() + \"/sha\";				$.get(Url);				}else{				var Url = \"http://\" + $(\"#url2\").val() + \"/uha\";				$.get(Url);				}			})		</script>		<script type=\"text/javascript\">			$(\".btn2\").on(\"click\",function(){			if($(\" #flag \").val()==\"off\"){				var Url = \"http://\" + $(\"#url2\").val() + \"/zuo\";				$.get(Url);				}else{				var Url = \"http://\" + $(\"#url2\").val() + \"/uuo\";				$.get(Url);				}			})		</script>		<script type=\"text/javascript\">			$(\".btn4\").on(\"click\",function(){			if($(\" #flag \").val()==\"off\"){				var Url = \"http://\" + $(\"#url2\").val() + \"/you\";				$.get(Url);				}else{				var Url = \"http://\" + $(\"#url2\").val() + \"/uou\";				$.get(Url);				}			})		</script><script type=\"text/javascript\">		$(\".btn5\").on(\"click\",function(){			if($(\" #flag \").val()==\"off\"){				var Url = \"http://\" + $(\"#url2\").val() + \"/xia\";				$.get(Url);				}else{				var Url = \"http://\" + $(\"#url2\").val() + \"/uia\";				$.get(Url);				}			})		</script>		<script type=\"text/javascript\">			$(\"#rightClick\").on(\"click\",function(){			if($(\" #flag \").val()==\"off\"){				var Url = \"http://\" + $(\"#url2\").val() + \"/rit\";				$.get(Url);				}else{				var Url = \"http://\" + $(\"#url2\").val() + \"/uuo\";				$.get(Url);				}			})		</script>	<script type=\"text/javascript\">    			$(\"#leftClick\").click(function(){			    $.ajaxSettings.async = false; 		var Url = \"http://\" + $(\"#url2\").val() + \"/oke\";				$.get(Url);	});    		</script>     		<script type=\"text/javascript\">			$(\".btn6\").on(\"click\",function(){			if($(\" #flag \").val()==\"off\"){				 $(\".btn6\").text(\"KeyOff\");  				 $(\" #flag \").val(\"on\");				 }else{				 $(\".btn6\").text(\"KeyOn\");  				 $(\" #flag \").val(\"off\");				 }			})		</script>		<script type=\"text/javascript\">			$(\"#altTab\").on(\"click\",function(){				var Url =\"http://\" + $(\"#url2\").val() + \"/alb\" ;				$.get(Url);			})		</script>			<script type=\"text/javascript\">			$(\".btn9\").on(\"click\",function(){var node=$(\"#myElement\");if(node.is(\":hidden\")){node.show();$(\".btn9\").text(\"PPTOff\");}else{node.hide();$(\".btn9\").text(\"PPTOn\");}			})		</script>		<script type=\"text/javascript\">			$(\".btn10\").on(\"click\",function(){				var Url =\"http://\" + $(\"#url2\").val() + \"/fas/\" + $(\"#url3\").val();				$.get(Url);                document.getElementById(\"url3\").value=\"\";			})		</script>		<script type=\"text/javascript\">			$(\"#esc\").on(\"click\",function(){				var Url =\"http://\" + $(\"#url2\").val() + \"/esc\" ;				$.get(Url);			})		</script><div class=\"text\" style=\" text-align:center;font-size:17px\">Copyright:haoMax &nbsp&nbsp</div><br/></body></html> "
#pragma comment(lib, "WS2_32")
//功能实现  

BOOL ReSetWindows(DWORD dwFlags, BOOL bForce)
{
	//检查参数是否正确  
	if (dwFlags != EWX_LOGOFF && dwFlags != EWX_REBOOT && dwFlags != EWX_SHUTDOWN)
		return FALSE;
	//获得系统的版本信息，让我们后面确定是否需要提升系统权限  
	OSVERSIONINFO osvi = { 0 };
	//获得参数的大小，以提供给GetVersionEx来判断这是一个新版本的OSVERSIONINFO，还是旧版本的  
	//新版本是OSVERSIONINFOEX。扩充版本  
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	if (!GetVersionEx(&osvi))
	{
		return FALSE;
	}
	//检查操作系统的版本，如果是NT类型的系统，需要提升系统权限  
	if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{
		//EnableShutDownPriv();  
	}
	//判断是否是强制关机，强制关闭系统进程。  
	dwFlags |= (bForce != FALSE) ? EWX_FORCE : EWX_FORCEIFHUNG;
	//调用API  
	return ExitWindowsEx(dwFlags, 0);
}


//用来提升系统权限
//这是一个通用的提升权限函数，如果需要提升其他权限  
//更改LookupPrivilegeValue的第二个参数SE_SHUTDOWN_NAME，即可  
BOOL EnableShutDownPriv()
{
	HANDLE hToken = NULL;
	TOKEN_PRIVILEGES tkp = { 0 };
	//打开当前程序的权限令牌  
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		return FALSE;
	}
	//获得某一特定权限的权限标识LUID，保存在tkp中  
	if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid))
	{
		CloseHandle(hToken);
		return FALSE;
	}
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	//调用AdjustTokenPrivileges来提升我们需要的系统权限  
	if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, sizeof(TOKEN_PRIVILEGES), NULL, NULL))
	{
		CloseHandle(hToken);
		return FALSE;
	}
	return TRUE;
}
//剪切板操作
BOOL CopyToClipboard(const char* pszData, const int nDataLen)
{
	if (::OpenClipboard(NULL))
	{
		::EmptyClipboard();
		HGLOBAL clipbuffer;
		char *buffer;
		clipbuffer = ::GlobalAlloc(GMEM_DDESHARE, nDataLen + 1);
		buffer = (char *)::GlobalLock(clipbuffer);
		strcpy(buffer, pszData);
		::GlobalUnlock(clipbuffer);
		::SetClipboardData(CF_TEXT, clipbuffer);
		::CloseClipboard();
		return TRUE;
	}
	return FALSE;
}
/*一下为模拟鼠标和键盘*/
void MouseMove(int x, int y)
{
	double fScreenWidth = ::GetSystemMetrics(SM_CXSCREEN) - 1;
	double fScreenHeight = ::GetSystemMetrics(SM_CYSCREEN) - 1;
	double fx = x * (65535.0f / fScreenWidth);
	double fy = y * (65535.0f / fScreenHeight);
	INPUT  Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_MOVE | MOUSEEVENTF_ABSOLUTE;
	Input.mi.dx = fx;
	Input.mi.dy = fy;
	::SendInput(1, &Input, sizeof(INPUT));
}
void RightClick()
{
	INPUT    Input = { 0 };
	// 右键按下
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// 右键抬起
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}
void LeftClick()
{
	INPUT    Input = { 0 };
	// 左键按下
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	::SendInput(1, &Input, sizeof(INPUT));

	// 左键抬起
	::ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	::SendInput(1, &Input, sizeof(INPUT));
}
//转字符串
char* hexToCharIP(struct in_addr addrIP)
{
	char* ip;
	unsigned int intIP;
	memcpy(&intIP, &addrIP, sizeof(unsigned int));
	int a = (intIP >> 24) & 0xFF;
	int b = (intIP >> 16) & 0xFF;
	int c = (intIP >> 8) & 0xFF;
	int d = intIP & 0xFF;
	if ((ip = (char*)malloc(16 * sizeof(char))) == NULL)
	{
		return NULL;
	}
	sprintf(ip, "%d.%d.%d.%d", d, c, b, a);
	return ip;
}
/**
** 字符串拼接方法
**/
char * str_contact(const char *str1, const char *str2)
{
	char * result;
	result = (char*)malloc(strlen(str1) + strlen(str2) + 1); //str1的长度 + str2的长度 + \0;
	if (!result) { //如果内存动态分配失败
		printf("Error: malloc failed in concat! \n");
		exit(EXIT_FAILURE);
	}
	strcpy(result, str1);
	strcat(result, str2); //字符串拼接
	return result;
}


int main(int argc, char **argv)
{
	SetWindowTextA(GetConsoleWindow(), "多功能遥控器  作者：大豪");
	char *res = NULL;//生成的网址
					 // define and init an server sockaddr
	sockaddr_in addrServer;
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.S_un.S_addr = INADDR_ANY;
	addrServer.sin_port = htons(PORT);
	SOCKET ServerSocket = INVALID_SOCKET;//服务端套接字
	SOCKADDR_IN ServerAddr = { 0 };//服务端地址
	SOCKET ClientSocket = INVALID_SOCKET;//客户端套接字
	SOCKADDR_IN ClientAddr = { 0 };//客户端地址
	int iClientAddrLen = sizeof(ClientAddr);
	// init socket dll
	WSADATA wsaData;
	WORD socketVersion = MAKEWORD(2, 0);
	if (WSAStartup(socketVersion, &wsaData) != 0)
	{
		printf("Init socket dll error!");
		exit(1);
	}
	//获取本机ip
	char host[255];
	if (gethostname(host, sizeof(host)) == SOCKET_ERROR)
	{
		//cout << "无法获取主机名" << endl;
		printf("无法获取主机名");
	}
	else
	{
		//cout << "本机计算机名为:" << host << endl;
	}

	struct hostent *p = gethostbyname(host);
	if (p == 0)
	{
		//cout << "无法获取计算机主机名及IP" << endl;
		printf("无法获取计算机主机名及IP");
	}
	else
	{
		HWND hWnd = GetConsoleWindow();
		HDC hdc = GetDC(hWnd);
		HFONT font = CreateFont(
			50, // nHeight
			0, // nWidth
			-50, // nEscapement
			20, // nOrientation
			FW_BOLD, // nWeight
			TRUE, // bItalic
			TRUE, // bUnderline
			0, // cStrikeOut
			ANSI_CHARSET, // nCharSet
			OUT_DEFAULT_PRECIS, // nOutPrecision
			CLIP_DEFAULT_PRECIS, // nClipPrecision
			DEFAULT_QUALITY, // nQuality
			DEFAULT_PITCH | FF_ROMAN,
			"Arial" // nPitchAndFamily Arial
		);
		SelectObject(hdc, font);
		SetBkColor(hdc, 0x000000);
		SetTextColor(hdc, RGB(100, 149, 237));
		TextOut(hdc, 50, 300, "Proudly Released by haoMax!", 27);
		int xy = 0;
		//本机IP:利用循环,输出本机所有IP  
		for (int i = 0; p->h_addr_list[i] != 0; i++)
		{
			
			struct in_addr in;
			memcpy(&in, p->h_addr_list[i], sizeof(struct in_addr));
			//cout << "第" << i + 1 << "块网卡的IP为:" << inet_ntoa(in) << endl;
			if (hexToCharIP(in)[12] != '1') {

				res = str_contact(hexToCharIP(in), ":18000");
				printf("请在移动设备中输入网址：");
				printf("%s\n", res);
				printf("连接成功后窗口自动最小化\n");
				printf("如果链接不成功可以尝试下面的网址:");
				ValidateRect(hWnd, 0);
			}
			else {
				res = str_contact(hexToCharIP(in), ":18000");
				HFONT font = CreateFont(
					25, // nHeight
					0, // nWidth
					0, // nEscapement
					20, // nOrientation
					FW_BOLD, // nWeight
					TRUE, // bItalic
					0, // bUnderline
					0, // cStrikeOut
					ANSI_CHARSET, // nCharSet
					OUT_DEFAULT_PRECIS, // nOutPrecision
					CLIP_DEFAULT_PRECIS, // nClipPrecision
					DEFAULT_QUALITY, // nQuality
					DEFAULT_PITCH | FF_ROMAN,
					"Arial" // nPitchAndFamily Arial
				);
				SelectObject(hdc, font);
				SetBkColor(hdc, 0x000000);
				SetTextColor(hdc, RGB(34, 139, 34));
				TextOut(hdc, 250, 200+xy*40, res, 19);
				xy++;
			}
		}

	}
	// create socket
	SOCKET socketServer = socket(AF_INET, SOCK_STREAM, 0);
	if (SOCKET_ERROR == socketServer)
	{
		printf("Create socket error!");
		exit(1);
	}
	// bind server socket host
	if (SOCKET_ERROR == bind(socketServer, (LPSOCKADDR)&addrServer, sizeof(addrServer)))
	{
		printf("Bind server host failed!");
		exit(1);
	}
	// listen
	if (SOCKET_ERROR == listen(socketServer, 1))
	{
		printf("Listen failed!");
		exit(1);
	}
	int flag = 0;
	int speed=30;
	while (true)
	{
			sockaddr_in addrClient;
			char buffer[BUFFER_SIZE];
			memset(buffer, 0, BUFFER_SIZE);
			int nClientAddrLen = sizeof(addrClient);
		if (flag == 0) {			
			SOCKET socketClient = accept(socketServer, (sockaddr*)&addrClient, &nClientAddrLen);
			if (SOCKET_ERROR == socketClient)
			{
				printf("Accept failed!");
				break;
			}	
			if (recv(socketClient, buffer, BUFFER_SIZE, 0) < 0)
			{
				printf("Recvive data failed!");
				break;
			}
			//printf("Recv data : \n%s", buffer);
			// response
			memset(buffer, 0, BUFFER_SIZE);
			char * H, *HTML;
			H = str_contact(HTML1, res);
			HTML = str_contact(H, HTML2);
			sprintf_s(buffer, HEADER, strlen(HTML), HTML);
			if (send(socketClient, buffer, strlen(buffer), 0) < 0)
			{
				printf("Send data failed!");
				break;
			}
			//printf("Send data : \n%s", buffer);
			closesocket(socketClient);
			flag = 1;
			closesocket(socketServer);
			//链接成功自动最小化
			HWND hwnd = GetForegroundWindow();//使hwnd代表最前端的窗口 
			ShowWindow(hwnd, SW_MINIMIZE);//最小化 hwnd 所代表的窗口
			ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (ServerSocket == INVALID_SOCKET)
			{
				printf("socket failed with error code: %d\n", WSAGetLastError());
				return -1;
			}
			//设置服务器地址
			ServerAddr.sin_family = AF_INET;//连接方式
			ServerAddr.sin_port = htons(PORT);//服务器监听端口
			ServerAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//任何客户端都能连接这个服务器

																//绑定服务器
			if (SOCKET_ERROR == bind(ServerSocket, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr)))
			{
				printf("bind failed with error code: %d\n", WSAGetLastError());
				closesocket(ServerSocket);
				return -1;
			}
			//监听有无客户端连接
			if (SOCKET_ERROR == listen(ServerSocket, 5))
			{
				printf("listen failed with error code: %d\n", WSAGetLastError());
				closesocket(ServerSocket);
				WSACleanup();
				return -1;
			}
		}
		//这里开始新的控制流程
		ClientSocket = accept(ServerSocket, (SOCKADDR*)&ClientAddr, &iClientAddrLen);
		if (ClientSocket == INVALID_SOCKET)
		{
			printf("accept failed with error code: %d\n", WSAGetLastError());
			closesocket(ServerSocket);
			WSACleanup();
			return -1;
		}
		//printf("Successfuuly got a connection from IP:%s Port:%d\n\n\n\n",
			//inet_ntoa(ClientAddr.sin_addr), htons(ClientAddr.sin_port));
		int iRecvLen = 0;
		int iSendLen = 0;
		memset(buffer, 0, sizeof(buffer));
		//接收客户端消息
		iRecvLen = recv(ClientSocket, buffer, sizeof(buffer), 0);
		if (SOCKET_ERROR == iRecvLen)
		{
			printf("recv failed with error code: %d\n", WSAGetLastError());
			closesocket(ServerSocket);
			closesocket(ClientSocket);
			WSACleanup();
			return -1;
		}
		//printf("recv %d bytes: ", iRecvLen);
		strcat(buffer, "\0"); //加一个截止符,因为接收到的数据没有这个
		char flag[4] = { 0 };
		flag[0] = buffer[5];
		flag[1] = buffer[6];
		flag[2] = buffer[7];
		strcat(flag, "\0");
		//printf("%s\n", flag);
		//printf("%s\n", buffer);
		if (!strcmp(flag, "fas"))
		{
			char chuan[500] = { 0 };
			strncpy(chuan, buffer + 9, 491);
			char temp[100] = { 0 };//用户输入的文字
			int i = 0;
			for (i; chuan[i] != ' '; i++)
			{
				temp[i] = chuan[i];
			}
			//string转char
			string pp = temp;
			printf("%s", pp);
			char p[100];
			int r = 0;
			for (r = 0; r<pp.length(); r++)
				p[r] = pp[r];
			p[r] = '\0';
			//复制字符串到剪贴板
			CopyToClipboard(p, i);
			HWND wnd;//窗口句柄
			wnd = GetForegroundWindow();//获得当前激活的窗口句柄
			DWORD SelfThreadId = GetCurrentThreadId();//获取本身的线程ID
			DWORD ForeThreadId = GetWindowThreadProcessId(wnd, NULL);//根据窗口句柄获取线程ID
			AttachThreadInput(ForeThreadId, SelfThreadId, true);//附加线程
			wnd = GetFocus();//获取具有输入焦点的窗口句柄
			AttachThreadInput(ForeThreadId, SelfThreadId, false);//取消附加的线程	
			SendMessage(wnd, 770, 0, 0);
			//SendMessage(wnd, WM_SETTEXT, 0, (LPARAM)chuan);
			//SendMessage(wnd, WM_SETTEXT, (WPARAM)'a', 0);//发送一个字消息
		}
		if (!strcmp(flag, "tou"))//触控板鼠标
		{
			char x[15] = { '\0' }, y[15] = { '\0' };
			//printf("%s\n", buffer);
			int k = 0,i=13;
			for (i,k; buffer[i] != '&';i++,k++)
			{
				x[k] = buffer[i];
			}
			for ( i=i+3,k=0; buffer[i] != 'H';k++,i++)
			{
				y[k] = buffer[i];
			}
			int xx = 0, yy = 0;
			sscanf(x, "%d", &xx);         // 将字符串转换成整数   i = 15
			sscanf(y, "%d", &yy);         // 将字符串转换成整数   i = 15
			POINT pt;
			xx = xx / speed;
			yy=yy/speed;
			GetCursorPos(&pt);
			MouseMove(pt.x+xx,pt.y+yy);
			//printf("%d,%d", pt.x + xx, pt.y + yy);

		}
		if (!strcmp(flag, "hid"))//隐藏
		{
			HWND hwnd;
			hwnd = FindWindow("ConsoleWindowClass", NULL); //处理顶级窗口的类名和窗口名称匹配指定的字符串,不搜索子窗口。  
			if (hwnd)
			{
				ShowWindow(hwnd, SW_HIDE);               //设置指定窗口的显示状态  
			}
		}
		if (!strcmp(flag, "spe"))//鼠标速度 测试
		{
			char x[15] = { '\0' };
			int k = 0, i = 11;
			for (i, k; buffer[i] != 'H'; i++, k++)
			{
				x[k] = buffer[i];
			}
			int xx = 1;
			sscanf(x, "%d", &xx);         
			speed = xx;
		}
		if (!strcmp(flag, "sho"))//显示
		{
			HWND hwnd;
			hwnd = FindWindow("ConsoleWindowClass", NULL); //处理顶级窗口的类名和窗口名称匹配指定的字符串,不搜索子窗口。  
			if (hwnd)
			{
				ShowWindow(hwnd, SW_SHOW);               //设置指定窗口的显示状态  
			}
		}

		if (!strcmp(flag, "shu"))//关机
		{
			//调用方法：
			EnableShutDownPriv();
			ReSetWindows(EWX_SHUTDOWN, true);//关机 
		}
		if (!strcmp(flag, "sha"))
		{

			POINT pt;
			GetCursorPos(&pt);
			MouseMove(pt.x, pt.y - MOV);
			printf("%d,%d", pt.x, pt.y - MOV);
		}
		if (!strcmp(flag, "uha"))
		{

			keybd_event(38, 0, 0, 0);
			keybd_event(38, 0, KEYEVENTF_KEYUP, 0);
		}
		if (!strcmp(flag, "xia"))
		{

			POINT pt;
			GetCursorPos(&pt);
			MouseMove(pt.x, pt.y + MOV);
			printf("%d,%d", pt.x, pt.y + MOV);
		}
		if (!strcmp(flag, "uia"))
		{

			keybd_event(40, 0, 0, 0);
			keybd_event(40, 0, KEYEVENTF_KEYUP, 0);
		}
		if (!strcmp(flag, "zuo"))
		{

			POINT pt;
			GetCursorPos(&pt);
			MouseMove(pt.x - MOV, pt.y);
			printf("%d,%d", pt.x - MOV, pt.y);
		}
		if (!strcmp(flag, "uuo"))
		{

			keybd_event(37, 0, 0, 0);
			keybd_event(37, 0, KEYEVENTF_KEYUP, 0);
		}
		if (!strcmp(flag, "you"))
		{

			POINT pt;
			GetCursorPos(&pt);
			MouseMove(pt.x + MOV, pt.y);
			printf("%d,%d", pt.x + MOV, pt.y);
		}
		if (!strcmp(flag, "uou"))
		{

			keybd_event(39, 0, 0, 0);
			keybd_event(39, 0, KEYEVENTF_KEYUP, 0);
		}
		if (!strcmp(flag, "oke"))
		{

			LeftClick();
			
		}
		if (!strcmp(flag, "rit"))
		{

			RightClick();
		}
		if (!strcmp(flag, "oke"))
		{

			LeftClick();
		}
		if (!strcmp(flag, "esc"))
		{
			keybd_event(27, 0, 0, 0);
			keybd_event(27, 0, KEYEVENTF_KEYUP, 0);
		}
		if (!strcmp(flag, "xof"))
		{
			keybd_event(18, 0, 0, 0);
			keybd_event(115, 0, 0, 0);
			keybd_event(115, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		}
		if (!strcmp(flag, "alb"))
		{
			keybd_event(18, 0, 0, 0);
			keybd_event(9, 0, 0, 0);
			keybd_event(9, 0, KEYEVENTF_KEYUP, 0);
			keybd_event(18, 0, KEYEVENTF_KEYUP, 0);
		}
		closesocket(ClientSocket);

	}
	closesocket(ServerSocket);
	WSACleanup();
	return 0;
}