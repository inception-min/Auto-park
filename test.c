/*******************************************************************************
*                (c) Copyright Foshan AndYu Technology Co. Ltd
*                         All rights reserved.
*
* File Name：   BlockMove.c
*
* Description:
Description:
*
********************************************************************************/
#include "Public.h"



int BlockMove_NextScanPosY_L, BlockMove_NextScanPosY_R;		//下一个扫描移动点
int BlockMove_Edge_StartIndex;	//边缘数据长度管理



void BlockMove_Process(int iOffset)
{
#if 0	//804us，static会使效率严重变低
	static u16 *pSourceEdge;
	static u16 *pTargetEdge;
	static u16 *pEndEdge;
	static u16 *pSourcePath;
	static u16 *pTargetPath;
#else	//115us
	int *pSourceEdgeL;
	int *pTargetEdgeL;
	int *pSourcePathL;
	int *pTargetPathL;
	int *pSourceEdgeR;
	int *pTargetEdgeR;
	int *pSourcePathR;
	int *pTargetPathR;
	int *pEndEdge;
#endif
#if (BLOCK_SIMULATE || BLOCK_REAL_TEST)
    int i;
    //memset(&uwRxRadarIndex[iOffset],0,(BLOCK_EDGE_LENGTH_MAX-iOffset) *sizeof(uwRxRadarIndex[0]));
    for(i=0;i<(BLOCK_EDGE_LENGTH_MAX-iOffset);i++)
    {
        uwRxRadarIndex[i] = uwRxRadarIndex[iOffset+i];
    }

    for(i=BLOCK_EDGE_LENGTH_MAX-iOffset;i<BLOCK_EDGE_LENGTH_MAX;i++)
    {
        uwRxRadarIndex[i] = 0;
    }
#endif

	pTargetEdgeL = &BlockEdgeDataL[0];
	pTargetPathL = &BlockPathDataL[0];
	pSourceEdgeL = &BlockEdgeDataL[iOffset];
	pSourcePathL = &BlockPathDataL[iOffset];
	pTargetEdgeR = &BlockEdgeDataR[0];
	pTargetPathR = &BlockPathDataR[0];
	pSourceEdgeR = &BlockEdgeDataR[iOffset];
	pSourcePathR = &BlockPathDataR[iOffset];

//	pEndEdge = &BlockEdgeDataR[BLOCK_EDGE_LENGTH_MAX-iOffset];
	pEndEdge = &BlockEdgeDataR[BLOCK_EDGE_LENGTH_MAX];
//	while(pTargetEdgeR <= pEndEdge)
	while(pSourceEdgeR < pEndEdge)
	{	//一个循环复制多次，以节省循环本身耗费的时间，可大幅提速（运行此函数总耗时：复制20次耗455.5us）
		//L
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 1
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 2
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 3
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 4
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 5
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 6
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 7
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 8
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 9
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 10
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 11
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 12
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 13
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 14
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 15
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 16
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 17
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 18
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 19
		{*pTargetEdgeL = *pSourceEdgeL;	pTargetEdgeL++;	pSourceEdgeL++;}	// 20

		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 1
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 2
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 3
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 4
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 5
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 6
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 7
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 8
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 9
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 10
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 11
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 12
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 13
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 14
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 15
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 16
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 17
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 18
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 19
		{*pTargetPathL = *pSourcePathL;	pTargetPathL++;	pSourcePathL++;}	// 20

		//R
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 1
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 2
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 3
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 4
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 5
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 6
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 7
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 8
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 9
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 10
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 11
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 12
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 13
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 14
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 15
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 16
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 17
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 18
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 19
		{*pTargetEdgeR = *pSourceEdgeR;	pTargetEdgeR++;	pSourceEdgeR++;}	// 20

		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 1
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 2
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 3
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 4
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 5
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 6
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 7
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 8
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 9
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 10
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 11
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 12
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 13
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 14
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 15
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 16
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 17
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 18
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 19
		{*pTargetPathR = *pSourcePathR;	pTargetPathR++;	pSourcePathR++;}	// 20
	}
	pTargetEdgeL = &BlockEdgeDataL[BLOCK_EDGE_LENGTH_MAX-iOffset];
	pTargetPathL = &BlockPathDataL[BLOCK_EDGE_LENGTH_MAX-iOffset];
	pTargetEdgeR = &BlockEdgeDataR[BLOCK_EDGE_LENGTH_MAX-iOffset];
	pTargetPathR = &BlockPathDataR[BLOCK_EDGE_LENGTH_MAX-iOffset];
//	pTargetEdgeL = &BlockEdgeDataL[BLOCK_EDGE_LENGTH_MAX-cm2w(150)];
//	pTargetPathL = &BlockPathDataL[BLOCK_EDGE_LENGTH_MAX-cm2w(150)];
//	pTargetEdgeR = &BlockEdgeDataR[BLOCK_EDGE_LENGTH_MAX-cm2w(150)];
//	pTargetPathR = &BlockPathDataR[BLOCK_EDGE_LENGTH_MAX-cm2w(150)];
	pEndEdge = &BlockEdgeDataR[BLOCK_EDGE_LENGTH_MAX];
	while(pTargetEdgeR < pEndEdge)
	{	//后续数据填零
		//L
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 1
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 2
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 3
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 4
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 5
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 6
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 7
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 8
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 9
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 10
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 11
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 12
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 13
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 14
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 15
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 16
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 17
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 18
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 19
		{*pTargetEdgeL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeL++;}	// 20

		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 1
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 2
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 3
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 4
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 5
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 6
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 7
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 8
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 9
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 10
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 11
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 12
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 13
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 14
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 15
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 16
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 17
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 18
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 19
		{*pTargetPathL = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathL++;}	// 20

		//R
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 1
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 2
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 3
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 4
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 5
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 6
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 7
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 8
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 9
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 10
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 11
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 12
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 13
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 14
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 15
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 16
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 17
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 18
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 19
		{*pTargetEdgeR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetEdgeR++;}	// 20

		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 1
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 2
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 3
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 4
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 5
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 6
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 7
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 8
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 9
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 10
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 11
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 12
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 13
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 14
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 15
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 16
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 17
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 18
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 19
		{*pTargetPathR = BLOCK_EDGE_WIDTH_DISABLE;	pTargetPathR++;}	// 20
	}
}


void BlockMove_MiddleTask(void)
{
	int iStartIndex, iEndIndex, iIndex, rOffset;

	rOffset = BLOCKMOVE_MIDDLE_CENTRE - (int)CarData.AX;

	SensorPosStartFRX				+= rOffset;
	SensorPositionFRX				+= rOffset;
	SensorPosFinishFRX				+= rOffset;

	if(Block_EdgeR_Park_OutsideX > 0)
		Block_EdgeR_Park_OutsideX	+= rOffset;
	if(Block_EdgeR_Park_InsideX > 0)
		Block_EdgeR_Park_InsideX	+= rOffset;

	SensorPosStartFLX				+= rOffset;
	SensorPositionFLX				+= rOffset;
	SensorPosFinishFLX				+= rOffset;

	if(Block_EdgeL_Park_OutsideX > 0)
		Block_EdgeL_Park_OutsideX	+= rOffset;
	if(Block_EdgeL_Park_InsideX > 0)
		Block_EdgeL_Park_InsideX	+= rOffset;

#if 1	//移动车体
	CarData.AX				+= rOffset;
	CarData.BodyFLX			+= rOffset;
	CarData.BodyFRX			+= rOffset;
	CarData.BodyRLX			+= rOffset;
	CarData.BodyRRX			+= rOffset;
	CarData.BodyCX			+= rOffset;
	CarData.WheelFLX		+= rOffset;
	CarData.WheelFRX		+= rOffset;
	CarData.WheelRLX		+= rOffset;
	CarData.WheelRRX		+= rOffset;
	CarData.RotateCentreX	+= rOffset;
#endif

	if(Block_ParkHL_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{
		Block_ParkHL_Data.AFOX		+= rOffset;
		Block_ParkHL_Data.AFIX		+= rOffset;
		Block_ParkHL_Data.AFX		+= rOffset;
		Block_ParkHL_Data.AROX		+= rOffset;
		Block_ParkHL_Data.ARIX		+= rOffset;
		Block_ParkHL_Data.ARX		+= rOffset;

		Block_ParkHL_Data.OFX		+= rOffset;
		Block_ParkHL_Data.IFX		+= rOffset;
		Block_ParkHL_Data.ORX		+= rOffset;
		Block_ParkHL_Data.IRX		+= rOffset;

		if(Block_ParkHLt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkHLt_Data.AFOX		+= rOffset;
			Block_ParkHLt_Data.AFIX		+= rOffset;
			Block_ParkHLt_Data.AFX		+= rOffset;
			Block_ParkHLt_Data.AROX		+= rOffset;
			Block_ParkHLt_Data.ARIX		+= rOffset;
			Block_ParkHLt_Data.ARX		+= rOffset;
		   //临时车位
			Block_ParkHLt_Data.OFX		+= rOffset;
			Block_ParkHLt_Data.IFX		+= rOffset;
			Block_ParkHLt_Data.ORX		+= rOffset;
			Block_ParkHLt_Data.IRX		+= rOffset;
		}
	}
	if(Block_ParkHR_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{
		Block_ParkHR_Data.AFOX		+= rOffset;
		Block_ParkHR_Data.AFIX		+= rOffset;
		Block_ParkHR_Data.AFX		+= rOffset;
		Block_ParkHR_Data.AROX		+= rOffset;
		Block_ParkHR_Data.ARIX		+= rOffset;
		Block_ParkHR_Data.ARX		+= rOffset;

		Block_ParkHR_Data.OFX		+= rOffset;
		Block_ParkHR_Data.IFX		+= rOffset;
		Block_ParkHR_Data.ORX		+= rOffset;
		Block_ParkHR_Data.IRX		+= rOffset;

		if(Block_ParkHRt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkHRt_Data.AFOX		+= rOffset;
			Block_ParkHRt_Data.AFIX		+= rOffset;
			Block_ParkHRt_Data.AFX		+= rOffset;
			Block_ParkHRt_Data.AROX		+= rOffset;
			Block_ParkHRt_Data.ARIX		+= rOffset;
			Block_ParkHRt_Data.ARX		+= rOffset;
		   //临时车位
			Block_ParkHRt_Data.OFX		+= rOffset;
			Block_ParkHRt_Data.IFX		+= rOffset;
			Block_ParkHRt_Data.ORX		+= rOffset;
			Block_ParkHRt_Data.IRX		+= rOffset;
		}
	}
	if(Block_ParkER_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{

		Block_ParkER_Data.AFOX		+= rOffset;
		Block_ParkER_Data.AFIX		+= rOffset;
		Block_ParkER_Data.AFX		+= rOffset;
		Block_ParkER_Data.AROX		+= rOffset;
		Block_ParkER_Data.ARIX		+= rOffset;
		Block_ParkER_Data.ARX		+= rOffset;

		Block_ParkER_Data.OFX		+= rOffset;
		Block_ParkER_Data.IFX		+= rOffset;
		Block_ParkER_Data.ORX		+= rOffset;
		Block_ParkER_Data.IRX		+= rOffset;

		if(Block_ParkERt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkERt_Data.AFOX		+= rOffset;
			Block_ParkERt_Data.AFIX		+= rOffset;
			Block_ParkERt_Data.AFX		+= rOffset;
			Block_ParkERt_Data.AROX		+= rOffset;
			Block_ParkERt_Data.ARIX		+= rOffset;
			Block_ParkERt_Data.ARX		+= rOffset;
		   //临时车位
			Block_ParkERt_Data.OFX		+= rOffset;
			Block_ParkERt_Data.IFX		+= rOffset;
			Block_ParkERt_Data.ORX		+= rOffset;
			Block_ParkERt_Data.IRX		+= rOffset;
		}
	}
	if(Block_ParkEL_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{

		Block_ParkEL_Data.AFOX		+= rOffset;
		Block_ParkEL_Data.AFIX		+= rOffset;
		Block_ParkEL_Data.AFX		+= rOffset;
		Block_ParkEL_Data.AROX		+= rOffset;
		Block_ParkEL_Data.ARIX		+= rOffset;
		Block_ParkEL_Data.ARX		+= rOffset;

		Block_ParkEL_Data.OFX		+= rOffset;
		Block_ParkEL_Data.IFX		+= rOffset;
		Block_ParkEL_Data.ORX		+= rOffset;
		Block_ParkEL_Data.IRX		+= rOffset;

		if(Block_ParkELt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkELt_Data.AFOX		+= rOffset;
			Block_ParkELt_Data.AFIX		+= rOffset;
			Block_ParkELt_Data.AFX		+= rOffset;
			Block_ParkELt_Data.AROX		+= rOffset;
			Block_ParkELt_Data.ARIX		+= rOffset;
			Block_ParkELt_Data.ARX		+= rOffset;
		    //临时车位
			Block_ParkELt_Data.OFX		+= rOffset;
			Block_ParkELt_Data.IFX		+= rOffset;
			Block_ParkELt_Data.ORX		+= rOffset;
			Block_ParkELt_Data.IRX		+= rOffset;
		}
	}
#if 1	//移动雷达边缘数据
	iStartIndex = Block_EdgeR_StartIndex - cm2w(BLOCKMOVE_DISTY_REMAIN);
	iEndIndex = Block_EdgeR_EndIndex + cm2w(50);
	if(iStartIndex < BLOCK_EDGE_LENGTH_MIN)
		iStartIndex = BLOCK_EDGE_LENGTH_MIN;
	if(iEndIndex > BLOCK_EDGE_LENGTH_MAX)
		iEndIndex = BLOCK_EDGE_LENGTH_MAX;
	for(iIndex = iStartIndex; iIndex <= iEndIndex; iIndex++)
	{
		if(BlockEdgeDataR[iIndex] < BLOCK_EDGE_WIDTH_DISABLE)
			BlockEdgeDataR[iIndex] += rOffset;
		if(BlockPathDataR[iIndex] < BLOCK_EDGE_WIDTH_DISABLE)
			BlockPathDataR[iIndex] += rOffset;
	}

	iStartIndex = Block_EdgeL_StartIndex - cm2w(BLOCKMOVE_DISTY_REMAIN);
	iEndIndex = Block_EdgeL_EndIndex + cm2w(50);
	if(iStartIndex < BLOCK_EDGE_LENGTH_MIN)
		iStartIndex = BLOCK_EDGE_LENGTH_MIN;
	if(iEndIndex > BLOCK_EDGE_LENGTH_MAX)
		iEndIndex = BLOCK_EDGE_LENGTH_MAX;
	for(iIndex = iStartIndex; iIndex <= iEndIndex; iIndex++)
	{
		if(BlockEdgeDataL[iIndex] < BLOCK_EDGE_WIDTH_DISABLE)
			BlockEdgeDataL[iIndex] += rOffset;
		if(BlockPathDataL[iIndex] < BLOCK_EDGE_WIDTH_DISABLE)
			BlockPathDataL[iIndex] += rOffset;
	}
#endif
}

void BlockMove_BackTask(void)
{
	int rOffset, wOffset;
	int i;

	#if(BLOCK_EDGE_MOVE_INSTEAD_ROTATE)
	//地图移动过，旋转角度累加计数清零
	Block_Rotate_AngleSum = 0;
	#endif

	//取整数倍，防止数据流失
	wOffset = BlockMove_Edge_StartIndex;// - cm2w(20);
	rOffset = w2r(wOffset);

	BlockMove_Edge_StartIndex = 0;

	//减整数倍，防止数据流失
	{	//右侧数据处理
		SensorPosStartFRY				-= rOffset;
		SensorPositionFRY				-= rOffset;
		SensorPosFinishFRY				-= rOffset;

		Block_EdgeR_StartIndex			-= wOffset;
		Block_EdgeR_CurrIndex			-= wOffset;
		Block_EdgeR_EndIndex			-= wOffset;
		Block_EdgeR_PreviousIndex		-= wOffset;

		Block_EdgeR_Front_FrontY		-= wOffset;
		Block_EdgeR_Park_FrontY			-= wOffset;
		Block_EdgeR_Park_RearY			-= wOffset;

		Block_EdgeR_StatFront_StartIndex-= wOffset;
		Block_EdgeR_StatFront_EndIndex	-= wOffset;

		BlockMove_NextScanPosY_R		-= rOffset;

        Block_EdgeR_Park_Safe_RearY		-= wOffset;
        Block_EdgeR_Park_Safe_FrontY	-= wOffset;

        //Block_EdgeR_Filter_Rear		-= wOffset;
        //Block_EdgeR_Filter_Front		-= wOffset;

        Block_EdgeR_Filter_Index		-= wOffset;
        Block_EdgeR_Filter_PreIndex		-= wOffset;
		Block_EdgeR_Process_HToE_FrontIndex	-= wOffset;
		Block_EdgeR_Process_HToE_RearIndex	-= wOffset;
		if(RMaxSpeedIndex)
		{
			u8 Temp;
			u8 MoveTemp;
			MoveTemp = 255;//初始化一个值
			Temp = RMaxSpeedIndex;
			for(i=0;i<Temp;i++)
			{
				RSpeedIndexArray[i] -= wOffset;
				if(RSpeedIndexArray[i] < 0)
				{
					MoveTemp = i;
				}
			}
			if(MoveTemp != 255)//若初值改变了 移动数据
			{
				MoveTemp++;
				RMaxSpeedIndex = RMaxSpeedIndex-MoveTemp;
				for(i=0;i<RMaxSpeedIndex;i++)
				{
					RSpeedIndexArray[i] = RSpeedIndexArray[i+MoveTemp];
					RSpeedArray[i] = RSpeedArray[i+MoveTemp];
				}
				for(i=RMaxSpeedIndex;i<Temp;i++)
				{
					RSpeedIndexArray[i] = 0;
					RSpeedArray[i] = 0;
				}
			}
		}

		if(Block_EdgeR_Filter_Flag)
		{
			for(i=0;i<Block_EdgeR_NoisyIndex_TmpCnt;i++)
			{
				Block_EdgeR_NoisyIndex_TmpTab[i] = Block_EdgeR_NoisyIndex_TmpTab[i] - wOffset;
			}
		}
		for(i=0;i<Block_EdgeR_NoisyIndex_ParkCnt;i++)
		{
			Block_EdgeR_NoisyIndex_ParkTab[i] = Block_EdgeR_NoisyIndex_ParkTab[i] - wOffset;
		}
		
	}
	{	//左侧数据处理
		SensorPosStartFLY				-= rOffset;
		SensorPositionFLY				-= rOffset;
		SensorPosFinishFLY				-= rOffset;

		Block_EdgeL_StartIndex			-= wOffset;
		Block_EdgeL_CurrIndex			-= wOffset;
		Block_EdgeL_EndIndex			-= wOffset;
		Block_EdgeL_PreviousIndex		-= wOffset;

		Block_EdgeL_Front_FrontY		-= wOffset;
		Block_EdgeL_Park_FrontY			-= wOffset;
		Block_EdgeL_Park_RearY			-= wOffset;

		Block_EdgeL_StatFront_StartIndex-= wOffset;
		Block_EdgeL_StatFront_EndIndex	-= wOffset;

		BlockMove_NextScanPosY_L		-= rOffset;

        Block_EdgeL_Park_Safe_RearY		-= wOffset;
        Block_EdgeL_Park_Safe_FrontY	-= wOffset;

        //Block_EdgeL_Filter_Rear		-= wOffset;
        //Block_EdgeL_Filter_Front		-= wOffset;

		Block_EdgeL_Filter_Index		-= wOffset;
        Block_EdgeL_Filter_PreIndex		-= wOffset;
		Block_EdgeL_Process_HToE_FrontIndex	-= wOffset;
		Block_EdgeL_Process_HToE_RearIndex	-= wOffset;
		if(LMaxSpeedIndex)
		{
			u8 Temp;
			u8 MoveTemp;
			MoveTemp = 255;//初始化一个值
			Temp = LMaxSpeedIndex;
			for(i=0;i<Temp;i++)
			{
				LSpeedIndexArray[i] -= wOffset;
				if(LSpeedIndexArray[i] < 0)
				{
					MoveTemp = i;
				}
			}
			if(MoveTemp != 255)//若初值改变了 移动数据
			{
				MoveTemp++;
				LMaxSpeedIndex = LMaxSpeedIndex-MoveTemp;
				for(i=0;i<LMaxSpeedIndex;i++)
				{
					LSpeedIndexArray[i] = LSpeedIndexArray[i+MoveTemp];
					LSpeedArray[i] = LSpeedArray[i+MoveTemp];
				}
				for(i=LMaxSpeedIndex;i<Temp;i++)
				{
					LSpeedIndexArray[i] = 0;
					LSpeedArray[i] = 0;
				}
			}
		}
		if(Block_EdgeL_Filter_Flag)
		{
			for(i=0;i<Block_EdgeL_NoisyIndex_TmpCnt;i++)
			{
				Block_EdgeL_NoisyIndex_TmpTab[i] = Block_EdgeL_NoisyIndex_TmpTab[i] - wOffset;
			}
		}
		for(i=0;i<Block_EdgeL_NoisyIndex_ParkCnt;i++)
		{
			Block_EdgeL_NoisyIndex_ParkTab[i] = Block_EdgeL_NoisyIndex_ParkTab[i] - wOffset;
		}
		
	}

#if 1	//移动车体
	CarData.AY				-= rOffset;
	CarData.BodyFLY			-= rOffset;
	CarData.BodyFRY			-= rOffset;
	CarData.BodyRLY			-= rOffset;
	CarData.BodyRRY			-= rOffset;
	CarData.BodyCY			-= rOffset;
	CarData.WheelFLY		-= rOffset;
	CarData.WheelFRY		-= rOffset;
	CarData.WheelRLY		-= rOffset;
	CarData.WheelRRY		-= rOffset;
	CarData.RotateCentreY	-= rOffset;
#endif

	if(Block_ParkHL_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{
		Block_ParkHL_Data.AFOY		-= rOffset;
		Block_ParkHL_Data.AFIY		-= rOffset;
		Block_ParkHL_Data.AFY		-= rOffset;
		Block_ParkHL_Data.AROY		-= rOffset;
		Block_ParkHL_Data.ARIY		-= rOffset;
		Block_ParkHL_Data.ARY		-= rOffset;

		Block_ParkHL_Data.OFY		-= rOffset;
		Block_ParkHL_Data.IFY		-= rOffset;
		Block_ParkHL_Data.ORY		-= rOffset;
		Block_ParkHL_Data.IRY		-= rOffset;

		if(Block_ParkHLt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkHLt_Data.AFOY		-= rOffset;
			Block_ParkHLt_Data.AFIY		-= rOffset;
			Block_ParkHLt_Data.AFY		-= rOffset;
			Block_ParkHLt_Data.AROY		-= rOffset;
			Block_ParkHLt_Data.ARIY		-= rOffset;
			Block_ParkHLt_Data.ARY		-= rOffset;
		   //临时车位
			Block_ParkHLt_Data.OFY		-= rOffset;
			Block_ParkHLt_Data.IFY		-= rOffset;
			Block_ParkHLt_Data.ORY		-= rOffset;
			Block_ParkHLt_Data.IRY		-= rOffset;
		}

	}
	if(Block_ParkHR_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{
		Block_ParkHR_Data.AFOY		-= rOffset;
		Block_ParkHR_Data.AFIY		-= rOffset;
		Block_ParkHR_Data.AFY		-= rOffset;
		Block_ParkHR_Data.AROY		-= rOffset;
		Block_ParkHR_Data.ARIY		-= rOffset;
		Block_ParkHR_Data.ARY		-= rOffset;

		Block_ParkHR_Data.OFY		-= rOffset;
		Block_ParkHR_Data.IFY		-= rOffset;
		Block_ParkHR_Data.ORY		-= rOffset;
		Block_ParkHR_Data.IRY		-= rOffset;

		if(Block_ParkHRt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkHRt_Data.AFOY		-= rOffset;
			Block_ParkHRt_Data.AFIY		-= rOffset;
			Block_ParkHRt_Data.AFY		-= rOffset;
			Block_ParkHRt_Data.AROY		-= rOffset;
			Block_ParkHRt_Data.ARIY		-= rOffset;
			Block_ParkHRt_Data.ARY		-= rOffset;
		   //临时车位
			Block_ParkHRt_Data.OFY		-= rOffset;
			Block_ParkHRt_Data.IFY		-= rOffset;
			Block_ParkHRt_Data.ORY		-= rOffset;
			Block_ParkHRt_Data.IRY		-= rOffset;
		}
	}
	if(Block_ParkER_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{
		Block_ParkER_Data.AFOY		-= rOffset;
		Block_ParkER_Data.AFIY		-= rOffset;
		Block_ParkER_Data.AFY		-= rOffset;
		Block_ParkER_Data.AROY		-= rOffset;
		Block_ParkER_Data.ARIY		-= rOffset;
		Block_ParkER_Data.ARY		-= rOffset;

		Block_ParkER_Data.OFY		-= rOffset;
		Block_ParkER_Data.IFY		-= rOffset;
		Block_ParkER_Data.ORY		-= rOffset;
		Block_ParkER_Data.IRY		-= rOffset;

		if(Block_ParkERt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkERt_Data.AFOY		-= rOffset;
			Block_ParkERt_Data.AFIY		-= rOffset;
			Block_ParkERt_Data.AFY		-= rOffset;
			Block_ParkERt_Data.AROY		-= rOffset;
			Block_ParkERt_Data.ARIY		-= rOffset;
			Block_ParkERt_Data.ARY		-= rOffset;
		   //临时车位
			Block_ParkERt_Data.OFY		-= rOffset;
			Block_ParkERt_Data.IFY		-= rOffset;
			Block_ParkERt_Data.ORY		-= rOffset;
			Block_ParkERt_Data.IRY		-= rOffset;
		}
	}

	if(Block_ParkEL_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
	{
		Block_ParkEL_Data.AFOY		-= rOffset;
		Block_ParkEL_Data.AFIY		-= rOffset;
		Block_ParkEL_Data.AFY		-= rOffset;
		Block_ParkEL_Data.AROY		-= rOffset;
		Block_ParkEL_Data.ARIY		-= rOffset;
		Block_ParkEL_Data.ARY		-= rOffset;

		Block_ParkEL_Data.OFY		-= rOffset;
		Block_ParkEL_Data.IFY		-= rOffset;
		Block_ParkEL_Data.ORY		-= rOffset;
		Block_ParkEL_Data.IRY		-= rOffset;

		if(Block_ParkELt_Data.Status != BLOCK_PARK_DATA_STATUS_IDLE)
		{
			Block_ParkELt_Data.AFOY		-= rOffset;
			Block_ParkELt_Data.AFIY		-= rOffset;
			Block_ParkELt_Data.AFY		-= rOffset;
			Block_ParkELt_Data.AROY		-= rOffset;
			Block_ParkELt_Data.ARIY		-= rOffset;
			Block_ParkELt_Data.ARY		-= rOffset;

		   //临时车位
			Block_ParkELt_Data.OFY		-= rOffset;
			Block_ParkELt_Data.IFY		-= rOffset;
			Block_ParkELt_Data.ORY		-= rOffset;
			Block_ParkELt_Data.IRY		-= rOffset;
		}
	}

#if(CAN_UPDATE_ENABLE&&SENSOR_SIMULATOR)
//	Sensor_AutoSimulatorParkFarLength += wOffset;
#endif

#if(CAN_UPDATE_ENABLE)
//Pin_Set_TestR17();
#endif
	BlockMove_Process(wOffset);
#if(CAN_UPDATE_ENABLE)
//Pin_Clr_TestR17();
#endif
}

void BlockMove_Init(void)
{
//	BlockMove_NextScanPosY_L = r2w(CarData.BodyCY) + cm2w(20);
//	BlockMove_NextScanPosY_R = r2w(CarData.BodyCY) + cm2w(10);	//错开时间扫描
	BlockMove_NextScanPosY_L = CarData.BodyCY + cm2r(20);
	BlockMove_NextScanPosY_R = CarData.BodyCY + cm2r(10);	//错开时间扫描
	if(Block_EdgeL_StartIndex < Block_EdgeR_StartIndex)
		BlockMove_Edge_StartIndex = Block_EdgeL_StartIndex;
	else
		BlockMove_Edge_StartIndex = Block_EdgeR_StartIndex;
}





