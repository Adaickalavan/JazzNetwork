package main

import "fmt"

func main() {
	// f := evenFib1()
	f := evenFib2()
	var sum = float64(0)
	for i := 1; i <= 100; i++ {
		evenFibValue := f()
		sum += evenFibValue
		// fmt.Println("evenValue", evenFibValue)
	}
	fmt.Println("sum", sum)
}

//Loop to obtain every third number which is even
func evenFib1() func() float64 {
	x := float64(0) //x=even
	y := float64(1) //y=odd
	return func() float64 {
		x, y = y, x+y // x=odd, y=odd
		x, y = y, x+y // x=odd, y=even
		x, y = y, x+y // x=even, y=odd
		return x
	}
}

//Use formula to obtain every third number which is even
//F_{n+6} = 4F_{n+3} + F_{n}
func evenFib2() func() float64 {
	x := float64(0)
	y := float64(2) //F_{3}
	return func() float64 {
		x, y = y, 4*y+x //x=F_{n}, y=F_{n+3}
		return x
	}
}
