#ifndef _AVDEVPROT_H_
#define _AVDEVPROT_H_






















NTSTATUS sub_140009388(PUNICODE_STRING src , PUNICODE_STRING dst);


NTSTATUS sub_1400093E8(PUNICODE_STRING RegistryPath);

NTSTATUS sub_1400019EC(void *a1);
void sub_14000172C();


void sub_1400027F4();
void sub_140002978(int itrue);
void sub_140002E74(HANDLE ParentId , HANDLE ProcessId , BOOLEAN Create);









//************************************************************************************************************
//	��������  :	Tennn
//  �޸�ʱ��  :  2017/11/27 22:04
//	��������  :	�����͹ر���ǲ���� sub_14000170C
//************************************************************************************************************
NTSTATUS avk_DispatchCreateClose(_Inout_ struct _DEVICE_OBJECT *DeviceObject , _Inout_ struct _IRP *Irp);



//************************************************************************************************************
//	��������  :	Tennn
//  �޸�ʱ��  :  2017/11/27 22:09
//	��������  :	�豸������ǲ�������� sub_140009198
//************************************************************************************************************
NTSTATUS avk_DispatchDeviceControl(_Inout_ struct _DEVICE_OBJECT *DeviceObject , _Inout_ struct _IRP *Irp);



















#endif // !_AVDEVPROT_H_