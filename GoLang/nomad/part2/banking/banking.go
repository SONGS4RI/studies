package banking

import (
	"errors"
	"fmt"
)

var errNoMoney = errors.New("can't withdraw you are poor")

type Account struct {
	owner   string
	balance int
}

func NewAccount(owner string) *Account {
	account := Account{owner: owner, balance: 0}
	return &account
}

func (a *Account) Deposit(amount int) {
	a.balance += amount
}

func (a *Account) Withdraw(amount int) error {
	if a.balance < amount {
		return errNoMoney
	}
	a.balance -= amount
	return nil
}

func (a *Account) ChangeOwner(newOwner string) {
	a.owner = newOwner
}

func (a Account) GetOwner() string {
	return a.owner
}

func (a *Account) GetBalance() int {
	return a.balance
}

func (a Account) String() string {
	return fmt.Sprint(a.owner, "'s account.\nHas:", a.balance)
}
