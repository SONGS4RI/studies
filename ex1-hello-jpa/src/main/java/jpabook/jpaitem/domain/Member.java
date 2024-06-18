package jpabook.jpaitem.domain;

import java.util.ArrayList;
import java.util.List;

import jakarta.persistence.Column;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.Id;
import jakarta.persistence.OneToMany;
import lombok.Getter;
import lombok.Setter;

@Entity
@Getter
@Setter
public class Member {
	@Id @GeneratedValue
	@Column(name = "MEMBER_ID")
	Long id;
	@Column(name = "NAME")
	String name;
	@Column(name = "CITY")
	String city;
	@Column(name = "STREET")
	String street;
	@Column(name = "ZIPCODE")
	String zipcode;

	@OneToMany(mappedBy = "member")
	List<Order> orders = new ArrayList<>();
}
