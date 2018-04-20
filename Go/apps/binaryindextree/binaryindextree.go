//https://github.com/ybping/binary_index_tree/blob/master/src/tree/tree.go
//https://www.cnblogs.com/xudong-bupt/p/3484080.html
/*
This package implement the binary index tree.
The relationship of tree is <y, x>, y is the father of x. And x + 2^k = y
*/
package tree

import "fmt"

// The abstract date type of BinaryIndexTree
type BinayIndexTree struct {
	count  int
	node   []int
	values []int
}

// Constructor function of BinaryIndexTree
func NewBinaryTreeArrary(count int) *BinayIndexTree {
	return &BinayIndexTree{count, make([]int, count), make([]int, count)}
}

func (bit *BinayIndexTree) Print() {
	for i := 0; i < bit.count; i++ {
		fmt.Print(bit.values[i], " ")
	}
	fmt.Println()
}

// Update an value of num which index is `index`
func (bit *BinayIndexTree) Update(index, num int) {
	bit.values[index] += num
	for {
		if index > bit.count {
			break
		}
		bit.node[index] += num
		index = index + lowbit(index)
	}
}

// Calculate sum[0:x]
func (bit *BinayIndexTree) Sum(x int) (ret int) {
	sum := 0
	for {
		if x <= 0 {
			break
		}
		sum += bit.node[x]
		x -= lowbit(x)
	}
	return sum
}

func lowbit(x int) (ret int) {
	return x & -x
}