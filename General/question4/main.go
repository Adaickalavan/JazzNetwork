package main

import (
	"fmt"
	"log"
	"strconv"
	"strings"
)

func main() {

	var value uint64 = 37
	var base uint = 36

	var output string
	convertBase1(value, base, &output)
	// convertBase2(value, base, &output)
	fmt.Println(output)

}

var baseVal = []string{
	"0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
	"A", "B", "C", "D", "E", "F", "G", "H", "I", "J",
	"K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",
	"U", "V", "W", "X", "Y", "Z"}

//Use recursive quotient and remainder to convert base of given decimal integer
func convertBase1(value uint64, base uint, output *string) {
	if base > 36 {
		log.Fatal("Base values larger than 36 are not supported")
	}
	quotient := value / uint64(base)
	remainder := value % uint64(base)
	*output = baseVal[remainder] + *output
	if quotient == 0 {
		return
	}
	convertBase1(quotient, base, output)
}

//Use strconv to convert base of given decimal integer
func convertBase2(value uint64, base uint, output *string) {
	if base > 36 {
		log.Fatal("Base values larger than 36 are not supported")
	}
	intBase := int(base)
	*output = strconv.FormatUint(value, intBase)
	*output = strings.ToUpper(*output)
}
