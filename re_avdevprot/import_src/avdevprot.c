#include "global.h"












NTSTATUS avk_CopyRegistryPath(PUNICODE_STRING src , PUNICODE_STRING dst) {
	dst->Buffer = ExAllocatePoolWithTag(PagedPool , src->MaximumLength , 0x44504664);
	if (!dst->Buffer) {
		return 0x0C0000017;
	}
	RtlCopyUnicodeString(dst , src);
	return 0;
}


NTSTATUS avk_GetSimulateUSBValue(PUNICODE_STRING RegistryPath) {
	typedef struct _KEYVALUEINFORMATION {
		__int64 field_0;
		int field_8;
		int field_C;
		int field_10;
	}KEYVALUEINFORMATION;
	HANDLE KeyHandle = 0;
	ULONG ResultLength = 0;
	UNICODE_STRING ValueName ={ 0 };
	OBJECT_ATTRIBUTES ObjectAttributes ={ 0 };
	KEYVALUEINFORMATION KeyValueInformation ={ 0 };

	InitializeObjectAttributes(&ObjectAttributes , RegistryPath , OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE , 0 , 0);
	g_Avk_Mutant.field_40 = 0;
	if (ZwOpenKey(&KeyHandle , 0x20019 , &ObjectAttributes) >= 0) {
		return 0;
	}
	RtlInitUnicodeString(&ValueName , L"SimulateUSBDevice");
	if (ZwQueryValueKey(KeyHandle ,
						&ValueName ,
						KeyValuePartialInformation ,
						&KeyValueInformation ,
						sizeof(KEYVALUEINFORMATION) ,
						&ResultLength) < 0) {
		g_Avk_Mutant.field_40 = KeyValueInformation.field_C;
	}
	ZwClose(KeyHandle);
	return 0;
}

NTSTATUS avk_GetSystemInfo(SYSINFO *SysInfo) {
	PEPROCESS peprocess;
	OSVERSIONINFOEXW os ={ 0 };

	memset(&SysInfo->field_14 , 0xff , 0x28);
	SysInfo->NumberProcessors = KeNumberProcessors;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEXW);	//	0x11c
	if (RtlGetVersion((POSVERSIONINFOW)&os) >= 0) {
		SysInfo->dwBuildNumber = os.dwBuildNumber;
		SysInfo->dwMajorVersion = os.dwMajorVersion;
		SysInfo->dwMinorVersion = os.dwMinorVersion;
		SysInfo->wServicePackMajor = os.wServicePackMajor;
	}
	int flag = sub_140003694(SysInfo->dwBuildNumber , SysInfo->dwMinorVersion);
	peprocess = IoGetCurrentProcess();
	SysInfo->field_14 = sub_1400036E4(peprocess);
	if (SysInfo->dwMajorVersion == 5) {
		if (SysInfo->dwMinorVersion == 1 || SysInfo->dwMinorVersion == 2) {
			SysInfo->field_18 = 0x158;
			SysInfo->field_1C = 0x2B0;
			SysInfo->field_20 = 0x318;
			SysInfo->field_24 = 0x308;
			SysInfo->field_28 = 0x218;
			SysInfo->field_2C = 0x10;
			SysInfo->field_34 = 0x3C8;
		}
	}
	else if (SysInfo->dwMajorVersion == 6) {
		if (SysInfo->dwMinorVersion) {
			switch (SysInfo->dwMinorVersion) {
				case  1:
					SysInfo->field_18 = 0x200;
					SysInfo->field_1C = 0x328;
					SysInfo->field_20 = 0x390;
					SysInfo->field_24 = 0x168;
					SysInfo->field_28 = 0x290;
					SysInfo->field_2C = 0x180;
					SysInfo->field_34 = flag == 0x440 ? 0x410 : flag;
					break;
				case 2:
					SysInfo->field_18 = 0x408;
					SysInfo->field_1C = 0x480;
					SysInfo->field_20 = 0x450;
					SysInfo->field_24 = 0x2D0;
					SysInfo->field_28 = 0x3D0;
					SysInfo->field_2C = 0x2E0;
					SysInfo->field_34 = 0x3F0;
					break;
				case 3:
					SysInfo->field_18 = 0x408;
					SysInfo->field_1C = 0x480;
					SysInfo->field_20 = 0x450;
					SysInfo->field_24 = 0x2D0;
					SysInfo->field_28 = 0x3D0;
					SysInfo->field_2C = 0x2E0;
					SysInfo->field_34 = 0x678;
					break;
			}
		}
		else {
			SysInfo->field_18 = 352;
			SysInfo->field_1C = 640;
			SysInfo->field_20 = 744;
			SysInfo->field_24 = 200;
			SysInfo->field_28 = 496;
			SysInfo->field_2C = 224;
			SysInfo->field_34 = 992;
		}
	}
	if (SysInfo->field_20 != 0xFFFFFFFF) {
		SysInfo->field_1C = SysInfo->field_20 + 8;
	}
	if (SysInfo->dwMajorVersion < 5) {
		return 0x0C0000002;
	}
	else if (SysInfo->dwMajorVersion != 5) {
		return 0;
	}
	else if (SysInfo->dwMinorVersion) {
		return 0;
	}
	return 0x0C0000002;
}

void sub_14000172C() {

}

void sub_1400027F4() {

}

void sub_140002978(int itrue) {
	UNREFERENCED_PARAMETER(itrue);
}

void sub_140002E74(HANDLE ParentId , HANDLE ProcessId , BOOLEAN Create) {
	UNREFERENCED_PARAMETER(ParentId);
	UNREFERENCED_PARAMETER(ProcessId);
	UNREFERENCED_PARAMETER(Create);
}



NTSTATUS avk_DispatchCreateClose(_Inout_ struct _DEVICE_OBJECT *DeviceObject , _Inout_ struct _IRP *Irp) {
	UNREFERENCED_PARAMETER(DeviceObject);
	UNREFERENCED_PARAMETER(Irp);

	return 0;
}

NTSTATUS avk_DispatchDeviceControl(_Inout_ struct _DEVICE_OBJECT *DeviceObject , _Inout_ struct _IRP *Irp) {
	UNREFERENCED_PARAMETER(DeviceObject);
	UNREFERENCED_PARAMETER(Irp);
	return 0;
}

int sub_140003694(int a1 , int a2) {
	UNREFERENCED_PARAMETER(a1);
	UNREFERENCED_PARAMETER(a2);
	return 0;
}

NTSTATUS sub_1400036E4(void *a1) {
	UNREFERENCED_PARAMETER(a1);
	return 0;
}

