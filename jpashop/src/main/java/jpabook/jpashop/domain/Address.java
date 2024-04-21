package jpabook.jpashop.domain;

import jakarta.persistence.Embeddable;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;

@Embeddable
@Entity
public class Address {
	@Id
	@GeneratedValue
	private Long id;

	private String city;
	private String street;
	private String zipcode;
}
