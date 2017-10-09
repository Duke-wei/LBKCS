/*************************************************************************
    > File Name: heap.cpp
    > Author: Duke-wei
    > Mail: 13540639584@163.com 
    > Created Time: 2017年05月02日 星期二 21时53分30秒
 ************************************************************************/
/*
 *二叉堆的两个特性：
 *1.父结点的键值总是大于或等于(小于或等于)任何一个子节点的键值。
 *2.每个结点的左子树和右子树都是二叉堆。
 * 
 * 一般通过数组来存储二叉堆，其中i的父结点(i-1)/2，i的左右子结点2*i+1，2*i+2
 * 注意，要从小到大排序则使用大顶堆，从大到小排序，使用小顶堆。
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Heap{
	public:
		Heap(){ }
		Heap(vector<int> &nums,bool bigc=true);
		~Heap(){ }
		void Heap_print(){
			for(int i=0;i<(int)hv.size();++i){
				cout<<hv[i]<<" ";
			}
			cout<<endl;
		}
		void Heap_del();
		void Heap_ins(int val);
		void Heap_fixup(int i);
		void Heap_fixdown(int i);
		vector<int> Heap_sort();
	private:
		vector<int> hv;//类中存储二叉堆的数组。
		int len;//给定长度，给排序函数的使用。
		bool big;//判定是大顶堆还是小顶堆,big默认为true
};

//通过给定数组初始化堆，默认大顶堆
Heap::Heap(vector<int> &nums,bool bigc){
	hv = nums;
	big = bigc;
	len = (int)hv.size();
	for(int i= (len-1)/2;i>=0;--i){
		Heap_fixdown(i);
	}
}


//通过结点i进行向上修正，默认为大顶堆修正。
void Heap::Heap_fixup(int i){
	if(big){
		for(int j=(i-1)/2;(j>=0&&i!=0)&&hv[i]<hv[j];i=j,j=(i-1)/2)
			swap(hv[i],hv[j]);
	}else{
		for(int j=(i-1)/2;(j>=0&&i!=0)&&hv[i]>hv[j];i=j,j=(i-1)/2)
			swap(hv[i],hv[j]);
	}
}

//通过结点i进行向下修正，默认为大顶堆修正。
void Heap::Heap_fixdown(int i){
	int j = 2*i+1;
	if(big){
		while(j<len){
			//j指向最大的子结点。
			if(j+1<len&&hv[j]<hv[j+1]){
				j++;
			}
			if(hv[j]<hv[i]){
				break;
			}else{
				swap(hv[j],hv[i]);
				i = j;
				j = 2*i+1;
			}
		}
	}else{
		while(j<len){
			//j指向最小的子结点。
			if(j+1<len&&hv[j]>hv[j+1]){
				j++;
			}
			if(hv[j]>hv[i]){
				break;
			}else{
				swap(hv[j],hv[i]);
				i = j;
				j = 2*i+1;
			}
		}
	}
}

//插入一个值为val的结点。
void Heap::Heap_ins(int val){
	hv.push_back(val);
	int i = len;
	len += 1;
	Heap_fixup(i);
}

//按定义，堆只删除堆顶元素。
void Heap::Heap_del(){
	int i = len;
	if(i>1) swap(hv[0],hv[i-1]);
	len -= 1;
	if(len!=0) Heap_fixdown(0);
}

vector<int> Heap::Heap_sort(){
	while(len!=0){
		Heap_del();
	}
	len = (int)hv.size();
	return hv;
}

int main(){
	vector<int> nums={1,2,5,8,7,9,6,3,4};
	Heap a(nums,false);
	a.Heap_print();
	a.Heap_sort();
	a.Heap_print();
}
