#pragma once
#include "AbstractIO.h"

class CVirtualMemoryIO : public CAbstractIO
{
public:
	CVirtualMemoryIO(ULONG64 uSize, int BlockSize = 20);
	virtual ~CVirtualMemoryIO();

	virtual ULONG64 GetDiskSize() const;
	virtual ULONG64 GetAllocSize() const;
	virtual bool CanBeFormated() const { return true; }

	virtual int Init();
	virtual void PrepViewOfFile(BYTE*) {}

	virtual bool DiskWrite(void* buf, int size, __int64 offset);
	virtual bool DiskRead(void* buf, int size, __int64 offset);
	virtual void TrimProcess(DEVICE_DATA_SET_RANGE* range, int n);

protected:
	void Expand(ULONG64 uSize);

	struct SVirtualMemory* m;
};

