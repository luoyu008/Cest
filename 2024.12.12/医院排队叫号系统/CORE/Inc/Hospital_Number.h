#ifndef __HOSPOTAL_NUMBER_H__
#define __HOSPOTAL_NUMBER_H__

typedef struct Hospital_List{
	struct Hospital_List* pre;
	uint16_t val;
	struct Hospital_List* next;
}HL;
//extern HL* List;
HL* Hospital_List_Init(void);
uint16_t Hospital_patient_Take(HL** List);
uint16_t Hospital_doctor_Take(HL** List);
#endif
