package jpabook.jpashop.domain;

import java.time.LocalDateTime;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.EnumType;
import jakarta.persistence.Enumerated;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.Getter;
import lombok.Setter;

@Entity
@Getter
@Setter
@Table(name = "ORDERS")
public class Order {
	@Id
	@GeneratedValue
	@Column(name = "order_id")
	private Long id;
	@Column(name = "member_id")
	private Long memberId;

	private Member member;
	private LocalDateTime orderDate;
	@Enumerated(EnumType.STRING)
	private OrderStatus status;
}
