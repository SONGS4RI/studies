package jpabook.jpaitem.domain;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

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

	@ElementCollection
	@CollectionTable(name = "FAVORITE_FOOD", joinColumns =
		@JoinColumn(name = "MEMBER_ID")
	)
	private Set<String> favoriteFoods = new HashSet<>();
//	 값을 변경할때 관련된 전체를 삭제하고 다시 만들어준다.
//	@ElementCollection
//	@CollectionTable(name = "ADDRESS_HISTORY", joinColumns =
//	@JoinColumn(name = "MEMBER_ID"))
//	private List<Address> addressHistory = new ArrayList<>();

	@OneToMany(cascade = CascadeType.ALL, orphanRemoval = true)
	@JoinColumn(name = "MEMBER_ID")
	private List<AddressEntity> addressHistory = new ArrayList<>();

	@OneToMany(mappedBy = "member")
	private List<Order> orders = new ArrayList<>();
}
