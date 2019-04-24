package main

import "fmt"

func main() {

	var i = []int{1, 4, 6}
	var j = []int{2, 3, 5}
	var output = &[]int{}
	merge(i, j, output)
	fmt.Println(*output)

}

func merge(i []int, j []int, output *[]int) {
	switch {
	case len(i) == 0 && len(j) == 0:
		return
	case len(i) > 0 && len(j) == 0:
		*output = append(*output, i...)
	case len(i) == 0 && len(j) > 0:
		*output = append(*output, j...)
	case len(i) >= 1 && len(j) >= 1:
		if i[0] <= j[0] {
			*output = append(*output, i[0])
			merge(i[1:], j, output)
		} else {
			*output = append(*output, j[0])
			merge(i, j[1:], output)
		}
	}
}
