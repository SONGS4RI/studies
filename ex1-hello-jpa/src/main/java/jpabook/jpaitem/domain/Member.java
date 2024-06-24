package jpabook.jpaitem.domain;

import java.util.ArrayList;
import java.util.List;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;

@Entity
@Getter
@Setter
public class Member {
	@Id @GeneratedValue
	@Column(name = "MEMBER_ID")
	private Long id;
	@Column(name = "NAME")
	private String name;
	@Column(name = "CITY")
	private String city;
	@Column(name = "STREET")
	private String street;
	@Column(name = "ZIPCODE")
	private String zipcode;

	@OneToMany(mappedBy = "member")
	private List<Order> orders = new ArrayList<>();
}
