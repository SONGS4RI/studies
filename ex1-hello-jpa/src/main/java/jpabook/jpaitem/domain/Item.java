package jpabook.jpaitem.domain;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import lombok.Getter;
import lombok.Setter;

@Entity
@Getter
@Setter
public class Item {
	@Id @GeneratedValue
	@Column(name = "ITEM_ID")
	Long id;

	@Column(name = "NAME")
	String name;

	@Column(name = "PRICE")
	Long price;

	@Column(name = "STOCKQUANTITY")
	Long stockQuantity;
}
