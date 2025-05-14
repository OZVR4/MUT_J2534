#pragma once

typedef struct {
	unsigned long ProtocolID;
	unsigned long RxStatus;
	unsigned long TxFlags;
	unsigned long Timestamp;
	unsigned long DataSize;
	unsigned long ExtraDataIndex;
	unsigned char Data[4128];
} PASSTHRU_MSG;