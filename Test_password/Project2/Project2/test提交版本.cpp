#include<iostream>
#include<Windows.h>
using namespace std;
BYTE g_byBuffer[0x1470] = { 0 };
BYTE g_byBuffer004[0x300] = { 0 };
BYTE g_Dst[16] = { 0 };
//���ڱ�����ܺ������
BYTE g_Src[0x200] = { 0 };
//���������õ��ı���
DWORD g_dwLen = 0x200;
BOOL g_bSwapFlag = FALSE;
//���ڴ��ڵı�־
BYTE g_This3D2D7D = 0;
int g_This3D2D88 = 0;
int g_byBufferxF4B62 = 0;
//���ļ��е�ĳ�����ݽ���У��
BOOL check_0063AD39(BYTE* a, BYTE b, int len) {
	for (int i = 0; i < len; ++i) {
		if (a[i] != b) {
			return FALSE;
		}
	}
	return TRUE;
}
//���ļ��е�ĳ�����ݽ���0��0xff У�� 
BOOL check_00632399(BYTE* a, int b) {
	BOOL result = FALSE;
	if (!b) {
		result = FALSE;
		goto end;
	}
	if (check_0063AD39(a, 0, b)) {
		result = TRUE;
		goto end;
	}
	if (check_0063AD39(a, 0xff, b)) {
		result = TRUE;
		goto end;
	}
end:
	return result;
}
//ok
BOOL check_0063ADC5(BYTE a, BYTE b, BYTE c) {
	BOOL result;
	if (a >= b) {
		//result = a <= c;
		if (a <= c) {
			result = TRUE;
		}
		else {
			result = FALSE;
		}
	}
	else
		result = FALSE;
	return result;

}
//ÿ�����ֽ�һ����н���
int check_0063A316(BYTE* a, int len)
{
	BYTE temp;
	int i = 0;
	for (i = 0; i < len; i += 2) {
		temp = a[0];
		a[0] = a[1];
		a[1] = temp;
		a += 2;
	}
	return i;
}
//��������ͬʱ���ñ�־λ
void check_005769A9()
{
	//�Ƚ����ֽ�
	check_0063A316(g_byBuffer, g_dwLen);
	//���ñ�־λ
	if (g_bSwapFlag)
	{
		g_bSwapFlag = FALSE;
	}
	else
	{
		g_bSwapFlag = TRUE;
	}
	return;
}
BOOL check_0063B392(BYTE* a, BYTE b) {
	return ((1 << b)&a[0]) != 0;
}
BOOL check_0063B43A(BYTE* a) {
	char CH_L_v1=0;
	BOOL result = FALSE;
	char CH_L_v4 = 0;
	for (int i = 0; i < 7; ++i) {
		CH_L_v4 = 2 * ((check_0063B392(a, i) | CH_L_v4));  //��or ��shl
	}
	CH_L_v1 = check_0063B392(a, 7) | CH_L_v4;
	result = *a;
	a[0] = CH_L_v1;
	return result;
}
BOOL check_00633A49(WORD* a) {
	BYTE BT_L_v2 = 0;
	int IN_L_v3 = a[0];   //0x11 38
	BYTE BT_L_v4 = 0;;
	IN_L_v3 = a[0] & 0xFFFF;
	BT_L_v2 = (IN_L_v3 >> 8) & 0xFF;
	BT_L_v4 = IN_L_v3 & 0xFF;   //0x  38 28 9f 11
	check_0063B43A(&BT_L_v2);   //0x  88 38 11 11
	check_0063B43A(&BT_L_v4);   //0x  1c 28 9f 11
	a[0] = (BT_L_v2 | (BT_L_v4 << 8));
	return (BT_L_v2| IN_L_v3);
}
//��У�麯��
int check_00633981(BYTE* a, int b, int c, int d, BOOL ch1, BOOL ch2) {

	WORD WO_L_v10=d;
	BYTE BT_L_v11=0;
	int IN_L_v8 = 0;
	while (b)
	{
		BT_L_v11 = *a;
		if (ch1)
		{
			check_0063B43A((BYTE*)&BT_L_v11);
		}
		//��shl ��xor
		WO_L_v10 ^= (BT_L_v11 << 8);
		for (int i = 0; i < 8; ++i)
		{
			if (WO_L_v10 & 0x8000)
				IN_L_v8 = c ^ (2 * WO_L_v10);
			else
				IN_L_v8 = 2 * WO_L_v10;
			IN_L_v8 &= 0xffff;
			WO_L_v10 = IN_L_v8;
		}
		++a;
		--b;
	}
	if (ch2) {
		check_00633A49(&WO_L_v10);  
	}

	return WO_L_v10;
}
//оƬ����
char check_006357B2(BYTE a1, const char* a2) {
	char result; // al
	switch (a1 >> 4)
	{
	case 1:
		a2 = "PCF7936";
		::MessageBoxA(NULL, "����Ϊ��PCF7936", "ok", MB_OK);
		goto LABEL_13;
	case 2:
		a2 = "PCF7946";
		::MessageBoxA(NULL, "����Ϊ��PCF7946", "ok", MB_OK);
		goto LABEL_13;
	case 3:
		a2 = "PCF7947";
		::MessageBoxA(NULL, "����Ϊ��PCF7947", "ok", MB_OK);
		goto LABEL_13;
	case 4:
		a2 = "PCF7942-44";
		::MessageBoxA(NULL, "����Ϊ��PCF7942-44", "ok", MB_OK);
		goto LABEL_13;
	case 5:
		a2 = "PCF7943";
		::MessageBoxA(NULL, "����Ϊ��PCF7943", "ok", MB_OK);
		goto LABEL_13;
	case 6:
		a2 = "PCF7941";
		::MessageBoxA(NULL, "����Ϊ��PCF7941", "ok", MB_OK);
		goto LABEL_13;
	case 7:
		a2 = "PCF7952";
		::MessageBoxA(NULL, "����Ϊ��PCF7952", "ok", MB_OK);
		goto LABEL_13;
	case 8:
		a2 = "PCF7961";
		::MessageBoxA(NULL, "����Ϊ��PCF7961", "ok", MB_OK);
		goto LABEL_13;
	case 9:
		a2 = "PCF7945";
		::MessageBoxA(NULL, "����Ϊ��PCF7945", "ok", MB_OK);
		goto LABEL_13;
	case 0xB:
		a2 = "NXP OEM";
		::MessageBoxA(NULL, "����Ϊ��NXP OEM", "ok", MB_OK);
	LABEL_13:
		result = 1;
		break;
	default:
		a2 = "UNKNOWN";
		::MessageBoxA(NULL, "����Ϊ��UNKNOWN", "ok", MB_OK);
		result = 0;
		break;
	}
	return result;
}
//��⺯��1
BOOL check_00538DC4() {
	BOOL result = FALSE;//����ֵ
	//���ڱ���У����ֵ
	WORD WO_l_v12 = 0;
	//���ڱ�����������
	BYTE BT_l_v13[4] = { 0 };
	if (!check_0063ADC5(g_byBuffer[0xAC], 1, 8) || (g_byBuffer[0xAD])) {
		//���ļ�ǰ0x200���ֽ����������ֽڻ���
		check_005769A9();
	}
	//   ����1Ϊ9C	ok
	if (!check_0063ADC5(g_byBuffer[0xAC], 1, 8) || (g_byBuffer[0xAD])) {
		result = -1;
		goto end;   //ok
	}
	//v7 + 0x15C0
	if ((g_byBuffer[0xAC] != g_byBuffer[0x150])) {
		result = -1;
		goto end;
	}
	if (g_byBuffer[0xAC]) {
		result = -1;
		//v7 + 0x1530
		if (check_00632399(g_byBuffer + 0xC0, 6)) {
			result = -1;
			goto end;
		}
		//v7 + 0x1530                                       v7 + 0x15D4
		else if (!memcmp((g_byBuffer + 0xC0), (g_byBuffer + 0x164), 6))
			//v7 + 0x14FC
			WO_l_v12 = check_00633981((g_byBuffer + 0x8c), 162, 0x1021, 0xFFFF, 1, 1);
		//v7 + 0x159F
		if ((g_byBuffer[0x12f] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x12e]) == (WO_l_v12 & 0xff))) {
			//v7 + 0x15A0
			WO_l_v12 = check_00633981((g_byBuffer + 0x130), 162, 0x1021, 0xFFFF, 1, 1);
			//v7 + 0x1643
			if ((g_byBuffer[0x1D3] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x1D2]) == (WO_l_v12 & 0xff))) {
				//v7 + 0x14FC
				if (!memcmp((g_byBuffer + 0x8C), (g_byBuffer + 0x130), 0x20))
				{
					//v7 + 0x151C
					for (int i = 0; i < g_byBuffer[0xAC]; ++i) {
						//v4 = (char*)&v13;
						if (check_006357B2((g_byBuffer[0x8C + 4 * i]), (const char*)BT_l_v13)) {
							//v4 = (char*)8323072;
						}
						else {
							//v4 = (char*)255;
						}
					}
					//v4 = (char*)8;
					//v7 + 0x151C
					if (!g_byBuffer[0xAC]) {
						::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
						::MessageBoxA(NULL, "succsess", "ok", MB_OK);
						result = 1;
						goto end;
					}
					else {
						result = -1;
						goto end;
					}
				}
				else {
					result = -1;
					goto end;
				}
			}
			else {
				result = -1;
				goto end;
			}
		}
		else {
			result = -1;
			goto end;
		}
	}
	//v7 + 0x14FC
	WO_l_v12 = check_00633981((g_byBuffer + 0x8c), 162, 0x1021, 0xFFFF, 1, 1);
	//v7 + 0x159F
	if ((g_byBuffer[0x12F] != ((WO_l_v12 >> 8) & 0xff)) || (g_byBuffer[0x12E] != (WO_l_v12 & 0xff)))
	{
		check_005769A9();
		WO_l_v12 = check_00633981((g_byBuffer + 0x8c), 162, 0x1021, 0xFFFF, 1, 1);
		if ((g_byBuffer[0x12F] == ((WO_l_v12 >> 8) & 0xff)) && (g_byBuffer[0x12E] != (WO_l_v12 & 0xff))) {
			//v7 + 0x1530
			if (check_00632399(g_byBuffer + 0xC0, 6)) {
				result = -1;
				goto end;
			}
			//v7 + 0x1530                                       v7 + 0x15D4
			else if (!memcmp((g_byBuffer + 0xC0), (g_byBuffer + 0x164), 6))
				//v7 + 0x14FC
				WO_l_v12 = check_00633981((g_byBuffer + 0x8c), 162, 0x1021, 0xFFFF, 1, 1);
			//v7 + 0x159F
			if ((g_byBuffer[0x12f] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x12e]) == (WO_l_v12 & 0xff))) {
				//v7 + 0x15A0
				WO_l_v12 = check_00633981((g_byBuffer + 0x130), 162, 0x1021, 0xFFFF, 1, 1);
				//v7 + 0x1643
				if ((g_byBuffer[0x1D3] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x1D2]) == (WO_l_v12 & 0xff))) {
					//v7 + 0x14FC
					if (!memcmp((g_byBuffer + 0x8C), (g_byBuffer + 0x130), 0x20))
					{
						//v7 + 0x151C
						for (int i = 0; i < g_byBuffer[0xAC]; ++i) {
							//v4 = (char*)&v13;
							if (check_006357B2((g_byBuffer[0x8C + 4 * i]), (const char*)BT_l_v13)) {
								//v4 = (char*)8323072;
							}
							else {
								//v4 = (char*)255;
							}
						}
						//v4 = (char*)8;
						//v7 + 0x151C
						if (!g_byBuffer[0xAC]) {
							::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
							::MessageBoxA(NULL, "succsess", "ok", MB_OK);
							result = 1;
							goto end;
						}
						else {
							result = -1;
							goto end;
						}
					}
					else {
						result = -1;
						goto end;
					}
				}
				else {
					result = -1;
					goto end;
				}
			}
			else {
				result = -1;
				goto end;
			}
		}
	}
	else {
		check_005769A9();
		WO_l_v12 = check_00633981((g_byBuffer + 0x8c), 162, 0x1021, 0xFFFF, 1, 1);
		if ((g_byBuffer[0x12F] != ((WO_l_v12 >> 8) & 0xff)) || (g_byBuffer[0x12E] != (WO_l_v12 & 0xff))) {
			check_005769A9();
			//v7 + 0x1530
			if (check_00632399(g_byBuffer + 0xC0, 6)) {
				result = -1;
				goto end;
			}
			//v7 + 0x1530                                       v7 + 0x15D4
			else if (!memcmp((g_byBuffer + 0xC0), (g_byBuffer + 0x164), 6))
				//v7 + 0x14FC
				WO_l_v12 = check_00633981((g_byBuffer + 0x8c), 162, 0x1021, 0xFFFF, 1, 1);
			//v7 + 0x159F
			if ((g_byBuffer[0x12f] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x12e]) == (WO_l_v12 & 0xff))) {
				//v7 + 0x15A0
				WO_l_v12 = check_00633981((g_byBuffer + 0x130), 162, 0x1021, 0xFFFF, 1, 1);
				//v7 + 0x1643
				if ((g_byBuffer[0x1D3] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x1D2]) == (WO_l_v12 & 0xff))) {
					//v7 + 0x14FC
					if (!memcmp((g_byBuffer + 0x8C), (g_byBuffer + 0x130), 0x20))
					{
						//v7 + 0x151C
						for (int i = 0; i < g_byBuffer[0xAC]; ++i) {
							//v4 = (char*)&v13;
							if (check_006357B2((g_byBuffer[0x8C + 4 * i]), (const char*)BT_l_v13)) {
								//v4 = (char*)8323072;
							}
							else {
								//v4 = (char*)255;
							}
						}
						//v4 = (char*)8;
						//v7 + 0x151C
						if (!g_byBuffer[0xAC]) {
							::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
							::MessageBoxA(NULL, "succsess", "ok", MB_OK);
							result = 1;
							goto end;
						}
						else {
							result = -1;
							goto end;
						}
					}
					else {
						result = -1;
						goto end;
					}
				}
				else {
					result = -1;
					goto end;
				}
			}
			else {
				result = -1;
				goto end;
			}
		}
	}
	//v7 + 0x15A0
	WO_l_v12 = check_00633981((g_byBuffer + 0x130), 162, 0x1021, 0xFFFF, 1, 1);

	//v7 + 0x1643
	if ((g_byBuffer[0x1d3] == ((WO_l_v12 >> 8) & 0xff)) && (g_byBuffer[0x1D2] != (WO_l_v12 & 0xff)))
	{
		check_005769A9();
		WO_l_v12 = check_00633981((g_byBuffer + 0x130), 162, 0x1021, 0xFFFF, 1, 1);
		if ((g_byBuffer[0x1D3] != ((WO_l_v12 >> 8) & 0xff)) || (g_byBuffer[0x1D2] != (WO_l_v12 & 0xff)))
		{
			check_005769A9();
			//v7 + 0x1530
			if (check_00632399(g_byBuffer + 0xC0, 6)) {
				result = -1;
				goto end;
			}
			//v7 + 0x1530                                       v7 + 0x15D4
			else if (!memcmp((g_byBuffer + 0xC0), (g_byBuffer + 0x164), 6))
				//v7 + 0x14FC
				WO_l_v12 = check_00633981((g_byBuffer + 0x8c), 162, 0x1021, 0xFFFF, 1, 1);
			//v7 + 0x159F
			if ((g_byBuffer[0x12f] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x12e]) == (WO_l_v12 & 0xff))) {
				//v7 + 0x15A0
				WO_l_v12 = check_00633981((g_byBuffer + 0x130), 162, 0x1021, 0xFFFF, 1, 1);
				//v7 + 0x1643
				if ((g_byBuffer[0x1D3] == ((WO_l_v12 >> 8) & 0xff)) && ((g_byBuffer[0x1D2]) == (WO_l_v12 & 0xff))) {
					//v7 + 0x14FC
					if (!memcmp((g_byBuffer + 0x8C), (g_byBuffer + 0x130), 0x20))
					{
						//v7 + 0x151C
						for (int i = 0; i < g_byBuffer[0xAC]; ++i) {
							//v4 = (char*)&v13;
							if (check_006357B2((g_byBuffer[0x8C + 4 * i]), (const char*)BT_l_v13)) {
								//v4 = (char*)8323072;
							}
							else {
								//v4 = (char*)255;
							}
						}
						//v4 = (char*)8;
						//v7 + 0x151C
						if (!g_byBuffer[0xAC]) {
							::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
							::MessageBoxA(NULL, "succsess", "ok", MB_OK);
							result = 1;
							goto end;
						}
						else {
							result = -1;
							goto end;
						}
					}
					else {
						result = -1;
						goto end;
					}
				}
				else {
					result = -1;
					goto end;
				}
			}
			else {
				result = -1;
				goto end;
			}
		}
		result = -1;
		goto end;
	}
	check_005769A9();
	//v7 + 0x15A0
	WO_l_v12 = check_00633981((g_byBuffer + 0x130), 162, 0x1021, 0xFFFF, 1, 1);
	//v7 + 0x1643
	if ((g_byBuffer[0x1D3] != ((WO_l_v12 >> 8) & 0xff)) || (g_byBuffer[0x12E] != (WO_l_v12 & 0xff)))
		result = -1;
end:
	return result;
}
//��⺯��2
void check_00538806() {
	//���ڱ�����������ֵ ˫�ֽ�
	WORD  WD_L_v12 = 0;
	//���ڱ�����������
	BYTE BY_L_v13[4] = { 0 };
	if (!check_0063ADC5(g_byBuffer[0xA0], 0, 8) || g_byBuffer[0xA1])
		//��������
		check_005769A9();
	// ����1Ϊ60  ok
	if (!check_0063ADC5(g_byBuffer[0xA0], 0, 8) || g_byBuffer[0xA1])
	{
		goto end;
	}
	if (g_byBuffer[0xA0] != g_byBuffer[0x144])
	{
		goto end;
	}
	if (g_byBuffer[0xA0])
		//v7 + 0x1524
		if (check_00632399((g_byBuffer + 0xB4), 6))
		{
			goto end;
		}
		else if (!memcmp((g_byBuffer + 0xB4), (g_byBuffer + 0x158), 6))
		{
			WD_L_v12 = check_00633981((g_byBuffer + 0x80), 162, 0x1021, 0xFFFF, 1, 1);
			//v7 + 0x1593
			if (((g_byBuffer[0x123] == ((WD_L_v12 >> 8) & 0xff))) && (g_byBuffer[0x122]) == (WD_L_v12 & 0xff))
			{//v7 + 0x1594
				WD_L_v12 = check_00633981((g_byBuffer + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
				//v7 + 0x1637
				if ((g_byBuffer[0x1c7] == ((WD_L_v12 >> 8) & 0xff)) && (g_byBuffer[0x1c6] == (WD_L_v12 & 0xff)))
				{//v7 + 0x14F0
					if (!memcmp((g_byBuffer + 0x80), (g_byBuffer + 0x124), 0x20))
					{
						//v7 + 0x1510
						for (int i = 0; i < g_byBuffer[0xA0]; ++i)
						{
							if (check_006357B2(g_byBuffer[0x80 + 4 * i], (const char*)BY_L_v13))
							{
								//v6 = CString::CString(&v3, v15);
							}
							else
							{
								//
								::MessageBoxA(NULL, "���Ϳ���û��", "error", MB_OK);
							}
							//
							::MessageBoxA(NULL, "����btn��ʾok", "ok", MB_OK);
						}
						//v7 + 0x1510
						if (!g_byBuffer[0xA0])
							::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
						::MessageBoxA(NULL, "succsess", "ok", MB_OK);
						goto end;
					}
					else
					{
						goto end;
					}
				}
				else
				{
					goto end;
				}
			}
			else
			{
				goto end;
			}
		}
		else
		{
			goto end;
		}
	//v7 + 0x14F0
	WD_L_v12 = check_00633981((g_byBuffer + 0x80), 162, 0x1021, 0xFFFF, 1, 1);
	if (g_byBuffer[0x123] != ((WD_L_v12 >> 8) & 0xff) || (g_byBuffer + 0x122)[0] != (WD_L_v12 & 0xff))
	{
		check_005769A9();
		WD_L_v12 = check_00633981((g_byBuffer + 0x80), 162, 0x1021, 0xFFFF, 1, 1);
		//v7 + 0x1593
		if (g_byBuffer[0x123] == ((WD_L_v12 >> 8) & 0xff) && (g_byBuffer[0x122] == (WD_L_v12 & 0xff)))
			//v7 + 0x1524
			if (check_00632399((g_byBuffer + 0xB4), 6))
			{
				goto end;
			}
			else if (!memcmp((g_byBuffer + 0xB4), (g_byBuffer + 0x158), 6))
			{
				WD_L_v12 = check_00633981((g_byBuffer + 0x80), 162, 0x1021, 0xFFFF, 1, 1);
				//v7 + 0x1593
				if (((g_byBuffer[0x123] == ((WD_L_v12 >> 8) & 0xff))) && (g_byBuffer[0x122]) == (WD_L_v12 & 0xff))
				{//v7 + 0x1594
					WD_L_v12 = check_00633981((g_byBuffer + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
					//v7 + 0x1637
					if ((g_byBuffer[0x1c7] == ((WD_L_v12 >> 8) & 0xff)) && (g_byBuffer[0x1c6] == (WD_L_v12 & 0xff)))
					{//v7 + 0x14F0
						if (!memcmp((g_byBuffer + 0x80), (g_byBuffer + 0x124), 0x20))
						{
							//v7 + 0x1510
							for (int i = 0; i < g_byBuffer[0xA0]; ++i)
							{
								if (check_006357B2(g_byBuffer[0x80 + 4 * i], (const char*)BY_L_v13))
								{
									//v6 = CString::CString(&v3, v15);
								}
								else
								{
									//
									::MessageBoxA(NULL, "���Ϳ���û��",  "error", MB_OK);
								}
								//
								::MessageBoxA(NULL, "����btn��ʾok", "ok", MB_OK);
							}
							//v7 + 0x1510
							if (!g_byBuffer[0xA0])
								::MessageBoxA(NULL, "error","0 keys detected. Continue on own responisibility.", MB_OK);
							::MessageBoxA(NULL, "succsess", "ok", MB_OK);
							goto end;
						}
						else
						{
							goto end;
						}
					}
					else
					{
						goto end;
					}
				}
				else
				{
					goto end;
				}
			}
			else
			{
				goto end;
			}
	}
	else
	{
		check_005769A9();
		WD_L_v12 = check_00633981((g_byBuffer + 0x80), 162, 0x1021, 0xFFFF, 1, 1);
		if ((g_byBuffer[0x123] != ((WD_L_v12 >> 8) & 0xff)) || (g_byBuffer[0x122] != (WD_L_v12 & 0xff)))
		{
			check_005769A9();
			//v7 + 0x1524
			if (check_00632399((g_byBuffer + 0xB4), 6))
			{
				goto end;
			}
			else if (!memcmp((g_byBuffer + 0xB4), (g_byBuffer + 0x158), 6))
			{
				WD_L_v12 = check_00633981((g_byBuffer + 0x80), 162, 0x1021, 0xFFFF, 1, 1);
				//v7 + 0x1593
				if (((g_byBuffer[0x123] == ((WD_L_v12 >> 8) & 0xff))) && (g_byBuffer[0x122]) == (WD_L_v12 & 0xff))
				{//v7 + 0x1594
					WD_L_v12 = check_00633981((g_byBuffer + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
					//v7 + 0x1637
					if ((g_byBuffer[0x1c7] == ((WD_L_v12 >> 8) & 0xff)) && (g_byBuffer[0x1c6] == (WD_L_v12 & 0xff)))
					{//v7 + 0x14F0
						if (!memcmp((g_byBuffer + 0x80), (g_byBuffer + 0x124), 0x20))
						{
							//v7 + 0x1510
							for (int i = 0; i < g_byBuffer[0xA0]; ++i)
							{
								if (check_006357B2(g_byBuffer[0x80 + 4 * i], (const char*)BY_L_v13))
								{
									//v6 = CString::CString(&v3, v15);
								}
								else
								{
									//
									::MessageBoxA(NULL, "���Ϳ���û��", "error", MB_OK);
								}
								//
								::MessageBoxA(NULL, "����btn��ʾok", "ok", MB_OK);
							}
							//v7 + 0x1510
							if (!g_byBuffer[0xA0])
								::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
							::MessageBoxA(NULL, "succsess", "ok", MB_OK);
							goto end;
						}
						else
						{
							goto end;
						}
					}
					else
					{
						goto end;
					}
				}
				else
				{
					goto end;
				}
			}
			else
			{
				goto end;
			}
		}
	}
	WD_L_v12 = check_00633981((g_byBuffer + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
	//v7 + 0x1637
	if ((g_byBuffer[0x1c7] == ((WD_L_v12 >> 8) & 0xff)) && (g_byBuffer[0x1c6] == (WD_L_v12 & 0xff)))
	{
		check_005769A9();
		WD_L_v12 = check_00633981((g_byBuffer + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
		if ((g_byBuffer[0x1c7] != ((WD_L_v12 >> 8) & 0xff)) || (g_byBuffer[0x1c6] != (WD_L_v12 & 0xff)))
		{
			check_005769A9();
			//v7 + 0x1524
			if (check_00632399((g_byBuffer + 0xB4), 6))
			{
				goto end;
			}
			else if (!memcmp((g_byBuffer + 0xB4), (g_byBuffer + 0x158), 6))
			{
				WD_L_v12 = check_00633981((g_byBuffer + 0x80), 162, 0x1021, 0xFFFF, 1, 1);
				//v7 + 0x1593
				if (((g_byBuffer[0x123] == ((WD_L_v12 >> 8) & 0xff))) && (g_byBuffer[0x122]) == (WD_L_v12 & 0xff))
				{//v7 + 0x1594
					WD_L_v12 = check_00633981((g_byBuffer + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
					//v7 + 0x1637
					if ((g_byBuffer[0x1c7] == ((WD_L_v12 >> 8) & 0xff)) && (g_byBuffer[0x1c6] == (WD_L_v12 & 0xff)))
					{//v7 + 0x14F0
						if (!memcmp((g_byBuffer + 0x80), (g_byBuffer + 0x124), 0x20))
						{
							//v7 + 0x1510
							for (int i = 0; i < g_byBuffer[0xA0]; ++i)
							{
								if (check_006357B2(g_byBuffer[0x80 + 4 * i], (const char*)BY_L_v13))
								{
									//v6 = CString::CString(&v3, v15);
								}
								else
								{
									//
									::MessageBoxA(NULL, "���Ϳ���û��", "error", MB_OK);
								}
								//
								::MessageBoxA(NULL, "����btn��ʾok", "ok", MB_OK);
							}
							//v7 + 0x1510
							if (!g_byBuffer[0xA0])
								::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
							::MessageBoxA(NULL, "succsess", "ok", MB_OK);
							goto end;
						}
						else
						{
							goto end;
						}
					}
					else
					{
						goto end;
					}
				}
				else
				{
					goto end;
				}
			}
			else
			{
				goto end;
			}
		}
		goto end;

	}
	check_005769A9();
	WD_L_v12 = check_00633981((g_byBuffer + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
	if ((g_byBuffer[0x1c7] != ((WD_L_v12 >> 8) & 0xff)) || (g_byBuffer[0x1c6] != (WD_L_v12 & 0xff)))
		goto end;

	
end:
	return;

}
int check_00625235(BYTE* a1, BYTE* a2, BYTE* a3, int a4) {
	int result;
	for (int i = 0; i < a4; ++i) {
		a1[i] = a3[i] ^ a2[i];
		result = i + 1;
	}
	//a1=0x69,0x2E,0xD0,0xF3
	return result;
}
int check_00624C77(BYTE* a2) {
	int i = 0;
	//ֻҪ��һ����Ӧ��Ϊok
	memcpy(g_Dst, a2 + 0xB0, 0x10);											 //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
	//����ȥ
	if (memcmp(g_Dst, a2 + 0xF0, 0x10))									     //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
	{
		if (memcmp(g_Dst, a2 + 0x110, 0x10))									 //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
		{
			if (memcmp(g_Dst, a2 + 0x190, 0x10))								 //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
			{
				if (memcmp(g_Dst, a2 + 0x1b0, 0x10))							 //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
				{
					memcpy(g_Dst, a2 + 0xF0, 0x10);
					if (memcmp(g_Dst, a2 + 0x110, 0x10))                       //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
					{
						if (memcmp(g_Dst, a2 + 0x190, 0x10))                   //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
						{
							if (memcmp(g_Dst, a2 + 0x1b0, 0x10))               //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
							{
								memcpy(g_Dst, a2 + 0x110, 0x10);               //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
								if (memcmp(g_Dst, a2 + 0x190, 0x10))           //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
								{
									if (memcmp(g_Dst, a2 + 0x1b0, 0x10))       //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
									{
										memcpy(g_Dst, a2 + 0x190, 0x10);       //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
										if (memcmp(g_Dst, a2 + 0x1b0, 0x10))   //E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6
											::MessageBoxA(NULL,  "�Ҳ�����E0 92 92 4E 4E 0E 0E 40 40 5E 5E 8A 8A 24 24 E6", "error", MB_OK);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	memcpy(g_byBuffer004 + 0x210, g_Dst, 0x10);

	memset(g_Src, 0, 0x10);
	memcpy(g_Dst, a2 + 0x160, 4);                    //60 94 94 79
	//������
	if (memcmp(g_Dst, a2 + 0x1A0, 4))                //60 94 94 79
	{
		if (memcmp(g_Dst, a2 + 0x1C0, 4))            //60 94 94 79
		{
			memcpy(g_Dst, a2 + 0x1A0, 4);            //60 94 94 79
			if (memcmp(g_Dst, a2 + 0x1C0, 4))        //60 94 94 79
				::MessageBoxA(NULL, "�Ҳ�����60 94 94 79", "error", MB_OK);
			return 0;
		}
	}
	//60 94 94 79
	memcpy(g_Src, g_Dst, 4); 
	check_00625235(g_Dst, g_Src, g_byBuffer + 0xC0, 4);
	check_00625235(g_Src + 0x4, g_Dst, g_byBuffer + 0x164, 4);//624f31
	check_00625235(g_Dst, g_Src, g_byBuffer + 0xC0, 6);   //0x00624f4d
	check_00625235(g_Src + 0x8, g_Dst + 4, g_byBuffer + 0x168, 2);   //0x624f69
	memcpy(g_Dst, a2 + 0xEA, 6);                                          //70 91 91 9C 9C E0
	if (memcmp(g_Dst, a2 + 0x10A, 6))                                      //70 91 91 9C 9C E0
	{
		if (memcmp(g_Dst, a2 + 0x18A, 6))                                  //70 91 91 9C 9C E0    
		{
			if (memcmp(g_Dst, a2 + 0x1AA, 6))                              //70 91 91 9C 9C E0
			{
				memcpy(g_Dst, a2 + 0x10A, 6);
				if (memcmp(g_Dst, a2 + 0x18A, 6))
				{
					if (memcmp(g_Dst, a2 + 0x1AA, 6))
					{
						memcpy(g_Dst, a2 + 0x18A, 6);
						if (memcmp(g_Dst, a2 + 0x1AA, 6))
							::MessageBoxA(NULL, "�Ҳ�����70 91 91 9C 9C E0", "error", MB_OK);
						return 0;
					}
				}
			}
		}
	}
	//
	memcpy(g_Src + 0xA, g_Dst, 6);    //0x0062508a
	memcpy(g_byBuffer004 + 0x200, g_Src, 0x10);
	memcpy(g_byBuffer004, a2, 0x200);

	for (i = 0; i < 11; ++i)                    //TEMP_0x11A164 = g_0x119F60 + 0x204
		check_00625235(g_byBuffer004 + 0x20 * i + 0x80, g_byBuffer004 + 0x200, g_byBuffer + 0x20 * i + 0x80, 0x20);

	return 1;
}
int check_006251EC(BYTE* a, void *g_Dst) {
	return  (int)memcpy(g_Dst, a + 4, 0x200);
}
int check_00625211(BYTE* a, void *g_Dst) {
	return  (int)memcpy(g_Dst, a + 0x204, 0x200);
}
//��⺯��3
BOOL check_00538251() {
	BOOL retu = FALSE;
	BYTE BY_L_v12[16] = { 0 };
	BYTE BY_L_v13 = 0;
	//���ڱ�����������ֵ ˫�ֽ�
	WORD  WO_L_v14 = 0;
	//���ڱ�����������
	BYTE v15[4] = { 0 };
	BYTE g_Src[512] = { 0 };
	//check
	if (!check_00624C77(g_byBuffer)) {
		check_005769A9();
		if (!check_00624C77(g_byBuffer)) {//ok������
			retu = FALSE;
			goto end;
		}
	}
	//��������ǰѽ��������ֽ����ŵ�������
	//�⴫�����׵�ַҪ��4  g_byBuffer004�ǴӼ�4��ʼ��
	check_006251EC(g_byBuffer004 - 0x4, &g_Src);//0x005383dc
	WO_L_v14 = check_00633981(g_Src + 140, 0xA2, 0x1021, 0xFFFF, 1, 1);//0x00538401
	if ((g_Src[303] != ((WO_L_v14 >> 8) & 0xff)) || (g_Src[302] != (WO_L_v14 & 0xff))) {
		check_005769A9();
		if (!check_00624C77(g_byBuffer))
		{
			retu = FALSE;
			goto end;
		}
		check_006251EC(g_byBuffer004 - 0x4, &g_Src);

	}
	WO_L_v14 = check_00633981(g_Src + 140, 0xA2, 0x1021, 0xFFFFu, 1, 1);  //ok  0x1C88
	if ((g_Src[303] == ((WO_L_v14 >> 8) & 0xff)) && (g_Src[302] == (WO_L_v14 & 0xff))) {
		WO_L_v14 = check_00633981(g_Src + 304, 0xA2, 0x1021, 0xFFFFu, 1, 1);
		if ((g_Src[467] == ((WO_L_v14 >> 8) & 0xff)) && (g_Src[466] == (WO_L_v14 & 0xff))) {
			if (check_00632399(g_byBuffer, 6)) {
				retu = FALSE;
				goto end;
			}
			else if (!memcmp(g_Src + 192, g_Src + 356, 6)) {
				if (!memcmp(g_Src + 199, g_Src + 363, 3u)) {
					if (check_0063ADC5(g_Src[172], 0, 8)) {  //v18=2;  fun return 1   0x005385b1
						if (g_Src[172] == g_Src[336]) {   //2
							BY_L_v13 = g_Src[172];
							if (!memcmp(g_Src + 140, g_Src + 304, 4 * g_Src[172])) {
								for (int i = 0; i < BY_L_v13; ++i) {//v13 = v18;  
									//��������
									//CString::CString((CString *)v15);
									if (check_006357B2(g_Src[4 * i + 140], (const char*)&v15))
									{
										//v6 = CString::CString(&v3, v15);
									}
									else
									{
										//
										::MessageBoxA(NULL, "���Ϳ���û��", "error", MB_OK);
									}
									//
									::MessageBoxA(NULL, "����btn��ʾok", "ok", MB_OK);
								}
								//*(v7[0] + 0x3D2D7D) = 1;
								g_This3D2D7D = 1;
								//v7[0xF4B62] = 902;
								g_byBufferxF4B62 = 902;
								if (!BY_L_v13)  //���Ϊ0
									::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
								//g_SrcΪ���ܺ��������
								memcpy(g_byBuffer, g_Src, 0x200u);
								//check_00625211(g_byBuffer, g_byBuffer + 1001308);
								check_00625211(g_byBuffer, g_byBuffer004 + 0x200);
								::MessageBoxA(NULL,"succsess", "ok", MB_OK);
								retu = TRUE;
								goto end;

							}
							else {

								retu = FALSE;
								goto end;
							}
						}
						else {

							retu = FALSE;
							goto end;
						}
					}
					else {

						retu = FALSE;
						goto end;
					}
				}
				else {

					retu = FALSE;
					goto end;
				}
			}
			else {

				retu = FALSE;
				goto end;
			}
		}
		else {

			retu = FALSE;
			goto end;
		}
	}
	else {

		retu = FALSE;
		goto end;
	}
end:
	return retu;
}
//��⺯��4
BOOL check_00537C9C() {
	BOOL result = 0;
	//���ڱ�����ܺ��ֵ
	WORD WO_L_v14 = 0;
	BYTE BY_L_v11[556] = { 0 };
	BYTE BY_L_v12[16] = { 0 };
	//���ڱ�����������
	BYTE BY_L_v13 = 0;
	//���ڱ�����������
	BYTE BY_L_v15[4] = { 0 };
	//���ڱ�����ܺ������
	BYTE BY_L_v16[512] = { 0 };
	if (!check_00624C77(g_byBuffer))
	{
		//�ļ�ǰ0x200�ֽ���������
		check_005769A9();
		if (!check_00624C77(g_byBuffer))
		{
			result = -1;
			goto end;
		}
	}
	//���3��У�麯��һ��
	check_006251EC(g_byBuffer004 - 0x4, BY_L_v16);
	WO_L_v14 = check_00633981(BY_L_v16 + 0x80, 162, 0x1021, 0xFFFF, 1, 1);
	if ((BY_L_v16[0x123] != ((WO_L_v14) >> 8) & 0xff) || (BY_L_v16[0x122] != (WO_L_v14 & 0xff)))
	{
		//�ļ�ǰ0x200�ֽ���������
		check_005769A9();
		if (!check_00624C77(g_byBuffer))
		{
			result = -1;
			goto end;
		}
		check_006251EC(g_byBuffer004 - 0x4, BY_L_v16);
	}
	WO_L_v14 = check_00633981(BY_L_v16 + 0x80, 162, 0x1021, 0xFFFF, 1, 1);
	if ((BY_L_v16[0x123] == ((WO_L_v14 >> 8) & 0xff)) && (BY_L_v16[0x122] == (WO_L_v14 & 0xff)))
	{
		WO_L_v14 = check_00633981((BY_L_v16 + 0x124), 162, 0x1021, 0xFFFF, 1, 1);
		if ((BY_L_v16[0x1c7] == ((WO_L_v14) >> 8) & 0xff) && (BY_L_v16[0x1c6] == (WO_L_v14 & 0xff)))
		{
			if (check_00632399(BY_L_v16 + 0xB4, 6))
			{
				result = -1;
				goto end;
			}
			else if (!memcmp(BY_L_v16 + 0xB0, BY_L_v16 + 0x158, 6))
			{
				if (!memcmp(BY_L_v16 + 0xBB, BY_L_v16 + 0x15F, 3))
				{
					if (check_0063ADC5(BY_L_v16[0xA0], 0, 8))
					{
						if (BY_L_v16[0xA0] == BY_L_v16[0x144])
						{
							BY_L_v13 = BY_L_v16[0xA0];
							if (!memcmp(BY_L_v16 + 0x80, BY_L_v16 + 0x124, 4 * BY_L_v16[0xA0]))
							{
								for (int i = 0; i < BY_L_v13; ++i)
								{
									if (check_006357B2(BY_L_v16[4 * i + 0x80], (const char*)&BY_L_v15))
									{
										//v4 = (char *)8323072;

									}
									else
									{
										//
										::MessageBoxA(NULL, "���Ϳ���û��", "error", MB_OK);
									}
									//
									::MessageBoxA(NULL, "����btn��ʾok", "ok", MB_OK);
								}
								if (!BY_L_v13)
									::MessageBoxA(NULL, "error", "0 keys detected. Continue on own responisibility.", MB_OK);
								//���ܺ������
								memcpy(g_byBuffer, BY_L_v16, 0x200);
								//sub_625211((int)v11, v7 + 1001308);
								check_00625211(g_byBuffer, g_byBuffer004 + 0x200);
								::MessageBoxA(NULL, "succsess", "ok", MB_OK);
								result = 1;
								goto end;
							}
							else
							{
								result = -1;
								goto end;
							}
						}
						else
						{
							result = -1;
							goto end;
						}
					}
					else
					{
						result = -1;
						goto end;
					}
				}
				else
				{
					result = -1;
					goto end;
				}
			}
			else
			{
				result = -1;
				goto end;
			}
		}
		else
		{
			result = -1;
			goto end;
		}
	}
	else
	{
		result = -1;
		goto end;
	}
end:
	return result;
}
//���
BOOL check_00537C1C(BYTE* chg_byBuffer, DWORD dwWritenSize) {
	BOOL result = FALSE;
	//��⺯��1
	result= check_00538DC4();
	if (result) {
		//��⺯��2
		check_00538806();
		if (result) {
			result = check_00538251();
			if (!result) {
				result = check_00537C9C();
				if (!result) {
					::MessageBoxA(NULL,"error", "Unknown version.", MB_OK);
				}
			}
		}
	}
	return result;
}
//����ļ�
BOOL check(CHAR* Fpath) {
	HANDLE h = CreateFile(Fpath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE) {
		CloseHandle(h);
		return false;
	}
	//�ļ����ȸ�32λ
	DWORD Hlength = 0;
	const int BUFSIZE = GetFileSize(h, &Hlength);
	DWORD tmeplen = BUFSIZE + Hlength;
	DWORD dwReatenSize = 0;
	BOOL bRet = ::ReadFile(h, g_byBuffer, tmeplen, &dwReatenSize, NULL);
	//��һ������ļ��Ƿ�Ϊ��
	if (tmeplen == 0) {
		CHAR TEMP[50] = { 0 };
		sprintf(TEMP, "Invalid file size: %u Bytes", dwReatenSize);
		::MessageBoxA(NULL, TEMP,  "error", MB_OK);
		return false;
	}
	//�ڶ�������ļ��Ƿ���ȷ
	if (check_00632399(g_byBuffer, 0x1470)) {
		::MessageBoxA(NULL, "error", "ERROR: the dump is empty.", MB_OK);
		return false;
	}
	if (dwReatenSize)
		//Europe->Fiat->500->93C86
		//switch(case) 
		//00575446
		if (check_00537C1C(g_byBuffer, dwReatenSize))
		{
			CloseHandle(h);
			return TRUE;
		}
	CloseHandle(h);
	::MessageBoxA(NULL, "error", "error", MB_OK);
	return TRUE;
}

//�ļ����ȵ�32λ
DWORD Llength = 0;
//�ļ����ȸ�32λ
DWORD Hlength = 0;
BOOL getlength(CHAR* Fpath) {
	HANDLE h = CreateFileA(Fpath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE) {
		CloseHandle(h);
		return false;
	}
	Llength = GetFileSize(h, &Hlength);
	CloseHandle(h);
	return TRUE;
}
int main() {
	STARTUPINFO si = { sizeof(STARTUPINFO) };
	PROCESS_INFORMATION pi = { 0 };
	BOOL bRet = 0;
	OPENFILENAMEA stOF;
	HANDLE hFile;
	CHAR szFileName[MAX_PATH] = { 0 }; //Ҫ�򿪵��ļ�·����������
	CHAR szExtPe[] = "PE s\0*.exe;*.dll;*.bin;*.scr;*.fon;*.drv\0All s(*.*)\0*.*\0\0";
	RtlZeroMemory(&stOF, sizeof(stOF));
	stOF.lStructSize = sizeof(stOF);
	stOF.hwndOwner = NULL;
	stOF.lpstrFilter = szExtPe;
	stOF.lpstrFile = szFileName;
	stOF.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	stOF.lpstrInitialDir = "C:\\Users\\liuhailong\\Desktop\\Test_password";
	stOF.nMaxFile = MAX_PATH;
	stOF.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (GetOpenFileNameA(&stOF))		//���û�ѡ��򿪵��ļ�
	{
		::MessageBoxA(NULL, szFileName, "ѡ��", MB_OK);
	}
	else {
		::MessageBoxA(NULL, "error", " not found", MB_OK);
	}
	//2.�ȶ��ļ�����
	getlength(szFileName);
	CHAR TEMP[50] = { 0 };
	DWORD tmeplen = Llength + Hlength;
	sprintf(TEMP, "%d", tmeplen);
	::MessageBoxA(NULL, TEMP, "ѡ��", MB_OK);
	//2.�ȶ��ļ�����
	getlength(szFileName);
	//������
	check(szFileName);
	return 0;
}