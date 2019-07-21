// Monitor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <Psapi.h>
#include <tlhelp32.h>
#include <string.h>
#include <iostream>
#include <set>
#include <map>
#include <string>


#pragma comment (lib,"Psapi.lib")
#pragma comment (lib,"iphlpapi.lib")


int main()
{
	SetConsoleTitle(_T("广西多普勒天气雷达综合业务管理系统监控程序  请勿关闭 关闭后以管理员权限打开"));

	std::wstring programOnePath = _T("StationEnvironmentMonitor");
	std::wstring programTwoPath = _T("StationSoftMonitor");

	std::map<std::wstring, UINT> programCnt;
	programCnt[programOnePath] = 0;
	programCnt[programTwoPath] = 0;

	std::set<DWORD> programPID;
	std::map<std::wstring, BOOL> programStatus;

	while (TRUE)
	{
		programPID.clear();

		programStatus[programOnePath] = FALSE;
		programStatus[programTwoPath] = FALSE;

		HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		if (INVALID_HANDLE_VALUE == hSnapshot)
		{
			return -1;
		}

		PROCESSENTRY32 pe = { 0 };
		pe.dwSize = sizeof(PROCESSENTRY32);

		BOOL fOk;
		for (fOk = Process32First(hSnapshot, &pe); fOk; fOk = Process32Next(hSnapshot, &pe))
		{
			if (wcscmp(pe.szExeFile, _T("WRISFramework.exe")) == 0)
			{
				programPID.insert(pe.th32ProcessID);
			}
		}

		for (auto item = programPID.cbegin(); item != programPID.cend(); item++)
		{
			HANDLE h_Process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, *item);
			if (h_Process == NULL)
			{
				auto code = GetLastError();
				std::cout << "fail from OpenProcess " << code << std::endl;
				break;
			}

			WCHAR path[MAX_PATH + 1] = { L'\0' };

			auto len = GetModuleFileNameEx(h_Process, NULL, path, MAX_PATH + 1);

			if (len == 0)
			{
				auto code = GetLastError();
				std::cout << "fail from GetModuleFileNameEx " << code << std::endl;
				break;
			}
			else
			{
				std::cout  << std::endl;

				std::wstring programPath;
				programPath.append(path);
				
				INT index = 0;
				index = programPath.find(L"StationEnvironmentMonitor");
				if (index > 0)
				{
					programStatus[programOnePath] = TRUE;
					programCnt[programOnePath] = 0;
					std::cout << "环境监控程序运行正常" << std::endl;
				}

				index = programPath.find(L"StationSoftMonitor");
				if (index > 0)
				{
					programStatus[programTwoPath] = TRUE;
					programCnt[programTwoPath] = 0;
					std::cout << "雷达状态监控程序运行正常" << std::endl;
				}
				

			}
		}

		if (!programStatus[programOnePath])
		{
			programCnt[programOnePath]++;

			if (programCnt[programOnePath] >= 2)
			{
				std::cout << std::endl;
				std::cout << "环境监控程序已退出" << std::endl;

				PROCESS_INFORMATION pi;
				STARTUPINFOW si;
				ZeroMemory(&si, sizeof(STARTUPINFOA));
				si.cb = sizeof(STARTUPINFOA);
				si.dwFlags = STARTF_USESHOWWINDOW;
				si.wShowWindow = SW_SHOW;

				WCHAR cmdLine[] = _T("D:\\Program Files\\WRIS-RadarManagement\\StationEnvironmentMonitor\\WRISFramework.exe");
				WCHAR directoryLine[] = _T("D:\\Program Files\\WRIS-RadarManagement\\StationEnvironmentMonitor");
				//WCHAR cmdLine[] = _T("F:\\WRIS-RadarManagement-StationEnvironmentMonitor\\Build\\Release\\WRISFramework.exe");

				if (!CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, directoryLine, &si, &pi))
				{
					auto code = GetLastError();
					std::cout << "fail from CreateProcess " << code << std::endl;
				}
				else
				{
					programStatus[programOnePath] = TRUE;
					programCnt[programOnePath] = 0;
					std::cout << "环境监控程序重新启动" << std::endl;
				}
			}


		}

		if (!programStatus[programTwoPath])
		{
			programCnt[programTwoPath]++;

			if (programCnt[programTwoPath] >= 2)
			{
				std::cout << std::endl;
				std::cout << "雷达状态监控程序已退出" << std::endl;

				PROCESS_INFORMATION pi;
				STARTUPINFOW si;
				ZeroMemory(&si, sizeof(STARTUPINFOA));
				si.cb = sizeof(STARTUPINFOA);
				si.dwFlags = STARTF_USESHOWWINDOW;
				si.wShowWindow = SW_SHOW;

				WCHAR cmdLine[] = _T("D:\\Program Files\\WRIS-RadarManagement\\StationSoftMonitor\\WRISFramework.exe");
				WCHAR directoryLine[] = _T("D:\\Program Files\\WRIS-RadarManagement\\StationSoftMonitor");
				//WCHAR cmdLine[] = _T("F:\\WRIS-RadarManagement-StationSoftMonitor\\Build\\Release\\WRISFramework.exe");

				if (!CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, directoryLine, &si, &pi))
				{
					auto code = GetLastError();
					std::cout << "fail from CreateProcess " << code << std::endl;
				}
				else
				{
					programStatus[programTwoPath] = TRUE;
					programCnt[programTwoPath] = 0;
					std::cout << "雷达状态监控程序重新启动" << std::endl;
				}
			}
		}
		

		if (programStatus[programOnePath] && programStatus[programTwoPath])
		{
			Sleep(6*60*1000);
		}
		else
		{
			Sleep(2*60*1000);
		}


	}



    return 0;
}

