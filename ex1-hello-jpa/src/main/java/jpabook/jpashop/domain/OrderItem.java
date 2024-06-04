package jpabook.jpashop.domain;

import org.hibernate.annotations.GenericGenerator;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;

@Entity
public class OrderItem {
	@Id @GeneratedValue
	@Column(name = "order_item_id")
	private Long id;

	@Column(name = "order_id")
	private Long orderId;

	@Column(name = "itemId")
	private Long itemId;

	private int orderPrice;
	private int count;
}
