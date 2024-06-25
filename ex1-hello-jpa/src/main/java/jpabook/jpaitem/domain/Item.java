package jpabook.jpaitem.domain;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

import java.util.ArrayList;
import java.util.List;

@Entity
@Getter
@Setter
@Inheritance(strategy = InheritanceType.JOINED)
@DiscriminatorColumn(name = "DTYPE")// DTYPE 생김
public abstract class Item {
	@Id @GeneratedValue
	@Column(name = "ITEM_ID")
	private Long id;

	@Column(name = "NAME")
	private String name;

	@Column(name = "PRICE")
	private Long price;

	@Column(name = "STOCKQUANTITY")
	private Long stockQuantity;

	@ManyToMany(mappedBy = "items")
	private List<Category> categories = new ArrayList<>();
}
