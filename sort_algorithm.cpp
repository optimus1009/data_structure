//查找排序
//1：冒泡排序
//2：快速排序
//3：堆排序
//4：归并排序
//5：杨氏矩阵的增删改查


//冒泡排序
void BubbleSort(int* a, int size)
{
	int i,j;
	int t;
	bool bBubble;
	for(i = 0; i< size -1, i++)
	{
		bBubble = false;
		for(j = 0; j < size-i-1;j++)
		{
			if(a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				bBubble = true;
			}
		}
		if(!bBubble)
			break;
	}
}

//堆排序
void HeapAjust(int* a ,int n ,int size)
{
	int nChild = z*n +1;//左孩子
	int t;
	while(nChild < size)
	{
		if((nChild +1 < size) && (a[nChild + 1] > a[nChild]))
			nChild++;
		if(a[nChild]<a[n])//孩子比父亲小，说明调整完毕
			break;
		t = a[nChild];
		a[nChild] = a[n];
		a[n] = t;
		
		n = nChild;
		nChild = 2*n+1;
	}
}
void HeapSort(int*a,int size,int k)//前K大
{
	int i;
	for(i = size/2 -1;i >=0;i--)//一次调整堆
		HeapAjust(a,i,size);
	int t ;
	int s = size -k;
	while(size > s)//一次找到最大的并放置到数组末尾
	{
		t = a[size -1];
		a[size -1] = a[0];
		a[0] = t;
		size--;
		HeapAjust(a,0,size);
	}
}

//快速排序
void QuickSort(int* a,int from ,int to)
{
	if(to - from <= 10)
	{
		BubbleSort(a+from,to-from+1)
		return;
	}
	int key = SelectPivotkey(a[from],a[to],a[(from+to)/2]);
	int index = Patition(key, a, from, to);
	QuickSort(a, from, index -1);
	QuickSort(a,index,to);
}
void QuickSort(int* a,int size)
{
	QuickSort(a,0,size-1);
}
int Patition(int key,int*a ,int from, int to )
{
	int t;
	while(from < to)
	{
		while((from < to) && a[from] < key)
			from++;
		while((from < to) && a[to] >= key))
			to--;
		t = a[from];
		a[from] = a[to];
		a[to] = t;
	}
	return from;
}

//快速排序2
int quicksort(vector<int> &v, int left, int right)
{
        if(left < right)
		{
                int key = v[left];
                int low = left;
                int high = right;
                while(low < high)
				{
                        while(low < high && v[high] > key)
						{
                                high--;
                        }
                        swap(v[low],v[high]);
                        while(low < high && v[low] < key)
						{
                                low++;
                        }
                        swap(v[high],v[low]);
                }
                v[low] = key;
                quicksort(v,left,low-1);
                quicksort(v,low+1,right);
        }
}

//归并排序-非递归
#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
using namespace std;
/**将a开头的长为length的数组和b开头长为right的数组合并n为数组长度，用于最后一组*/
void　Merge(int*　data,int　a,int　b,int　length,int　n)
{
　int　right;
　if(b+length-1 >= n-1)　right = n-b;
　else　right = length;
　int*　temp = new　int[length+right];
　int　i=0, j=0;
　while(i<=length-1 && j<=right-1)
{
    　if(data[a+i] <= data[b+j])
	{
    　    temp[i+j] = data[a+i];i++;
    }
    　else
	{
        temp[i+j] = data[b+j];
        j++;
    }
}
　if(j == right)
{//a中还有元素，且全都比b中的大,a[i]还未使用
　  memcpy(temp + i + j, data + a + i, (length - i) * sizeof(int));
}
  else if(i == length)
  {
      memcpy(temp + i + j, data + b + j, (right - j)*sizeof(int));
  }
　memcpy(data+a, temp, (right + length) * sizeof(int));
　delete [] temp;
}
void　MergeSort(int*　data, int　n){
　int　step = 1;
　while(step < n){
    　for(int　i=0; i<=n-step-1; i+=2*step)
    　    Merge(data, i, i+step, step, n);
    //将i和i+step这两个有序序列进行合并
    //序列长度为step
    //当i以后的长度小于或者等于step时，退出
    　step*=2;//在按某一步长归并序列之后，步长加倍
　}
}
int　main()
{
　int　n;
　cin>>n;
　int*　data = new　int[n];
　if(!data)　exit(1);
　int　k = n;
　while(k--)
{
　    cin>>data[n-k-1];
}
　clock_t　s = clock();
　MergeSort(data, n);
　clock_t　e = clock();
　k=n;
　while(k--)
{
　    cout<<data[n-k-1]<<' ';
}
　cout<<endl;
　cout<<"the algorithm used"<<e-s<<"miliseconds."<<endl;
　delete　data;
　return　0;
}

//归并排序-递归
int temp[100];
void Merge(int* a,int low,int mid, int high)
{
	int i = low;
	int j = mid+1;
	int size =0;
	for(; (i <= mid) &&(j<=high);size++)
	{
		if(a[i]<a[j])
			temp[size] = a[i++];
		else
			temp[size] = a[j++];
	}
	//剩余部分的copy
	while(i <= mid)
		temp[size++] = a[i++];
	while(j <= high)
		temp[size++] = a[j++];
	
	//将temp中的值重新copy到a数组中去
	for(i = 0; i <size;i++)
		a[low + i] = temp[i];
}
void MergeSort(int* a,int low,int high)
{
	if(low >= high)
		return;
	int mid = (low + high) /2;
	MergeSort(a,low,mid);
	MergeSort(a,mid+1,high);
	Merge(a,low,mid,high);
}