#ifndef __ADC_H__
#define __ADC_H__
extern ADC_HandleTypeDef ADC_ccscmodeHandInit;
extern DMA_HandleTypeDef DMA_ccscmodeHandInit;
extern ADC_ChannelConfTypeDef ADC_ccscmodeChannelInit;
extern uint16_t data[4];
void ADC_ccscmode(void);
//����ת����ɨ��ģʽ
extern ADC_HandleTypeDef ADC_onetimenoscmodeHandInit;
extern DMA_HandleTypeDef DMA_onetimescmodeHandInit;
extern ADC_ChannelConfTypeDef ADC_onetimenoscmodeChannelInit;
extern uint32_t Data;
extern uint8_t tc_state;
void ADC_onetime_noscmode(void);
void ADC_ENABLEDMA(void);
#endif
