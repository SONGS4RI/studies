package jpabook.jpaitem.domain;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.FetchType;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.OneToMany;
import jakarta.persistence.Table;
import lombok.Getter;
import lombok.Setter;

@Entity
@Table(name = "ORDERS")
@Getter
@Setter
public class Order {
	@Id @GeneratedValue
	Long id;

	@ManyToOne(fetch = FetchType.LAZY)
	@Column(name = "MEMBER_ID")
	Member member;

	@OneToMany(mappedBy = "order")
	@Column(name = "ORDER_ITEMS")
	List<OrderItem> orderItems = new ArrayList<>();

	@Column(name = "ORDERDATE")
	LocalDateTime orderDate;

	@Column(name = "STATUS")
	Status status;

	public void addOrderItem(OrderItem orderItem) {
		orderItems.add(orderItem);
		orderItem.setOrder(this);
	}
}
