package jpabook.jpaitem.domain;

import java.time.LocalDateTime;
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

	@Embedded
	private Period period;
	@Embedded
	private Address address;


	@OneToMany(mappedBy = "member")
	private List<Order> orders = new ArrayList<>();
}
