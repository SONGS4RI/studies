package main

import (
	"regexp"
	"strings"
	"fmt"
)

func ValidIP4(ipAddress string) bool {
	ipAddress = strings.Trim(ipAddress, " ")
	re, _ := regexp.Compile(`^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$`)
	if re.MatchString(ipAddress) {
		return true
	}
	return false
}

func main() {
	IPv4 := "127.0.0.1"
	fmt.Printf("IPv4[%s] valid: %t", IPv4, ValidIP4(IPv4))
}
