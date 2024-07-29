package dict

import "errors"

type Dictionary map[string]string

var (
	errNotFound   = errors.New("word not found")
	errWordExists = errors.New("word already exists")
)

func (d Dictionary) Search(word string) (string, error) {
	value, exists := d[word]
	if exists {
		return value, nil
	}
	return "", errNotFound
}

func (d Dictionary) Add(word, def string) error {
	if _, err := d.Search(word); err != nil {
		return errWordExists
	}
	d[word] = def
	return nil
}

func (d Dictionary) Update(word, def string) {
	d[word] = def
}

func (d Dictionary) Delete(word string) {
	delete(d, word)
}
