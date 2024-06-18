package jpabook.jpaitem.domain;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToOne;
import lombok.Getter;
import lombok.Setter;

@Entity
@Getter
@Setter
public class OrderItem {
	@Id @GeneratedValue
	@Column(name = "ORDER_ITEM_ID")
	Long id;

	@ManyToOne(fetch = FetchType.LAZY)
	Order order;

	@ManyToOne(fetch = FetchType.LAZY)
	Item item;

	int orderPrice;

	int count;
}
