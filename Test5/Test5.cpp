// Test5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <SetupAPI.h>
#include <iostream>
using namespace std;
//
// must include initguid.h ahead of Devpkey.h
//
#include <initguid.h>
#include <Devpkey.h>

VOID
GetDevicePropertiesSetupapi( VOID )
{
  HDEVINFO DeviceInfoSet = INVALID_HANDLE_VALUE;
  SP_DEVINFO_DATA DeviceInfoData;
  DWORD Index;
  WCHAR DeviceDesc[2048];
  DEVPROPTYPE PropertyType;

  DeviceInfoSet = SetupDiGetClassDevs(NULL,
    NULL,
    NULL,
    DIGCF_ALLCLASSES | DIGCF_PRESENT);

  if (DeviceInfoSet == INVALID_HANDLE_VALUE)
  {
    goto Exit;
  }

  ZeroMemory(&DeviceInfoData, sizeof(DeviceInfoData));
  DeviceInfoData.cbSize = sizeof(DeviceInfoData);

  for (Index = 0;
    SetupDiEnumDeviceInfo(DeviceInfoSet,
      Index,
      &DeviceInfoData);
    Index++)
  {
    // Query a property on the device.  For example, the device description.
    if (!SetupDiGetDeviceProperty(DeviceInfoSet,
      &DeviceInfoData,
      &DEVPKEY_Device_DeviceDesc,
      &PropertyType,
      (PBYTE)DeviceDesc,
      sizeof(DeviceDesc),
      NULL,
      0))
    {
      // The error can be retrieved with GetLastError();
      continue;
    }

    if (PropertyType != DEVPROP_TYPE_STRING)
    {
      continue;
    }
    else
    {
      wcout << L"Devcie #" << Index << L": " <<"\t" << DeviceDesc << endl;
    }
  }

  if (GetLastError() != ERROR_NO_MORE_ITEMS)
  {
    goto Exit;
  }

Exit:

  if (DeviceInfoSet != INVALID_HANDLE_VALUE)
  {
    SetupDiDestroyDeviceInfoList(DeviceInfoSet);
  }

  return;
}

int main()
{
  GetDevicePropertiesSetupapi();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
