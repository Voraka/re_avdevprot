#ifndef _GTYPE_H_
#define _GTYPE_H_











typedef struct _AVK_MUTANT {
	int field_0;
	int field_4;
	KMUTANT Mutant;
	int field_40;
}AVK_MUTANT,*PAVK_MUTANT;	//	0x44


typedef struct _SYSINFO {
	int dwBuildNumber;
	int dwMajorVersion;
	int dwMinorVersion;
	int wServicePackMajor;
	int NumberProcessors;
	int field_14;
	int field_18;
	int field_1C;
	int field_20;
	int field_24;
	int field_28;
	int field_2C;
	int field_30;
	int field_34;
	int field_38;
}SYSINFO,*PSYSINFO;


typedef struct _AVK_INIT {
	__int64 field_0;
	PDEVICE_OBJECT DeviceObject;		//	0x08
	char field_10;
	char field_11;
	char field_12;
	char field_13;
	int field_14;
	UNICODE_STRING RegistryPath;		//	0x18
	__int64 field_28;
	__int64 field_30;
	__int64 field_38;
	SINGLE_LIST_ENTRY ListHead_40;
	KSPIN_LOCK SpinLock;				//	0x48
	__int64 field_50;
	__int64 field_58;
	__int64 field_60;
	int field_68;
	int field_6C;
	__int64 field_70;
	KEVENT Object_78;
	int field_90;
	int field_94;
	__int64 field_98;
}AVK_INIT , *PAVK_INIT;		//	0xa0































































#endif // !_GTYPE_H_
