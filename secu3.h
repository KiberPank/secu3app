
#ifndef _SECU3_H_
#define _SECU3_H_

#include "tables.h"

#define SEND_PACKET_INTERVAL_VALUE   4
#define SAVE_PARAM_TIMEOUT_VALUE     254
#define FORCE_MEASURE_TIMEOUT_VALUE  8
#define ENGINE_STOP_TIMEOUT_VALUE    25
#define CE_CONTROL_STATE_TIME_VALUE  50

//��������� ��� ����� ������� - �� ����������� � ������������ ��������
typedef struct
{
 unsigned int map;                                          //�������� �� �������� ���������� (�����������)
 unsigned int voltage;                                      //���������� �������� ���� (�����������)
 unsigned int temperat;                                     //����������� ����������� �������� (�����������)
 unsigned int frequen;                                      //������� �������� ��������� (�����������)
 unsigned int inst_frq;                                     //���������� ������� ��������
 unsigned char carb;                                        //��������� ��������� ����������� 
 unsigned char gas;                                         //��������� �������� ������� 
 unsigned int frequen4;                                     //������� ����������� ����� �� 4-� �������� 
}sensors;


//��������� ������ �������, ������������ ������ ��������� ������
typedef struct
{
 params           param;                                      //--���������
 sensors          sens;                                       //--�������
 unsigned char    ephh_valve;                                 //��������� ������� ����
 int              atmos_press;                                //����������� ��������
 unsigned char    airflow;                                    //������ �������
 signed int       curr_angle;                                 //������� ���� ����������
 __flash F_data*  fn_dat;                                     //��������� �� ����� �������������
}ecudata;                                     


#endif  //_SECU3_H_

