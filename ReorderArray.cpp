//调整数组，使得奇数位于偶数前面
//12345->15342

void ReorderOddEven(int* pData, unsigned int length)
{
	if(pData == NULL || length ==0)
		return;
	int* pBegin = pData;
	int* pEnd = pData + length -1;
	
	while(pBegin < pEnd)
	{
		//向后移动PBegin,直到它指向偶数
		while(pBegin < pEnd && (*pBegin & 0x1) != 0)
			pBegin ++;
		//向前移动pEnd，直到它指向奇数
		while(pBegin < pEnd && (*pEnd & 0x1) != 0)
			pEnd --;
		
		if(pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}	
	
	}
}