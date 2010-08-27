 /****************************************************************
 *       SECU-3  - An open source, free engine control unit
 *    Designed by Alexey A. Shabelnikov. Ukraine, Gorlovka 2007.
 *       Microprocessors systems - design & programming.
 *    contacts:
 *              http://secu-3.narod.ru
 *              ICQ: 405-791-931
 ****************************************************************/

/* ��������� ������������� ������ �������� ����� ���������� SECU-3
 *        ________________________
 *       |                        |
 *       |       ���              |   
 *       |                        |
 *       |------------------------|
 *       | ��������� ������������ | 
 *       |------------------------|<--- ����� ������ � ��������� ��������� � ����� ������
 *       | �������������� �����.  |
 *       |------------------------| 
 *       |  ���������  ���������  |
 *       |------------------------|
 *       |   ������ ������        |
 *       |                        |
 *       |------------------------|
 *       |     CRC16              |  - ����������� ����� �������� ��� ����� ���� ����  
 *       |________________________|    ����������� ����� � ������ ����������
 *       |                        |
 *       |  boot loader           |
 *        ------------------------
 */



#ifndef _TABLES_H_
#define _TABLES_H_

#include <stdint.h>
#include "bootldr.h"   //��� ���� ����� ����� �������� SECU3BOOTSTART, � ������

//���������� ���������� ����� ������������ ��� ������ �������
#define F_WRK_POINTS_F         16  
#define F_WRK_POINTS_L         16  
#define F_TMP_POINTS           16
#define F_STR_POINTS           16                            
#define F_IDL_POINTS           16     

#define F_NAME_SIZE            16

#define KC_ATTENUATOR_LOOKUP_TABLE_SIZE 128
#define FW_SIGNATURE_INFO_SIZE 48

//��������� ���� ��������� �������������, �������� ��� = 0.5 ����.
typedef struct F_data
{
  int8_t f_str[F_STR_POINTS];                       // ������� ��� �� ������
  int8_t f_idl[F_IDL_POINTS];                       // ������� ��� ��� ��
  int8_t f_wrk[F_WRK_POINTS_L][F_WRK_POINTS_F];     // �������� ������� ��� (3D)
  int8_t f_tmp[F_TMP_POINTS];                       // ������� �������. ��� �� �����������
  uint8_t name[F_NAME_SIZE];                        // ��������������� ��� (��� ���������)
}F_data;


//��������� �������������� ������ �������� � ��������
typedef struct FirmwareData
{
  uint8_t fw_signature_info[FW_SIGNATURE_INFO_SIZE];
  
  //������� �������� ����������� (����������� �� ��������).
  uint8_t attenuator_table[KC_ATTENUATOR_LOOKUP_TABLE_SIZE]; 
  
  //��� ����������������� ����� ���������� ��� ���������� �������� �������������
  //����� ������ �������� � ����� ������� ��������. ��� ���������� ����� ������
  //� ���������, ���������� ����������� ��� �����.
  uint8_t reserved[128];  
}FirmwareData;

//��������� ��������� �������
typedef struct params
{
  uint8_t  tmp_use;                      //������� ������������ ����-��
  uint8_t  carb_invers;                  //�������� ��������� �� �����������
  uint8_t  idl_regul;                    //������������ �������� ������� �� �������������� ���
  uint8_t  fn_benzin;                    //����� ������ ������������� ������������ ��� �������
  uint8_t  fn_gas;                       //����� ������ ������������� ������������ ��� ����
  uint16_t map_lower_pressure;           //������ ������� ��� �� ��� ������� (���)
  uint16_t ephh_lot;                     //������ ����� ���� (���-1)
  uint16_t ephh_hit;                     //������� ����� ���� (���-1)
  uint16_t starter_off;                  //����� ���������� �������� (���-1)
  int16_t  map_upper_pressure;           //������� �������� ��� �� ��� ������� (���)
  uint16_t smap_abandon;                 //������� �������� � �������� ����� �� �������  (���-1) 
  int16_t  max_angle;                    //����������� ������������� ���
  int16_t  min_angle;                    //����������� ������������ ���
  int16_t  angle_corr;                   //�����-��������� ���    
  uint16_t idling_rpm;                   //�������� ������� �� ��� ����������� �������������� ���   
  int16_t  ifac1;                        //������������ ���������� �������� ��, ��� ������������� �
  int16_t  ifac2;                        //������������� ������ ��������������.
  int16_t  MINEFR;                       //���� ������������������ ���������� (�������)
  int16_t  vent_on;                      //����������� ��������� �����������
  int16_t  vent_off;                     //����������� ���������� �����������  

  int16_t  map_adc_factor;               // �������� ��� ��������� ������������ ���
  int32_t  map_adc_correction;           //
  int16_t  ubat_adc_factor;              //
  int32_t  ubat_adc_correction;          //
  int16_t  temp_adc_factor;              //
  int32_t  temp_adc_correction;          //
  
  uint8_t  ckps_edge_type;                
  uint8_t  ckps_cogs_btdc;
  uint8_t  ckps_ignit_cogs;
  
  int16_t  angle_dec_spead;
  int16_t  angle_inc_spead;  
  int16_t  idlreg_min_angle;
  int16_t  idlreg_max_angle;
  uint16_t map_curve_offset;
  uint16_t map_curve_gradient;
  
  int16_t  epm_on_threshold;             //����� ��������� ������������ ���������� �������
  
  uint16_t ephh_lot_g;                   //������ ����� ���� (���)
  uint16_t ephh_hit_g;                   //������� ����� ���� (���)
  uint8_t  shutoff_delay;                //�������� ���������� �������
 
  uint16_t uart_divisor;                 //�������� ��� ��������������� �������� UART-a
  uint8_t  uart_period_t_ms;             //������ ������� ������� � �������� �����������
  
  uint8_t ckps_engine_cyl;               //���-�� ��������� ��������� 
  
  //--knock 
  uint8_t  knock_use_knock_channel;      //������� ������������� ������ ���������
  uint8_t  knock_bpf_frequency;          //����������� ������� ���������� �������
  int16_t  knock_k_wnd_begin_angle;      //������ �������������� ���� (�������)
  int16_t  knock_k_wnd_end_angle;        //����� �������������� ���� (�������)
  uint8_t  knock_int_time_const;         //���������� ������� �������������� (���)
  //--
  int16_t knock_retard_step;             //��� �������� ��� ��� ��������� 
  int16_t knock_advance_step;            //��� �������������� ��� 
  int16_t knock_max_retard;              //������������ �������� ���
  uint16_t knock_threshold;              //����� ��������� - ����������
  uint8_t knock_recovery_delay;          //�������� �������������� ��� � ������� ������ ���������
  //--/knock
  
  //��� ����������������� ����� ���������� ��� ���������� �������� �������������
  //����� ������ �������� � ����� ������� ��������. ��� ���������� ����� ������
  //� ���������, ���������� ����������� ��� �����.
  uint8_t  reserved[10];
  
  uint16_t crc;                         //����������� ����� ������ ���� ��������� (��� �������� ������������ ������ ����� ���������� �� EEPROM)  
}params;

//================================================================================
//���������� ������ ������ � �������� ������������ �� ����������

//������ ���������� ����������� ����� ���������� � ������
#define PAR_CRC_SIZE   sizeof(uint16_t) 

//������ ���������� ����������� ����� �������� � ������
#define CODE_CRC_SIZE   sizeof(uint16_t) 

//������ ���� ��������� ��� ����� ����������� �����
#define CODE_SIZE (SECU3BOOTSTART-CODE_CRC_SIZE)

//���������� ������� ������������� �������� � ������ ��������
#define TABLES_NUMBER          8   

//����� ����������� ����� � ��������
#define CODE_CRC_ADDR (SECU3BOOTSTART-CODE_CRC_SIZE)

//����� ������� ������ - �������� �������������
#define TABLES_START (CODE_CRC_ADDR-(sizeof(F_data)*TABLES_NUMBER))

//����� ��������� ���������� ���������� (���������� EEPROM �� ���������)
#define DEFPARAM_START (TABLES_START-sizeof(params))

//����� �������������� ����������
#define FIRMWARE_DATA_START (DEFPARAM_START-sizeof(FirmwareData))

//================================================================================



//�������������� ������ �� ���������
#pragma object_attribute=__root
FirmwareData __flash fwdata@FIRMWARE_DATA_START=
{
  //����� ���� ������ ������ ���� ����� FW_SIGNATURE_INFO_SIZE.  
  //���� � ������� Mmm dd yyyy.
  "SECU-3 firmware v2.3. Build ["__DATE__"]       ",
   
  //������� �����������, �� ��������� k = 1.000
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,
  0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E,0x0E
};

//������ � �������� �� ���������
#pragma object_attribute=__root
F_data __flash tables[TABLES_NUMBER]@TABLES_START=
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,  //�������� �����
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,  //�� �����

0x04,0x05,0x06,0x07,0x0A,0x0C,0x10,0x15,0x1A,0x20,0x24,0x27,0x28,0x28,0x28,0x28,  //����� ��������� ������
0x04,0x05,0x06,0x08,0x0B,0x0D,0x10,0x16,0x1B,0x21,0x26,0x29,0x2A,0x2A,0x2A,0x2A,
0x04,0x05,0x08,0x08,0x0C,0x0E,0x12,0x18,0x1E,0x23,0x28,0x2A,0x2C,0x2C,0x2C,0x2C,
0x04,0x06,0x08,0x0A,0x0C,0x10,0x14,0x1B,0x21,0x26,0x28,0x2A,0x2C,0x2C,0x2C,0x2D,
0x06,0x07,0x0A,0x0C,0x0E,0x12,0x18,0x20,0x26,0x2A,0x2C,0x2D,0x2E,0x2E,0x2F,0x30,
0x08,0x08,0x0A,0x0E,0x12,0x16,0x1E,0x27,0x2D,0x2F,0x30,0x31,0x33,0x34,0x35,0x36,
0x0A,0x0B,0x0D,0x10,0x14,0x1B,0x24,0x2D,0x32,0x33,0x35,0x37,0x39,0x3A,0x3A,0x3B,
0x0C,0x10,0x12,0x15,0x1A,0x21,0x29,0x32,0x36,0x37,0x39,0x3C,0x3E,0x40,0x40,0x40,
0x10,0x16,0x18,0x1C,0x22,0x28,0x2E,0x36,0x3A,0x3B,0x3D,0x3F,0x41,0x44,0x44,0x44,
0x16,0x1C,0x1E,0x22,0x27,0x2E,0x34,0x3A,0x3D,0x3E,0x40,0x42,0x44,0x48,0x48,0x48,
0x1C,0x21,0x22,0x26,0x2A,0x31,0x38,0x3F,0x41,0x42,0x44,0x45,0x48,0x4A,0x4A,0x4B,
0x1E,0x22,0x24,0x27,0x2B,0x33,0x3B,0x42,0x45,0x45,0x47,0x48,0x4A,0x4C,0x4C,0x4C,
0x20,0x24,0x26,0x29,0x2E,0x36,0x3D,0x45,0x47,0x47,0x48,0x49,0x4A,0x4C,0x4C,0x4D,
0x20,0x24,0x27,0x2B,0x31,0x37,0x3F,0x45,0x47,0x48,0x49,0x49,0x4B,0x4D,0x4D,0x4D,
0x1E,0x22,0x26,0x2C,0x31,0x39,0x40,0x46,0x48,0x4A,0x4A,0x4B,0x4D,0x4E,0x4E,0x4E,
0x1E,0x21,0x25,0x29,0x2F,0x36,0x3F,0x45,0x49,0x4B,0x4C,0x4D,0x4F,0x4F,0x4F,0x4F,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC, //����� ������������� ��������� ���
'2','1','0','8','3',' ','�','�','�','�','�','�','�','�',' ',' ',

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,

0x09,0x09,0x09,0x09,0x11,0x14,0x1A,0x20,0x26,0x24,0x30,0x33,0x3B,0x43,0x45,0x45,
0x09,0x09,0x09,0x09,0x11,0x14,0x1A,0x20,0x26,0x24,0x30,0x33,0x3B,0x43,0x45,0x45,
0x09,0x09,0x09,0x09,0x11,0x14,0x1A,0x20,0x26,0x24,0x30,0x33,0x3B,0x43,0x45,0x45,
0x09,0x09,0x09,0x09,0x13,0x14,0x1A,0x20,0x26,0x26,0x32,0x33,0x3F,0x43,0x45,0x45,
0x09,0x09,0x09,0x0A,0x13,0x16,0x1C,0x22,0x28,0x2F,0x39,0x3B,0x3F,0x47,0x49,0x49,
0x09,0x09,0x09,0x0B,0x15,0x28,0x2C,0x35,0x3A,0x41,0x42,0x43,0x45,0x45,0x4B,0x4B,
0x0B,0x0D,0x17,0x1D,0x25,0x2D,0x33,0x38,0x3F,0x45,0x4A,0x48,0x48,0x48,0x4A,0x4C,
0x16,0x1A,0x22,0x26,0x2D,0x33,0x39,0x3D,0x46,0x48,0x4D,0x4A,0x4A,0x4A,0x4A,0x50,
0x21,0x27,0x2F,0x35,0x33,0x36,0x3D,0x41,0x49,0x4B,0x4F,0x4C,0x4C,0x4C,0x4A,0x52,
0x28,0x2E,0x3A,0x3A,0x37,0x37,0x3D,0x45,0x4C,0x4D,0x4F,0x4F,0x4F,0x52,0x52,0x56,
0x2E,0x38,0x3E,0x40,0x38,0x37,0x45,0x49,0x4E,0x4F,0x51,0x50,0x50,0x54,0x58,0x58,
0x30,0x3E,0x42,0x40,0x38,0x3D,0x47,0x4F,0x52,0x50,0x4F,0x4E,0x4E,0x54,0x54,0x5A,
0x32,0x40,0x46,0x48,0x48,0x49,0x4B,0x4E,0x51,0x52,0x4E,0x4D,0x4B,0x54,0x58,0x58,
0x2E,0x3C,0x40,0x42,0x46,0x41,0x47,0x4B,0x4E,0x4E,0x4E,0x4D,0x45,0x54,0x54,0x56,
0x28,0x32,0x36,0x38,0x36,0x39,0x43,0x49,0x4B,0x4E,0x48,0x48,0x49,0x50,0x54,0x54,
0x24,0x28,0x28,0x28,0x30,0x35,0x3F,0x47,0x4B,0x4E,0x47,0x46,0x48,0x4C,0x50,0x50,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC,
'2','1','0','8','3',' ','�','�','�','�','�','�','�','�','�','�',

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,

0x0C,0x0C,0x0E,0x10,0x11,0x12,0x14,0x16,0x1B,0x1D,0x1F,0x21,0x22,0x24,0x27,0x27,
0x0E,0x0E,0x10,0x11,0x12,0x13,0x15,0x17,0x1C,0x20,0x24,0x25,0x26,0x26,0x29,0x29,
0x10,0x10,0x12,0x14,0x15,0x16,0x17,0x19,0x1E,0x22,0x26,0x27,0x29,0x28,0x2C,0x2C,
0x12,0x12,0x14,0x16,0x17,0x17,0x18,0x1D,0x21,0x26,0x2A,0x2B,0x2C,0x2D,0x2F,0x2F,
0x14,0x14,0x16,0x18,0x19,0x1B,0x23,0x2E,0x30,0x30,0x30,0x30,0x31,0x33,0x33,0x33,
0x16,0x16,0x18,0x1A,0x1B,0x23,0x2A,0x32,0x3C,0x3A,0x3A,0x3A,0x3B,0x38,0x38,0x38,
0x18,0x18,0x1A,0x1E,0x23,0x26,0x32,0x3A,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,0x3F,
0x1B,0x1B,0x20,0x20,0x24,0x2C,0x36,0x40,0x43,0x43,0x43,0x43,0x43,0x46,0x46,0x46,
0x1E,0x1E,0x20,0x22,0x26,0x2C,0x38,0x42,0x46,0x47,0x47,0x47,0x47,0x48,0x49,0x49,
0x1E,0x1E,0x20,0x22,0x26,0x32,0x3C,0x45,0x47,0x48,0x48,0x48,0x49,0x4A,0x4B,0x4B,
0x1E,0x1E,0x20,0x22,0x26,0x34,0x40,0x48,0x4A,0x4A,0x4A,0x4A,0x4A,0x4C,0x4C,0x4C,
0x1E,0x24,0x28,0x30,0x36,0x3C,0x42,0x48,0x4C,0x4C,0x4C,0x4C,0x4C,0x4E,0x4E,0x4E,
0x1B,0x24,0x28,0x30,0x36,0x3C,0x42,0x48,0x4C,0x4C,0x4C,0x4C,0x4C,0x4E,0x4E,0x4E,
0x19,0x24,0x28,0x30,0x36,0x3C,0x42,0x46,0x4A,0x4A,0x4A,0x4A,0x4A,0x4B,0x4B,0x4B,
0x17,0x24,0x28,0x30,0x36,0x3C,0x42,0x46,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,0x4A,
0x15,0x24,0x28,0x30,0x36,0x3C,0x42,0x43,0x43,0x43,0x43,0x44,0x45,0x49,0x49,0x49,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC,
'�','�','�','�','�','�','�','�',' ','1','.','5',' ',' ',' ',' ',

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,

0x14,0x15,0x17,0x19,0x1B,0x1D,0x20,0x24,0x29,0x2D,0x2F,0x31,0x33,0x35,0x20,0x20,
0x16,0x18,0x1A,0x1C,0x1E,0x20,0x23,0x27,0x2C,0x31,0x34,0x36,0x38,0x3A,0x20,0x20,
0x18,0x1A,0x1C,0x1E,0x21,0x24,0x28,0x2D,0x33,0x38,0x3C,0x3E,0x3F,0x41,0x20,0x20,
0x1A,0x1C,0x1E,0x21,0x24,0x28,0x2D,0x33,0x39,0x3F,0x43,0x45,0x46,0x47,0x20,0x20,
0x1C,0x1E,0x20,0x23,0x26,0x2B,0x31,0x39,0x40,0x46,0x49,0x4A,0x4B,0x4C,0x20,0x20,
0x1E,0x20,0x22,0x25,0x29,0x30,0x36,0x3E,0x46,0x4D,0x51,0x52,0x52,0x52,0x20,0x20,
0x20,0x22,0x24,0x28,0x2C,0x34,0x3A,0x42,0x4A,0x51,0x55,0x57,0x58,0x59,0x20,0x20,
0x22,0x24,0x28,0x2C,0x30,0x38,0x3E,0x46,0x4E,0x54,0x59,0x5B,0x5D,0x5E,0x1C,0x1C,
0x24,0x28,0x2C,0x30,0x34,0x3D,0x42,0x49,0x51,0x57,0x5C,0x5E,0x5F,0x5F,0x18,0x18,
0x26,0x2A,0x2E,0x32,0x38,0x40,0x44,0x4B,0x53,0x59,0x5E,0x5F,0x5F,0x5F,0x14,0x14,
0x28,0x2C,0x2E,0x32,0x3A,0x42,0x46,0x4C,0x54,0x5A,0x5E,0x5F,0x5F,0x5F,0x10,0x10,
0x28,0x2C,0x2E,0x32,0x3A,0x42,0x48,0x4C,0x54,0x5A,0x5E,0x5F,0x5F,0x5F,0x10,0x10,
0x24,0x24,0x24,0x24,0x2C,0x42,0x48,0x4C,0x54,0x5A,0x5C,0x5E,0x5F,0x5F,0x10,0x10,
0x24,0x24,0x24,0x24,0x2C,0x42,0x48,0x4C,0x54,0x5A,0x5C,0x5E,0x5F,0x5F,0x10,0x10,
0x24,0x24,0x24,0x24,0x2C,0x40,0x46,0x48,0x50,0x54,0x56,0x58,0x58,0x58,0x10,0x10,
0x24,0x24,0x24,0x24,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x2C,0x10,0x10,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC,
'�','�','�','�','�','�','�','�',' ','1','.','6',' ',' ',' ',' ',

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,

0x04,0x04,0x04,0x06,0x12,0x12,0x18,0x1C,0x22,0x28,0x2E,0x32,0x38,0x40,0x42,0x42,
0x04,0x04,0x04,0x06,0x12,0x12,0x18,0x1E,0x22,0x28,0x30,0x32,0x38,0x40,0x42,0x42,
0x04,0x04,0x04,0x06,0x12,0x14,0x1A,0x20,0x24,0x28,0x30,0x32,0x3A,0x40,0x42,0x42,
0x04,0x04,0x06,0x06,0x12,0x16,0x1C,0x24,0x28,0x2C,0x30,0x34,0x3C,0x40,0x42,0x42,
0x04,0x06,0x08,0x08,0x12,0x18,0x20,0x28,0x2C,0x32,0x36,0x3A,0x3C,0x44,0x46,0x46,
0x08,0x08,0x0A,0x0B,0x14,0x24,0x28,0x32,0x38,0x3E,0x40,0x40,0x42,0x44,0x48,0x48,
0x08,0x0C,0x16,0x19,0x21,0x2A,0x30,0x38,0x40,0x44,0x48,0x48,0x48,0x48,0x48,0x4A,
0x12,0x16,0x1E,0x22,0x29,0x30,0x36,0x3C,0x44,0x47,0x4A,0x4A,0x4A,0x4A,0x4A,0x4E,
0x1D,0x23,0x2B,0x31,0x2F,0x33,0x3A,0x40,0x48,0x4A,0x4C,0x4C,0x4C,0x4C,0x4C,0x50,
0x24,0x2A,0x36,0x36,0x33,0x34,0x3E,0x44,0x4A,0x4C,0x4C,0x4E,0x4E,0x50,0x50,0x54,
0x2A,0x34,0x3A,0x3C,0x34,0x34,0x42,0x48,0x4C,0x4E,0x4E,0x4E,0x4E,0x52,0x54,0x56,
0x2C,0x3A,0x3E,0x40,0x38,0x3A,0x44,0x4E,0x50,0x50,0x4E,0x4E,0x4C,0x52,0x54,0x58,
0x2E,0x3C,0x42,0x44,0x44,0x46,0x48,0x4C,0x50,0x50,0x4C,0x4C,0x4C,0x52,0x54,0x56,
0x2A,0x38,0x3C,0x3E,0x42,0x42,0x44,0x4A,0x4B,0x4C,0x4C,0x4B,0x48,0x52,0x52,0x54,
0x24,0x2E,0x32,0x34,0x32,0x36,0x40,0x48,0x48,0x4C,0x46,0x46,0x48,0x4E,0x52,0x52,
0x20,0x24,0x24,0x24,0x2C,0x32,0x3C,0x46,0x48,0x4B,0x44,0x44,0x46,0x4A,0x4E,0x4E,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC,
'�','�','�','�',' ','1','.','7',' ',' ',' ',' ',' ',' ',' ',' ',

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,

0x12,0x14,0x14,0x16,0x1E,0x22,0x2C,0x32,0x34,0x36,0x3A,0x3E,0x44,0x44,0x44,0x39,
0x12,0x14,0x14,0x16,0x1F,0x22,0x2C,0x34,0x37,0x38,0x3B,0x3E,0x44,0x44,0x44,0x39,
0x12,0x14,0x14,0x16,0x20,0x23,0x2C,0x36,0x38,0x3A,0x3E,0x3E,0x44,0x44,0x44,0x39,
0x17,0x19,0x1A,0x1D,0x21,0x26,0x2C,0x3C,0x3E,0x3E,0x41,0x44,0x46,0x46,0x48,0x39,
0x14,0x16,0x16,0x1F,0x28,0x31,0x3A,0x3E,0x40,0x3E,0x44,0x45,0x46,0x46,0x46,0x39,
0x1C,0x1D,0x1E,0x1F,0x27,0x38,0x40,0x43,0x42,0x44,0x46,0x48,0x4C,0x4D,0x4C,0x39,
0x18,0x1A,0x22,0x2C,0x35,0x3C,0x46,0x48,0x4A,0x4A,0x48,0x4C,0x4E,0x4F,0x50,0x39,
0x1A,0x1E,0x2B,0x34,0x3A,0x43,0x49,0x4B,0x4C,0x4C,0x4C,0x4E,0x4E,0x4E,0x50,0x45,
0x20,0x24,0x2C,0x36,0x43,0x48,0x4C,0x4E,0x4E,0x4E,0x4E,0x50,0x50,0x52,0x50,0x4E,
0x26,0x2A,0x36,0x48,0x4E,0x53,0x54,0x56,0x56,0x56,0x56,0x58,0x52,0x56,0x50,0x54,
0x2C,0x2E,0x3C,0x46,0x50,0x52,0x56,0x56,0x58,0x5A,0x56,0x58,0x5A,0x5C,0x5E,0x5A,
0x2C,0x30,0x3A,0x3C,0x48,0x52,0x54,0x58,0x5A,0x5E,0x5A,0x5E,0x60,0x5E,0x5E,0x5A,
0x2C,0x2E,0x2E,0x3C,0x4A,0x53,0x58,0x58,0x5E,0x5E,0x5E,0x5E,0x65,0x65,0x64,0x5A,
0x2C,0x2C,0x2C,0x3A,0x54,0x56,0x5A,0x5A,0x5C,0x5E,0x60,0x5F,0x64,0x64,0x62,0x5A,
0x2C,0x2C,0x2F,0x2E,0x2E,0x4E,0x54,0x58,0x5B,0x5E,0x5F,0x61,0x63,0x63,0x62,0x5A,
0x2C,0x2C,0x2C,0x2C,0x2E,0x4A,0x51,0x54,0x58,0x5C,0x5F,0x61,0x62,0x62,0x62,0x5A,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC,
'�','�','�','�',' ','1','.','8',' ',' ',' ',' ',' ',' ',' ',' ',

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,

0x15,0x15,0x15,0x15,0x10,0x02,0x02,0x05,0x0E,0x12,0x18,0x21,0x2A,0x2A,0x2A,0x2A,
0x15,0x15,0x15,0x15,0x10,0x02,0x0C,0x12,0x15,0x18,0x1E,0x24,0x2E,0x2E,0x2E,0x2E,
0x15,0x15,0x15,0x15,0x12,0x05,0x15,0x21,0x2A,0x2E,0x2E,0x31,0x31,0x31,0x31,0x31,
0x15,0x15,0x15,0x15,0x1B,0x15,0x1B,0x24,0x2E,0x31,0x37,0x3A,0x3E,0x2E,0x2E,0x2E,
0x15,0x15,0x15,0x1E,0x22,0x1B,0x28,0x31,0x34,0x37,0x3E,0x41,0x41,0x2E,0x2E,0x2E,
0x15,0x15,0x1B,0x28,0x24,0x22,0x2A,0x31,0x34,0x3A,0x3E,0x40,0x44,0x2E,0x2E,0x2E,
0x15,0x15,0x1E,0x31,0x2B,0x28,0x2E,0x31,0x3A,0x3A,0x40,0x44,0x44,0x2E,0x2E,0x2E,
0x15,0x15,0x18,0x3A,0x34,0x2B,0x31,0x34,0x3A,0x3B,0x40,0x44,0x4A,0x31,0x31,0x31,
0x15,0x15,0x22,0x37,0x2E,0x2E,0x31,0x34,0x37,0x3A,0x44,0x47,0x4D,0x2E,0x2E,0x2E,
0x15,0x15,0x22,0x3D,0x37,0x31,0x37,0x37,0x3A,0x44,0x47,0x4A,0x50,0x31,0x31,0x31,
0x18,0x18,0x24,0x40,0x34,0x31,0x34,0x37,0x3A,0x3E,0x47,0x53,0x54,0x2E,0x2E,0x2E,
0x18,0x18,0x18,0x31,0x40,0x34,0x37,0x3A,0x3E,0x44,0x50,0x4D,0x31,0x31,0x31,0x31,
0x15,0x15,0x18,0x2B,0x44,0x34,0x34,0x3A,0x3E,0x44,0x4A,0x4D,0x4D,0x2E,0x2E,0x2E,
0x15,0x15,0x18,0x2B,0x44,0x34,0x34,0x3A,0x3E,0x44,0x4A,0x4D,0x4D,0x2E,0x2E,0x2E,
0x15,0x15,0x18,0x2B,0x44,0x34,0x34,0x3A,0x3E,0x44,0x4A,0x4D,0x4D,0x2E,0x2E,0x2E,
0x15,0x15,0x18,0x2B,0x44,0x34,0x34,0x3A,0x3E,0x44,0x4A,0x4D,0x4D,0x2E,0x2E,0x2E,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC,
'�','�','�','�','3','3','1',' ',' ',' ',' ',' ',' ',' ',' ',' ',

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x08,0x0C,0x10,0x14,0x14,0x14,
0x0A,0x0A,0x0A,0x00,0x00,0x00,0x00,0x0A,0x19,0x28,0x37,0x37,0x37,0x37,0x37,0x37,

0x14,0x14,0x14,0x14,0x14,0x01,0x01,0x07,0x0E,0x1A,0x1A,0x1E,0x27,0x27,0x27,0x27,
0x14,0x14,0x14,0x14,0x14,0x01,0x0E,0x17,0x1A,0x1E,0x21,0x21,0x27,0x27,0x27,0x27,
0x14,0x14,0x14,0x14,0x14,0x11,0x17,0x27,0x27,0x2C,0x2C,0x2D,0x2D,0x27,0x27,0x27,
0x14,0x14,0x14,0x14,0x14,0x1E,0x1E,0x27,0x2A,0x30,0x34,0x36,0x3C,0x27,0x27,0x27,
0x17,0x17,0x17,0x1E,0x21,0x24,0x27,0x2D,0x34,0x34,0x3A,0x3D,0x3D,0x27,0x27,0x27,
0x21,0x21,0x21,0x27,0x2E,0x27,0x2A,0x30,0x34,0x34,0x3A,0x3D,0x40,0x27,0x27,0x27,
0x2D,0x2D,0x30,0x34,0x36,0x30,0x2A,0x30,0x34,0x36,0x3A,0x3C,0x40,0x27,0x27,0x27,
0x34,0x34,0x34,0x3A,0x30,0x2A,0x2D,0x34,0x3A,0x3A,0x3D,0x40,0x43,0x27,0x27,0x27,
0x36,0x36,0x36,0x3A,0x36,0x34,0x30,0x34,0x36,0x3A,0x3C,0x43,0x49,0x27,0x27,0x27,
0x3A,0x3A,0x3A,0x3A,0x3A,0x30,0x34,0x34,0x36,0x3C,0x43,0x46,0x49,0x27,0x27,0x27,
0x21,0x21,0x21,0x40,0x40,0x34,0x34,0x34,0x3A,0x3D,0x43,0x4C,0x50,0x27,0x27,0x27,
0x17,0x17,0x1A,0x2D,0x2D,0x2D,0x30,0x36,0x3A,0x3C,0x43,0x4C,0x49,0x27,0x27,0x27,
0x17,0x17,0x17,0x1E,0x1E,0x1E,0x30,0x36,0x3C,0x40,0x46,0x4C,0x49,0x27,0x27,0x27,
0x17,0x17,0x17,0x1E,0x1E,0x1E,0x30,0x36,0x3C,0x40,0x46,0x4C,0x49,0x27,0x27,0x27,
0x17,0x17,0x17,0x1E,0x1E,0x1E,0x30,0x36,0x3C,0x40,0x46,0x4C,0x49,0x27,0x27,0x27,
0x17,0x17,0x17,0x1E,0x1E,0x1E,0x30,0x36,0x3C,0x40,0x46,0x4C,0x49,0x27,0x27,0x27,

0x22,0x1C,0x19,0x16,0x13,0x0F,0x0C,0x0A,0x07,0x05,0x02,0x00,0x00,0xFD,0xF6,0xEC,
'�','�','�','�','3','3','1','7',' ',' ',' ',' ',' ',' ',' ',' '
};

//��������� ���������
#pragma object_attribute=__root
params __flash def_param@DEFPARAM_START = 
{1,0,0,6,6,1920,1250,1500,600,6400,650,1600,-320,0,800,4,4,10,392,384,16384,8192,16384,8192,16384,8192,0,20,10,
 96,96,-320,320,240,410,392,1250,1500,0, 0x0067,8, 4, 0,35,0,800,23,128,8,512,1000,2, 0,0,0,0,0,0,0,0,0,0,/*crc*/0};                                         

#pragma object_attribute=__root
uint16_t __flash code_crc@CODE_CRC_ADDR = 0x0000;

#endif //_TABLES_H_
