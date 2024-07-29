package jpabook.jpashop.service;

import java.util.List;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import jpabook.jpashop.domain.Item;
import jpabook.jpashop.domain.item.Book;
import jpabook.jpashop.repository.ItemRepository;
import lombok.RequiredArgsConstructor;

@Service
@Transactional(readOnly = true)
@RequiredArgsConstructor
public class ItemService {
	private final ItemRepository itemRepository;

	@Transactional
	public void saveItem(Item item) {
		itemRepository.save(item);
	}

	@Transactional
	public Item updateItem(Long itemId, Book param) {
		// 머지 방법을 사용하면 null로 갱신되는 문제가 발생할 수 있기때문에
		// 최대한 변경감지로 설계하는게 훨씬 낫다.
		Item findItem = itemRepository.findOne(itemId);
		findItem.setPrice(param.getPrice());
		findItem.setName(param.getName());
		findItem.setPrice(param.getPrice());
		findItem.setStockQuantity(param.getStockQuantity());
		return findItem;
	}
	public List<Item> findItems() {
		return itemRepository.findAll();
	}

	public Item findOne(Long itemId) {
		return itemRepository.findOne(itemId);
	}
}
